

module Worker = {

  type t;

  [@bs.send] external disconnect: t => unit = "disconnect";
  [@bs.send] external exitedAfterDisconnect: t => bool = "exitedAfterDisconnect";
  [@bs.send] external id: t => int = "id";
  [@bs.send] external isConnected: t => bool = "isConnected";
  [@bs.send] external kill: (t, option(string)) => unit = "kill";
  let kill = (~signal=?, worker) => kill(worker, signal);
  [@bs.send] external process: t => ChildProcess.t = "process";

  // TODO: implement `send` function


  include Events.EventEmitter.Impl({ type nonrec t = t; });

};

// TODO: refactor as a Js.t
module Settings = {
  type t;
  [@bs.get] external execArgv: t => array(string) = "execArgv";
  [@bs.get] external exec: t => string = "exec";
  [@bs.get] external args: t => array(string) = "args";
  [@bs.get] external cwd: t => string = "cwd";
}

type t;

[@bs.send] external fork: (t, option(Js.Dict.t(string))) => t = "fork";
let fork = (~env=?, cluster) => fork(cluster, env);
[@bs.get] external isMaster: t => bool = "isMaster";
[@bs.get] external isWorker: t => bool = "isWorker";
[@bs.get] external settings: t => Settings.t = "settings";

