/**
 * UNDER CONSTRUCTION - API UNSTABLE
 */

// TODO: Consider alternative implementation of KeyObject subtype.

module KeyObject = {
  type t('a, 'b);
  type symmetric = [ | `Symmetric ];
  type asymmetric = [ | `Asymmetric ];
  type publicKey = [ | `PublicKey ];
  type privateKey = [ | `PrivateKey ];
  type secretKey = [ | `SecretKey ];

  [@bs.send] external symmetricExport: t(symmetric, [< publicKey | privateKey ]) => Buffer.t = "export";

  [@bs.send] external asymmetricExport: ( t(asymmetric, [< publicKey | privateKey | secretKey ])) => Buffer.t = "export";

  module Symmetric = {
    type kind = [ `Symmetric ];
    type nonrec t('a) = t([ kind ], 'a);
    module Impl = {
    };
  };

  module Asymmetric = {
    type kind = [ `Symmetric ];
    type nonrec t('a) = t([ kind ], 'a);
    module Impl = {
    };
  };

  module Impl = {
    include Symmetric.Impl;
    include Asymmetric.Impl;
  };

  include Impl;

};

module PivateKey = {
  include KeyObject.Impl;
  type kind = [ KeyObject.publicKey ];
  type t('a) = KeyObject.t('a, [ kind ]);

  [@bs.module "crypto"] external make: Buffer.t => t('a) = "createPrivateKey";
  [@bs.module "crypto"] external makeWithPassphrase: { .. "key": Buffer.t, "passphrase": Buffer.t } => t('a) = "createPrivateKey";

};

module PublicKey = {
  include KeyObject.Impl;
  type kind = [ KeyObject.publicKey ];
  type t('a) = KeyObject.t('a, [ kind ]);

  [@bs.module "crypto"] external make: Buffer.t => t('a) = "createPublicKey";
  [@bs.module "crypto"] external fromPrivateKey: KeyObject.t('a, [> KeyObject.privateKey ]) => t('a) = "createPublicKey";

};

module Hash = {
  type kind = [ Stream__.transform | `Hash ];
  type t = Stream__.t(Buffer.t, [ kind ]); 
  module Impl = {
    include Stream__.Transform.Impl;
    [@bs.send] external copy: Stream__.t('data, [> kind ]) => Stream__.t('data, [> kind ]) = "copy"; 
    [@bs.send] external digest: Stream__.t('data, [> kind ]) => Buffer.t = "digest"; 
    [@bs.send] external update: (Stream__.t('data, [> kind ]), Buffer.t) => unit = "update";
  };
  include Impl;
};

[@bs.module "crypto"] external createHash: string => Hash.t = "createHash";

module Hmac = {
  type kind = [ Stream__.transform | `Hmac ];
  type t = Stream__.t(Buffer.t, [ kind ]);
  module Impl = {
    include Stream__.Transform.Impl;
    [@bs.send] external digest: Stream__.t('data, [> kind ]) => Buffer.t = "digest";
    [@bs.send] external update: (Stream__.t('data, [> kind ]), Buffer.t) => unit = "update";
  };
  include Impl;
};

[@bs.module "crypto"] external createHmac: (string, ~key: string) => Hmac.t = "createHmac";

module Certificate = {

  type t;

  [@bs.send] external exportChallenge: (t, Buffer.t) => Buffer.t = "exportChallenge"; 
  [@bs.send] external exportPublicKey: ( t, Buffer.t) => Buffer.t = "exportPublicKey";
  [@bs.send] external verifyCertificate: (t, Buffer.t) => bool = "verifyCertificate"

};

module Cipher = {

  type kind = [ Stream__.transform | `Cipher ];
  type t = Stream__.t(Buffer.t, [ kind ]);

  module Impl = {
    include Stream__.Transform.Impl;
    [@bs.send] external final: (Stream__.t('data, [> kind ]), string) => Buffer.t = "final";
    [@bs.send] external setAAD: (Stream__.t('data, [> kind ]), Buffer.t) => t = "setAAD";
    [@bs.send] external setAADWith: (Stream__.t('data, [> kind ]), Buffer.t, ~options: Stream__.Transform.makeOptions) => t = "setAAD";
    [@bs.send] external getAuthTag: Stream__.t('data, [> kind ]) => Buffer.t = "getAuthTag";
    [@bs.send] external setAutoPadding: (Stream__.t('data, [> kind ]), bool) => t = "setAutoPadding";
    [@bs.send] external update: (Stream__.t('data, [> kind ]), Buffer.t) => Buffer.t = "update";
  };

  include Impl;

  [@bs.module "crypto"] external make: (
      ~algorithm: string,
      ~key: KeyObject.t('a, [> KeyObject.secretKey ]),
      ~iv: Js.Null.t(Buffer.t)
    ) => t = "createCipheriv";

  [@bs.module "crypto"] external makeWith: (
      ~algorithm: string,
      ~key: KeyObject.t('a, [> KeyObject.secretKey ]),
      ~iv: Js.Null.t(Buffer.t),
      ~options: Stream__.Transform.makeOptions=?
    ) => t = "createCipheriv";

};

module Decipher = {

  type kind = [ Stream__.transform | `Decipher ];
  type t = Stream__.t(Buffer.t, [ kind ]);

  module Impl = {
    [@bs.send] external final: (Stream__.t('data, [> kind ]), string) => Buffer.t = "final";
    [@bs.send] external setAAD: (Stream__.t('data, [> kind ]), Buffer.t) => t = "setAAD";
    [@bs.send] external setAADWith: (Stream__.t('data, [> kind ]), Buffer.t, ~options: Stream__.Transform.makeOptions) => t = "setAAD";
    [@bs.send] external setAuthTag: (Stream__.t('data, [> kind ]), Buffer.t) => t = "setAuthTag";
    [@bs.send] external setAutoPatting: (Stream__.t('data, [> kind ]), bool) => t = "setAutoPadding";
    [@bs.send] external update: (Stream__.t('data, [> kind ]), Buffer.t) => Buffer.t = "update";
  };

  include Impl;

  [@bs.module "crypto"] external make: (
      ~algorithm: string,
      ~key: KeyObject.t('a, [> KeyObject.secretKey ]),
      ~iv: Js.Null.t(Buffer.t)
    ) => t = "createDecipheriv";

  [@bs.module "crypto"] external makeWith: (
      ~algorithm: string,
      ~key: KeyObject.t('a, [> KeyObject.secretKey ]),
      ~iv: Js.Null.t(Buffer.t),
      ~options: Stream__.Transform.makeOptions=?
    ) => t = "createDecipheriv";

};

module DiffieHellman = {

};

module DiffieHellmanGroup = {

};

module Sign = {

};

module Verify = {

};

