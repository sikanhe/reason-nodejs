type t;

[@bs.send]
external onData: (t, [@bs.as "data"] _, Buffer.t => unit) => unit = "on";
[@bs.send]
external onDisconnect: (t, [@bs.as "disconnect"] _, unit => unit) => unit =
  "on";
[@bs.send]
external onError: (t, [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
[@bs.send]
external onExit: (t, [@bs.as "exit"] _, int => unit) => unit = "on";
[@bs.send]
external onClose: (t, [@bs.as "close"] _, int => unit) => unit = "on";

[@bs.get] external connected: t => bool = "connected";
[@bs.send] external disconnect: t => bool = "disconnect";
[@bs.send] external kill: (t, string) => unit = "kill";
[@bs.get] external killed: t => bool = "killed";
[@bs.get] external pid: t => int = "pid";
[@bs.get] external ref: t => unit = "ref";
[@bs.get] [@bs.return nullable]
external stderr: t => option(Net.Socket.t) = "stderr";
[@bs.get] [@bs.return nullable]
external stdin: t => option(Net.Socket.t) = "stdin";
[@bs.get] [@bs.return nullable]
external stdout: t => option(Net.Socket.t) = "stdout";
[@bs.get] external unref: t => unit = "unref";

type execOptions;

[@bs.obj]
external execOptions:
  (
    ~cwd: string=?,
    ~env: Js.Dict.t(string)=?,
    ~encoding: string=?,
    ~shell: string=?,
    ~timeout: int=?,
    ~maxBuffer: int=?,
    ~killSignal: string=?,
    ~uid: int=?,
    ~gid: int=?,
    ~windowsHide: bool=?,
    unit
  ) =>
  execOptions =
  "";

[@bs.module "child_process"] [@bs.val]
external exec: (string, (option(Js.Exn.t), string, string) => unit) => t =
  "exec";

[@bs.module "child_process"] [@bs.val]
external execWith:
  (string, execOptions, (option(Js.Exn.t), string, string) => unit) => t =
  "exec";

type execFileOptions;

[@bs.obj]
external execFileOption:
  (
    ~cwd: string=?,
    ~env: Js.Dict.t(string)=?,
    ~encoding: string=?,
    ~timeout: int=?,
    ~maxBuffer: int=?,
    ~killSignal: string=?,
    ~uid: int=?,
    ~gid: int=?,
    ~windowsHide: bool=?,
    ~shell: string=?,
    unit
  ) =>
  execFileOptions =
  "";

[@bs.module "child_process"] [@bs.val]
external execFile:
  (string, array(string), (option(Js.Exn.t), string, string) => unit) => t =
  "execFile";

[@bs.module "child_process"] [@bs.val]
external execFileWith:
  (
    string,
    array(string),
    execFileOptions,
    (option(Js.Exn.t), string, string) => unit
  ) =>
  t =
  "execFile";

type forkOptions;

[@bs.obj]
external forkOptions:
  (
    ~cwd: string=?,
    ~detached: bool=?,
    ~env: Js.Dict.t(string)=?,
    ~execPath: string=?,
    ~execArgv: array(string)=?,
    ~silent: bool=?,
    ~stdio: string=?,
    ~uid: int=?,
    ~gid: int=?,
    ~windowsVerbatimArguments: bool=?,
    unit
  ) =>
  forkOptions =
  "";

[@bs.module "child_process"] [@bs.val]
external fork: (string, array(string)) => t = "fork";

[@bs.module "child_process"] [@bs.val]
external forkWith: (string, array(string), forkOptions) => t = "fork";

type spawnOptions;

[@bs.obj]
external spawnOptions:
  (
    ~cwd: string=?,
    ~env: Js.Dict.t(string)=?,
    ~argv0: string=?,
    ~stdio: string=?,
    ~detached: bool=?,
    ~uid: int=?,
    ~gid: int=?,
    ~shell: string=?,
    ~windowsVerbatimArguments: bool=?,
    ~windowsHide: bool=?,
    unit
  ) =>
  spawnOptions =
  "";

[@bs.module "child_process"] [@bs.val]
external spawn: (string, array(string)) => t = "spawn";

[@bs.module "child_process"] [@bs.val]
external spawnWith: (string, array(string), spawnOptions) => t = "spawn";

type spawnSyncResult('a) = {
  pid: int,
  output: array('a),
  stdout: string,
  stderr: string,
  status: int,
  signal: Js.Nullable.t(string),
  error: option(Js.Exn.t),
};

type spawnSyncOptions;

[@bs.obj]
external spawnSyncOptions:
  (
    ~cwd: string=?,
    ~env: Js.Dict.t(string)=?,
    ~input: BinaryLike.t(BinaryLike.any)=?,
    ~argv0: string=?,
    ~stdio: string=?,
    ~detached: bool=?,
    ~uid: int=?,
    ~gid: int=?,
    ~shell: string=?,
    ~windowsVerbatimArguments: bool=?,
    ~windowsHide: bool=?,
    unit
  ) =>
  spawnSyncOptions =
  "";

[@bs.module "child_process"] [@bs.val]
external spawnSync:
  (string, array(string), spawnSyncOptions) => spawnSyncResult('a) =
  "spawnSync";

[@bs.module "child_process"] [@bs.val]
external spawnSyncWith:
  (string, array(string), spawnSyncOptions) => spawnSyncResult('a) =
  "spawnSync";

type execSyncOptions;

[@bs.obj]
external execSyncOptions:
  (
    ~cwd: string=?,
    ~env: Js.Dict.t(string)=?,
    ~input: BinaryLike.t(BinaryLike.any)=?,
    ~encoding: string=?,
    ~shell: string=?,
    ~timeout: int=?,
    ~maxBuffer: int=?,
    ~killSignal: string=?,
    ~uid: int=?,
    ~gid: int=?,
    ~windowsHide: bool=?,
    unit
  ) =>
  execSyncOptions =
  "";

[@bs.module "child_process"] [@bs.val]
external execSync: string => string = "execSync";

[@bs.module "child_process"] [@bs.val]
external execSyncWith: (string, execSyncOptions) => string = "execSync";

type execFileSyncOptions;

[@bs.obj]
external execFileSyncOptions:
  (
    ~cwd: string=?,
    ~env: Js.Dict.t(string)=?,
    ~input: BinaryLike.t(BinaryLike.any)=?,
    ~encoding: string=?,
    ~shell: string=?,
    ~timeout: int=?,
    ~maxBuffer: int=?,
    ~killSignal: string=?,
    ~uid: int=?,
    ~gid: int=?,
    ~windowsHide: bool=?,
    unit
  ) =>
  execFileSyncOptions =
  "";

[@bs.module "child_process"] [@bs.val]
external execFileSync: (string, array(string)) => string = "execFileSync";

[@bs.module "child_process"] [@bs.val]
external execFileSyncWith:
  (string, array(string), execFileSyncOptions) => string =
  "execFileSync";
