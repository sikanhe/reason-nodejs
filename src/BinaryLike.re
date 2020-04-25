/**
 * Currently, this module is not used in the libary. It solved a
 * problem that we have since decided to solve in other ways. It may
 * come in handy as a useful abstraction, so we will leave it in for now.
 * However users are expected to not rely on it.
 *
 * The purpose of this module is for unifying most of the binary-like
 * data types that are commonly used for streaming, IO, data serialization,
 * compression, etc. it also facilitates type-safe conversions between
 * unified and normal types Since many of Node's functions are
 * polymorphic, this might help with binding to those functions.
 *
 * However, we prefer to just assume everything uses the `Buffer` type,
 * for the most part. And this is typically enforced by the API design.
 */
open Js.TypedArray2;

type t('a);

type string_ = [ | `string];
type buffer = [ | `buffer];
type int8Array = [ | `int8Array];
type uInt8Array = [ | `uInt8Array];
type uInt8ClampedArray = [ | `uInt8ClampedArray];
type int16Array = [ | `int16Array];
type uInt16Array = [ | `uInt16Array];
type int32Array = [ | `int32Array];
type uInt32Array = [ | `uInt32Array];
type float32Array = [ | `float32Array];
type float64Array = [ | `float64Array];
type dataView = [ | `dataView];

type typedArray = [
  int8Array
  | uInt8Array
  | uInt8ClampedArray
  | int16Array
  | uInt16Array
  | int32Array
  | uInt32Array
  | float32Array
  | float64Array
];

type all = [
  string_
  | buffer
  | int8Array
  | uInt8Array
  | uInt8ClampedArray
  | int16Array
  | uInt16Array
  | int32Array
  | uInt32Array
  | float32Array
  | float64Array
  | dataView
];

type case(_) =
  | String(string): case([> string_])
  | Buffer(Buffer.t): case([> buffer])
  | Int8Array(Int8Array.t): case([> int8Array])
  | Uint8Array(Uint8Array.t): case([> uInt8Array])
  | Uint8ClampedArray(Uint8ClampedArray.t): case([> uInt8ClampedArray])
  | Uint16Array(Uint16Array.t): case([> uInt16Array])
  | Int16Array(Int16Array.t): case([> int16Array])
  | Uint32Array(Uint32Array.t): case([> uInt32Array])
  | Int32Array(Uint32Array.t): case([> int32Array])
  | Float32Array(Float32Array.t): case([> float32Array])
  | Float64Array(Float64Array.t): case([> float64Array])
  | DataView(DataView.t): case([> int8Array]);

external string: string => t(string_) = "%identity";
external buffer: Buffer.t => t(buffer) = "%identity";
external int8Array: Int8Array.t => t(uInt8Array) = "%identity";
external uInt8Array: Uint8Array.t => t(uInt8Array) = "%identity";
external uInt8ClampedArray: Uint8ClampedArray.t => t(uInt8ClampedArray) =
  "%identity";
external uInt16Array: Uint16Array.t => t(uInt16Array) = "%identity";
external int16Array: Int16Array.t => t(int16Array) = "%identity";
external uInt32Array: Uint32Array.t => t(uInt32Array) = "%identity";
external int32Array: Int32Array.t => t(int32Array) = "%identity";
external float32Array: Float32Array.t => t(float32Array) = "%identity";
external float64Array: Float64Array.t => t(float64Array) = "%identity";
external dataView: DataView.t => t(dataView) = "%identity";

external toString: t(string_) => string = "%identity";
external toBuffer: t(buffer) => Buffer.t = "%identity";
external toInt8Array: t(int8Array) => Int8Array.t = "%identity";
external toUint8Array: t(uInt8Array) => Uint8Array.t = "%identity";
external toUInt8ClampedArray: t(uInt8ClampedArray) => Uint8ClampedArray.t =
  "%identity";
external toUInt16Array: t(uInt16Array) => Uint16Array.t = "%identity";
external toInt16Array: t(int16Array) => Int16Array.t = "%identity";
external toUInt32Array: t(uInt32Array) => Uint32Array.t = "%identity";
external toInt32Array: t(int32Array) => Int32Array.t = "%identity";
external toFloat32Array: t(float32Array) => Float32Array.t = "%identity";
external toFloat64Array: t(float64Array) => Float64Array.t = "%identity";
external toDataView: t(dataView) => DataView.t = "%identity";

let classify: t('a) => case('b) =
  binaryLike =>
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
    } else {
      DataView(Obj.magic(binaryLike));
    };

module Test = {
  external bufferOrString: string => t([ buffer | string_]) = "%identity";

  let y = "test string"->bufferOrString;

  let testClassify =
    switch (classify(y)) {
    | Buffer(value) => Js.log(value)
    | String(value) => Js.log(value)
    | unknown => Js.log(unknown)
    };
};
