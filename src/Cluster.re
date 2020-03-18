/**
 * TODO: add EventEmitter functions for both
 * Cluster and Cluster.Worker.
 */

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
  [@bs.send] external sendSocketHandle: (string, Net.Socket.subtype('a), Js.nullable(Js.t({..}))) => unit = "send";
  let sendSocketHandle = (~options=?, msg, handle) => sendSocketHandle(msg, handle, Js.Nullable.fromOption(options));
};

type clusterSettings = {
  .
  "execArgv": Js.Nullable.t(array(string)),
  "exec": Js.Nullable.t(string),
  "args": Js.Nullable.t(array(string)),
  "cwd": Js.Nullable.t(string),
  "serialization": Js.Nullable.t(string),
  "silent": Js.Nullable.t(bool),
  "stdio": Js.Nullable.t(array(string)),
  "uid": Js.Nullable.t(int),
  "gid": Js.Nullable.t(int),
  "inspectPort": Js.Nullable.t(int),
  "windowsHide": Js.Nullable.t(bool)
};

[@bs.obj] external clusterSettings: (
  ~execArgv: array(string)=?,
  ~exec: string=?,
  ~args: array(string)=?,
  ~cwd: string=?,
  ~serialization: string=?,
  ~silent: bool=?,
  ~stdio: array(string)=?,
  ~uid: int=?,
  ~gid: int=?,
  ~inspectPort: int=?,
  ~windowsHide: bool=?
) => clusterSettings = "";

[@bs.module] external disconnect: Js.Nullable.t(unit => unit) => unit = "disconnect";
let disconnect = (~callback=?, ()) => disconnect(Js.Nullable.fromOption(callback));
[@bs.module "cluster"] external fork: (option(Js.Dict.t(string))) => Worker.t = "fork";
let fork = (~env=?, ()) => fork(env);
[@bs.module "cluster"] external isMaster: bool = "isMaster";
[@bs.module "cluster"] external isWorker: bool = "isWorker";
[@bs.module "cluster"] external settings: clusterSettings = "settings";
[@bs.module "cluster"] external setupMaster: clusterSettings => unit = "setupMaster";
[@bs.module "cluster"] external _SCHED_NONE: int = "SCHED_NONE";
[@bs.module "cluster"] external _SCHED_RR: int = "SCHED_RR";
[@bs.module "cluster"] external schedulingPolicy: int = "schedulingPolicy";
type schedulingPolicy = SCHED_NONE | SCHED_RR;
let decodeSchedulingPolicy =
  if(schedulingPolicy === _SCHED_RR) {
    SCHED_RR;
  } else {
    SCHED_NONE;
  };
[@bs.module "cluster"] external worker: Worker.t = "worker";
[@bs.module "cluster"] external workers: Js.Dict.t(Worker.t) = "workers";
let getWorker: (Js.Dict.t(Worker.t), int) => option(Worker.t) = (_workers, id) =>
  Js.Dict.get(_workers, Js.Int.toString(id));

module Test = {
  Js.log([%bs.raw {|Cluster|}]);
  let () = switch (isMaster) {
    | true => schedulingPolicy |> Js.log;
    | false => worker->Js.log;
  }
};
