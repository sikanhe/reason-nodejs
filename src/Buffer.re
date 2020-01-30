type t = Node.buffer;
open Js.TypedArray2;

module Constants = {
  [@bs.module "buffer"] [@bs.scope "constants"] [@bs.val]
  external max_length: int = "MAX_LENGTH";

  [@bs.module "buffer"] [@bs.scope "constants"] [@bs.val]
  external max_string_length: int = "MAX_STRING_LENGTH";
};

[@bs.val] external isBuffer: 'a => bool = "Buffer.isBuffer";
[@bs.val] external fromString: string => t = "Buffer.from";
[@bs.val]
external fromStringWithEncoding:
  (
    string,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ]
  ) =>
  t =
  "Buffer.from";
[@bs.val] external fromArray: array(int) => t = "Buffer.from";
[@bs.val] external fromArrayBuffer: ArrayBuffer.t => t = "Buffer.from";
[@bs.val]
external fromArrayBufferOffset: (ArrayBuffer.t, ~offset: int) => t =
  "Buffer.from";
[@bs.val]
external fromArrayBufferRange: (ArrayBuffer.t, ~offset: int, ~length: int) => t =
  "Buffer.from";
[@bs.val] external fromBuffer: t => t = "Buffer.from";

[@bs.val] external alloc: int => t = "Buffer.alloc";
[@bs.val] external allocFillInt: (int, ~fill: int) => t = "Buffer.alloc";
[@bs.val] external allocFillString: (int, ~fill: string) => t = "Buffer.alloc";
[@bs.val]
external allocFillStringWithEncoding:
  (
    int,
    ~fill: string,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ]
  ) =>
  t =
  "Buffer.alloc";
[@bs.val] external allocFillBuffer: (int, ~fill: t) => t = "Buffer.alloc";
[@bs.val] external allocUnsafe: int => t = "Buffer.allocUnsafe";
[@bs.val] external allocUnsafeSlow: int => t = "Buffer.allocUnsafeSlow";

[@bs.get_index] external unsafeGet: (t, int) => int = "";
[@bs.set_index] external unsafeSet: (t, int, int) => unit = "";

[@bs.val] external byteLengthString: string => int = "Buffer.byteLength";
[@bs.val]
external byteLengthStringWithEncoding:
  (
    string,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ]
  ) =>
  int =
  "Buffer.byteLength";
[@bs.val] external byteLengthBuffer: t => int = "Buffer.byteLength";
[@bs.val]
external byteLengthInt8Array: Int8Array.t => int = "Buffer.byteLength";
[@bs.val]
external byteLengthUint8Array: Uint8Array.t => int = "Buffer.byteLength";
[@bs.val]
external byteLengthInt16Array: Int16Array.t => int = "Buffer.byteLength";
[@bs.val]
external byteLengthUint16Array: Uint16Array.t => int = "Buffer.byteLength";
[@bs.val]
external byteLengthInt32Array: Int32Array.t => int = "Buffer.byteLength";
[@bs.val]
external byteLengthUint32Array: Uint32Array.t => int = "Buffer.byteLength";
[@bs.val]
external byteLengthFloat32Array: Float32Array.t => int = "Buffer.byteLength";
[@bs.val]
external byteLengthFloat64Array: Float64Array.t => int = "Buffer.byteLength";
[@bs.val] external byteLengthDataView: DataView.t => int = "Buffer.byteLength";
[@bs.val]
external byteLengthArrayBuffer: ArrayBuffer.t => int = "Buffer.byteLength";

[@bs.val] external compare: (t, t) => int = "Buffer.compare";

[@bs.val] external concat: array(t) => t = "Buffer.concat";
[@bs.val]
external concatLength: (array(t), ~length: int) => t = "Buffer.concat";

[@bs.val] external isEncoding: string => bool = "Buffer.isEncoding";

type buffer;
[@bs.val] external buffer: buffer = "Buffer";
[@bs.val] external poolSize: int = "Buffer.poolSize";
[@bs.scope "Buffer"] [@bs.set]
external setPoolSize: (buffer, int) => int = "poolSize";

[@bs.send] external copy: (t, t) => int = "copy";
[@bs.send] external copyOffset: (t, t, ~offset: int) => int = "copy";
[@bs.send]
external copyOffsetFromOffset:
  (t, t, ~targetStart: int, ~sourceStart: int) => int =
  "copy";
[@bs.send]
external copyOffsetFromRange:
  (t, t, ~targetStart: int, ~sourceStart: int, ~sourceEnd: int) => int =
  "copy";
[@bs.send] external copyToUint8Array: (t, Uint8Array.t) => int = "copy";
[@bs.send]
external copyToUint8ArrayOffset: (t, Uint8Array.t, ~targetStart: int) => int =
  "copy";
[@bs.send]
external copyToUint8ArrayFrom:
  (t, Uint8Array.t, ~targetStart: int, ~sourceStart: int) => int =
  "copy";
[@bs.send]
external copyToUint8ArrayFromRange:
  (t, Uint8Array.t, ~targetStart: int, ~sourceStart: int, ~sourceEnd: int) =>
  int =
  "copy";

/* FIXME after iterators support */
/* external entries : t -> Iterator = "" [@@bs.get] */

[@bs.send] external equals: (t, t) => bool = "equals";

[@bs.send] external fillString: (t, string) => t = "fill";
[@bs.send] external fillStringOffset: (t, string, ~offset: int) => t = "fill";
[@bs.send]
external fillStringRange: (t, string, ~offset: int, ~end_: int) => t = "fill";
[@bs.send]
external fillStringRangeWithEncoding:
  (
    t,
    string,
    ~offset: int,
    ~end_: int,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ]
  ) =>
  t =
  "fill";
[@bs.send] external fillBuffer: (t, t) => t = "fill";
[@bs.send] external fillBufferOffset: (t, t, ~offset: int) => t = "fill";
[@bs.send]
external fillBufferRange: (t, t, ~offset: int, ~end_: int) => t = "fill";
[@bs.send] external fillInt: (t, int) => t = "fill";
[@bs.send] external fillIntOffset: (t, int, ~offset: int) => t = "fill";
[@bs.send]
external fillIntRange: (t, int, ~offset: int, ~end_: int) => t = "fill";

[@bs.send] external includesString: (t, string) => bool = "includes";
[@bs.send]
external includesStringFrom: (t, string, ~offset: int) => bool = "includes";
[@bs.send]
external includesStringWithEncodingFrom:
  (
    t,
    string,
    ~offset: int,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ]
  ) =>
  bool =
  "includes";
[@bs.send] external includesBuffer: (t, t) => bool = "includes";
[@bs.send]
external includesBufferFrom: (t, t, ~offset: int) => bool = "includes";
[@bs.send] external includesInt: (t, int) => bool = "includes";
[@bs.send]
external includesIntFrom: (t, int, ~offset: int) => bool = "includes";

[@bs.send] external indexOfString: (t, string) => int = "indexOf";
[@bs.send]
external indexOfStringFrom: (t, string, ~offset: int) => int = "indexOf";
[@bs.send]
external indexOfStringWithEncodingFrom:
  (
    t,
    string,
    ~offset: int,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ]
  ) =>
  int =
  "indexOf";
[@bs.send] external indexOfBuffer: (t, t) => int = "indexOf";
[@bs.send] external indexOfBufferFrom: (t, t, ~offset: int) => int = "indexOf";
[@bs.send] external indexOfInt: (t, int) => int = "indexOf";
[@bs.send] external indexOfIntFrom: (t, int, ~offset: int) => int = "indexOf";

/* FIXME after iterators support */
/* external keys : t -> Iterator = "" [@@bs.send] */

[@bs.send] external lastIndexOfString: (t, string) => int = "lastIndexOf";
[@bs.send]
external lastIndexOfStringFrom: (t, string, ~offset: int) => int =
  "lastIndexOf";
[@bs.send]
external lastIndexOfStringWithEncodingFrom:
  (
    t,
    string,
    ~offset: int,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ]
  ) =>
  int =
  "lastIndexOf";
[@bs.send] external lastIndexOfBuffer: (t, t) => int = "lastIndexOf";
[@bs.send]
external lastIndexOfBufferFrom: (t, t, ~offset: int) => int = "lastIndexOf";
[@bs.send] external lastIndexOfInt: (t, int) => int = "lastIndexOf";
[@bs.send]
external lastIndexOfIntFrom: (t, int, ~offset: int) => int = "lastIndexOf";

[@bs.get] external length: t => int = "length";

[@bs.send] external readDoubleBE: (t, ~offset: int) => float = "readDoubleBE";

[@bs.send] external readDoubleLE: (t, ~offset: int) => float = "readDoubleLE";

[@bs.send] external readFloatBE: (t, ~offset: int) => float = "readFloatBE";

[@bs.send] external readFloatLE: (t, ~offset: int) => float = "readFloatLE";

[@bs.send] external readInt8: (t, ~offset: int) => float = "readInt8";

[@bs.send] external readInt16BE: (t, ~offset: int) => float = "readInt16BE";

[@bs.send] external readInt16LE: (t, ~offset: int) => float = "readInt16LE";

[@bs.send] external readInt32BE: (t, ~offset: int) => float = "readInt32BE";

[@bs.send] external readInt32LE: (t, ~offset: int) => float = "readInt32LE";
[@bs.send] external readIntBE: (t, ~offset: int) => float = "readIntBE";
[@bs.send]
external readIntLE: (t, ~offset: int, ~length: int) => float = "readIntLE";
[@bs.send] external readUint8: (t, ~offset: int) => float = "readUint8";
[@bs.send] external readUint16BE: (t, ~offset: int) => float = "readUint16BE";
[@bs.send] external readUint16LE: (t, ~offset: int) => float = "readUint16LE";
[@bs.send] external readUint32BE: (t, ~offset: int) => float = "readUint32BE";
[@bs.send] external readUint32LE: (t, ~offset: int) => float = "readUint32LE";
[@bs.send]
external readUintBE: (t, ~offset: int, ~length: int) => float = "readUintBE";

[@bs.send]
external readUintLE: (t, ~offset: int, ~length: int) => float = "readUintLE";

[@bs.send] external slice: (t, ~start: int, ~end_: int) => t = "slice";
[@bs.send] external sliceToEnd: (t, ~start: int) => t = "slice";
[@bs.send] external swap16: t => t = "swap16";
[@bs.send] external swap32: t => t = "swap32";
[@bs.send] external swap64: t => t = "swap64";

[@bs.send] external toJSON: t => Js.Json.t = "toJSON";
[@bs.send] external toString: t => string = "toString";
[@bs.send]
external toStringWithEncoding:
  (
    t,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ]
  ) =>
  string =
  "toString";
[@bs.send]
external toStringWithEncodingOffset:
  (
    t,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ],
    ~start: int
  ) =>
  string =
  "toString";
[@bs.send]
external toStringWithEncodingRange:
  (
    t,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ],
    ~start: int,
    ~end_: int
  ) =>
  string =
  "toString";

[@bs.send] external write: (t, string) => int = "write";
[@bs.send] external writeOffset: (t, string, ~offset: int) => int = "write";
[@bs.send]
external writeRange: (t, string, ~offset: int, ~length: int) => int = "write";
[@bs.send]
external writeRangeWithEncoding:
  (
    t,
    string,
    ~offset: int,
    ~length: int,
    [@bs.string] [
      | `ascii
      | `utf8
      | `utf16le
      | `usc2
      | `base64
      | `latin1
      | `binary
      | `hex
    ]
  ) =>
  int =
  "write";

[@bs.send]
external writeDoubleBE: (t, float, ~offset: int) => float = "writeDoubleBE";

[@bs.send]
external writeDoubleLE: (t, float, ~offset: int) => float = "writeDoubleLE";

[@bs.send]
external writeFloatBE: (t, float, ~offset: int) => float = "writeFloatBE";

[@bs.send]
external writeFloatLE: (t, float, ~offset: int) => float = "writeFloatLE";

[@bs.send] external writeInt8: (t, int, ~offset: int) => float = "writeInt8";

[@bs.send]
external writeInt16BE: (t, int, ~offset: int) => float = "writeInt16BE";

[@bs.send]
external writeInt16LE: (t, int, ~offset: int) => float = "writeInt16LE";

[@bs.send]
external writeInt32BE: (t, int, ~offset: int) => float = "writeInt32BE";

[@bs.send]
external writeInt32LE: (t, int, ~offset: int) => float = "writeInt32LE";

[@bs.send]
external writeIntBE: (t, int, ~offset: int, ~length: int) => float =
  "writeIntBE";

[@bs.send]
external writeIntLE: (t, int, ~offset: int, ~length: int) => float =
  "writeIntLE";

[@bs.send] external writeUint8: (t, int, ~offset: int) => float = "writeUint8";

[@bs.send]
external writeUint16BE: (t, int, ~offset: int) => float = "writeUint16BE";

[@bs.send]
external writeUint16LE: (t, int, ~offset: int) => float = "writeUint16LE";

[@bs.send]
external writeUint32BE: (t, int, ~offset: int) => float = "writeUint32BE";

[@bs.send]
external writeUint32LE: (t, int, ~offset: int) => float = "writeUint32LE";

[@bs.send]
external writeUintBE: (t, int, ~offset: int, ~length: int) => float =
  "writeUintBE";

[@bs.send]
external writeUintLE: (t, int, ~offset: int, ~length: int) => float =
  "writeUintLE";

[@bs.get] external _INSPECT_MAX_BYTES: t => int = "INSPECT_MAX_BYTES";
[@bs.get] external kMaxLength: t => int = "kMaxLength";

[@bs.send]
external transcode:
  (
    t,
    ~source: t,
    ~fromEnc: [@bs.string] [
                | `ascii
                | `utf8
                | `utf16le
                | `usc2
                | `base64
                | `latin1
                | `binary
                | `hex
              ],
    ~toEnc: [@bs.string] [
              | `ascii
              | `utf8
              | `utf16le
              | `usc2
              | `base64
              | `latin1
              | `binary
              | `hex
            ]
  ) =>
  t =
  "transcode";