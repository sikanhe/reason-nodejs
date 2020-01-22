module Hash = {
  include Stream.Transform;
  type t = Stream.t([ Stream.transform | `Hash]);

  [@bs.send] external copy: t => t = "copy";

  [@bs.send] external digest: t => Buffer.t = "digest";

  [@bs.send]
  external digestWithEncoding:
    (t, [@bs.string] [ | `latin1 | `hex | `base64]) => string =
    "digest";

  [@bs.send] external update: (t, string) => unit = "update";
  [@bs.send]
  external updateWithEncoding:
    (t, [@bs.string] [ | `utf8 | `ascii | `latin1]) => unit =
    "update";
  [@bs.send] external updateBuffer: (t, Buffer.t) => unit = "update";
  [@bs.send]
  external updateDataView: (t, Js.TypedArray2.DataView.t) => unit = "update";
};

module Hmac = {
  include Stream.Transform;
  type t = Stream.t([ Stream.transform | `Hmac]);

  [@bs.send] external digest: t => Buffer.t = "digest";

  [@bs.send]
  external digestWithEncoding:
    (t, [@bs.string] [ | `latin1 | `hex | `base64]) => string =
    "digest";

  [@bs.send] external update: (t, string) => unit = "update";
  [@bs.send]
  external updateWithEncoding:
    (t, [@bs.string] [ | `utf8 | `ascii | `latin1]) => unit =
    "update";
  [@bs.send] external updateBuffer: (t, Buffer.t) => unit = "update";
  [@bs.send]
  external updateDataView: (t, Js.TypedArray2.DataView.t) => unit = "update";
};

[@bs.module "crypto"] external createHash: string => Hash.t = "createHash";

[@bs.module "crypto"]
external createHmac: (string, ~key: string) => Hmac.t = "createHmac";