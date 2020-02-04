
module Interface = {
  type t;
  [@bs.send] external close: t => unit = "close";
  [@bs.send] external pause: t => unit = "pause";
  [@bs.send] external prompt: t => option(bool) = "prompt";
};

