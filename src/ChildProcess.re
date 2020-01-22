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

[@bs.module "child_process"] [@bs.val]
external exec:
  (
    string,
    {
      .
      "cwd": option(string),
      "env": option(Js.Dict.t(string)),
      "encoding": option(string),
      "shell": option(string),
      "timeout": option(float),
      "maxBuffer": option(int),
      "killSignal": option(string),
      "uid": option(float),
      "gid": option(float),
      "windowsHide": option(bool),
    },
    (option(Js.Exn.t), string, string) => unit
  ) =>
  t =
  "exec";

let exec =
    (
      command,
      ~cwd=?,
      ~env=?,
      ~encoding=?,
      ~shell=?,
      ~timeout=?,
      ~maxBuffer=?,
      ~killSignal=?,
      ~uid=?,
      ~gid=?,
      ~windowsHide=?,
      callback,
    ) => {
  exec(
    command,
    {
      "cwd": cwd,
      "env": env,
      "encoding": encoding,
      "shell": shell,
      "timeout": timeout,
      "maxBuffer": maxBuffer,
      "killSignal": killSignal,
      "uid": uid,
      "gid": gid,
      "windowsHide": windowsHide,
    },
    (error, stdout, stderr) => {
    switch (error) {
    | Some(err) => callback(Error(err))
    | None => callback(Ok((stdout, stderr)))
    }
  });
};

[@bs.module "child_process"] [@bs.val]
external execFile:
  (
    string,
    array(string),
    {
      .
      "cwd": option(string),
      "env": option(Js.Dict.t(string)),
      "encoding": option(string),
      "timeout": option(float),
      "maxBuffer": option(int),
      "killSignal": option(string),
      "uid": option(float),
      "gid": option(float),
      "windowsHide": option(bool),
      "shell": option(string),
    },
    (option(Js.Exn.t), string, string) => unit
  ) =>
  t =
  "execFile";

let execFile =
    (
      file,
      args,
      ~cwd=?,
      ~env=?,
      ~encoding=?,
      ~shell=?,
      ~timeout=?,
      ~maxBuffer=?,
      ~killSignal=?,
      ~uid=?,
      ~gid=?,
      ~windowsHide=?,
      callback,
    ) => {
  execFile(
    file,
    args,
    {
      "cwd": cwd,
      "env": env,
      "encoding": encoding,
      "shell": shell,
      "timeout": timeout,
      "maxBuffer": maxBuffer,
      "killSignal": killSignal,
      "uid": uid,
      "gid": gid,
      "windowsHide": windowsHide,
    },
    (error, stdout, stderr) => {
    switch (error) {
    | Some(err) => callback(Error(err))
    | None => callback(Ok((stdout, stderr)))
    }
  });
};

[@bs.module "child_process"] [@bs.val]
external fork:
  (
    string,
    array(string),
    {
      .
      "cwd": option(string),
      "detached": option(bool),
      "env": option(Js.Dict.t(string)),
      "execPath": option(string),
      "execArgv": option(array(string)),
      "silent": option(bool),
      "stdio": option(string),
      "uid": option(float),
      "gid": option(float),
      "windowsVerbatimArguments": option(bool),
    }
  ) =>
  t =
  "fork";

let fork =
    (
      modulePath,
      args,
      ~cwd=?,
      ~detached=?,
      ~execPath=?,
      ~execArgv=?,
      ~uid=?,
      ~gid=?,
      ~env=?,
      ~stdio=?,
      ~silent=?,
      ~windowsVerbatimArguments=?,
      (),
    ) => {
  fork(
    modulePath,
    Array.of_list(args),
    {
      "cwd": cwd,
      "detached": detached,
      "env": env,
      "execPath": execPath,
      "execArgv": execArgv,
      "silent": silent,
      "stdio": stdio,
      "uid": uid,
      "gid": gid,
      "windowsVerbatimArguments": windowsVerbatimArguments,
    },
  );
};

[@bs.module "child_process"] [@bs.val]
external spawn:
  (
    string,
    array(string),
    {
      .
      "cwd": option(string),
      "env": option(Js.Dict.t(string)),
      "argv0": option(string),
      "stdio": option(string),
      "detached": option(bool),
      "uid": option(float),
      "gid": option(float),
      "shell": option(string),
      "windowsVerbatimArguments": option(bool),
      "windowsHide": option(bool),
    }
  ) =>
  t =
  "spawn";

let spawn =
    (
      command,
      args,
      ~cwd=?,
      ~detached=?,
      ~uid=?,
      ~gid=?,
      ~env=?,
      ~argv0=?,
      ~stdio=?,
      ~shell=?,
      ~windowsVerbatimArguments=?,
      ~windowsHide=?,
      (),
    ) => {
  spawn(
    command,
    Array.of_list(args),
    {
      "cwd": cwd,
      "env": env,
      "argv0": argv0,
      "stdio": stdio,
      "detached": detached,
      "uid": uid,
      "gid": gid,
      "shell": shell,
      "windowsVerbatimArguments": windowsVerbatimArguments,
      "windowsHide": windowsHide,
    },
  );
};

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
      "cwd": option(string),
      "env": option(Js.Dict.t(string)),
      "input": option('a),
      "argv0": option(string),
      "stdio": option(string),
      "detached": option(bool),
      "uid": option(float),
      "gid": option(float),
      "shell": option(string),
      "windowsVerbatimArguments": option(bool),
      "windowsHide": option(bool),
    }
  ) =>
  spawnSyncResult('a) =
  "spawnSync";

let spawnSync =
    (
      command,
      args,
      ~cwd=?,
      ~input=?,
      ~detached=?,
      ~uid=?,
      ~gid=?,
      ~env=?,
      ~argv0=?,
      ~stdio=?,
      ~shell=?,
      ~windowsVerbatimArguments=?,
      ~windowsHide=?,
      (),
    ) => {
  spawnSync(
    command,
    Array.of_list(args),
    {
      "cwd": cwd,
      "env": env,
      "input":
        switch (input) {
        | Some(input) => Some(BinaryLike.unwrap(input))
        | None => None
        },
      "argv0": argv0,
      "stdio": stdio,
      "detached": detached,
      "uid": uid,
      "gid": gid,
      "shell": shell,
      "windowsVerbatimArguments": windowsVerbatimArguments,
      "windowsHide": windowsHide,
    },
  );
};

[@bs.module "child_process"] [@bs.val]
external execSync:
  (
    string,
    {
      .
      "cwd": option(string),
      "env": option(Js.Dict.t(string)),
      "input": option('a),
      "encoding": option(string),
      "shell": option(string),
      "timeout": option(float),
      "maxBuffer": option(int),
      "killSignal": option(string),
      "uid": option(float),
      "gid": option(float),
      "windowsHide": option(bool),
    }
  ) =>
  string =
  "execSync";

let execSync =
    (
      command,
      ~cwd=?,
      ~input=?,
      ~env=?,
      ~encoding=?,
      ~shell=?,
      ~timeout=?,
      ~maxBuffer=?,
      ~killSignal=?,
      ~uid=?,
      ~gid=?,
      ~windowsHide=?,
      (),
    ) => {
  execSync(
    command,
    {
      "cwd": cwd,
      "env": env,
      "input":
        switch (input) {
        | Some(input) => Some(BinaryLike.unwrap(input))
        | None => None
        },
      "encoding": encoding,
      "shell": shell,
      "timeout": timeout,
      "maxBuffer": maxBuffer,
      "killSignal": killSignal,
      "uid": uid,
      "gid": gid,
      "windowsHide": windowsHide,
    },
  );
};

[@bs.module "child_process"] [@bs.val]
external execFileSync:
  (
    string,
    array(string),
    {
      .
      "cwd": option(string),
      "input": option('a),
      "env": option(Js.Dict.t(string)),
      "encoding": option(string),
      "timeout": option(float),
      "maxBuffer": option(int),
      "killSignal": option(string),
      "uid": option(float),
      "gid": option(float),
      "windowsHide": option(bool),
      "shell": option(string),
    }
  ) =>
  string =
  "execFileSync";

let execFileSync =
    (
      file,
      args,
      ~cwd=?,
      ~input=?,
      ~env=?,
      ~encoding=?,
      ~shell=?,
      ~timeout=?,
      ~maxBuffer=?,
      ~killSignal=?,
      ~uid=?,
      ~gid=?,
      ~windowsHide=?,
      (),
    ) => {
  execFileSync(
    file,
    args,
    {
      "cwd": cwd,
      "env": env,
      "input":
        switch (input) {
        | Some(input) => Some(BinaryLike.unwrap(input))
        | None => None
        },
      "encoding": encoding,
      "shell": shell,
      "timeout": timeout,
      "maxBuffer": maxBuffer,
      "killSignal": killSignal,
      "uid": uid,
      "gid": gid,
      "windowsHide": windowsHide,
    },
  );
};