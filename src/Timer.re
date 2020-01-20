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

[@bs.module "timer"]
external setImmediate: (unit => unit) => Immediate.t = "setImmediate";
[@bs.module "timer"]
external setTimeout: (unit => unit, int) => Timeout.t = "setTimeout";
[@bs.module "timer"]
external setInterval: (unit => unit, int) => Timeout.t = "setInterval";
[@bs.module "timer"]
external clearImmediate: Immediate.t => unit = "clearImmediate";
[@bs.module "timer"] external clearTimeout: Timeout.t => unit = "clearTimeout";
[@bs.module "timer"]
external clearInterval: Timeout.t => unit = "clearInterval";