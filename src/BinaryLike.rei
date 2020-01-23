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

let string: string => t;
let buffer: Buffer.t => t;
let int8Array: Int8Array.t => t;
let uInt8Array: Uint8Array.t => t;
let uInt8ClampedArray: Uint8ClampedArray.t => t;
let uInt16Array: Uint16Array.t => t;
let int16Array: Int16Array.t => t;
let uInt32Array: Uint32Array.t => t;
let int32Array: Int32Array.t => t;
let float32Array: Float32Array.t => t;
let float64Array: Float64Array.t => t;
let dataView: DataView.t => t;