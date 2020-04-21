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
  module Events = {
    [@bs.send]
    external onError:
      (subtype('data, 'a), [@bs.as "error"] _, (. Js.Exn.t) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external onClose:
      (subtype('data, 'a), [@bs.as "close"] _, (. unit) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external offError:
      (subtype('data, 'a), [@bs.as "error"] _, (. Js.Exn.t) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external offClose:
      (subtype('data, 'a), [@bs.as "close"] _, (. unit) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external onErrorOnce:
      (subtype('data, 'a), [@bs.as "error"] _, (. Js.Exn.t) => unit) => subtype('data, 'a) =
      "once";
    [@bs.send]
    external onCloseOnce:
      (subtype('data, 'a), [@bs.as "close"] _, (. unit) => unit) => subtype('data, 'a) =
      "once";
    [@bs.send]
    external removeAllListeners: subtype('data, 'a) => subtype('data, 'a) = "removeAllListeners";
  };
  module Impl = {
    include Events;
  };
  include Impl;
};

module Readable = {
  type kind = [ readable];
  module Events = {
    include Base.Events;
    [@bs.send]
    external onData:
      (subtype('data, [> kind] as 'a), [@bs.as "data"] _, (. 'data) => unit) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external onEnd:
      (subtype('data, [> kind] as 'a), [@bs.as "end"] _, (. unit) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external onPause:
      (subtype('data, [> kind] as 'a), [@bs.as "pause"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external onReadable:
      (subtype('data, [> kind] as 'a), [@bs.as "readable"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external onResume:
      (subtype('data, [> kind] as 'a), [@bs.as "resume"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external offData:
      (subtype('data, [> kind] as 'a), [@bs.as "data"] _, (. 'data) => unit) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external offEnd:
      (subtype('data, [> kind] as 'a), [@bs.as "end"] _, (. unit) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external offPause:
      (subtype('data, [> kind] as 'a), [@bs.as "pause"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external offReadable:
      (subtype('data, [> kind] as 'a), [@bs.as "readable"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external offResume:
      (subtype('data, [> kind] as 'a), [@bs.as "resume"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external onDataOnce:
      (subtype('data, [> kind] as 'a), [@bs.as "data"] _, (. 'data) => unit) =>
      subtype('data, 'a) =
      "once";
    [@bs.send]
    external onEndOnce:
      (subtype('data, [> kind] as 'a), [@bs.as "end"] _, (. unit) => unit) => subtype('data, 'a) =
      "once";
    [@bs.send]
    external onPauseOnce:
      (subtype('data, [> kind] as 'a), [@bs.as "pause"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "once";
    [@bs.send]
    external onReadableOnce:
      (subtype('data, [> kind] as 'a), [@bs.as "readable"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "once";
    [@bs.send]
    external onResumeOnce:
      (subtype('data, [> kind] as 'a), [@bs.as "resume"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "once";
  };
  module Impl = {
    include Base.Impl;
    include Events;
    [@bs.send]
    external pipe: (subtype('data, [> kind] as 'a), subtype('data, [> writable]) as 'ws) => 'ws =
      "pipe";
    [@bs.send]
    external unpipe: (subtype('data, [> kind] as 'a) as 'rs, subtype('data, [> writable])) => 'rs =
      "unpipe";
  };
  include Impl;
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
  type nonrec t('data) = subtype('data, kind);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Readable";
};

module Writable = {
  type kind = [ writable];
  module Events = {
    [@bs.send]
    external onDrain:
      (subtype('data, [> kind] as 'a), [@bs.as "drain"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external onFinish:
      (subtype('data, [> kind] as 'a), [@bs.as "finish"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external onPipe:
      (
        subtype('data, [> kind] as 'a),
        [@bs.as "pipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external onUnpipe:
      (
        subtype('data, [> kind] as 'a),
        [@bs.as "unpipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external offDrain:
      (subtype('data, [> kind] as 'a), [@bs.as "drain"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external offFinish:
      (subtype('data, [> kind] as 'a), [@bs.as "finish"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external offPipe:
      (
        subtype('data, [> kind] as 'a),
        [@bs.as "pipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external offUnpipe:
      (
        subtype('data, [> kind] as 'a),
        [@bs.as "unpipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external onDrainOnce:
      (subtype('data, [> kind] as 'a), [@bs.as "drain"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "once";
    [@bs.send]
    external onFinishOnce:
      (subtype('data, [> kind] as 'a), [@bs.as "finish"] _, (. unit) => unit) =>
      subtype('data, 'a) =
      "once";
    [@bs.send]
    external onPipeOnce:
      (
        subtype('data, [> kind] as 'a),
        [@bs.as "pipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      subtype('data, 'a) =
      "once";
    [@bs.send]
    external onUnpipeOnce:
      (
        subtype('data, [> kind] as 'a),
        [@bs.as "unpipe"] _,
        (. subtype('data, [> readable])) => unit
      ) =>
      subtype('data, 'a) =
      "once";
  };
  module Impl = {
    include Base.Impl;
    include Events;
    [@bs.send] external cork: subtype('data, [> kind] as 'a) => unit = "cork";
    [@bs.send] external uncork: subtype('data, [> kind] as 'a) => unit = "uncork";
    [@bs.send] external destroy: subtype('data, [> kind] as 'a) => unit = "destroy";
    [@bs.send]
    external destroyWithError: (subtype('data, [> kind] as 'a), Js.Exn.t) => unit = "destroy";
    [@bs.get] external destroyed: subtype('data, [> kind] as 'a) => bool = "destroy";
    [@bs.send] external end_: subtype('data, [> kind] as 'a) => unit = "end";
    [@bs.send] external write: (subtype('data, [> kind] as 'a), 'data) => bool = "write";
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
    [@bs.get] external writable: subtype('data, [> kind] as 'a) => bool = "writable";
    [@bs.get] external writableEnded: subtype('data, [> kind] as 'a) => bool = "writableEnded";
    [@bs.get] external writableCorked: subtype('data, [> kind] as 'a) => bool = "writableCorked";
    [@bs.get]
    external writableFinished: subtype('data, [> kind] as 'a) => bool = "writableFinished";
    [@bs.get] external writableLength: subtype('data, [> kind] as 'a) => int = "writableLength";
    [@bs.get]
    external writableHighWaterMark: subtype('data, [> kind] as 'a) => int =
      "writableHighWaterMark";
    [@bs.get]
    external writableObjectMode: subtype('data, [> kind] as 'a) => bool = "writableObjectMode";
  };
  include Impl;
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
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
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
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
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
  type nonrec t('data) = subtype('data, kind);
  type makeOptions;
  [@bs.obj]
  external makeOptions:
    (
      ~transform: (~chunk: Buffer.t, ~callback: (. option(Js.Exn.t), Buffer.t) => unit) => Buffer.t,
      ~flush: (option(Js.Exn.t), Buffer.t) => unit
    ) =>
    makeOptions;
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Transform";
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
  type nonrec subtype('data, 'a) = subtype('data, [> kind] as 'a);
  type nonrec supertype('data, 'a) = subtype('data, [< kind] as 'a);
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
[@bs.module "stream"] [@bs.val]
external finished: (subtype('data, [> ]), option(Js.Exn.t) => unit) => cleanupFn = "finished";
