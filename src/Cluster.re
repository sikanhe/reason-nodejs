

module Worker = {

  type t;

  [@bs.send] external disconnect: t => unit = "disconnect";
  [@bs.send] external exitedAfterDisconnect: t => bool = "exitedAfterDisconnect";
  [@bs.send] external id: t => int = "id";
  [@bs.send] external isConnected: t => bool = "isConnected";
  [@bs.send] external kill: (t, option(string)) => unit = "kill";
  [@bs.send] external process: t => ChildProcess.t = "process";


  include Events.EventEmitter.Impl({ type nonrec t = t; });

};

type t;

[@bs.send] external fork: t => Worker.t = "fork";


