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