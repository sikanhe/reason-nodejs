open Js.TypedArray2;

[@bs.deriving accessors]
type t('a) =
  | String(string): t(string)
  | Buffer(Buffer.t): t(Buffer.t)
  | Int8Array(Int8Array.t): t(Int8Array.t)
  | Uint8Array(Uint8Array.t): t(Uint8Array.t)
  | Uint8ClampedArray(Uint8ClampedArray.t): t(Uint8ClampedArray.t)
  | Uint16Array(Uint16Array.t): t(Uint16Array.t)
  | Int16Array(Int16Array.t): t(Int16Array.t)
  | Uint32Array(Uint32Array.t): t(Uint32Array.t)
  | Int32Array(Int32Array.t): t(Int32Array.t)
  | Float32Array(Float32Array.t): t(Float32Array.t)
  | Float64Array(Float64Array.t): t(Float64Array.t)
  | DataView(DataView.t): t(DataView.t);

let unwrap: type a. t(a) => a =
  fun
  | String(a) => a
  | Buffer(a) => a
  | Int8Array(a) => a
  | Uint8Array(a) => a
  | Uint8ClampedArray(a) => a
  | Uint16Array(a) => a
  | Int16Array(a) => a
  | Uint32Array(a) => a
  | Int32Array(a) => a
  | Float32Array(a) => a
  | Float64Array(a) => a
  | DataView(a) => a;