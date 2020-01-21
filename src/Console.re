type t;

[@bs.new]
external make:
  {
    .
    "stdout": Stream.t(Stream.writable),
    "stderr": option(Stream.t(Stream.writable)),
    "ignoreErrors": option(bool),
    "colorMode": option(bool),
    "inspectOptions": option(Util.inspectOptions),
  } =>
  t =
  "Console";

[@bs.val] external console: t = "console";

[@bs.send] external assert_: (t, bool) => unit = "assert";
[@bs.send] external assertWithMessage: (t, bool, string) => unit = "assert";

[@bs.send] external clear: (t, unit) => unit = "clear";

[@bs.send] external count: (t, string) => unit = "count";
[@bs.send] external countReset: (t, string) => unit = "countReset";

[@bs.send] external debug: (t, string) => unit = "debug";
[@bs.send] [@bs.variadic] external debugMany: (t, array(string)) => unit = "debug";

[@bs.send] external dir: (t, string) => unit = "dir";
[@bs.send] [@bs.variadic] external dirMany: (t, array(string)) => unit = "dir";

[@bs.send] external dirxml: (t, string) => unit = "dirxml";
[@bs.send] [@bs.variadic] external dirxmlMany: (t, array(string)) => unit = "dirxml";

[@bs.send] external error: (t, string) => unit = "error";
[@bs.send] [@bs.variadic] external errorMany: (t, array(string)) => unit = "error";

[@bs.send] external group: (t, string) => unit = "group";
[@bs.send] [@bs.variadic] external groupMany: (t, array(string)) => unit = "group";

[@bs.send] external groupEnd: (t, unit) => unit = "groupEnd";

[@bs.send] external info: (t, string) => unit = "info";
[@bs.send] [@bs.variadic] external infoMany: (t, array(string)) => unit = "info";

[@bs.send] external log: (t, string) => unit = "log";
[@bs.send] [@bs.variadic] external logMany: (t, array(string)) => unit = "log";

[@bs.send] external table: (t, array(string)) => unit = "table";

[@bs.send] external time: (t, string) => unit = "time";

//TODO: research more into this function. Not sure how it works.
[@bs.send] [@bs.variadic] external timeLog: (t, string, array(string)) => unit = "timeLog";

//////////////////////////////////



module Make = (M: {
  let stdout: Stream.t(Stream.writable);
  let stderr: option(Stream.t(Stream.writable));
  let ignoreErrors: option(bool);
  let colorMode: option(bool);
  let inspectOptions: option(Util.inspectOptions);
}) => {
  let console = make({
      "stdout": M.stdout,
      "stderr": M.stderr,
      "ignoreErrors": M.ignoreErrors,
      "colorMode": M.colorMode,
      "inspectOptions": M.inspectOptions,
    });
  
  let assert_ = assert_(console);
  let assertWithMessage = assertWithMessage(console);
  let clear = clear(console);
  let count = count(console);
  let countReset = countReset(console);
  let debug = debug(console);
  let debugMany = debugMany(console);
  let dir = dir(console);
  let dirMany = dirMany(console);
  let dirxml = dirxml(console);
  let dirxmlMany = dirxmlMany(console);
  let error = error(console);
  let errorMany = errorMany(console);
  let group = group(console);
  let groupMany = groupMany(console);
  let groupEnd = groupEnd(console);
  let info = info(console);
  let infoMany = infoMany(console);
  let log = log(console);
  let logMany = logMany(console);
  let table = table(console);
  let time = time(console);
  let timeLog = timeLog(console);
};

/////////////////////////////////////////

let make = (~stderr=?, ~ignoreErrors=?, ~colorMode=?, ~inspectOptions=?, ~stdout) =>
  make({
    "stdout": stdout,
    "stderr": stderr,
    "ignoreErrors": ignoreErrors,
    "inspectOptions": inspectOptions,
    "colorMode": colorMode,
  });


let assert_ = assert_(console);
let assertWithMessage = assertWithMessage(console);

let clear = clear(console);

let count = count(console);
let countReset = countReset(console);

let debug = debug(console);
let debugMany = debugMany(console);

let dir = dir(console);
let dirMany = dirMany(console);

let dirXml = dirxml(console);
let dirXmlMany = dirxmlMany(console);

let error = error(console);
let errorMany = errorMany(console);

let group = group(console);
let groupMany = groupMany(console);

let groupEnd = groupEnd(console);

let info = info(console);
let infoMany = infoMany(console);

let log = log(console);
let logMany = logMany(console);

let table = table(console);
[@bs.val] [@bs.scope "console"] external tableJsObject: Js.t('a) => unit = "table";

let time = time(console);
let timeLog = timeLog(console);
