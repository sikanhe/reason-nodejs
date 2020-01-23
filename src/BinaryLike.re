open Js.TypedArray2;

[@unboxed]
type t = 
  | Any('a): t;

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

let string = (a: string) => Any(a);
let buffer = (a: Buffer.t) => Any(a);
let int8Array = (a: Int8Array.t) => Any(a);
let uInt8Array = (a: Uint8Array.t) => Any(a);
let uInt8ClampedArray = (a: Uint8ClampedArray.t) => Any(a);
let uInt16Array = (a: Uint16Array.t) => Any(a);
let int16Array = (a: Int16Array.t) => Any(a);
let uInt32Array = (a: Uint32Array.t) => Any(a);
let int32Array = (a: Int32Array.t) => Any(a);
let float32Array = (a: Float32Array.t) => Any(a);
let float64Array = (a: Float64Array.t) => Any(a);
let dataView = (a: DataView.t) => Any(a);