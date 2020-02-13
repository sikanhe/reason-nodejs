
// TODO: Consider alternative implementation of KeyObject subtype.

module KeyObject = {
  type t('a, 'b);
  type symmetric = [ | `Symmetric ];
  type asymmetric = [ | `Asymmetric ];
  type publicKey = [ | `PublicKey ];
  type privateKey = [ | `PrivateKey ];
  type secretKey = [ | `SecretKey ];

  [@bs.send] external symmetricExport: t(symmetric, [< publicKey | privateKey ]) => BinaryLike.t([< BinaryLike.string_ | BinaryLike.buffer ]) = "export";

  [@bs.send] external asymmetricExport: ( t(asymmetric, [< publicKey | privateKey | secretKey ])) => BinaryLike.t([< BinaryLike.string_ | BinaryLike.buffer ]) = "export";

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

  [@bs.module "crypto"] external make: BinaryLike.t([< BinaryLike.string_ | BinaryLike.buffer ]) => t('a) = "createPrivateKey";

  [@bs.module "crypto"] external makeWithPassphrase:
    {
      ..
      "key": BinaryLike.t([< BinaryLike.string_ | BinaryLike.buffer ]),
      "passphrase": BinaryLike.t([< BinaryLike.string_ | BinaryLike.buffer ])
    }
    => t('a) = "createPrivateKey";

};

module PublicKey = {
  include KeyObject.Impl;
  type kind = [ KeyObject.publicKey ];
  type t('a) = KeyObject.t('a, [ kind ]);

  [@bs.module "crypto"] external make: BinaryLike.t([< BinaryLike.string_ | BinaryLike.buffer ]) => t('a) = "createPublicKey";

  [@bs.module "crypto"] external fromPrivateKey: KeyObject.t('a, [> KeyObject.privateKey ]) => t('a) = "createPublicKey";

};

module Hash = {
  type kind = [ Stream.transform | `Hash ];
  type t = Stream.t([ kind ]); 
  module Impl = {
    include Stream.Transform.Impl;
    [@bs.send] external copy: Stream.t([> kind ]) => Stream.t([> kind ]) = "copy"; 
    [@bs.send] external digest: Stream.t([> kind ]) => Buffer.t = "digest"; 
    [@bs.send] external digestWithEncoding: (Stream.t([> kind ]), [@bs.string] [ | `latin1 | `hex | `base64 ]) => string = "digest";
    [@bs.send] external update: (Stream.t([> kind ]), string) => unit = "update";
    [@bs.send] external updateWithEncoding: (Stream.t([> kind ]), [@bs.string] [ | `utf8 | `ascii | `latin1 ]) => unit = "update";
    [@bs.send] external updateBuffer: (Stream.t([> kind ]), Buffer.t) => unit = "update";
    [@bs.send] external updateDataView: (Stream.t([> kind ]), Js.TypedArray2.DataView.t) => unit = "update";
  };
  include Impl;
};

[@bs.module "crypto"] external createHash: string => Hash.t = "createHash";

module Hmac = {
  type kind = [ Stream.transform | `Hmac ];
  type t = Stream.t([ kind ]);
  module Impl = {
    include Stream.Transform.Impl;
    [@bs.send] external digest: Stream.t([> kind ]) => Buffer.t = "digest";
    [@bs.send] external digestWithEncoding: (Stream.t([> kind ]), [@bs.string] [ | `latin1 | `hex | `base64 ]) => string = "digest";
    [@bs.send] external update: (Stream.t([> kind ]), string) => unit = "update";
    [@bs.send] external updateWithEncoding: (Stream.t([> kind ]), [@bs.string] [ | `utf8 | `ascii | `latin1 ]) => unit = "update";
    [@bs.send] external updateBuffer: (Stream.t([> kind ]), Buffer.t) => unit = "update";
    [@bs.send] external updateDataView: (Stream.t([> kind ]), Js.TypedArray2.DataView.t) => unit = "update";
  };
  include Impl;
};

[@bs.module "crypto"] external createHmac: (string, ~key: string) => Hmac.t = "createHmac";

module Certificate = {

  type t;

  [@bs.send] external exportChallenge: (
      t,
      BinaryLike.t([<
        | BinaryLike.string_
        | BinaryLike.buffer
        | BinaryLike.typedArray
        | BinaryLike.dataView
      ])
    ) => Buffer.t = "exportChallenge";

  [@bs.send] external exportPublicKey: (
      t,
      BinaryLike.t([<
        | BinaryLike.string_
        | BinaryLike.buffer
        | BinaryLike.typedArray
        | BinaryLike.dataView
      ]),
      ~encoding: [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]=?
    ) => Buffer.t = "exportPublicKey";

  [@bs.send] external verifyCertificate: (
      t,
      BinaryLike.t([<
        | BinaryLike.buffer
        | BinaryLike.typedArray
        | BinaryLike.dataView
      ])
    ) => bool = "verifyCertificate"

};

module Cipher = {

  type kind = [ Stream.transform | `Cipher ];
  type t = Stream.t([ kind ]);

  module Impl = {
    include Stream.Transform.Impl;
    [@bs.send] external final: (Stream.t([> kind ]), string) => Buffer.t = "final";
    [@bs.send] external finalWithEncoding: (
        string,
        [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => string = "final";

    [@bs.send] external setAAD: (
        Stream.t([> kind ]),
        BinaryLike.t([<
          | BinaryLike.buffer
          | BinaryLike.typedArray
          | BinaryLike.dataView
        ])
      ) => t = "setAAD";

    [@bs.send] external setAADWith: (
        Stream.t([> kind ]),
        BinaryLike.t([<
          | BinaryLike.buffer
          | BinaryLike.typedArray
          | BinaryLike.dataView
        ]),
        ~options: Stream.Transform.makeOptions
      ) => t = "setAAD";

    [@bs.send] external getAuthTag: Stream.t([> kind ]) => Buffer.t = "getAuthTag";

    [@bs.send] external setAutoPadding: (Stream.t([> kind ]), bool) => t = "setAutoPadding";

    [@bs.send] external updateBinaryLikeToString: (
        Stream.t([> kind ]),
        BinaryLike.t([<
          | BinaryLike.buffer
          | BinaryLike.typedArray
          | BinaryLike.dataView
        ]),
        ~outputEncoding: [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => string = "update";

    [@bs.send] external updateBinaryLikeToBuffer: (
        Stream.t([> kind ]),
        BinaryLike.t([<
          | BinaryLike.buffer
          | BinaryLike.typedArray
          | BinaryLike.dataView
        ])
      ) => Buffer.t = "update";

    [@bs.send] external updateStringToString: (
        Stream.t([> kind ]),
        string,
        ~inputEncoding: [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ],
        ~outputEncoding: [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => string = "update";

    [@bs.send] external updateStringToBuffer: (
      Stream.t([> kind ]),
      string,
        ~inputEncoding: [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => Buffer.t = "update";

  };

  include Impl;

  [@bs.module "crypto"] external make: (
      ~algorithm: string,
      ~key: KeyObject.t('a, [> KeyObject.secretKey ]),
      ~iv: Js.Null.t(BinaryLike.t([<
        | BinaryLike.string_
        | BinaryLike.buffer
        | BinaryLike.typedArray
        | BinaryLike.dataView
      ]))
    ) => t = "createCipheriv";

  [@bs.module "crypto"] external makeWith: (
      ~algorithm: string,
      ~key: KeyObject.t('a, [> KeyObject.secretKey ]),
      ~iv: Js.Null.t(BinaryLike.t([<
        | BinaryLike.string_
        | BinaryLike.buffer
        | BinaryLike.typedArray
        | BinaryLike.dataView
      ])),
      ~options: Stream.Transform.makeOptions=?
    ) => t = "createCipheriv";

};

module Decipher = {

  type kind = [ Stream.transform | `Decipher ];
  type t = Stream.t([ kind ]);

  module Impl = {

    [@bs.send] external final: (Stream.t([> kind ]), string) => Buffer.t = "final";

    [@bs.send] external finalWithEncoding: (
        string,
        [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => string = "final";

    [@bs.send] external setAAD: (
        Stream.t([> kind ]),
        BinaryLike.t([<
          | BinaryLike.buffer
          | BinaryLike.typedArray
          | BinaryLike.dataView
        ])
      ) => t = "setAAD";

    [@bs.send] external setAADWith: (
        Stream.t([> kind ]),
        BinaryLike.t([<
          | BinaryLike.buffer
          | BinaryLike.typedArray
          | BinaryLike.dataView
        ]),
        ~options: Stream.Transform.makeOptions
      ) => t = "setAAD";

    [@bs.send] external setAuthTag: (
        Stream.t([> kind ]),
        BinaryLike.t([<
          | BinaryLike.buffer
          | BinaryLike.typedArray
          | BinaryLike.dataView
        ])
      ) => t = "setAuthTag";
    
    [@bs.send] external setAutoPatting: (Stream.t([> kind ]), bool) => t = "setAutoPadding";

    [@bs.send] external updateBinaryLikeToString: (
        Stream.t([> kind ]),
        BinaryLike.t([<
          | BinaryLike.buffer
          | BinaryLike.typedArray
          | BinaryLike.dataView
        ]),
        ~outputEncoding: [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => string = "update";

    [@bs.send] external updateBinaryLikeToBuffer: (
        Stream.t([> kind ]),
        BinaryLike.t([<
          | BinaryLike.buffer
          | BinaryLike.typedArray
          | BinaryLike.dataView
        ])
      ) => Buffer.t = "update";

    [@bs.send] external updateStringToString: (
        Stream.t([> kind ]),
        string,
        ~inputEncoding: [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ],
        ~outputEncoding: [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => string = "update";

    [@bs.send] external updateStringToBuffer: (
      Stream.t([> kind ]),
      string,
        ~inputEncoding: [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => Buffer.t = "update";

  };

  include Impl;

  [@bs.module "crypto"] external make: (
      ~algorithm: string,
      ~key: KeyObject.t('a, [> KeyObject.secretKey ]),
      ~iv: Js.Null.t(BinaryLike.t([<
        | BinaryLike.string_
        | BinaryLike.buffer
        | BinaryLike.typedArray
        | BinaryLike.dataView
      ]))
    ) => t = "createDecipheriv";

  [@bs.module "crypto"] external makeWith: (
      ~algorithm: string,
      ~key: KeyObject.t('a, [> KeyObject.secretKey ]),
      ~iv: Js.Null.t(BinaryLike.t([<
        | BinaryLike.string_
        | BinaryLike.buffer
        | BinaryLike.typedArray
        | BinaryLike.dataView
      ])),
      ~options: Stream.Transform.makeOptions=?
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
