type t('a);
type readable = [ | `Readable];
type writable = [ | `Writable];
type duplex = [ readable | writable];

module Readable = {
  [@bs.module "stream"] [@bs.new]
  external make: unit => t([> readable]) = "Readable";
  [@bs.send]
  external onError:
    (t([> readable]), [@bs.as "error"] _, Js.Exn.t => unit) => unit =
    "on";
  [@bs.send]
  external onData:
    (t([> readable]), [@bs.as "data"] _, Buffer.t => unit) => unit =
    "on";
  [@bs.send]
  external onClose:
    (t([> readable]), [@bs.as "close"] _, unit => unit) => unit =
    "on";
  [@bs.send]
  external onEnd: (t([> readable]), [@bs.as "end"] _, unit => unit) => unit =
    "on";
  [@bs.send]
  external pipe: (t([> readable]), t([> writable]) as 'a) => 'a = "pipe";
  [@bs.send]
  external unpipe: (t([> readable]) as 'a, t([> writable])) => 'a = "unpipe";
};

module Writable = {
  [@bs.module "stream"] [@bs.new]
  external make: unit => t([> writable]) = "Writable";
  [@bs.send]
  external onClose:
    (t([> writable]), [@bs.as "close"] _, unit => unit) => unit =
    "on";
  [@bs.send]
  external onDrain:
    (t([> writable]), [@bs.as "drain"] _, unit => unit) => unit =
    "on";
  [@bs.send]
  external onError:
    (t([> writable]), [@bs.as "error"] _, Js.Exn.t => unit) => unit =
    "on";
  [@bs.send]
  external onFinish:
    (t([> writable]), [@bs.as "finish"] _, unit => unit) => unit =
    "on";
  [@bs.send]
  external onPipe:
    (t([> writable]), [@bs.as "pipe"] _, t([> readable]) => unit) => unit =
    "on";
  [@bs.send]
  external onUnpipe:
    (t([> writable]), [@bs.as "unpipe"] _, t([> readable]) => unit) => unit =
    "on";

  [@bs.send] external cork: t([> writable]) => unit = "cork";
  [@bs.send] external destroy: t([> writable]) => unit = "destroy";
  [@bs.send]
  external destroyWithError: (t([> writable]), Js.Exn.t) => unit = "destroy";
  [@bs.get] external destroyed: t([> writable]) => bool = "destroy";
  [@bs.send] external end_: t([> writable]) => unit = "end";
  [@bs.send]
  external write: (t([> writable]), string, string) => unit = "write";
};

module Duplex = {
  include Readable;
  include Writable;
  [@bs.module "stream"] [@bs.new]
  external make: unit => t([> duplex]) = "Duplex";
};

module PassThrough = {
  [@bs.module "stream"] [@bs.new]
  external make: unit => t([> duplex]) = "PassThrough";
};

include Readable;
include Writable;

[@bs.send]
external onError: (t('a), [@bs.as "error"] _, Js.Exn.t => unit) => unit =
  "on";
[@bs.send]
external onClose: (t('a), [@bs.as "close"] _, unit => unit) => unit = "on";
[@unboxed]
type cleanup = {unsubscribe: unit => unit};
[@bs.module "stream"] [@bs.val]
external finished: (t('a), option(Js.Exn.t) => unit) => cleanup = "finished";