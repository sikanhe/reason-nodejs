

module Worker = {

  type t;

  [@bs.send] external disconnect: t => unit = "disconnect";



};

type t;

[@bs.send] external fork: t => Worker.t = "fork";


