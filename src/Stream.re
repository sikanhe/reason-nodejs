/**
 * This section contains most of polymorphic variant constraints
 * corresponding to the various subtypes of `Stream.t` throughout this library.
 */
type readable = [ `Readable ];
type writable = [ `Writable ];
type duplex = [ readable | writable ];
type transform = [ duplex | `Transform ];
type passThrough = [ transform | `PassThrough ];
type socket = [ `Socket ];
type objectMode = [ `ObjectMode ];

type t('data, 'a);
type subtype('data, 'a) = t('data, [> ] as 'a);
type objectStream('data, 'a) = t('data, [> objectMode ] as 'a);

module Base = {
  module Events = {
    [@bs.send] external onError: (subtype('data, 'a), [@bs.as "error"] _, (. Js.Exn.t) => unit) => t('data, 'a) = "on";
    [@bs.send] external onClose: (subtype('data, 'a), [@bs.as "close"] _, (. unit) => unit) => t('data, 'a) = "on";
    [@bs.send] external offError: (subtype('data, 'a), [@bs.as "error"] _, (. Js.Exn.t) => unit) => t('data, 'a) = "off";
    [@bs.send] external offClose: (subtype('data, 'a), [@bs.as "close"] _, (. unit) => unit) => t('data, 'a) = "off";
    [@bs.send] external onErrorOnce: (subtype('data, 'a), [@bs.as "error"] _, (. Js.Exn.t) => unit) => t('data, 'a) = "once";
    [@bs.send] external onCloseOnce: (subtype('data, 'a), [@bs.as "close"] _, (. unit) => unit) => t('data, 'a) = "once";
    [@bs.send] external removeAllListeners: subtype('data, 'a) => t('data, 'a) = "removeAllListeners";
  };
  module Impl = {
    include Events;
  };
  include Impl;
};

module Readable = {
  type kind = [ readable ];
  type subtype('data, 'a) = t('data, [> kind ] as 'a);
  type supertype('data, 'a) = t('data, [< kind ] as 'a);
  module Events = {
    include Base.Events;
    [@bs.send] external onData: (subtype('data, 'a), [@bs.as "data"] _, (. 'data) => unit) => subtype('data, 'a) = "on";
    [@bs.send] external onEnd: (subtype('data, 'a), [@bs.as "end"] _, (. unit) => unit) => subtype('data, 'a) = "on";
    [@bs.send] external onPause: (subtype('data, 'a), [@bs.as "pause"] _, (. unit) => unit) => subtype('data, 'a) = "on";
    [@bs.send] external onReadable: (subtype('data, 'a), [@bs.as "readable"] _, (. unit) => unit) => subtype('data, 'a) = "on";
    [@bs.send] external offData: (subtype('data, 'a), [@bs.as "data"] _, (. 'data) => unit) => subtype('data, 'a) = "off";
    [@bs.send] external offEnd: (subtype('data, 'a), [@bs.as "end"] _, (. unit) => unit) => subtype('data, 'a) = "off";
    [@bs.send] external offPause: (subtype('data, 'a), [@bs.as "pause"] _, (. unit) => unit) => subtype('data, 'a) = "off";
    [@bs.send] external offReadable: (subtype('data, 'a), [@bs.as "readable"] _, (. unit) => unit) => subtype('data, 'a) = "off";
    [@bs.send] external onDataOnce: (subtype('data, 'a), [@bs.as "data"] _, (. 'data) => unit) => subtype('data, 'a) = "once";
    [@bs.send] external onEndOnce: (subtype('data, 'a), [@bs.as "end"] _, (. unit) => unit) => subtype('data, 'a) = "once";
    [@bs.send] external onPauseOnce: (subtype('data, 'a), [@bs.as "pause"] _, (. unit) => unit) => subtype('data, 'a) = "once";
    [@bs.send] external onReadableOnce: (subtype('data, 'a), [@bs.as "readable"] _, (. unit) => unit) => subtype('data, 'a) = "once";
  };
  module Impl = {
    include Base.Impl;
    include Events;
    [@bs.send] external pipe: (subtype('data, 'a), t('data, [> writable ]) as 'ws) => 'ws = "pipe";
    [@bs.send] external unpipe: (subtype('data, 'a) as 'rs, t('data, [> writable ])) => 'rs = "unpipe";
  };
  include Impl;
  type nonrec t('data) = subtype('data, kind);
  type nonrec objectStream('data) = subtype('data, [ kind | objectMode ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Readable";
};

module Writable = {
  type kind = [ writable ];
  type subtype('data, 'a) = t('data, [> kind ] as 'a);
  type supertype('data, 'a) = t('data, [< kind ] as 'a);
  module Events = {
    [@bs.send] external onDrain: (subtype('data, 'a), [@bs.as "drain"] _, (. unit) => unit) => subtype('data, 'a) = "on";
    [@bs.send] external onFinish: (subtype('data, 'a), [@bs.as "finish"] _, (. unit) => unit) => subtype('data, 'a) = "on";
    [@bs.send] external onPipe: (subtype('data, 'a), [@bs.as "pipe"] _, (. t('data, [> readable])) => unit) => subtype('data, 'a) = "on";
    [@bs.send] external onUnpipe: (subtype('data, 'a), [@bs.as "unpipe"] _, (. t('data, [> readable])) => unit) => subtype('data, 'a) = "on";
    [@bs.send] external offDrain: (subtype('data, 'a), [@bs.as "drain"] _, (. unit) => unit) => subtype('data, 'a) = "off";
    [@bs.send] external offFinish: (subtype('data, 'a), [@bs.as "finish"] _, (. unit) => unit) => subtype('data, 'a) = "off";
    [@bs.send] external offPipe: (subtype('data, 'a), [@bs.as "pipe"] _, (. t('data, [> readable])) => unit) => subtype('data, 'a) = "off";
    [@bs.send] external offUnpipe: (subtype('data, 'a), [@bs.as "unpipe"] _, (. t('data, [> readable])) => unit) => subtype('data, 'a) = "off";
    [@bs.send] external onDrainOnce: (subtype('data, 'a), [@bs.as "drain"] _, (. unit) => unit) => subtype('data, 'a) = "once";
    [@bs.send] external onFinishOnce: (subtype('data, 'a), [@bs.as "finish"] _, (. unit) => unit) => subtype('data, 'a) = "once";
    [@bs.send] external onPipeOnce: (subtype('data, 'a), [@bs.as "pipe"] _, (. t('data, [> readable])) => unit) => subtype('data, 'a) = "once";
    [@bs.send] external onUnpipeOnce: (subtype('data, 'a), [@bs.as "unpipe"] _, (. t('data, [> readable])) => unit) => subtype('data, 'a) = "once";
  };
  module Impl = {
    include Base.Impl;
    include Events;
    [@bs.send] external cork: subtype('data, 'a) => unit = "cork";
    [@bs.send] external uncork: subtype('data, 'a) => unit = "uncork";
    [@bs.send] external destroy: subtype('data, 'a) => unit = "destroy";
    [@bs.send] external destroyWithError: (subtype('data, 'a), Js.Exn.t) => unit = "destroy";
    [@bs.get] external destroyed: subtype('data, 'a) => bool = "destroy";
    [@bs.send] external end_: subtype('data, 'a) => unit = "end";
    [@bs.send] external write: (subtype('data, 'a), 'data) => bool = "write";
    [@bs.send] external writeWith: (subtype('data, 'a), 'data , ~callback: Js.Nullable.t(Js.Exn.t) => unit=?, unit) => bool = "write";
    [@bs.get] external writable: subtype('data, 'a) => bool = "writable";
    [@bs.get] external writableEnded: subtype('data, 'a) => bool = "writableEnded";
    [@bs.get] external writableCorked: subtype('data, 'a) => bool = "writableCorked";
    [@bs.get] external writableFinished: subtype('data, 'a) => bool = "writableFinished";
    [@bs.get] external writableLength: subtype('data, 'a) => int = "writableLength";
    [@bs.get] external writableHighWaterMark: subtype('data, 'a) => int = "writableHighWaterMark";
    [@bs.get] external writableObjectMode: subtype('data, 'a) => bool = "writableObjectMode";

  };
  include Impl;
  type nonrec t('data) = subtype('data, kind);
  type nonrec objectStream('data) = subtype('data, [ kind | objectMode ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Writable";
};

module Duplex = {
  type kind = [ duplex ];
  type subtype('data, 'a) = t('data, [> kind ] as 'a);
  type supertype('data, 'a) = t('data, [< kind ] as 'a);
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
  type nonrec t('data) = subtype('data, kind);
  type nonrec objectStream('data) = subtype('data, [ kind | objectMode ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Duplex";
};

module Transform = {
  type kind = [ transform ];
  type subtype('data, 'a) = t('data, [> kind ] as 'a);
  type supertype('data, 'a) = t('data, [< kind ] as 'a);
  module Events = {
    include Duplex.Events;
  };
  module Impl = {
    include Duplex.Impl;
    include Events;
  };
  include Impl;
  type nonrec t('data) = subtype('data, kind);
  type nonrec objectStream('data) = subtype('data, [ kind | objectMode ]);
  type makeOptions;
  [@bs.obj] external makeOptions: (
    ~transform: (
        ~chunk: Buffer.t,
        ~callback: (. option(Js.Exn.t), Buffer.t) => unit
      ) => Buffer.t,
    ~flush: (option(Js.Exn.t), Buffer.t) => unit
  ) => makeOptions = "";
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Transform";
  [@bs.module "stream"] [@bs.new] external makeWith: (~options: makeOptions) => t(Buffer.t) = "Transform";
};

module PassThrough = {
  type kind = [ passThrough ];
  type subtype('data, 'a) = t('data, [> kind ] as 'a);
  type supertype('data, 'a) = t('data, [< kind ] as 'a);
  module Events = {
    include Transform.Events;
  };
  module Impl = {
    include Transform.Impl;
    include Events;
  };
  include Impl;
  type nonrec t('data) = subtype('data, kind);
  type nonrec objectStream('data) = subtype('data, [ kind | objectMode ]);
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
[@bs.module "stream"] [@bs.val] external finished: (t('data, [> ]), option(Js.Exn.t) => unit) => cleanupFn = "finished";