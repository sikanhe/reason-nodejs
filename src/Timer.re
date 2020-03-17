module Immediate = {
  type t;
  [@bs.send] external hasRef: t => bool = "hasRef";
  [@bs.send] external ref: t => t = "ref";
  [@bs.send] external unref: t => t = "unref";
};

module Timeout = {
  type t;
  [@bs.send] external hasRef: t => bool = "hasRef";
  [@bs.send] external ref: t => t = "ref";
  [@bs.send] external refresh: t => t = "refresh";
  [@bs.send] external unref: t => t = "unref";
};

[@bs.val] external setImmediate: (unit => unit) => Immediate.t = "setImmediate";
[@bs.val] external setTimeout: (unit => unit, int) => Timeout.t = "setTimeout";
[@bs.val] external setInterval: (unit => unit, int) => Timeout.t = "setInterval";
[@bs.val] external clearImmediate: Immediate.t => unit = "clearImmediate";
[@bs.val] external clearTimeout: Timeout.t => unit = "clearTimeout";
[@bs.val] external clearInterval: Timeout.t => unit = "clearInterval";