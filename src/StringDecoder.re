type t;
[@bs.new] [@bs.module "string_decoder"]
external make: StringEncoding.t => t = "StringDecoder";
[@bs.send] external end_: t => string = "end";
[@bs.send] external writeEnd: (t, Buffer.t) => string = "end";
[@bs.send] external write: (t, Buffer.t) => string = "write";
