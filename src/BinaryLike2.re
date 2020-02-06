
open Js.TypedArray2;

type t('a);

type string_ = [ `String ];
type buffer = [ `Buffer ];
type int8Array = [ `Int8Array ];
type uInt8Array = [ `Uint8Array ];
type uInt8ClampedArray = [ `Uint8ClampedArray ];
type int16Array = [ `Int16Array ];
type uInt16Array = [ `Uint16Array ];
type int32Array = [ `Int32Array ];
type uInt32Array = [ `Uint32Array ];
type float32Array = [ `Float32Array ];
type float64Array = [ `Float64Array ];
type dataView = [ `DataView ];

type typedArray = [
  | int8Array
  | uInt8Array
  | uInt8ClampedArray
  | int16Array
  | uInt16Array
  | int32Array
  | uInt32Array
  | float32Array
  | float64Array
];

type any = [
  | string_
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

type tag(_, _) =
  | String: tag([> string_ ], string)
  | Buffer: tag([> buffer ], Buffer.t)
  | Int8Array: tag([> int8Array ], Int8Array.t)
  | Uint8Array: tag([> uInt8Array ], Uint8Array.t)
  | Uint8ClampedArray: tag([> uInt8ClampedArray ], Uint8ClampedArray.t)
  | Uint16Array: tag([> uInt16Array ], Uint16Array.t)
  | Int16Array: tag([> int16Array ], Int16Array.t)
  | Uint32Array: tag([> uInt32Array ], Uint32Array.t)
  | Int32Array: tag([> int32Array ], Int32Array.t)
  | Float32Array: tag([> float32Array ], Float32Array.t)
  | Float64Array: tag([> float64Array ], Float64Array.t)
  | DataView: tag([> int8Array ], DataView.t);

external string: string => t(string_) = "%identity";
external buffer: Buffer.t => t(buffer) = "%identity";
external int8Array: Int8Array.t => t(uInt8Array) = "%identity";
external uInt8Array: Uint8Array.t => t(uInt8Array) = "%identity";
external uInt8ClampedArray: Uint8ClampedArray.t => t(uInt8ClampedArray) = "%identity";
external uInt16Array: Uint16Array.t => t(uInt16Array)= "%identity";
external int16Array: Int16Array.t => t(int16Array)= "%identity";
external uInt32Array: Uint32Array.t => t(uInt32Array) = "%identity";
external int32Array: Int32Array.t => t(int32Array) = "%identity";
external float32Array: Float32Array.t => t(float32Array) = "%identity";
external float64Array: Float64Array.t => t(float64Array) = "%identity";
external dataView: DataView.t => t(dataView) = "%identity";

external toString: t(string_) => string = "%identity";
external toBuffer: t(buffer) => Buffer.t = "%identity";
external toInt8Array: t(int8Array) => Int8Array.t = "%identity";
external toUint8Array: t(uInt8Array) => Uint8Array.t = "%identity";
external toUInt8ClampedArray: t(uInt8ClampedArray) => Uint8ClampedArray.t= "%identity";
external toUInt16Array: t(uInt16Array) => Uint16Array.t = "%identity";
external toInt16Array:  t(int16Array) => Int16Array.t = "%identity";
external toUInt32Array: t(uInt32Array) =>  Uint32Array.t = "%identity";
external toInt32Array: t(int32Array) => Int32Array.t = "%identity";
external toFloat32Array: t(float32Array) => Float32Array.t = "%identity";
external toFloat64Array: t(float64Array) => Float64Array.t = "%identity";
external toDataView: t(dataView) => DataView.t = "%identity";

/**
 * `maybeCoerceTo(tag, binaryLike)`
 * 
 * Uses type reflection to optionally coerce a BinaryLike.t('a)
 * into a desired type. Returns `Some(data)` if the underlying type
 * matches the associated `tag` label. Otherwise returns `None`.
 * 
 * Useful if the datatype could be one of several BinaryLike.t('a)
 * subtypes(e.g. `BinaryLike.t([> buffer | dataView | typedArray ])`).
 * 
 * Usage:
 * 
 * ```ocaml
 * let binaryLikeBuffer = BinaryLike.buffer(Buffer.fromString("some buffer"));
 * 
 * let maybeBuffer = BinaryLike.maybeCoerceTo(Buffer, binaryLikeBuffer);
 * // should be `Some(Buffer.t)`;
 * 
 * let maybeString = BinaryLike.maybeCoerceTo(String, binaryLikeBuffer);
 * // should be `None`;
 * ```
 */
let maybeCoerceTo: type kind data. (tag(kind, data), t(kind)) => (option((data))) = (k, binaryLike) => {
  switch(k) {
    | String => Js.typeof(binaryLike) === "string" ? Some(Obj.magic(binaryLike)) : None;
    | Buffer => Buffer.isBuffer(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | Int8Array => Util.Types.isInt8Array(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | Uint8Array => Util.Types.isUint8Array(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | Uint8ClampedArray => Util.Types.isUint8ClampedArray(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | Int16Array => Util.Types.isInt16Array(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | Uint16Array => Util.Types.isUint16Array(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | Int32Array => Util.Types.isInt32Array(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | Uint32Array => Util.Types.isUint32Array(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | Float32Array => Util.Types.isFloat32Array(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | Float64Array => Util.Types.isFloat64Array(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
    | DataView => Util.Types.isFloat64Array(binaryLike) ? Some(Obj.magic(binaryLike)) : None;
  }
};

module Test = {

  let x = string("hi"); // BinaryLike.t([ | string ]);

  let testOpt = maybeCoerceTo(String, x); // option(string);

  let testString = toString(x); // string;

};


