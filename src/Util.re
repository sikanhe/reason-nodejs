[@bs.val] [@bs.module "util"] external deprecate0: (unit => 'result) => (unit => 'result) = "deprecate";
[@bs.val] [@bs.module "util"] external deprecate1: ('a1 => 'result) => ('a1 => 'result) = "deprecate";
[@bs.val] [@bs.module "util"] external deprecate2: (('a1, 'a2) => 'result) => (('a1, 'a2) => 'result) = "deprecate";
[@bs.val] [@bs.module "util"] external deprecate3: (('a1, 'a2, 'a3) => 'result) => (('a1, 'a2, 'a3) => 'result) = "deprecate";
[@bs.val] [@bs.module "util"] external deprecate4: (('a1, 'a2, 'a3, 'a4) => 'result) => (('a1, 'a2, 'a3, 'a4) => 'result) = "deprecate";
[@bs.val] [@bs.module "util"] external deprecate5: (('a1, 'a2, 'a3, 'a4, 'a5) => 'result) => (('a1, 'a2, 'a3, 'a4, 'a5) => 'result) = "deprecate";
[@bs.val] [@bs.module "util"] external deprecate6: (('a1, 'a2, 'a3, 'a4, 'a5, 'a6) => 'result) => (('a1, 'a2, 'a3, 'a4, 'a5, 'a6) => 'result) = "deprecate";
[@bs.val] [@bs.module "util"] external getSystemErrorName: int => string = "getSystemErrorName";

type inspectOptions;
[@bs.obj]
external inspectOptions:
  (
    ~showHidden: bool=?,
    ~depth: int=?,
    ~colors: bool=?,
    ~customInspect: bool=?,
    ~showProxy: bool=?,
    ~maxArrayLength: int=?,
    ~breakLength: int=?,
    ~compact: bool=?,
    ~sorted: bool=?,
    ~getters: bool=?,
    unit
  ) =>
  inspectOptions =
  "";

[@bs.val] [@bs.module "util"] external inspect: 'a => string = "inspect";
[@bs.val] [@bs.module "util"] external inspectWithOptions: ('a, inspectOptions) => string = "inspect";
[@bs.val] [@bs.module "util"] [@bs.scope "inspect"] external customInspectSymbol: Js.Types.symbol = "custom";
[@bs.val] [@bs.module "util"] [@bs.scope "inspect"] external defaultInspectOptions: inspectOptions = "defaultOptions";
[@bs.val] [@bs.module "util"] external isDeepStrictEqual: ('a, 'a) => bool = "isDeepStrictEqual";

[@bs.val] [@bs.module "util"] external promisify0: ((Js.Exn.t) => unit) => (unit => Js.Promise.t(unit)) = "promisify";
[@bs.val] [@bs.module "util"] external promisifyWithResult0: ((Js.Exn.t, 'res) => unit) => (unit => Js.Promise.t('res)) = "promisify";
[@bs.val] [@bs.module "util"] external promisify1: ('a1, (Js.Exn.t, 'a1) => unit) => ('a1 => Js.Promise.t(unit)) = "promisify";
[@bs.val] [@bs.module "util"] external promisifyWithResult1: ('a1, (Js.Exn.t, 'res) => unit) => ('a1 => Js.Promise.t('res)) = "promisify";
[@bs.val] [@bs.module "util"] external promisify2: ('a1, 'a2, (Js.Exn.t) => unit) => (('a1, 'a2) => Js.Promise.t(unit)) = "promisify";
[@bs.val] [@bs.module "util"] external promisifyWithResult2: ('a1, 'a2, (Js.Exn.t, 'res) => unit) => (('a1, 'a2) => Js.Promise.t('res)) = "promisify";
[@bs.val] [@bs.module "util"] external promisify3: ('a1, 'a2, 'a3, (Js.Exn.t) => unit) => (('a1, 'a2, 'a3) => Js.Promise.t(unit)) = "promisify";
[@bs.val] [@bs.module "util"] external promisifyWithResult3: ('a1, 'a2, 'a3, (Js.Exn.t, 'res) => unit) => (('a1, 'a2, 'a3) => Js.Promise.t('res)) = "promisify";
[@bs.val] [@bs.module "util"] external promisify4: ('a1, 'a2, 'a3, 'a4, (Js.Exn.t) => unit) => (('a1, 'a2, 'a3, 'a4) => Js.Promise.t(unit)) = "promisify";
[@bs.val] [@bs.module "util"] external promisifyWithResult4: ('a1, 'a2, 'a3, 'a4, (Js.Exn.t, 'res) => unit) => (('a1, 'a2, 'a3, 'a4) => Js.Promise.t('res)) = "promisify";
[@bs.val] [@bs.module "util"] external promisify5: ('a1, 'a2, 'a3, 'a4, 'a5, (Js.Exn.t) => unit) => (('a1, 'a2, 'a3, 'a4, 'a5) => Js.Promise.t(unit)) = "promisify";
[@bs.val] [@bs.module "util"] external promisifyWithResult5: ('a1, 'a2, 'a3, 'a4, 'a5, (Js.Exn.t, 'res) => unit) => (('a1, 'a2, 'a3, 'a4, 'a5) => Js.Promise.t('res)) = "promisify";

module Types = {
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isAnyArrayBuffer: 'a => bool = "isAnyArrayBuffer";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isArgumentsObject: 'a => bool = "isArgumentsObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isAsyncFunction: 'a => bool = "isAsyncFunction";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isBigInt64Array: 'a => bool = "isBigInt64Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isBigUint64Array: 'a => bool = "isBigUint64Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isBooleanObject: 'a => bool = "isBooleanObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isBoxedPrimitive: 'a => bool = "isBoxedPrimitive";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isDataView: 'a => bool = "isDataView";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isDate: 'a => bool = "isDate";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isExternal: 'a => bool = "isExternal";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isFloat32Array: 'a => bool = "isFloat32Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isFloat64Array: 'a => bool = "isFloat64Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isGeneratorObject: 'a => bool = "isGeneratorObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isInt8Array: 'a => bool = "isInt8Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isInt16Array: 'a => bool = "isInt16Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isInt32Array: 'a => bool = "isInt32Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isMap: 'a => bool = "isMap";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isMapIterator: 'a => bool = "isMapIterator";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isModuleNamespaceObject: 'a => bool = "isModuleNamespaceObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isNumberObject: 'a => bool = "isNumberObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isPromise: 'a => bool = "isPromise";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isProxy: 'a => bool = "isProxy";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isRegExp: 'a => bool = "isRegExp";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isSet: 'a => bool = "isSet";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isSetIterator: 'a => bool = "isSetIterator";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isSharedArrayBuffer: 'a => bool = "isSharedArrayBuffer";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isStringObject: 'a => bool = "isStringObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isSymbolObject: 'a => bool = "isSymbolObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isUint8Array: 'a => bool = "isUint8Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isUint8ClampedArray: 'a => bool = "isUint8ClampedArray";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isUint16Array: 'a => bool = "isUint16Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isUint32Array: 'a => bool = "isUint32Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isWeakMap: 'a => bool = "isWeakMap";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isWeakSet: 'a => bool = "isWeakSet";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"] external isWebAssemblyCompiledModule: 'a => bool = "isWebAssemblyCompiledModule";
};
