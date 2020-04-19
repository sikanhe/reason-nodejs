type t;

external string: string => t = "%identity";
external buffer: Buffer.t => t = "%identity";

type case =
  | String(string)
  | Buffer(Buffer.t);

let classifyOpt = value =>
  if (Js.typeof(value) === "string") {
    Some(String(Obj.magic(value)));
  } else if (Buffer.isBuffer(value)) {
    Some(Buffer(Obj.magic(value)));
  } else {
    None;
  };

let classifyExn = value =>
  if (Js.typeof(value) === "string") {
    String(Obj.magic(value));
  } else if (Buffer.isBuffer(value)) {
    Buffer(Obj.magic(value));
  } else {
    failwith("Unknown data type");
  };

let classify = value =>
  if (Js.typeof(value) === "string") {
    Ok(String(Obj.magic(value)));
  } else if (Buffer.isBuffer(value)) {
    Ok(Buffer(Obj.magic(value)));
  } else {
    Error(value);
  };
