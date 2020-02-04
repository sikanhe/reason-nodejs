
type t;
[@bs.new] [@bs.module "string_decoder"] external make: (
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
  ) => t = "StringDecoder";
[@bs.send] external end_: t => string = "end";
[@bs.send] external writeEnd: (t, BinaryLike.t) => string = "end";
[@bs.send] external write: (t, BinaryLike.t) => string = "end";
