module Events = {
  [@bs.module "process"] external onBeforeExit: ([@bs.as "beforeExit"] _, (. int) => unit) => unit = "on";
  [@bs.module "process"] external onDisconnect: ([@bs.as "disconnect"] _, (. unit) => unit) => unit = "on";
  [@bs.module "process"] external onExit: ([@bs.as "exit"] _, (. int) => unit) => unit = "on";
  [@bs.module "process"] external onMultipleResolves: ([@bs.as "multipleResolves"] _, (. string, Js.Promise.t('a), 'a) => unit) => unit = "on";
  [@bs.module "process"] external onRejectionHandled: ([@bs.as "rejectionHandled"] _, (. Js.Promise.t('a)) => unit) => unit = "on";
  [@bs.module "process"] external onUncaughtException: ([@bs.as "uncaughtException"] _, (. Js.Exn.t, string) => unit) => unit = "on";
  [@bs.module "process"] external onUnhandledRejection: ([@bs.as "unhandledRejection"] _, (. Js.Exn.t, Js.Promise.t('a)) => unit) => unit = "on";

  [@bs.module "process"] external offBeforeExit: ([@bs.as "beforeExit"] _, (. int) => unit) => unit = "off";
  [@bs.module "process"] external offDisconnect: ([@bs.as "disconnect"] _, (. unit) => unit) => unit = "off";
  [@bs.module "process"] external offExit: ([@bs.as "exit"] _, (. int) => unit) => unit = "off";
  [@bs.module "process"] external offMultipleResolves: ([@bs.as "multipleResolves"] _, (. string, Js.Promise.t('a), 'a) => unit) => unit = "off";
  [@bs.module "process"] external offRejectionHandled: ([@bs.as "rejectionHandled"] _, (. Js.Promise.t('a)) => unit) => unit = "off";
  [@bs.module "process"] external offUncaughtException: ([@bs.as "uncaughtException"] _, (. Js.Exn.t, string) => unit) => unit = "off";
  [@bs.module "process"] external offUnhandledRejection: ([@bs.as "unhandledRejection"] _, (. Js.Exn.t, Js.Promise.t('a)) => unit) => unit = "off";

  [@bs.module "process"] external onBeforeExitOnce: ([@bs.as "beforeExit"] _, (. int) => unit) => unit = "once";
  [@bs.module "process"] external onDisconnectOnce: ([@bs.as "disconnect"] _, (. unit) => unit) => unit = "once";
  [@bs.module "process"] external onExitOnce: ([@bs.as "exit"] _, (. int) => unit) => unit = "once";
  [@bs.module "process"] external onMultipleResolvesOnce: ([@bs.as "multipleResolves"] _, (. string, Js.Promise.t('a), 'a) => unit) => unit = "once";
  [@bs.module "process"] external onRejectionHandledOnce: ([@bs.as "rejectionHandled"] _, (. Js.Promise.t('a)) => unit) => unit = "once";
  [@bs.module "process"] external onUncaughtExceptionOnce: ([@bs.as "uncaughtException"] _, (. Js.Exn.t, string) => unit) => unit = "once";
  [@bs.module "process"] external onUnhandledRejectionOnce: ([@bs.as "unhandledRejection"] _, (. Js.Exn.t, Js.Promise.t('a)) => unit) => unit = "once";
};
include Events;
type warning = {
  name: string,
  message: string,
  stack: string,
};
[@bs.module "process"] external onWarning: ([@bs.as "warning"] _, warning => unit) => unit = "on";
[@bs.module "process"] external abort: unit => unit = "abort";
[@bs.module "process"] external argv: array(string) = "argv";
[@bs.module "process"] external argv0: string = "argv0";
[@bs.module "process"] external chdir: string => unit = "chdir";
[@bs.module "process"] external cwd: unit => string = "cwd";
[@bs.module "process"] external disconnect: unit => unit = "disconnect";
[@bs.module "process"] external env: Js.Dict.t(string) = "env";
[@bs.module "process"] external execArgv: array(string) => unit = "execArgv";
[@bs.module "process"] external execPath: string => unit = "execPath";
[@bs.module "process"] external exit: unit => unit = "exit";
[@bs.module "process"] external exitWithCode: int => unit = "exit";
[@bs.module "process"] external exitCode: int = "exitCode";
[@bs.module "process"] external nextTick: (unit => unit) => unit = "nextTick";
[@bs.module "process"] external hrtime: unit => (int, int) = "hrtime";
[@bs.module "process"] [@bs.scope "hrtime"] external hrtimeBigInt: unit => BigInt.t = "bigint";
[@bs.module "process"] external stderr: Stream.Writable.subtype(Buffer.t, [< Stream.socket | Stream.writable]) = "stderr";
[@bs.module "process"] external stdin: Stream.Readable.subtype(Buffer.t, [< Stream.socket | Stream.readable]) = "stdin";
[@bs.module "process"] external stdout: Stream.Writable.subtype(Buffer.t, [< Stream.socket | Stream.writable]) = "stdout";
[@bs.module "process"] external pid: int = "pid";
[@bs.module "process"] external platform: string = "platform";
[@bs.module "process"] external ppid: int = "ppid";
[@bs.module "process"] external uptime: float = "uptime";
[@bs.module "process"] external title: string = "title";
[@bs.module "process"] external version: string = "version";
[@bs.module "process"] external versions: Js.Dict.t(string) = "versions";
