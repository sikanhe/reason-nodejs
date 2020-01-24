open Js.TypedArray2;

type t;

type case =
  | String(string)
  | Buffer(Buffer.t)
  | Int8Array(Int8Array.t)
  | Uint8Array(Uint8Array.t)
  | Uint8ClampedArray(Uint8ClampedArray.t)
  | Uint16Array(Uint16Array.t)
  | Int16Array(Int16Array.t)
  | Uint32Array(Uint32Array.t)
  | Int32Array(Int32Array.t)
  | Float32Array(Float32Array.t)
  | Float64Array(Float64Array.t)
  | DataView(DataView.t);

external string: string => t = "%identity";
external buffer: Buffer.t => t = "%identity";
external int8Array: Int8Array.t => t = "%identity";
external uInt8Array: Uint8Array.t => t = "%identity";
external uInt8ClampedArray: Uint8ClampedArray.t => t = "%identity";
external uInt16Array: Uint16Array.t => t = "%identity";
external int16Array: Int16Array.t => t = "%identity";
external uInt32Array: Uint32Array.t => t = "%identity";
external int32Array: Int32Array.t => t = "%identity";
external float32Array: Float32Array.t => t = "%identity";
external float64Array: Float64Array.t => t = "%identity";
external dataView: DataView.t => t = "%identity";

[%%bs.raw {|
function reflectJsConstructor(data) {
  let str = Object.prototype.toString.call(data);
  return str.slice(8, str.length - 1);
};
|}];

module Unsafe = {
  [@bs.val] external reflectJsConstructor: t => string = "reflectJsConstructor";
};

let classify_exn: t => case = (binaryLike) => {
  switch (Unsafe.reflectJsConstructor(binaryLike)) {
    | "String" => String(Obj.magic(binaryLike));
    | "ArrayBuffer" => Buffer(Obj.magic(binaryLike));
    | "Int8Array" => Int8Array(Obj.magic(binaryLike));
    | "Uint8Array" => Uint8Array(Obj.magic(binaryLike));
    | "Uint8ClampedArray" => Uint8ClampedArray(Obj.magic(binaryLike));
    | "Int16Array" => Int16Array(Obj.magic(binaryLike));
    | "Uint16Array" => Uint16Array(Obj.magic(binaryLike));
    | "Int32Array" => Int32Array(Obj.magic(binaryLike));
    | "Uint32Array" => Uint32Array(Obj.magic(binaryLike));
    | "Float32Array" => Float32Array(Obj.magic(binaryLike));
    | "Float64Array" => Float64Array(Obj.magic(binaryLike));
    | "DataView" => DataView(Obj.magic(binaryLike));
    | _ => failwith("Unknown Data Type");
  };
};

let classify: t => Belt.Result.t(case, t) = (binaryLike) => {
  switch (Unsafe.reflectJsConstructor(binaryLike)) {
    | "String" => Ok(String(Obj.magic(binaryLike)));
    | "ArrayBuffer" => Ok(Buffer(Obj.magic(binaryLike)));
    | "Int8Array" => Ok(Int8Array(Obj.magic(binaryLike)));
    | "Uint8Array" => Ok(Uint8Array(Obj.magic(binaryLike)));
    | "Uint8ClampedArray" => Ok(Uint8ClampedArray(Obj.magic(binaryLike)));
    | "Int16Array" => Ok(Int16Array(Obj.magic(binaryLike)));
    | "Uint16Array" => Ok(Uint16Array(Obj.magic(binaryLike)));
    | "Int32Array" => Ok(Int32Array(Obj.magic(binaryLike)));
    | "Uint32Array" => Ok(Uint32Array(Obj.magic(binaryLike)));
    | "Float32Array" => Ok(Float32Array(Obj.magic(binaryLike)));
    | "Float64Array" => Ok(Float64Array(Obj.magic(binaryLike)));
    | "DataView" => Ok(DataView(Obj.magic(binaryLike)));
    | _ => Error(binaryLike);
  };
};

