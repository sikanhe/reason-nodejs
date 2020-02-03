
[@bs.val] [@bs.scope "Error"] external captureStackTrace: Js.t({..}) => unit = "captureStackTrace";
[@bs.val] [@bs.scope "Error"] external stackTraceLimit: int = "captureStackTrace";
[%%bs.raw {|
  function setStackTraceLimit(n) {
    Error.stackTraceLimit = n;
    return undefined;
  }
|}];
[@bs.val] external setStackTraceLimit: int => Js.Undefined.t('a) = "setStackTraceLimit";
let setStackTraceLimit: int => unit = (n) => setStackTraceLimit(n)->ignore;

module Error = {
  type t;
  type constructor;
  [@bs.val] external constructor: constructor = "Error";
  [@bs.new] external make: string => t = "Error";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let instanceOf = (x) => JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor);
  let isError: 'a => bool = (x) =>
    JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor)
    && JsTypeReflection.constructorName(x) == "Error";
};

module AssertionError = {
  type t;
  type constructor;
  type makeOptions;
  [@bs.obj]
  external makeOptions:
    (
      ~message: string=?,
      ~actual: 'actual=?,
      ~expected: 'expected=?,
      ~operator: string=?,
      ~stackStartFn: ('a => 'b)=?,
      unit
    ) =>
    makeOptions =
    "";
  [@bs.module "assert"] external constructor: constructor = "AssertionError";
  [@bs.module "assert"] [@bs.new] external make: makeOptions => t = "AssertionError";
  [@bs.get] external actual: t => 'a = "actual";
  [@bs.get] external expected: t => 'a = "expected";
  [@bs.get] external generatedMessage: t => bool = "generatedMessage";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external operator: t => string = "operator";
  [@bs.get] external stack: t => string = "stack";
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let instanceOf = (x) => JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor);
  let isAssertionError: 'a => bool = (x) =>
    JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor)
    && JsTypeReflection.constructorName(x) == "AssertionError";
};

module RangeError = {
  type t;
  type constructor;
  [@bs.val] external constructor: constructor = "RangeError";
  [@bs.new] external make: string => t = "RangeError";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let instanceOf = (x) => JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor);
  let isRangeError: 'a => bool = (x) =>
    JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor)
    && JsTypeReflection.constructorName(x) == "RangeError";
};

module ReferenceError = {
  type t;
  type constructor;
  [@bs.val] external constructor: constructor = "ReferenceError";
  [@bs.new] external make: string => t = "ReferenceError";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let instanceOf = (x) => JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor);
  let isReferenceError: 'a => bool = (x) =>
    JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor)
    && JsTypeReflection.constructorName(x) == "ReferenceError";
};

module SyntaxError = {
  type t;
  type constructor;
  [@bs.val] external constructor: constructor = "SyntaxError";
  [@bs.new] external make: string => t = "SyntaxError";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let instanceOf = (x) => JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor);
  let isSyntaxError: 'a => bool = (x) =>
    JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor)
    && JsTypeReflection.constructorName(x) == "SyntaxError";
};

module TypeError = {
  type t;
  type constructor;
  [@bs.val] external constructor: constructor = "TypeError";
  [@bs.new] external make: string => t = "TypeError";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  external toJsExn: t => Js.Exn.t = "%identity";
  // external fromJsExn: Js.Exn.t => t = (jsExn) => { };
  let instanceOf = (x) => JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor);
  let isTypeError: 'a => bool = (x) =>
    JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor)
    && JsTypeReflection.constructorName(x) == "TypeError";
};

// module SystemError = {
//   type t;
//   type constructor;
//   [@bs.val] external constructor: constructor = "SystemError";
//   [@bs.get] external name: t => string = "name";
//   [@bs.get] external address: t => option(string) = "address";
//   [@bs.get] external code: t => string = "code";
//   [@bs.get] external dest: t => option(string) = "dest";
//   [@bs.get] external errno: t => int = "errno";
//   [@bs.get] external info: t => option(Js.t({..})) = "info";
//   [@bs.get] external message: t => string = "message";
//   [@bs.get] external path: t => option(string) = "path";
//   [@bs.get] external port: t => option(int) = "port";
//   [@bs.get] external stack: t => option(string) = "stack";
//   [@bs.get] external syscall: t => string = "syscall";
//   external toJsExn: t => Js.Exn.t = "%identity";
//   external fromJsExn: Js.Exn.t => t = "%identity";
//   let instanceOf = (x) => JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor);
//   let isSystemError: 'a => bool = (x) =>
//     JsTypeReflection.instanceOfClass(~instance=x, ~class_=constructor)
//     && JsTypeReflection.constructorName(x) == "SystemError";
// };

type case =
  | Error(Error.t)
  | AssertionError(AssertionError.t)
  | RangeError(RangeError.t)
  | ReferenceError(ReferenceError.t)
  | SyntaxError(SyntaxError.t)
  | TypeError(TypeError.t)
;

let classifyOpt: 'a => option(case) = (value) =>
  if (AssertionError.isAssertionError(value)) {
    Some(AssertionError(Obj.magic(value)));
  } else if (RangeError.isRangeError(value)) {
    Some(RangeError(Obj.magic(value)));
  } else if (ReferenceError.isReferenceError(value)) {
    Some(ReferenceError(Obj.magic(value)));
  } else if (SyntaxError.isSyntaxError(value)) {
    Some(SyntaxError(Obj.magic(value)));
  } else if (TypeError.isTypeError(value)) {
    Some(TypeError(Obj.magic(value)));
  } else if (Error.isError(value)) {
    Some(Error(Obj.magic(value)));
  } else {
    None;
  };

let classifyExn: 'a => case = (value) =>
  switch (classifyOpt(value)) {
    | None => failwith("Unknown data type");
    | Some(err) => err;
  };

let classify: 'a => Belt.Result.t(case, 'a) = (value) =>
  switch (classifyOpt(value)) {
    | None => Error(value)
    | Some(err) => Ok(err);
  };

module ErrorCodes = { };
