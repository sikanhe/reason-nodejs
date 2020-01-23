type t;

[@bs.send]
external onData: (t, [@bs.as "data"] _, Buffer.t => unit) => unit = "on";
[@bs.send]
external onDisconnect: (t, [@bs.as "disconnect"] _, unit => unit) => unit =
  "on";
[@bs.send]
external onError: (t, [@bs.as "close"] _, Js.Exn.t => unit) => unit = "on";
[@bs.send]
external onExit: (t, [@bs.as "close"] _, int => unit) => unit = "on";
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
  _ =
  "";

[@bs.module "child_process"] [@bs.val]
external exec: (string, (option(Js.Exn.t), string, string) => unit) => t =
  "exec";

[@bs.module "child_process"] [@bs.val]
external execWith:
  (
    string,
    {
      .
      "cwd": Js.undefined(string),
      "env": Js.undefined(Js.Dict.t(string)),
      "encoding": Js.undefined(string),
      "shell": Js.undefined(string),
      "timeout": Js.undefined(int),
      "maxBuffer": Js.undefined(int),
      "killSignal": Js.undefined(string),
      "uid": Js.undefined(int),
      "gid": Js.undefined(int),
      "windowsHide": Js.undefined(bool),
    },
    (option(Js.Exn.t), string, string) => unit
  ) =>
  t =
  "exec";

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
  _ =
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
    {
      .
      "cwd": Js.undefined(string),
      "env": Js.undefined(Js.Dict.t(string)),
      "encoding": Js.undefined(string),
      "timeout": Js.undefined(int),
      "maxBuffer": Js.undefined(int),
      "killSignal": Js.undefined(string),
      "uid": Js.undefined(int),
      "gid": Js.undefined(int),
      "windowsHide": Js.undefined(bool),
      "shell": Js.undefined(string),
    },
    (option(Js.Exn.t), string, string) => unit
  ) =>
  t =
  "execFile";

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
  _ =
  "";

[@bs.module "child_process"] [@bs.val]
external fork: (string, array(string)) => t = "fork";

[@bs.module "child_process"] [@bs.val]
external forkWith:
  (
    string,
    array(string),
    {
      .
      "cwd": Js.undefined(string),
      "detached": Js.undefined(bool),
      "env": Js.undefined(Js.Dict.t(string)),
      "execPath": Js.undefined(string),
      "execArgv": Js.undefined(array(string)),
      "silent": Js.undefined(bool),
      "stdio": Js.undefined(string),
      "uid": Js.undefined(int),
      "gid": Js.undefined(int),
      "windowsVerbatimArguments": Js.undefined(bool),
    }
  ) =>
  t =
  "fork";

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
  _ =
  "";

[@bs.module "child_process"] [@bs.val]
external spawn: (string, array(string)) => t = "spawn";

[@bs.module "child_process"] [@bs.val]
external spawnWith:
  (
    string,
    array(string),
    {
      .
      "cwd": Js.undefined(string),
      "env": Js.undefined(Js.Dict.t(string)),
      "argv0": Js.undefined(string),
      "stdio": Js.undefined(string),
      "detached": Js.undefined(bool),
      "uid": Js.undefined(int),
      "gid": Js.undefined(int),
      "shell": Js.undefined(string),
      "windowsVerbatimArguments": Js.undefined(bool),
      "windowsHide": Js.undefined(bool),
    }
  ) =>
  t =
  "spawn";

type spawnSyncResult('a) = {
  pid: int,
  output: array('a),
  stdout: string,
  stderr: string,
  status: int,
  signal: Js.Nullable.t(string),
  error: option(Js.Exn.t),
};

[@bs.module "child_process"] [@bs.val]
external spawnSync:
  (
    string,
    array(string),
    {
      .
      "cwd": Js.undefined(string),
      "env": Js.undefined(Js.Dict.t(string)),
      "input": Js.undefined(BinaryLike.t),
      "argv0": Js.undefined(string),
      "stdio": Js.undefined(string),
      "detached": Js.undefined(bool),
      "uid": Js.undefined(int),
      "gid": Js.undefined(int),
      "shell": Js.undefined(string),
      "windowsVerbatimArguments": Js.undefined(bool),
      "windowsHide": Js.undefined(bool),
    }
  ) =>
  spawnSyncResult('a) =
  "spawnSync";

[@bs.obj]
external execSyncOptions:
  (
    ~cwd: string=?,
    ~env: Js.Dict.t(string)=?,
    ~input: BinaryLike.t=?,
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
  _ =
  "";

[@bs.module "child_process"] [@bs.val]
external execSync: string => string = "execSync";

[@bs.module "child_process"] [@bs.val]
external execSyncWith:
  (
    string,
    {
      .
      "cwd": Js.undefined(string),
      "env": Js.undefined(Js.Dict.t(string)),
      "input": Js.undefined(BinaryLike.t),
      "encoding": Js.undefined(string),
      "shell": Js.undefined(string),
      "timeout": Js.undefined(int),
      "maxBuffer": Js.undefined(int),
      "killSignal": Js.undefined(string),
      "uid": Js.undefined(int),
      "gid": Js.undefined(int),
      "windowsHide": Js.undefined(bool),
    }
  ) =>
  string =
  "execSync";

[@bs.obj]
external execFileSyncOptions:
  (
    ~cwd: string=?,
    ~env: Js.Dict.t(string)=?,
    ~input: BinaryLike.t=?,
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
  _ =
  "";

[@bs.module "child_process"] [@bs.val]
external execFileSync: (string, array(string)) => string = "execFileSync";

[@bs.module "child_process"] [@bs.val]
external execFileSyncWith:
  (
    string,
    array(string),
    {
      .
      "cwd": Js.undefined(string),
      "input": Js.undefined(BinaryLike.t),
      "env": Js.undefined(Js.Dict.t(string)),
      "encoding": Js.undefined(string),
      "timeout": Js.undefined(int),
      "maxBuffer": Js.undefined(int),
      "killSignal": Js.undefined(string),
      "uid": Js.undefined(int),
      "gid": Js.undefined(int),
      "windowsHide": Js.undefined(bool),
      "shell": Js.undefined(string),
    }
  ) =>
  string =
  "execFileSync";