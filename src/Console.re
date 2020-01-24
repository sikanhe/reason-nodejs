// We'll only bind to the instance version of console.Console for now: https://nodejs.org/api/console.html
// For global console.log and others, use the existing Js.Console.* provided by BuckleScript out of the box

type t;

[@bs.new][@bs.module "console"]
external make:
  {
    .
    "stdout": Stream.t([> Stream.writable]),
    "stderr": option(Stream.t([> Stream.writable])),
    "ignoreErrors": option(bool),
    "colorMode": option(bool),
    "inspectOptions": option(Util.inspectOptions),
  } =>
  t =
  "Console";

[@bs.new][@bs.module "console"]
external make2:
  {
    ..
    "stdout": Stream.t([> Stream.writable]),
  } =>
  t =
  "Console";

type consoleOptions;
[@bs.obj]
external consoleOptions:
  (
    ~stderr: Stream.t([> Stream.writable])=?,
    ~ignoreErrors: bool=?,
    ~colorMode: bool=?,
    ~inspectOptions: Util.inspectOptions=?,
    ~stdout: Stream.t([> Stream.writable]),
  ) =>
  consoleOptions = "";

[@bs.new][@bs.module "console"]
external make3: consoleOptions => t = "Console";

[@bs.send] external assert_: (t, bool) => unit = "assert";
// TODO: reconsider naming
[@bs.send] external assertWithMessage: (t, bool, string) => unit = "assert";
[@bs.send] external clear: (t, unit) => unit = "clear";
[@bs.send] external count: (t, string) => unit = "count";
[@bs.send] external countReset: (t, string) => unit = "countReset";

[@bs.send] external debug: (t, string) => unit = "debug";
[@bs.send] [@bs.variadic] external debugMany: (t, array('a)) => unit = "debug";

[@bs.send] external dir: (t, string) => unit = "dir";
[@bs.send] [@bs.variadic] external dirMany: (t, array('a)) => unit = "dir";

[@bs.send] external dirxml: (t, string) => unit = "dirxml";
[@bs.send] [@bs.variadic] external dirxmlMany: (t, array('a)) => unit = "dirxml";

[@bs.send] external error: (t, string) => unit = "error";
[@bs.send] [@bs.variadic] external errorMany: (t, array('a)) => unit = "error";

[@bs.send] external group: (t, string) => unit = "group";
[@bs.send] [@bs.variadic] external groupMany: (t, array('a)) => unit = "group";

[@bs.send] external groupEnd: (t, unit) => unit = "groupEnd";

[@bs.send] external info: (t, string) => unit = "info";
[@bs.send] [@bs.variadic] external infoMany: (t, array('a)) => unit = "info";

[@bs.send] external log: (t, string) => unit = "log";
[@bs.send] [@bs.variadic] external logMany: (t, array('a)) => unit = "log";

[@bs.send] external table: (t, array('a)) => unit = "table";

[@bs.send] external time: (t, string) => unit = "time";

//TODO: research more into this function. Not sure how it works.
[@bs.send] [@bs.variadic] external timeLog: (t, string, array('a)) => unit = "timeLog";

[@bs.send] external trace: (t, string) => unit = "trace";
[@bs.send] [@bs.variadic] external traceMany: (t, array('a)) => unit = "trace";

[@bs.send] external warn: (t, string) => unit = "warn";
[@bs.send] [@bs.variadic] external warnMany: (t, array('a)) => unit = "warn";
