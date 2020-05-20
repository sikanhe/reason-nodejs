/** Not sure if we will need the `void` type */
// type void;

type stream = [ | `Stream];
type objectMode = [ stream | `ObjectMode];
type writable('w) = [ stream | `Writable('w)];
type readable('r) = [ stream | `Readable('r)];
type duplex('w, 'r) = [ writable('w) | readable('r)];
type transform('w, 'r) = [ duplex('w, 'r) | `Transform];
type passThrough('w, 'r) = [ transform('w, 'r) | `PassThrough];
type socket('w, 'r) = [ duplex('w, 'r) | `Socket];
type tcpSocket('w, 'r) = [ socket('w, 'r) | `Tcp];
type icpSocket('w, 'r) = [ socket('w, 'r) | `Icp];
type fsWritable('w) = [ writable('w) | `FileSystem];
type fsReadable('r) = [ readable('r) | `FileSystem];

type kind = [ stream];
type subtype('ty) constraint 'ty = [> stream];
type t = subtype(stream);

type chunk('a) =
  pri {
    chunk: 'a,
    encoding: string,
  };

module Common = {
  type kind = [ stream];

  module Events = {
    [@bs.send]
    external onError:
      (
        subtype('ty) as 'stream,
        [@bs.as "error"] _,
        [@bs.uncurry] (Js.Exn.t => unit)
      ) =>
      'stream =
      "on";

    [@bs.send]
    external onClose:
      (
        subtype('ty) as 'stream,
        [@bs.as "close"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'stream =
      "on";

    [@bs.send]
    external offError:
      (
        subtype('ty) as 'stream,
        [@bs.as "error"] _,
        [@bs.uncurry] (Js.Exn.t => unit)
      ) =>
      'stream =
      "off";

    [@bs.send]
    external offClose:
      (
        subtype('ty) as 'stream,
        [@bs.as "close"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'stream =
      "off";

    [@bs.send]
    external onCloseOnce:
      (
        subtype('ty) as 'stream,
        [@bs.as "close"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'stream =
      "once";

    [@bs.send]
    external onErrorOnce:
      (
        subtype('ty) as 'stream,
        [@bs.as "error"] _,
        [@bs.uncurry] (Js.Exn.t => unit)
      ) =>
      'stream =
      "once";

    [@bs.send]
    external removeAllListeners: (subtype('ty) as 'stream) => 'stream =
      "removeAllListeners";
  };

  module Impl = {
    include Events;
    [@bs.send]
    external destroy: (subtype([> kind]) as 'stream) => 'stream = "destroy";
    [@bs.send]
    external destroyWithError:
      (subtype([> kind]) as 'stream, Js.Exn.t) => 'stream =
      "destroy";
    [@bs.get] external destroyed: subtype([> kind]) => bool = "destroyed";
  };
  include Impl;
};

module Writable = {
  type kind('w) = writable('w);
  module Events = {
    [@bs.send]
    external onDrain:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "drain"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'ws =
      "on";
    [@bs.send]
    external onFinish:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "finish"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'ws =
      "on";
    [@bs.send]
    external onPipe:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "pipe"] _,
        [@bs.uncurry] (subtype([> readable('r)]) => unit)
      ) =>
      'ws =
      "on";
    [@bs.send]
    external onUnpipe:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "unpipe"] _,
        [@bs.uncurry] (subtype([> readable('r)]) => unit)
      ) =>
      'ws =
      "on";
    [@bs.send]
    external offDrain:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "drain"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'ws =
      "off";
    [@bs.send]
    external offFinish:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "finish"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'ws =
      "off";
    [@bs.send]
    external offPipe:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "pipe"] _,
        [@bs.uncurry] (subtype([> readable('r)]) => unit)
      ) =>
      'ws =
      "off";
    [@bs.send]
    external offUnpipe:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "unpipe"] _,
        [@bs.uncurry] (subtype([> readable('r)]) => unit)
      ) =>
      'ws =
      "off";
    [@bs.send]
    external onDrainOnce:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "drain"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'ws =
      "once";
    [@bs.send]
    external onFinishOnce:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "finish"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'ws =
      "once";
    [@bs.send]
    external onPipeOnce:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "pipe"] _,
        [@bs.uncurry] (subtype([> readable('r)]) => unit)
      ) =>
      'ws =
      "once";
    [@bs.send]
    external onUnpipeOnce:
      (
        subtype([> writable('w)]) as 'ws,
        [@bs.as "unpipe"] _,
        [@bs.uncurry] (subtype([> readable('r)]) => unit)
      ) =>
      'ws =
      "once";
  };
  module Impl = {
    include Common.Impl;
    include Events;
    [@bs.send] external cork: subtype([> writable('w)]) => unit = "cork";
    [@bs.send] external end_: subtype([> writable('w)]) => unit = "end";
    [@bs.send] external uncork: subtype([> writable('w)]) => unit = "uncork";
    [@bs.send]
    external write: (subtype([> writable('w)]), 'w) => bool = "write";
    [@bs.send]
    external writeWith:
      (
        subtype([> writable('w)]),
        'w,
        ~callback: Js.Nullable.t(Js.Exn.t) => unit=?,
        unit
      ) =>
      bool =
      "write";
    [@bs.get]
    external writable: subtype([> writable('w)]) => bool = "writable";
    [@bs.get]
    external writableEnded: subtype([> writable('w)]) => bool =
      "writableEnded";
    [@bs.get]
    external writableCorked: subtype([> writable('w)]) => bool =
      "writableCorked";
    [@bs.get]
    external writableFinished: subtype([> writable('w)]) => bool =
      "writableFinished";
    [@bs.get]
    external writableLength: subtype([> writable('w)]) => int =
      "writableLength";
    [@bs.get]
    external writableHighWaterMark: subtype([> writable('w)]) => int =
      "writableHighWaterMark";
    [@bs.get]
    external writableObjectMode: subtype([> writable('w)]) => bool =
      "writableObjectMode";
  };
  include Impl;
  type nonrec t('w) = subtype(writable('w));
  type objStream('w) = subtype([ writable('w) | objectMode]);
  type nonrec supertype('w, 'ty) = subtype([< writable('w)] as 'ty);
  type nonrec subtype('w, 'ty) = subtype([> writable('w)] as 'ty);
  type makeOptions('w);
  [@bs.obj]
  external makeOptions:
    (
      ~highWaterMark: int=?,
      ~objectMode: [@bs.as {json|false|json}] _,
      ~emitClose: bool=?,
      ~autoDestroy: bool=?,
      ~destroy: [@bs.this] (
                  (
                    t('w),
                    Js.nullable(Js.Exn.t),
                    (~err: option(Js.Exn.t)) => unit
                  ) =>
                  unit
                )
                  =?,
      ~final: [@bs.this] (
                (t('w), 'w, (~err: option(Js.Exn.t)) => unit) => unit
              )
                =?,
      ~writev: [@bs.this] (
                 (
                   t('w),
                   array(chunk('w)),
                   (~err: option(Js.Exn.t)) => unit
                 ) =>
                 unit
               )
                 =?,
      ~write: [@bs.this] (
                (t('w), 'w, (~err: option(Js.Exn.t)) => unit) => unit
              ),
      unit
    ) =>
    makeOptions('w);
  [@bs.module "stream"] [@bs.new]
  external make: makeOptions(Buffer.t) => t(Buffer.t) = "Writable";

  type makeOptionsObjMode('w);
  [@bs.obj]
  external makeOptionsObjMode:
    (
      ~highWaterMark: int=?,
      ~objectMode: [@bs.as {json|true|json}] _,
      ~emitClose: bool=?,
      ~autoDestroy: bool=?,
      ~destroy: [@bs.this] (
                  (
                    t('w),
                    Js.nullable(Js.Exn.t),
                    (~err: option(Js.Exn.t)) => unit
                  ) =>
                  unit
                )
                  =?,
      ~final: [@bs.this] (
                (t('w), 'w, (~err: option(Js.Exn.t)) => unit) => unit
              )
                =?,
      ~writev: [@bs.this] (
                 (
                   t('w),
                   array(chunk('w)),
                   (~err: option(Js.Exn.t)) => unit
                 ) =>
                 unit
               )
                 =?,
      ~write: [@bs.this] (
                (t('w), 'w, (~err: option(Js.Exn.t)) => unit) => unit
              ),
      unit
    ) =>
    makeOptionsObjMode('w);
  [@bs.module "stream"] [@bs.new]
  external makeObjMode: makeOptionsObjMode('w) => objStream('w) = "Writable";
};

module Readable = {
  type kind('r) = [ readable('r)];
  module Events = {
    include Common.Events;
    [@bs.send]
    external onData:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "data"] _,
        [@bs.uncurry] ('r => unit)
      ) =>
      'rs =
      "on";
    [@bs.send]
    external onEnd:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "end"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "on";
    [@bs.send]
    external onPause:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "pause"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "on";
    [@bs.send]
    external onReadable:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "readable"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "on";
    [@bs.send]
    external onResume:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "resume"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "on";
    [@bs.send]
    external offData:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "data"] _,
        [@bs.uncurry] ('r => unit)
      ) =>
      'rs =
      "off";
    [@bs.send]
    external offEnd:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "end"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "off";
    [@bs.send]
    external offPause:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "pause"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "off";
    [@bs.send]
    external offReadable:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "readable"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "off";
    [@bs.send]
    external offResume:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "resume"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "off";
    [@bs.send]
    external onDataOnce:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "data"] _,
        [@bs.uncurry] ('r => unit)
      ) =>
      'rs =
      "once";
    [@bs.send]
    external onEndOnce:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "end"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "once";
    [@bs.send]
    external onPauseOnce:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "pause"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "once";
    [@bs.send]
    external onReadableOnce:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "readable"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "once";
    [@bs.send]
    external onResumeOnce:
      (
        subtype([> readable('r)]) as 'rs,
        [@bs.as "resume"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'rs =
      "once";
  };
  module Impl = {
    include Common.Impl;
    include Events;
    [@bs.send]
    external isPaused: subtype([> readable('r)]) => bool = "isPaused";
    [@bs.send]
    external pause: (subtype([> readable('r)]) as 'rs) => 'rs = "pause";
    [@bs.send]
    external pipe:
      (subtype([> readable('r)]), subtype([> writable('r)]) as 'ws) =>
      'ws =
      "pipe";
    [@bs.send]
    external push: (subtype([> readable('r)]), 'r) => unit = "push";
    [@bs.send] external read: subtype([> readable('r)]) => unit = "read";
    [@bs.send]
    external readSize: (subtype([> readable('r)]), int) => unit = "read";
    [@bs.get]
    external readable: subtype([> readable('r)]) => bool = "readable";
    [@bs.get]
    external readableEncoding:
      subtype([> readable('r)]) => Js.nullable(string) =
      "readableEncoding";
    [@bs.get]
    external readableEnded: subtype([> readable('r)]) => bool =
      "readableEnded";
    [@bs.get]
    external readableFlowing: subtype([> readable('r)]) => bool =
      "readableFlowing";
    [@bs.get]
    external readableHighWaterMark: subtype([> readable('r)]) => int =
      "readableHighWaterMark";
    [@bs.get]
    external readableLength: subtype([> readable('r)]) => int =
      "readableLength";
    [@bs.get]
    external readableObjectMode: subtype([> readable('r)]) => bool =
      "readableObjectMode";
    [@bs.send]
    external resume: (subtype([> readable('r)]) as 'rs) => 'rs = "resume";
    [@bs.send]
    external unpipe:
      (subtype([> readable('r)]), subtype([> writable('r)]) as 'ws) =>
      'ws =
      "unpipe";
    [@bs.send]
    external unshift: (subtype([> readable('r)]), 'r) => unit = "unshift";
  };
  include Impl;
  type nonrec t('r) = subtype(readable('r));
  type objStream('r) = subtype([ readable('r) | objectMode]);
  type nonrec supertype('r, 'ty) = subtype([< readable('r)] as 'ty);
  type nonrec subtype('r, 'ty) = subtype([> readable('r)] as 'ty);

  type makeOptions('r);
  [@bs.obj]
  external makeOptions:
    (
      ~highWaterMark: int=?,
      ~emitClose: bool=?,
      ~objectMode: [@bs.as {json|false|json}] _,
      ~autoDestroy: bool=?,
      ~destroy: [@bs.this] (
                  (
                    t('r),
                    Js.nullable(Js.Exn.t),
                    (~err: option(Js.Exn.t)) => unit
                  ) =>
                  unit
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
                  (
                    t('r),
                    Js.nullable(Js.Exn.t),
                    (~err: option(Js.Exn.t)) => unit
                  ) =>
                  unit
                ),
      ~read: [@bs.this] ((t('r), Js.nullable(int)) => unit),
      unit
    ) =>
    makeOptionsObjMode('r);

  [@bs.module "stream"] [@bs.new]
  external makeObjMode: makeOptionsObjMode('r) => objStream('r) = "Readable";
};

module Duplex = {
  type kind('w, 'r) = [ duplex('w, 'r)];
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
  type nonrec t('w, 'r) = subtype(duplex('w, 'r));
  type nonrec supertype('w, 'r, 'ty) = subtype([< duplex('w, 'r)] as 'ty);
  type nonrec subtype('w, 'r, 'ty) = subtype([> duplex('w, 'r)] as 'ty);
  type makeOptions('w, 'r);
  [@bs.obj]
  external makeOptions:
    (
      ~objectMode: [@bs.as {json|false|json}] _,
      ~allowHalfOpen: bool=?,
      ~highWaterMark: int=?,
      ~emitClose: bool=?,
      ~autoDestroy: bool=?,
      ~destroy: [@bs.this] (
                  (
                    t('w, 'r),
                    Js.nullable(Js.Exn.t),
                    (~err: option(Js.Exn.t)) => unit
                  ) =>
                  unit
                )
                  =?,
      ~final: [@bs.this] (
                (t('w, 'r), 'w, (~err: option(Js.Exn.t)) => unit) => unit
              )
                =?,
      ~writev: [@bs.this] (
                 (
                   t('w, 'r),
                   array(chunk('w)),
                   (~err: option(Js.Exn.t)) => unit
                 ) =>
                 unit
               )
                 =?,
      ~read: [@bs.this] ((t('w, 'r), Js.nullable(int)) => unit),
      ~write: [@bs.this] (
                (t('w, 'r), 'w, (~err: option(Js.Exn.t)) => unit) => unit
              ),
      unit
    ) =>
    makeOptions('w, 'r);

  [@bs.module "stream"] [@bs.new]
  external make: makeOptions(Buffer.t, Buffer.t) => t(Buffer.t, Buffer.t) =
    "Duplex";
};

module Transform = {
  type kind('w, 'r) = [ transform('w, 'r)];
  module Events = {
    include Duplex.Events;
  };
  module Impl = {
    include Duplex.Impl;
    include Events;
  };
  include Impl;
  type nonrec t('w, 'r) = subtype(transform('w, 'r));
  type objStream('w, 'r) = subtype([ transform('w, 'r) | objectMode]);
  type nonrec supertype('w, 'r, 'ty) = subtype([< transform('w, 'r)] as 'ty);
  type nonrec subtype('w, 'r, 'ty) = subtype([> transform('w, 'r)] as 'ty);
  type makeOptions('w, 'r);
  [@bs.obj]
  external makeOptions:
    (
      ~objectMode: [@bs.as {json|false|json}] _,
      ~highWaterMark: int=?,
      ~emitClose: bool=?,
      ~autoDestroy: bool=?,
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
                (
                  t('w, 'r),
                  (~err: option(Js.Exn.t), ~data: option('r)) => unit
                ) =>
                unit
              ),
      unit
    ) =>
    makeOptions('w, 'r);

  [@bs.module "stream"] [@bs.new]
  external make: makeOptions(Buffer.t, Buffer.t) => t(Buffer.t, Buffer.t) =
    "Transform";

  type makeOptionsObjMode('w, 'r);
  [@bs.obj]
  external makeOptionsObjMode:
    (
      ~objectMode: [@bs.as {json|true|json}] _,
      ~highWaterMark: int=?,
      ~emitClose: bool=?,
      ~autoDestroy: bool=?,
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
                (
                  t('w, 'r),
                  (~err: option(Js.Exn.t), ~data: option('r)) => unit
                ) =>
                unit
              ),
      unit
    ) =>
    makeOptionsObjMode('w, 'r);

  [@bs.module "stream"] [@bs.new]
  external makeObjMode: makeOptionsObjMode('w, 'r) => objStream('w, 'r) =
    "Transform";
};


module PassThrough = {
  type kind('w, 'r) = [ passThrough('w, 'r)];
  module Events = {
    include Transform.Events;
  };
  module Impl = {
    include Transform.Impl;
    include Events;
  };
  include Impl;
  type nonrec t('w, 'r) = subtype(passThrough('w, 'r));
  type nonrec supertype('w, 'r, 'ty) = subtype([< passThrough('w, 'r)] as 'ty);
  type nonrec subtype('w, 'r, 'ty) = subtype([> passThrough('w, 'r)] as 'ty);
  [@bs.module "stream"] [@bs.new]
  external make: unit => t(Buffer.t, Buffer.t) = "PassThrough";
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
external finished:
  (subtype('ty), Js.nullable(Js.Exn.t) => unit) => cleanupFn =
  "finished";

[@bs.module "stream"]
external pipeline2:
  (
    subtype([> readable('t1)] as 'src),
    subtype([> writable('t1)] as 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  subtype([> writable('t1)] as 'dest) =
  "pipeline";

[@bs.module "stream"]
external pipeline3:
  (
    subtype([> readable('t1)] as 'src),
    subtype([> writable('t1) | readable('t2)] as 'kindA),
    subtype([> writable('t2)] as 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  subtype([> writable('t2) ] as 'dest) =
  "pipeline";
[@bs.module "stream"]
external pipeline4:
  (
    subtype([> readable('t1)] as 'src),
    subtype([> writable('t1) | readable('t2)] as 'kindA),
    subtype([> writable('t2) | readable('t3)] as 'kindA),
    subtype([> writable('t3)] as 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  subtype([> writable('t3)] as 'dest) =
  "pipeline";
