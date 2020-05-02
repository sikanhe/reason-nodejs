[@bs.val] [@bs.scope "Error"]
external captureStackTrace: Js.t({..}) => unit = "captureStackTrace";
[@bs.val] [@bs.scope "Error"]
external stackTraceLimit: int = "captureStackTrace";
%bs.raw
{|
  function setStackTraceLimit(n) {
    Error.stackTraceLimit = n;
    return undefined;
  }
|};
[@bs.val]
external setStackTraceLimit: int => Js.Undefined.t('a) = "setStackTraceLimit";
let setStackTraceLimit: int => unit = n => setStackTraceLimit(n)->ignore;

module Error = {
  type t = exn;
  type constructor;
  [@bs.val] external constructor: constructor = "Error";
  [@bs.new] external make: string => t = "Error";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  let instanceOf = x =>
    Internal__JsTypeReflection.instanceOfClass(
      ~instance=x,
      ~class_=constructor,
    );
  let isError: Js.Exn.t => bool =
    x =>
      Internal__JsTypeReflection.constructorName(x) == "Error"
      && Internal__JsTypeReflection.instanceOfClass(
           ~instance=x,
           ~class_=constructor,
         );
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let fromJsExn: Js.Exn.t => option(t) =
    exn => isError(exn) ? Some(fromJsExn(exn)) : None;
};

module AssertionError = {
  type t = exn;
  type constructor;
  type makeOptions;
  [@bs.obj]
  external makeOptions:
    (
      ~message: string=?,
      ~actual: 'actual=?,
      ~expected: 'expected=?,
      ~operator: string=?,
      ~stackStartFn: 'a => 'b=?,
      unit
    ) =>
    makeOptions;
  [@bs.module "assert"] external constructor: constructor = "AssertionError";
  [@bs.module "assert"] [@bs.new]
  external make: makeOptions => t = "AssertionError";
  [@bs.get] external actual: t => 'a = "actual";
  [@bs.get] external expected: t => 'a = "expected";
  [@bs.get] external generatedMessage: t => bool = "generatedMessage";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external operator: t => string = "operator";
  [@bs.get] external stack: t => string = "stack";
  let instanceOf = x =>
    Internal__JsTypeReflection.instanceOfClass(
      ~instance=x,
      ~class_=constructor,
    );
  let isAssertionError: Js.Exn.t => bool =
    x =>
      Internal__JsTypeReflection.constructorName(x) == "AssertionError"
      && Internal__JsTypeReflection.instanceOfClass(
           ~instance=x,
           ~class_=constructor,
         );
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let fromJsExn: Js.Exn.t => option(t) =
    exn => isAssertionError(exn) ? Some(fromJsExn(exn)) : None;
};

module EvalError = {
  type t = exn;
  type constructor;
  [@bs.val] external constructor: constructor = "EvalError";
  [@bs.new] external make: string => t = "EvalError";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external stack: t => string = "stack";
  let instanceOf = x =>
    Internal__JsTypeReflection.instanceOfClass(
      ~instance=x,
      ~class_=constructor,
    );
  let isEvalError: Js.Exn.t => bool =
    x =>
      Internal__JsTypeReflection.constructorName(x) == "EvalError"
      && Internal__JsTypeReflection.instanceOfClass(
           ~instance=x,
           ~class_=constructor,
         );
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let fromJsExn: Js.Exn.t => option(t) =
    exn => isEvalError(exn) ? Some(fromJsExn(exn)) : None;
};

module RangeError = {
  type t = exn;
  type constructor;
  [@bs.val] external constructor: constructor = "RangeError";
  [@bs.new] external make: string => t = "RangeError";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  let instanceOf = x =>
    Internal__JsTypeReflection.instanceOfClass(
      ~instance=x,
      ~class_=constructor,
    );
  let isRangeError: Js.Exn.t => bool =
    x =>
      Internal__JsTypeReflection.constructorName(x) == "RangeError"
      && Internal__JsTypeReflection.instanceOfClass(
           ~instance=x,
           ~class_=constructor,
         );
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let fromJsExn: Js.Exn.t => option(t) =
    exn => isRangeError(exn) ? Some(fromJsExn(exn)) : None;
};

module ReferenceError = {
  type t = exn;
  type constructor;
  [@bs.val] external constructor: constructor = "ReferenceError";
  [@bs.new] external make: string => t = "ReferenceError";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  let instanceOf = x =>
    Internal__JsTypeReflection.instanceOfClass(
      ~instance=x,
      ~class_=constructor,
    );
  let isReferenceError: Js.Exn.t => bool =
    x =>
      Internal__JsTypeReflection.constructorName(x) == "ReferenceError"
      && Internal__JsTypeReflection.instanceOfClass(
           ~instance=x,
           ~class_=constructor,
         );
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let fromJsExn: Js.Exn.t => option(t) =
    exn => isReferenceError(exn) ? Some(fromJsExn(exn)) : None;
};

module SyntaxError = {
  type t = exn;
  type constructor;
  [@bs.val] external constructor: constructor = "SyntaxError";
  [@bs.new] external make: string => t = "SyntaxError";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  let instanceOf = x =>
    Internal__JsTypeReflection.instanceOfClass(
      ~instance=x,
      ~class_=constructor,
    );
  let isSyntaxError: Js.Exn.t => bool =
    x =>
      Internal__JsTypeReflection.constructorName(x) == "SyntaxError"
      && Internal__JsTypeReflection.instanceOfClass(
           ~instance=x,
           ~class_=constructor,
         );
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let fromJsExn: Js.Exn.t => option(t) =
    exn => isSyntaxError(exn) ? Some(fromJsExn(exn)) : None;
};

// It's not clear that SystemError works as expressed in the Node API.
// `SystemError` is an undefined identifier at runtime.

module SystemError = {
  type t = exn;
  [@bs.get] external name: t => string = "name";
  [@bs.get] [@bs.return nullable]
  external address: t => option(string) = "address";
  [@bs.get] external code: t => string = "code";
  [@bs.get] [@bs.return nullable] external dest: t => option(string) = "dest";
  [@bs.get] external errno: t => int = "errno";
  [@bs.get] [@bs.return nullable]
  external info: t => option(Js.t({..})) = "info";
  [@bs.get] external message: t => string = "message";
  [@bs.get] [@bs.return nullable] external path: t => option(string) = "path";
  [@bs.get] [@bs.return nullable] external port: t => option(int) = "port";
  [@bs.get] [@bs.return nullable]
  external stack: t => option(string) = "stack";
  [@bs.get] external syscall: t => string = "syscall";
};

module TypeError = {
  type t = exn;
  type constructor;
  [@bs.val] external constructor: constructor = "TypeError";
  [@bs.new] external make: string => t = "TypeError";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external code: t => string = "code";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external stack: t => string = "stack";
  external toJsExn: t => Js.Exn.t = "%identity";
  let instanceOf = x =>
    Internal__JsTypeReflection.instanceOfClass(
      ~instance=x,
      ~class_=constructor,
    );
  let isTypeError: Js.Exn.t => bool =
    x =>
      Internal__JsTypeReflection.constructorName(x) == "TypeError"
      && Internal__JsTypeReflection.instanceOfClass(
           ~instance=x,
           ~class_=constructor,
         );
  external fromJsExn: Js.Exn.t => t = "%identity";
  let fromJsExn: Js.Exn.t => option(t) =
    exn => isTypeError(exn) ? Some(fromJsExn(exn)) : None;
};

module URIError = {
  type t = exn;
  type constructor;
  [@bs.val] external constructor: constructor = "URIError";
  [@bs.new] external make: string => t = "URIError";
  [@bs.get] external message: t => string = "message";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external stack: t => string = "stack";
  let instanceOf = x =>
    Internal__JsTypeReflection.instanceOfClass(
      ~instance=x,
      ~class_=constructor,
    );
  let isURIError: Js.Exn.t => bool =
    x =>
      Internal__JsTypeReflection.constructorName(x) == "URIError"
      && Internal__JsTypeReflection.instanceOfClass(
           ~instance=x,
           ~class_=constructor,
         );
  external toJsExn: t => Js.Exn.t = "%identity";
  external fromJsExn: Js.Exn.t => t = "%identity";
  let fromJsExn: Js.Exn.t => option(t) =
    exn => isURIError(exn) ? Some(fromJsExn(exn)) : None;
};

type case =
  | Error(Error.t)
  | AssertionError(AssertionError.t)
  | EvalError(EvalError.t)
  | RangeError(RangeError.t)
  | ReferenceError(ReferenceError.t)
  | SyntaxError(SyntaxError.t)
  | TypeError(TypeError.t)
  | URIError(URIError.t);

let classifyOpt: Js.Exn.t => option(case) =
  value =>
    if (AssertionError.isAssertionError(value)) {
      Some(AssertionError(Obj.magic(value)));
    } else if (EvalError.isEvalError(value)) {
      Some(EvalError(Obj.magic(value)));
    } else if (RangeError.isRangeError(value)) {
      Some(RangeError(Obj.magic(value)));
    } else if (ReferenceError.isReferenceError(value)) {
      Some(ReferenceError(Obj.magic(value)));
    } else if (SyntaxError.isSyntaxError(value)) {
      Some(SyntaxError(Obj.magic(value)));
    } else if (TypeError.isTypeError(value)) {
      Some(TypeError(Obj.magic(value)));
    } else if (URIError.isURIError(value)) {
      Some(URIError(Obj.magic(value)));
    } else if (Error.isError(value)) {
      Some(Error(Obj.magic(value)));
    } else {
      None;
    };

let classifyExn: Js.Exn.t => case =
  value =>
    switch (classifyOpt(value)) {
    | None => failwith("Unknown data type")
    | Some(err) => err
    };

let classify: Js.Exn.t => Belt.Result.t(case, 'a) =
  value =>
    switch (classifyOpt(value)) {
    | None => Error(value)
    | Some(err) => Ok(err)
    };

module ErrorCodes = {};
