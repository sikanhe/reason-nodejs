/**
 * This `void` type is meant to represent the type of readable or
 * writable data which can never be produced.
 */
type void;

/**
 * This section contains most of polymorphic variant constraints
 * corresponding to the various subtypes of `Stream.t` throughout this library.
 */
type stream = [ | `Stream];
type readable = [ stream | `Readable];
type writable = [ stream | `Writable];
type duplex = [ stream | readable | writable];
type transform = [ stream | duplex | `Transform];
type passThrough = [ stream | transform | `PassThrough];
type socket = [ stream | duplex | `Socket];
type tcpSocket = [ stream | socket | `Tcp];
type icpSocket = [ stream | socket | `Icp];
type objectMode = [ stream | `ObjectMode];

type subtype('w, 'r, 'a) constraint 'a = [> stream];
type t('w, 'r) = subtype('w, 'r, stream);

module Common = {
  type kind = [ stream];
  type nonrec subtype('w, 'r, 'a) = subtype('w, 'r, 'a);
  module Events = {
    [@bs.send]
    external onError:
      (subtype('w, 'r, 'a) as 'stream, [@bs.as "error"] _, [@bs.uncurry] (Js.Exn.t => unit)) =>
      'stream =
      "on";
    [@bs.send]
    external onClose:
      (subtype('w, 'r, 'a) as 'stream, [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      'stream =
      "on";
    [@bs.send]
    external offError:
      (subtype('w, 'r, 'a) as 'stream, [@bs.as "error"] _, [@bs.uncurry] (Js.Exn.t => unit)) =>
      'stream =
      "off";
    [@bs.send]
    external offClose:
      (subtype('w, 'r, 'a) as 'stream, [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      'stream =
      "off";
    [@bs.send]
    external onErrorOnce:
      (subtype('w, 'r, 'a) as 'stream, [@bs.as "error"] _, [@bs.uncurry] (Js.Exn.t => unit)) =>
      'stream =
      "once";
    [@bs.send]
    external onCloseOnce:
      (subtype('w, 'r, 'a) as 'stream, [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      'stream =
      "once";
    [@bs.send]
    external removeAllListeners: (subtype('w, 'r, 'a) as 'stream) => 'stream =
      "removeAllListeners";
  };
  module Impl = {
    include Events;
    [@bs.send] external destroy: (subtype('w, 'r, [> kind]) as 'stream) => 'stream = "destroy";
    [@bs.send]
    external destroyWithError: (subtype('w, 'r, [> kind]) as 'stream, Js.Exn.t) => 'stream =
      "destroy";
    [@bs.get] external destroyed: subtype('w, 'r, [> kind]) => bool = "destroyed";
  };
  include Impl;
};

module Readable = {
  type kind = [ readable];
  module Events = {
    include Common.Events;
    [@bs.send]
    external onData:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "data"] _, [@bs.uncurry] ('r => unit)) => 'rs =
      "on";
    [@bs.send]
    external onEnd:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "end"] _, [@bs.uncurry] (unit => unit)) => 'rs =
      "on";
    [@bs.send]
    external onPause:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "pause"] _, [@bs.uncurry] (unit => unit)) => 'rs =
      "on";
    [@bs.send]
    external onReadable:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "readable"] _, [@bs.uncurry] (unit => unit)) =>
      'rs =
      "on";
    [@bs.send]
    external onResume:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "resume"] _, [@bs.uncurry] (unit => unit)) => 'rs =
      "on";
    [@bs.send]
    external offData:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "data"] _, [@bs.uncurry] ('r => unit)) => 'rs =
      "off";
    [@bs.send]
    external offEnd:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "end"] _, [@bs.uncurry] (unit => unit)) => 'rs =
      "off";
    [@bs.send]
    external offPause:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "pause"] _, [@bs.uncurry] (unit => unit)) => 'rs =
      "off";
    [@bs.send]
    external offReadable:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "readable"] _, [@bs.uncurry] (unit => unit)) =>
      'rs =
      "off";
    [@bs.send]
    external offResume:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "resume"] _, [@bs.uncurry] (unit => unit)) => 'rs =
      "off";
    [@bs.send]
    external onDataOnce:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "data"] _, [@bs.uncurry] ('r => unit)) => 'rs =
      "once";
    [@bs.send]
    external onEndOnce:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "end"] _, [@bs.uncurry] (unit => unit)) => 'rs =
      "once";
    [@bs.send]
    external onPauseOnce:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "pause"] _, [@bs.uncurry] (unit => unit)) => 'rs =
      "once";
    [@bs.send]
    external onReadableOnce:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "readable"] _, [@bs.uncurry] (unit => unit)) =>
      'rs =
      "once";
    [@bs.send]
    external onResumeOnce:
      (subtype('w, 'r, [> kind]) as 'rs, [@bs.as "resume"] _, [@bs.uncurry] (unit => unit)) => 'rs =
      "once";
  };
  module Impl = {
    include Common.Impl;
    include Events;
    [@bs.send] external isPaused: subtype('w, 'r, [> kind]) => bool = "isPaused";
    [@bs.send] external pause: (subtype('w, 'r, [> kind]) as 'rs) => 'rs = "pause";
    [@bs.send]
    external pipe: (subtype('w, 'r, [> kind]), subtype('w, 'r, [> writable]) as 'ws) => 'ws =
      "pipe";
    [@bs.send] external push: (subtype('w, 'r, [> kind]), 'r) => unit = "push";
    [@bs.send] external read: subtype('w, 'r, [> kind]) => unit = "read";
    [@bs.send] external readSize: (subtype('w, 'r, [> kind]), int) => unit = "read";
    [@bs.get] external readable: subtype('w, 'r, [> kind]) => bool = "readable";
    [@bs.get]
    external readableEncoding: subtype('w, 'r, [> kind]) => Js.nullable(string) =
      "readableEncoding";
    [@bs.get] external readableEnded: subtype('w, 'r, [> kind]) => bool = "readableEnded";
    [@bs.get] external readableFlowing: subtype('w, 'r, [> kind]) => bool = "readableFlowing";
    [@bs.get]
    external readableHighWaterMark: subtype('w, 'r, [> kind]) => int = "readableHighWaterMark";
    [@bs.get] external readableLength: subtype('w, 'r, [> kind]) => int = "readableLength";
    [@bs.get]
    external readableObjectMode: subtype('w, 'r, [> kind]) => bool = "readableObjectMode";
    [@bs.send] external resume: (subtype('w, 'r, [> kind]) as 'rs) => 'rs = "resume";
    [@bs.send]
    external unpipe: (subtype('w, 'r, [> kind]) as 'rs, subtype('w, 'r, [> writable])) => 'rs =
      "unpipe";
    [@bs.send] external unshift: (subtype('w, 'r, [> kind]), 'w, 'r) => unit = "unshift";
  };
  include Impl;
  type nonrec supertype('w, 'r, 'a) = subtype('w, 'r, [< kind] as 'a);
  type nonrec subtype('w, 'r, 'a) = subtype('w, 'r, [> kind] as 'a);
  type nonrec t('r) = subtype(void, 'r, kind);
  type objectStream('r) = subtype(void, 'r, [ kind | objectMode ])

  type makeOptions('r);
  [@bs.obj]
  external makeOptions:
    (
      ~highWaterMark: int=?,
      ~emitClose: bool=?,
      ~objectMode: [@bs.as {json|false|json}] _,
      ~autoDestroy: bool=?,
      ~destroy: [@bs.this] (
                  (t('r), Js.nullable(Js.Exn.t), (~err: option(Js.Exn.t)) => unit) => unit
                ),
      ~read: [@bs.this] ((t('r), Js.nullable(int)) => unit),
      unit
    ) =>
    makeOptions('r);
  [@bs.module "stream"] [@bs.new]
  external make: makeOptions(Buffer.t) => t(Buffer.t) = "Readable";

  type makeOptionsObjMode('r);
  [@bs.obj]
  external makeOptionsObjMode:
    (
      ~highWaterMark: int=?,
      ~emitClose: bool=?,
      ~objectMode: [@bs.as {json|true|json}] _,
      ~autoDestroy: bool=?,
      ~destroy: [@bs.this] (
                  (t('r), Js.nullable(Js.Exn.t), (~err: option(Js.Exn.t)) => unit) => unit
                ),
      ~read: [@bs.this] ((t('r), Js.nullable(int)) => unit),
      unit
    ) =>
    makeOptionsObjMode('r);

  [@bs.module "stream"] [@bs.new]
  external makeObjMode: makeOptions('r) => t('r) = "Readable";
  
};

module Writable = {
  type kind = [ writable];
  module Events = {
    [@bs.send]
    external onDrain:
      (subtype('w, 'r, [> kind]) as 'ws, [@bs.as "drain"] _, [@bs.uncurry] (unit => unit)) => 'ws =
      "on";
    [@bs.send]
    external onFinish:
      (subtype('w, 'r, [> kind]) as 'ws, [@bs.as "finish"] _, [@bs.uncurry] (unit => unit)) => 'ws =
      "on";
    [@bs.send]
    external onPipe:
      (
        subtype('w, 'r, [> kind]) as 'ws,
        [@bs.as "pipe"] _,
        [@bs.uncurry] (subtype('w, 'r, [> readable]) => unit)
      ) =>
      'ws =
      "on";
    [@bs.send]
    external onUnpipe:
      (
        subtype('w, 'r, [> kind]) as 'ws,
        [@bs.as "unpipe"] _,
        [@bs.uncurry] (subtype('w, 'r, [> readable]) => unit)
      ) =>
      'ws =
      "on";
    [@bs.send]
    external offDrain:
      (subtype('w, 'r, [> kind]) as 'ws, [@bs.as "drain"] _, [@bs.uncurry] (unit => unit)) => 'ws =
      "off";
    [@bs.send]
    external offFinish:
      (subtype('w, 'r, [> kind]) as 'ws, [@bs.as "finish"] _, [@bs.uncurry] (unit => unit)) => 'ws =
      "off";
    [@bs.send]
    external offPipe:
      (
        subtype('w, 'r, [> kind]) as 'ws,
        [@bs.as "pipe"] _,
        [@bs.uncurry] (subtype('w, 'r, [> readable]) => unit)
      ) =>
      'ws =
      "off";
    [@bs.send]
    external offUnpipe:
      (
        subtype('w, 'r, [> kind]) as 'ws,
        [@bs.as "unpipe"] _,
        [@bs.uncurry] (subtype('w, 'r, [> readable]) => unit)
      ) =>
      'ws =
      "off";
    [@bs.send]
    external onDrainOnce:
      (subtype('w, 'r, [> kind]) as 'ws, [@bs.as "drain"] _, [@bs.uncurry] (unit => unit)) => 'ws =
      "once";
    [@bs.send]
    external onFinishOnce:
      (subtype('w, 'r, [> kind]) as 'ws, [@bs.as "finish"] _, [@bs.uncurry] (unit => unit)) => 'ws =
      "once";
    [@bs.send]
    external onPipeOnce:
      (
        subtype('w, 'r, [> kind]) as 'ws,
        [@bs.as "pipe"] _,
        [@bs.uncurry] (subtype('w, 'r, [> readable]) => unit)
      ) =>
      'ws =
      "once";
    [@bs.send]
    external onUnpipeOnce:
      (
        subtype('w, 'r, [> kind]) as 'ws,
        [@bs.as "unpipe"] _,
        [@bs.uncurry] (subtype('w, 'r, [> readable]) => unit)
      ) =>
      'ws =
      "once";
  };
  module Impl = {
    include Common.Impl;
    include Events;
    [@bs.send] external cork: subtype('w, 'r, [> kind]) => unit = "cork";
    [@bs.send] external uncork: subtype('w, 'r, [> kind]) => unit = "uncork";
    [@bs.send] external end_: subtype('w, 'r, [> kind]) => unit = "end";
    [@bs.send] external write: (subtype('w, 'r, [> kind]), 'w) => bool = "write";
    [@bs.send]
    external writeWith:
      (subtype('w, 'r, [> kind]), 'w, ~callback: Js.Nullable.t(Js.Exn.t) => unit=?, unit) => bool =
      "write";
    [@bs.get] external writable: subtype('w, 'r, [> kind]) => bool = "writable";
    [@bs.get] external writableEnded: subtype('w, 'r, [> kind]) => bool = "writableEnded";
    [@bs.get] external writableCorked: subtype('w, 'r, [> kind]) => bool = "writableCorked";
    [@bs.get] external writableFinished: subtype('w, 'r, [> kind]) => bool = "writableFinished";
    [@bs.get] external writableLength: subtype('w, 'r, [> kind]) => int = "writableLength";
    [@bs.get]
    external writableHighWaterMark: subtype('w, 'r, [> kind]) => int = "writableHighWaterMark";
    [@bs.get]
    external writableObjectMode: subtype('w, 'r, [> kind]) => bool = "writableObjectMode";
  };
  include Impl;
  type nonrec supertype('w, 'r, 'a) = subtype('w, 'r, [< kind] as 'a);
  type nonrec subtype('w, 'r, 'a) = subtype('w, 'r, [> kind] as 'a);
  type nonrec t('w) = subtype('w, void, kind);
  type objectStream('w) = subtype('w, void, [ kind | objectMode ])
  type chunk('w) =
    pri {
      chunk: 'w,
      encoding: string,
    };
  type makeOptions('w);
  [@bs.obj]
  external makeOptions:
    (
      ~highWaterMark: int=?,
      ~objectMode: [@bs.as {json|false|json}] _,
      ~emitClose: bool=?,
      ~autoDestroy: bool=?,
      ~destroy: [@bs.this] (
                  (t('w), Js.nullable(Js.Exn.t), (~err: option(Js.Exn.t)) => unit) => unit
                )
                  =?,
      ~final: [@bs.this] ((t('w), 'w, (~err: option(Js.Exn.t)) => unit) => unit)=?,
      ~writev: [@bs.this] ((t('w), array(chunk('w)), (~err: option(Js.Exn.t)) => unit) => unit)
                 =?,
      ~write: [@bs.this] ((t('w), 'w, (~err: option(Js.Exn.t)) => unit) => unit),
      unit
    ) =>
    makeOptions('w);
  [@bs.module "stream"] [@bs.new]
  external make: makeOptions(Buffer.t) => t(Buffer.t) = "Writable";
};

module Duplex = {
  type kind = [ duplex];
  module Events = {
    include Readable.Events;
    include Writable.Events;
  };
  module Impl = {
    include Readable.Impl;
    include Writable.Impl;
    include Events;
  };
  include Impl;
  type nonrec supertype('w, 'r, 'a) = subtype('w, 'r, [< kind] as 'a);
  type nonrec subtype('w, 'r, 'a) = subtype('w, 'r, [> kind] as 'a);
  type nonrec t('w, 'r) = subtype('w, 'r, kind);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t, Buffer.t) = "Duplex";
};

module Transform = {
  type kind = [ transform];
  module Events = {
    include Duplex.Events;
  };
  module Impl = {
    include Duplex.Impl;
    include Events;
  };
  include Impl;
  type nonrec supertype('w, 'r, 'a) = subtype('w, 'r, [< kind] as 'a);
  type nonrec subtype('w, 'r, 'a) = subtype('w, 'r, [> kind] as 'a);
  type nonrec t('w, 'r) = subtype('w, 'r, kind);
  type makeOptions('w, 'r);
  [@bs.obj]
  external makeOptions:
    (
      ~transform: [@bs.this] (
                    (
                      t('w, 'r),
                      'w,
                      string,
                      (~err: option(Js.Exn.t), ~data: option('r)) => unit
                    ) =>
                    unit
                  ),
      ~flush: [@bs.this] (
                (t('w, 'r), (~err: option(Js.Exn.t), ~data: option('r)) => unit) => unit
              ),
      unit
    ) =>
    makeOptions('w, 'r);

  [@bs.module "stream"] [@bs.new] external make: makeOptions('w, 'r) => t('w, 'r) = "Transform";
};

module PassThrough = {
  type kind = [ passThrough];
  module Events = {
    include Transform.Events;
  };
  module Impl = {
    include Transform.Impl;
    include Events;
  };
  include Impl;
  type nonrec supertype('w, 'r, 'a) = subtype('w, 'r, [< kind] as 'a);
  type nonrec subtype('w, 'r, 'a) = subtype('w, 'r, [> kind] as 'a);
  type nonrec t('w, 'r) = subtype('w, 'r, kind);
  [@bs.module "stream"] [@bs.new] external make: unit => t('w, 'r) = "PassThrough";
};

module Events = {
  include Common.Events;
  include Readable.Events;
  include Writable.Events;
};
include Common.Impl;
include Readable.Impl;
include Writable.Impl;
include Events;

type cleanupFn = unit => unit;

[@bs.module "stream"]
external finished: (subtype('w, 'r, 'a), Js.nullable(Js.Exn.t) => unit) => cleanupFn =
  "finished";

[@bs.module "stream"]
external pipeline0:
  (
    Readable.subtype('t0, 't1, 'src),
    Writable.subtype('t1, 't2, 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  Writable.subtype('t1, 't1, 'dest) =
  "pipeline";

[@bs.module "stream"]
external pipeline1:
  (
    Readable.subtype('t0, 't1, 'src),
    Duplex.subtype('t1, 't2, 'kind1),
    Writable.subtype('t2, 't3, 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  Writable.subtype('t1, 't2, 'dest) =
  "pipeline";
[@bs.module "stream"]
external pipeline2:
  (
    Readable.subtype('t0, 't1, 'src),
    Duplex.subtype('t1, 't2, 'kind1),
    Duplex.subtype('t2, 't3, 'kind2),
    Writable.subtype('t3, 't4, 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  Writable.subtype('t1, 't3, 'dest) =
  "pipeline";
