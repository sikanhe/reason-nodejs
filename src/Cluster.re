module Worker = {

  type t;

  [@bs.send] external disconnect: t => unit = "disconnect";
  [@bs.send] external exitedAfterDisconnect: t => bool = "exitedAfterDisconnect";
  [@bs.send] external id: t => int = "id";
  [@bs.send] external isConnected: t => bool = "isConnected";
  [@bs.send] external isDead: t => bool = "isConnected";
  [@bs.send] external kill: (t, option(string)) => unit = "kill";
  let kill = (~signal=?, worker) => kill(worker, signal);
  [@bs.send] external process: t => ChildProcess.t = "process";
  [@bs.send] external send: string => unit = "send";
  [@bs.send] external sendHttpServerHandle: (string, Http.Server.t, Js.nullable(Js.t({..}))) => unit = "send";
  let sendHttpServerHandle = (~options=?, msg, handle) => sendHttpServerHandle(msg, handle, Js.Nullable.fromOption(options));
  [@bs.send] external sendSocketHandle: (string, Net.Socket.t, Js.nullable(Js.t({..}))) => unit = "send";
  let sendSocketHandle = (~options=?, msg, handle) => sendSocketHandle(msg, handle, Js.Nullable.fromOption(options));

};

module Settings = {
  type t;
  [@bs.get] external execArgv: t => array(string) = "execArgv";
  [@bs.get] external exec: t => string = "exec";
  [@bs.get] external args: t => array(string) = "args";
  [@bs.get] external cwd: t => string = "cwd";
};

[@bs.module "cluster"] external fork: (option(Js.Dict.t(string))) => Worker.t = "fork";
let fork = (~env=?, ()) => fork(env);
[@bs.module "cluster"] external isMaster: bool = "isMaster";
[@bs.module "cluster"] external isWorker: bool = "isWorker";
[@bs.module "cluster"] external settings: Settings.t = "settings";
