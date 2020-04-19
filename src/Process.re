type t;
[@bs.module] external process: t = "process";

type warning = {
  name: string,
  message: string,
  stack: string,
};

module Events = {
  [@bs.send] external onBeforeExit: (t, [@bs.as "beforeExit"] _, (. int) => unit) => t = "on";
  [@bs.send] external onDisconnect: (t, [@bs.as "disconnect"] _, (. unit) => unit) => t = "on";
  [@bs.send] external onExit: (t, [@bs.as "exit"] _, (. int) => unit) => t = "on";
  [@bs.send]
  external onMultipleResolves:
    (t, [@bs.as "multipleResolves"] _, (. string, Js.Promise.t('a), 'a) => unit) => t =
    "on";
  [@bs.send]
  external onRejectionHandled:
    (t, [@bs.as "rejectionHandled"] _, (. Js.Promise.t('a)) => unit) => t =
    "on";
  [@bs.send]
  external onUncaughtException:
    (t, [@bs.as "uncaughtException"] _, (. Js.Exn.t, string) => unit) => t =
    "on";
  [@bs.send]
  external onUnhandledRejection:
    (t, [@bs.as "unhandledRejection"] _, (. Js.Exn.t, Js.Promise.t('a)) => unit) => t =
    "on";
  [@bs.send] external onWarning: (t, [@bs.as "warning"] _, (. warning) => unit) => t = "on";

  [@bs.send] external offBeforeExit: (t, [@bs.as "beforeExit"] _, (. int) => unit) => t = "off";
  [@bs.send] external offDisconnect: (t, [@bs.as "disconnect"] _, (. unit) => unit) => t = "off";
  [@bs.send] external offExit: (t, [@bs.as "exit"] _, (. int) => unit) => t = "off";
  [@bs.send]
  external offMultipleResolves:
    (t, [@bs.as "multipleResolves"] _, (. string, Js.Promise.t('a), 'a) => unit) => t =
    "off";
  [@bs.send]
  external offRejectionHandled:
    (t, [@bs.as "rejectionHandled"] _, (. Js.Promise.t('a)) => unit) => t =
    "off";
  [@bs.send]
  external offUncaughtException:
    (t, [@bs.as "uncaughtException"] _, (. Js.Exn.t, string) => unit) => t =
    "off";
  [@bs.send]
  external offUnhandledRejection:
    (t, [@bs.as "unhandledRejection"] _, (. Js.Exn.t, Js.Promise.t('a)) => unit) => t =
    "off";
  [@bs.send] external offWarning: (t, [@bs.as "warning"] _, (. warning) => unit) => t = "off";

  [@bs.send]
  external onBeforeExitOnce: (t, [@bs.as "beforeExit"] _, (. int) => unit) => t = "once";
  [@bs.send]
  external onDisconnectOnce: (t, [@bs.as "disconnect"] _, (. unit) => unit) => t = "once";
  [@bs.send] external onExitOnce: (t, [@bs.as "exit"] _, (. int) => unit) => unit = "once";
  [@bs.send]
  external onMultipleResolvesOnce:
    (t, [@bs.as "multipleResolves"] _, (. string, Js.Promise.t('a), 'a) => unit) => t =
    "once";
  [@bs.send]
  external onRejectionHandledOnce:
    (t, [@bs.as "rejectionHandled"] _, (. Js.Promise.t('a)) => unit) => t =
    "once";
  [@bs.send]
  external onUncaughtExceptionOnce:
    (t, [@bs.as "uncaughtException"] _, (. Js.Exn.t, string) => unit) => t =
    "once";
  [@bs.send]
  external onUnhandledRejectionOnce:
    (t, [@bs.as "unhandledRejection"] _, (. Js.Exn.t, Js.Promise.t('a)) => unit) => t =
    "once";
  [@bs.send] external onWarningOnce: (t, [@bs.as "warning"] _, (. warning) => unit) => t = "once";

  [@bs.send] external removeAllListeners: t => t = "removeAllListeners";
};
include Events;

[@bs.send] external abort: t => unit = "abort";
[@bs.get] external argv: t => array(string) = "argv";
[@bs.get] external argv0: t => string = "argv0";
[@bs.send] external chdir: (t, string) => unit = "chdir";
[@bs.send] external cwd: t => string = "cwd";
[@bs.send] external disconnect: t => unit = "disconnect";
[@bs.get] external env: t => Js.Dict.t(string) = "env";
[@bs.get] external execArgv: t => array(string) = "execArgv";
[@bs.get] external execPath: t => string = "execPath";
[@bs.send] external exit: (t, unit) => unit = "exit";
[@bs.send] external exitWithCode: (t, int) => unit = "exit";
[@bs.get] external exitCode: t => int = "exitCode";
[@bs.send] external nextTick: (t, unit => unit) => unit = "nextTick";
[@bs.send] external nextTickApply1: (t, 'a => unit, 'a) => unit = "nextTick";
[@bs.send] external nextTickApply2: (t, ('a, 'b) => unit, 'a, 'b) => unit = "nextTick";
[@bs.send] external nextTickApply3: (t, ('a, 'b, 'c) => unit, 'a, 'b, 'c) => unit = "nextTick";
[@bs.send]
external nextTickApply4: (t, ('a, 'b, 'c, 'd) => unit, 'a, 'b, 'c, 'd) => unit = "nextTick";
[@bs.send]
external nextTickApply5: (t, ('a, 'b, 'c, 'd, 'e) => unit, 'a, 'b, 'c, 'd, 'e) => unit =
  "nextTick";
[@bs.send] external hrtime: t => (int, int) = "hrtime";
[@bs.send] [@bs.scope "hrtime"] external hrtimeBigInt: t => BigInt.t = "bigint";
[@bs.get]
external stderr: t => Stream.Writable.subtype(Buffer.t, [< Stream.socket | Stream.writable]) =
  "stderr";
[@bs.get]
external stdin: t => Stream.Readable.subtype(Buffer.t, [< Stream.socket | Stream.readable]) =
  "stdin";
[@bs.get]
external stdout: t => Stream.Writable.subtype(Buffer.t, [< Stream.socket | Stream.writable]) =
  "stdout";
[@bs.get] external pid: t => int = "pid";
[@bs.get] external platform: t => string = "platform";
[@bs.get] external ppid: t => int = "ppid";
[@bs.get] external uptime: t => float = "uptime";
[@bs.get] external title: t => string = "title";
[@bs.get] external version: t => string = "version";
[@bs.get] external versions: t => Js.Dict.t(string) = "versions";
type memoryUsageStats = {
  [@bs.as "rss"]
  rss: int,
  [@bs.as "heapTotal"]
  heapTotal: int,
  [@bs.as "heapUsed"]
  heapUsed: int,
  [@bs.as "external"]
  external_: int,
  [@bs.as "arrayBuffers"]
  arrayBuffers: int,
};
[@bs.send] external memoryUsage: t => memoryUsageStats = "memoryUsage";
