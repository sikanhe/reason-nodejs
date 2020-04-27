
module Impl: {
  open Js.TypedArray2;

  type t;

  type case =
    | String(string)
    | Buffer(Buffer.t)
    | Uint8Array(Uint8Array.t)
    | Int8Array(Int8Array.t)
    | Uint8ClampedArray(Uint8ClampedArray.t)
    | Uint16Array(Uint16Array.t)
    | Int16Array(Int16Array.t)
    | Uint32Array(Uint32Array.t)
    | Int32Array(Uint32Array.t)
    | Float32Array(Float32Array.t)
    | Float64Array(Float64Array.t)
    | DataView(DataView.t)
    // | Unknown(t);

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
  let classify: t => case;

} = {
  open Js.TypedArray2;

  [@unboxed]
  type t =
    | Any('a): t;

  type case =
    | String(string)
    | Buffer(Buffer.t)
    | Uint8Array(Uint8Array.t)
    | Int8Array(Int8Array.t)
    | Uint8ClampedArray(Uint8ClampedArray.t)
    | Uint16Array(Uint16Array.t)
    | Int16Array(Int16Array.t)
    | Uint32Array(Uint32Array.t)
    | Int32Array(Uint32Array.t)
    | Float32Array(Float32Array.t)
    | Float64Array(Float64Array.t)
    | DataView(DataView.t)
    // | Unknown(t);

  let string: string => t = x => Any(x);
  let buffer: Buffer.t => t = x => Any(x);
  let int8Array: Int8Array.t => t = x => Any(x);
  let uInt8Array: Uint8Array.t => t = x => Any(x);
  let uInt8ClampedArray: Uint8ClampedArray.t => t = x => Any(x);
  let uInt16Array: Uint16Array.t => t = x => Any(x);
  let int16Array: Int16Array.t => t = x => Any(x);
  let uInt32Array: Uint32Array.t => t = x => Any(x);
  let int32Array: Int32Array.t => t = x => Any(x);
  let float32Array: Float32Array.t => t = x => Any(x);
  let float64Array: Float64Array.t => t = x => Any(x);
  let dataView: DataView.t => t = x => Any(x);

  let classify: t => case =
    fun
    | Any(binaryLike) =>
      if (Js.typeof(binaryLike) === "string") {
        String(Obj.magic(binaryLike));
      } else if (Buffer.isBuffer(binaryLike)) {
        Buffer(Obj.magic(binaryLike));
      } else if (Util.Types.isInt8Array(binaryLike)) {
        Int8Array(Obj.magic(binaryLike));
      } else if (Util.Types.isUint8Array(binaryLike)) {
        Uint8Array(Obj.magic(binaryLike));
      } else if (Util.Types.isUint8ClampedArray(binaryLike)) {
        Uint8ClampedArray(Obj.magic(binaryLike));
      } else if (Util.Types.isInt16Array(binaryLike)) {
        Int16Array(Obj.magic(binaryLike));
      } else if (Util.Types.isUint16Array(binaryLike)) {
        Uint16Array(Obj.magic(binaryLike));
      } else if (Util.Types.isInt32Array(binaryLike)) {
        Int32Array(Obj.magic(binaryLike));
      } else if (Util.Types.isUint32Array(binaryLike)) {
        Uint32Array(Obj.magic(binaryLike));
      } else if (Util.Types.isFloat32Array(binaryLike)) {
        Float32Array(Obj.magic(binaryLike));
      } else if (Util.Types.isFloat64Array(binaryLike)) {
        Float64Array(Obj.magic(binaryLike));
      } else if (Util.Types.isDataView(binaryLike)) {
        DataView(Obj.magic(binaryLike));
      } else if (Util.Types.isStringObject(binaryLike)) {
        String(Obj.magic(binaryLike));
      } else {
        raise(Failure("test"));
        // Unknown(Obj.magic(binaryLike));
      };
};

include Impl;
