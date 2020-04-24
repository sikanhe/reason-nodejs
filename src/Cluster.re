
module Address = {
  type t = pri {
    [@bs.as "address"] address: string,
    [@bs.as "port"] port: string,
  };
  type internalView('a) = pri {
    [@bs.as "address"] address: string,
    [@bs.as "port"] port: string,
    [@bs.as "addressType"] addressType: 'a,
  };
  type case =
    | TcpV4(t)
    | TcpV6(t)
    | UnixDomainSocket(t)
    | Udp4(t)
    | Udp6(t)
    | Unknown(t)
  ;
  let classify: t => case = fun
    | address => {
      let internalReturn: internalView('a) = Obj.magic(address);
      let addressType = internalReturn.addressType;
      let intOrString = Js.typeof(addressType);
      switch (intOrString) {
        | ("number") => {
          switch (Obj.magic(addressType): int) {
            | 4 => TcpV4(address)
            | 6 => TcpV6(address)
            | -1 => UnixDomainSocket(address)
            | _ => Unknown(address)
          };
        };
        | ("string") => {
          switch (Obj.magic(addressType): string) {
            | "udp4" => Udp4(address)
            | "udp6" => Udp6(address)
            | _ => Unknown(address)
          };
        };
        | _ => Unknown(address);
      };
    };
};

module Message = {
  type t('a) = Js.t('a);
};

module Worker = {
  type t;
  module Events = {
    [@bs.send] external onDisconnect: (t, [@bs.as "disconnect"]_, [@bs.uncurry] (unit) => unit) => t = "on";
    [@bs.send] external onError: (t, [@bs.as "error"]_, [@bs.uncurry] (Js.Exn.t) => unit) => t = "on";
    [@bs.send] external onExit: (t, [@bs.as "exit"]_, [@bs.uncurry] (Js.nullable(int), Js.nullable(string)) => unit) => t = "on";
    [@bs.send] external onListening: (t, [@bs.as "listening"]_, [@bs.uncurry] (Address.t) => unit) => t = "on";
    [@bs.send] external onMessage: (t, [@bs.as "message"]_, [@bs.uncurry] (Message.t('a), Js.nullable(Js.t('a))) => unit) => t = "on";
    [@bs.send] external onOnline: (t, [@bs.as "online"]_, [@bs.uncurry] (unit) => unit) => t = "on";

    [@bs.send] external offDisconnect: (t, [@bs.as "disconnect"]_, [@bs.uncurry] (unit) => unit) => t = "off";
    [@bs.send] external offError: (t, [@bs.as "error"]_, [@bs.uncurry] (Js.Exn.t) => unit) => t = "off";
    [@bs.send] external offExit: (t, [@bs.as "exit"]_, [@bs.uncurry] (Js.nullable(int), Js.nullable(string)) => unit) => t = "off";
    [@bs.send] external offListening: (t, [@bs.as "listening"]_, [@bs.uncurry] (Address.t) => unit) => t = "off";
    [@bs.send] external offMessage: (t, [@bs.as "message"]_, [@bs.uncurry] (Message.t('a), Js.nullable(Js.t('a))) => unit) => t = "off";
    [@bs.send] external offOnline: (t, [@bs.as "online"]_, [@bs.uncurry] (unit) => unit) => t = "off";

    [@bs.send] external onDisconnectOnce: (t, [@bs.as "disconnect"]_, [@bs.uncurry] (unit) => unit) => t = "once";
    [@bs.send] external onErrorOnce: (t, [@bs.as "error"]_, [@bs.uncurry] (Js.Exn.t) => unit) => t = "once";
    [@bs.send] external onExitOnce: (t, [@bs.as "exit"]_, [@bs.uncurry] (Js.nullable(int), Js.nullable(string)) => unit) => t = "once";
    [@bs.send] external onListeningOnce: (t, [@bs.as "listening"]_, [@bs.uncurry] (Address.t) => unit) => t = "once";
    [@bs.send] external onMessageOnce: (t, [@bs.as "message"]_, [@bs.uncurry] (Message.t('a), Js.nullable(Js.t('a))) => unit) => t = "once";
    [@bs.send] external onOnlineOnce: (t, [@bs.as "online"]_, [@bs.uncurry] (unit) => unit) => t = "once";

    [@bs.send] external removeAllListeners: t => unit = "removeAllListeners";
  };
  [@bs.send] external disconnect: t => unit = "disconnect";
  [@bs.send] external exitedAfterDisconnect: t => bool = "exitedAfterDisconnect";
  [@bs.send] external id: t => int = "id";
  [@bs.send] external isConnected: t => bool = "isConnected";
  [@bs.send] external isDead: t => bool = "isConnected";
  [@bs.send] external kill: (t) => unit = "kill";
  [@bs.send] external killWith: (t, ~signal: string) => unit = "kill";
  [@bs.send] external process: t => ChildProcess.t = "process";
  [@bs.send] external send: string => unit = "send";

  [@bs.send] external sendHttpServerHandle: (string, Http.Server.t, Js.nullable(Js.t({..}))) => unit = "send";
  let sendHttpServerHandle = (~options=?, msg, handle) => sendHttpServerHandle(msg, handle, Js.Nullable.fromOption(options));
  [@bs.send] external sendSocketHandle: (string, Net.Socket.subtype('w, 'r, 'a), Js.nullable(Js.t({..}))) => unit = "send";
  let sendSocketHandle = (~options=?, msg, handle) => sendSocketHandle(msg, handle, Js.Nullable.fromOption(options));
};

type clusterSettings = pri {
  execArgv: Js.nullable(array(string)),
  exec: Js.nullable(string),
  args: Js.nullable(array(string)),
  cwd: Js.nullable(string),
  serialization: Js.nullable(string),
  silent: Js.nullable(bool),
  stdio: Js.nullable(array(string)),
  uid: Js.nullable(int),
  gid: Js.nullable(int),
  inspectPort: Js.nullable(int),
  windowsHide: Js.nullable(bool)
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
  ~windowsHide: bool=?,
  unit
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
