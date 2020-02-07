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

[@bs.module "crypto"] external createHash: string => Hash.t = "createHash";

[@bs.module "crypto"] external createHmac: (string, ~key: string) => Hmac.t = "createHmac";