[@bs.module "process"] [@bs.val]
external onBeforeExit: ([@bs.as "beforeExit"] _, int => unit) => unit = "on";
[@bs.module "process"] [@bs.val]
external onDisconnect: ([@bs.as "disconnect"] _, unit => unit) => unit = "on";
[@bs.module "process"] [@bs.val]
external onExit: ([@bs.as "exit"] _, int => unit) => unit = "on";
[@bs.module "process"] [@bs.val]
external onUncaughtException:
  ([@bs.as "uncaughtException"] _, (Js.Exn.t, string) => unit) => unit =
  "on";
[@bs.module "process"] [@bs.val]
external onUnhandledRejection:
  ([@bs.as "unhandledRejection"] _, (Js.Exn.t, Js.Promise.t('a)) => unit) =>
  unit =
  "on";
type warning = {
  name: string,
  message: string,
  stack: string,
};
[@bs.module "process"] [@bs.val]
external onWarning: ([@bs.as "warning"] _, warning => unit) => unit = "on";
[@bs.module "process"] [@bs.val] external abort: unit => unit = "abort";
[@bs.module "process"] [@bs.val] external argv: array(string) = "argv";
[@bs.module "process"] [@bs.val] external argv0: string = "argv0";
[@bs.module "process"] [@bs.val] external chdir: string => unit = "chdir";
[@bs.module "process"] [@bs.val] external cwd: unit => string = "cwd";
[@bs.module "process"] [@bs.val]
external disconnect: unit => unit = "disconnect";
[@bs.module "process"] [@bs.val] external env: Js.Dict.t(string) = "env";
[@bs.module "process"] [@bs.val]
external execArgv: array(string) => unit = "execArgv";
[@bs.module "process"] [@bs.val]
external execPath: string => unit = "execPath";
[@bs.module "process"] [@bs.val] external exit: unit => unit = "exit";
[@bs.module "process"] [@bs.val] external exitWithCode: int => unit = "exit";
[@bs.module "process"] [@bs.val] external exitCode: int = "exitCode";
[@bs.module "process"] [@bs.val]
external nextTick: (unit => unit) => unit = "nextTick";
[@bs.module "process"] [@bs.val]
external hrtime: unit => (int, int) = "hrtime";
[@bs.module "process"] [@bs.scope "hrtime"] [@bs.val]
external hrtimeBigInt: unit => BigInt.t = "bigint";
[@bs.module "process"] [@bs.val] external stderr: Net.Socket.t = "stderr";
[@bs.module "process"] [@bs.val] external stdin: Net.Socket.t = "stdin";
[@bs.module "process"] [@bs.val] external stdout: Net.Socket.t = "stdout";
[@bs.module "process"] [@bs.val] external pid: int = "pid";
[@bs.module "process"] [@bs.val] external platform: string = "platform";
[@bs.module "process"] [@bs.val] external ppid: int = "ppid";
[@bs.module "process"] [@bs.val] external uptime: float = "uptime";
[@bs.module "process"] [@bs.val] external title: string = "title";
[@bs.module "process"] [@bs.val] external version: string = "version";
[@bs.module "process"] [@bs.val]
external versions: Js.Dict.t(string) = "versions";