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
type socket = [ stream | `Socket];
type objectMode = [ stream | `ObjectMode];

type subtype('data, 'a) constraint 'a = [> stream];
type t('data) = subtype('data, stream);

module Base = {
  type kind = [ stream];
  type nonrec subtype('data, 'a) = subtype('data, 'a);
  module Events = {
    [@bs.send]
    external onError:
      (subtype('data, 'a) as 'stream, [@bs.as "error"] _, (. Js.Exn.t) => unit) => 'stream =
      "on";
    [@bs.send]
    external onClose:
      (subtype('data, 'a) as 'stream, [@bs.as "close"] _, (. unit) => unit) => 'stream =
      "on";
    [@bs.send]
    external offError:
      (subtype('data, 'a) as 'stream, [@bs.as "error"] _, (. Js.Exn.t) => unit) => 'stream =
      "off";
    [@bs.send]
    external offClose:
      (subtype('data, 'a) as 'stream, [@bs.as "close"] _, (. unit) => unit) => 'stream =
      "off";
    [@bs.send]
    external onErrorOnce:
      (subtype('data, 'a) as 'stream, [@bs.as "error"] _, (. Js.Exn.t) => unit) => 'stream =
      "once";
    [@bs.send]
    external onCloseOnce:
      (subtype('data, 'a) as 'stream, [@bs.as "close"] _, (. unit) => unit) => 'stream =
      "once";
    [@bs.send]
    external removeAllListeners: (subtype('data, 'a) as 'stream) => 'stream =
      "removeAllListeners";
  };
  module Impl = {
    include Events;
    [@bs.send] external destroy: (subtype('data, [> kind]) as 'stream) => 'stream = "destroy";
    [@bs.send]
    external destroyWithError: (subtype('data, [> kind]) as 'stream, Js.Exn.t) => 'stream =
      "destroy";
    [@bs.get] external destroyed: subtype('data, [> kind]) => bool = "destroyed";
  };
  include Impl;
};

module Readable = {
  type kind = [ readable];
  module Events = {
    include Base.Events;
    [@bs.send]
    external onData:
      (subtype('data, [> kind]) as 'rs, [@bs.as "data"] _, (. 'data) => unit) => 'rs =
      "on";
    [@bs.send]
    external onEnd: (subtype('data, [> kind]) as 'rs, [@bs.as "end"] _, (. unit) => unit) => 'rs =
      "on";
    [@bs.send]
    external onPause:
      (subtype('data, [> kind]) as 'rs, [@bs.as "pause"] _, (. unit) => unit) => 'rs =
      "on";
    [@bs.send]
    external onReadable:
      (subtype('data, [> kind]) as 'rs, [@bs.as "readable"] _, (. unit) => unit) => 'rs =
      "on";
    [@bs.send]
    external onResume:
      (subtype('data, [> kind]) as 'rs, [@bs.as "resume"] _, (. unit) => unit) => 'rs =
      "on";
    [@bs.send]
    external offData:
      (subtype('data, [> kind]) as 'rs, [@bs.as "data"] _, (. 'data) => unit) => 'rs =
      "off";
    [@bs.send]
    external offEnd: (subtype('data, [> kind]) as 'rs, [@bs.as "end"] _, (. unit) => unit) => 'rs =
      "off";
    [@bs.send]
    external offPause:
      (subtype('data, [> kind]) as 'rs, [@bs.as "pause"] _, (. unit) => unit) => 'rs =
      "off";
    [@bs.send]
    external offReadable:
      (subtype('data, [> kind]) as 'rs, [@bs.as "readable"] _, (. unit) => unit) => 'rs =
      "off";
    [@bs.send]
    external offResume:
      (subtype('data, [> kind]) as 'rs, [@bs.as "resume"] _, (. unit) => unit) => 'rs =
      "off";
    [@bs.send]
    external onDataOnce:
      (subtype('data, [> kind]) as 'rs, [@bs.as "data"] _, (. 'data) => unit) => 'rs =
      "once";
    [@bs.send]
    external onEndOnce:
      (subtype('data, [> kind]) as 'rs, [@bs.as "end"] _, (. unit) => unit) => 'rs =
      "once";
    [@bs.send]
    external onPauseOnce:
      (subtype('data, [> kind]) as 'rs, [@bs.as "pause"] _, (. unit) => unit) => 'rs =
      "once";
    [@bs.send]
    external onReadableOnce:
      (subtype('data, [> kind]) as 'rs, [@bs.as "readable"] _, (. unit) => unit) => 'rs =
      "once";
    [@bs.send]
    external onResumeOnce:
      (subtype('data, [> kind]) as 'rs, [@bs.as "resume"] _, (. unit) => unit) => 'rs =
      "once";
  };
  module Impl = {
    include Base.Impl;
    include Events;
    [@bs.send] external isPaused: subtype('data, [> kind]) => bool = "isPaused";
    [@bs.send] external pause: (subtype('data, [> kind]) as 'rs) => 'rs = "isPaused";
    [@bs.send]
    external pipe: (subtype('data, [> kind]), subtype('data, [> writable]) as 'ws) => 'ws =
      "pipe";
    [@bs.send]
    external unpipe: (subtype('data, [> kind]) as 'rs, subtype('data, [> writable])) => 'rs =
      "unpipe";
    [@bs.send] external read: subtype('data, [> kind]) => Js.nullable('data) = "read";
    [@bs.send] external readSize: (subtype('data, [> kind]), int) => Js.nullable('data) = "read";
    [@bs.get] external readable: subtype('data, [> kind]) => bool = "readable";
    [@bs.get]
    external readableEncoding: subtype('data, [> kind]) => Js.nullable(string) =
      "readableEncoding";
    [@bs.get] external readableEnded: subtype('data, [> kind]) => bool = "readableEnded";
    [@bs.get] external readableFlowing: subtype('data, [> kind]) => bool = "readableFlowing";
    [@bs.get]
    external readableHighWaterMark: subtype('data, [> kind]) => int = "readableHighWaterMark";
    [@bs.get] external readableLength: subtype('data, [> kind]) => int = "readableLength";
    [@bs.get]
    external readableObjectMode: subtype('data, [> kind]) => bool = "readableObjectMode";
    [@bs.send] external resume: (subtype('data, [> kind]) as 'rs) => 'rs = "resume";
    [@bs.send] external unshift: (subtype('data, [> kind]), 'data) => unit = "unshift";
  };
  include Impl;
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec t('data) = subtype('data, kind);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Readable";
};

module Writable = {
  type kind = [ writable];
  module Events = {
    [@bs.send]
    external onDrain:
      (subtype('data, [> kind]) as 'ws, [@bs.as "drain"] _, (. unit) => unit) => 'ws =
      "on";
    [@bs.send]
    external onFinish:
      (subtype('data, [> kind]) as 'ws, [@bs.as "finish"] _, (. unit) => unit) => 'ws =
      "on";
    [@bs.send]
    external onPipe:
      (
        subtype('data, [> kind]) as 'ws,
        [@bs.as "pipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      'ws =
      "on";
    [@bs.send]
    external onUnpipe:
      (
        subtype('data, [> kind]) as 'ws,
        [@bs.as "unpipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      'ws =
      "on";
    [@bs.send]
    external offDrain:
      (subtype('data, [> kind]) as 'ws, [@bs.as "drain"] _, (. unit) => unit) => 'ws =
      "off";
    [@bs.send]
    external offFinish:
      (subtype('data, [> kind]) as 'ws, [@bs.as "finish"] _, (. unit) => unit) => 'ws =
      "off";
    [@bs.send]
    external offPipe:
      (
        subtype('data, [> kind]) as 'ws,
        [@bs.as "pipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      'ws =
      "off";
    [@bs.send]
    external offUnpipe:
      (
        subtype('data, [> kind]) as 'ws,
        [@bs.as "unpipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      'ws =
      "off";
    [@bs.send]
    external onDrainOnce:
      (subtype('data, [> kind]) as 'ws, [@bs.as "drain"] _, (. unit) => unit) => 'ws =
      "once";
    [@bs.send]
    external onFinishOnce:
      (subtype('data, [> kind]) as 'ws, [@bs.as "finish"] _, (. unit) => unit) => 'ws =
      "once";
    [@bs.send]
    external onPipeOnce:
      (
        subtype('data, [> kind]) as 'ws,
        [@bs.as "pipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      'ws =
      "once";
    [@bs.send]
    external onUnpipeOnce:
      (
        subtype('data, [> kind]) as 'ws,
        [@bs.as "unpipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      'ws =
      "once";
  };
  module Impl = {
    include Base.Impl;
    include Events;
    [@bs.send] external cork: subtype('data, [> kind]) => unit = "cork";
    [@bs.send] external uncork: subtype('data, [> kind]) => unit = "uncork";
    [@bs.send] external end_: subtype('data, [> kind]) => unit = "end";
    [@bs.send] external write: (subtype('data, [> kind]), 'data) => bool = "write";
    [@bs.send]
    external writeWith:
      (
        subtype('data, [> kind] as 'a),
        'data,
        ~callback: Js.Nullable.t(Js.Exn.t) => unit=?,
        unit
      ) =>
      bool =
      "write";
    [@bs.get] external writable: subtype('data, [> kind]) => bool = "writable";
    [@bs.get] external writableEnded: subtype('data, [> kind]) => bool = "writableEnded";
    [@bs.get] external writableCorked: subtype('data, [> kind]) => bool = "writableCorked";
    [@bs.get] external writableFinished: subtype('data, [> kind]) => bool = "writableFinished";
    [@bs.get] external writableLength: subtype('data, [> kind]) => int = "writableLength";
    [@bs.get]
    external writableHighWaterMark: subtype('data, [> kind]) => int = "writableHighWaterMark";
    [@bs.get]
    external writableObjectMode: subtype('data, [> kind]) => bool = "writableObjectMode";
  };
  include Impl;
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec t('data) = subtype('data, kind);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Writable";
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
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec t('data) = subtype('data, kind);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Duplex";
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
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec t('data) = subtype('data, kind);
  type makeOptions;
  [@bs.obj]
  external makeOptions:
    (
      ~transform: [@bs.this] (t(Buffer.t), Buffer.t, (. Js.nullable(Js.Exn.t), Js.nullable(Buffer.t)) => unit) => unit,
      ~flush: [@bs.this] (t(Buffer.t), Js.nullable(Js.Exn.t), Buffer.t) => unit
    ) =>
    makeOptions;
  [@bs.module "stream"] [@bs.new]
  external makeWith: (~options: makeOptions) => t(Buffer.t) = "Transform";
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
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec t('data) = subtype('data, kind);
  [@bs.module "stream"] [@bs.new] external make: unit => t('data) = "PassThrough";
};

module Events = {
  include Base.Events;
  include Readable.Events;
  include Writable.Events;
};
include Base.Impl;
include Readable.Impl;
include Writable.Impl;
include Events;

type cleanupFn = unit => unit;

[@bs.module "stream"]
external finished: (subtype('data, 'a), Js.nullable(Js.Exn.t) => unit) => cleanupFn = "finished";

[@bs.module "stream"]
external pipeline0:
  (Readable.subtype(Buffer.t, 'src), Writable.subtype(Buffer.t, 'dest), Js.nullable(Js.Exn.t) => unit) =>
  Writable.subtype(Buffer.t, 'dest) =
  "pipeline";

[@bs.module "stream"]
external pipeline1:
  (
    Readable.subtype(Buffer.t, 'src),
    Duplex.subtype(Buffer.t, 'kind1),
    Writable.subtype(Buffer.t, 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  Writable.subtype(Buffer.t, 'dest) =
  "pipeline";

[@bs.module "stream"]
external pipeline2:
  (
    Readable.subtype(Buffer.t, 'src),
    Duplex.subtype(Buffer.t, 'kind1),
    Duplex.subtype(Buffer.t, 'kind2),
    Writable.subtype(Buffer.t, 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  Writable.subtype(Buffer.t, 'dest) =
  "pipeline";

[@bs.module "stream"]
external pipeline3:
  (
    Readable.subtype(Buffer.t, 'src),
    Duplex.subtype(Buffer.t, 'kind1),
    Duplex.subtype(Buffer.t, 'kind2),
    Duplex.subtype(Buffer.t, 'kind3),
    Writable.subtype(Buffer.t, 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  Writable.subtype(Buffer.t, 'dest) =
  "pipeline";

[@bs.module "stream"]
external pipeline4:
  (
    Readable.subtype(Buffer.t, 'src),
    Duplex.subtype(Buffer.t, 'kind1),
    Duplex.subtype(Buffer.t, 'kind2),
    Duplex.subtype(Buffer.t, 'kind3),
    Duplex.subtype(Buffer.t, 'kind4),
    Writable.subtype(Buffer.t, 'dest),
    Js.nullable(Js.Exn.t) => unit
  ) =>
  Writable.subtype(Buffer.t, 'dest) =
  "pipeline";
