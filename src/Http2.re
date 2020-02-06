
module Http2Session = {
  type t;
  [@bs.send] external onClose: (t, [@bs.as "close"] _, unit => unit) => unit = "on";
  [@bs.send] external onConnect: (t, [@bs.as "connect"] _, (t, Net.Socket.t) => unit) => unit = "on";
  [@bs.send] external onError: (t, [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
  [@bs.send] external onFrameError: (t, [@bs.as "frameError"] _, (~type_:int, ~code:int, ~id:int) => unit) => unit = "on";

};