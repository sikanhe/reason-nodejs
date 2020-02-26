
type t('a);
type readable = [ `Readable ];
type writable = [ `Writable ];
type duplex = [ readable | writable ];
type transform = [ duplex | `Transform ];
type passThrough = [ transform | `PassThrough ];

module Base = {
  module Impl = {
    [@bs.send] external onError: (t('a), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
    [@bs.send] external onClose: (t('a), [@bs.as "close"] _, unit => unit) => unit = "on";
  }
  include Impl;
};

module Readable = {
  type kind = [ readable ];
  module Impl = {
    include Base.Impl;
    [@bs.send] external onData: (t([> readable ]), [@bs.as "data"] _, Buffer.t => unit) => unit = "on";
    [@bs.send] external onEnd: (t([> readable ]), [@bs.as "end"] _, unit => unit) => unit = "on";
    [@bs.send] external pipe: (t([> readable ]), t([> writable ]) as 'a) => 'a = "pipe";
    [@bs.send] external unpipe: (t([> readable ]) as 'a, t([> writable ])) => 'a = "unpipe";
  };
  [@bs.module "stream"] [@bs.new] external make: unit => t([> readable ]) = "Readable";
  include Impl;
};

module Writable = {
  type kind = [ writable ];
  module Impl = {
    include Base.Impl;
    [@bs.send] external onDrain: (t([> writable ]), [@bs.as "drain"] _, unit => unit) => unit = "on";
    [@bs.send] external onFinish: (t([> writable ]), [@bs.as "finish"] _, unit => unit) => unit = "on";
    [@bs.send] external onPipe: (t([> writable ]), [@bs.as "pipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external onUnpipe: (t([> writable ]), [@bs.as "unpipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external cork: t([> writable ]) => unit = "cork";
    [@bs.send] external uncork: t([> writable ]) => unit = "uncork";
    [@bs.send] external destroy: t([> writable ]) => unit = "destroy";
    [@bs.send] external destroyWithError: (t([> writable ]), Js.Exn.t) => unit = "destroy";
    [@bs.get] external destroyed: t([> writable ]) => bool = "destroy";
    [@bs.send] external end_: t([> writable ]) => unit = "end";
    [@bs.send] external write: ( t([> writable ]), Buffer.t) => bool = "write";
    [@bs.send] external writeWith: (t([> writable ]), Buffer.t, ~callback: Js.Nullable.t(Js.Exn.t) => unit=?, unit) => bool = "write";
    [@bs.get] external writable: t([> writable ]) => bool = "writable";
    [@bs.get] external writableEnded: t([> writable ]) => bool = "writableEnded";
    [@bs.get] external writableCorked: t([> writable ]) => bool = "writableCorked";
    [@bs.get] external writableFinished: t([> writable ]) => bool = "writableFinished";
    [@bs.get] external writableLength: t([> writable ]) => int = "writableLength";
    [@bs.get] external writableHighWaterMark: t([> writable ]) => int = "writableHighWaterMark";
    [@bs.get] external writableObjectMode: t([> writable ]) => bool = "writableObjectMode";
  };
  [@bs.module "stream"] [@bs.new] external make: unit => t([ writable ]) = "Writable";
  include Impl;
};

module Duplex = {
  type kind = [ duplex ];
  [@bs.module "stream"] [@bs.new] external make: unit => t([ duplex ]) = "Duplex";
  module Impl = {
    include Readable.Impl;
    include Writable.Impl;
  };
  type nonrec t = t([ duplex ]);
};

module Transform = {
  type kind = [ transform ];
  type nonrec t = t([ transform ]);

  module Impl = {
    include Duplex.Impl;
  }

  type makeOptions;

  [@bs.obj] external makeOptions: (
    ~transform: (
        ~chunk: Buffer.t,
        ~encoding: string,
        ~callback: (option(Js.Exn.t), Buffer.t) => unit
      ) => Buffer.t,
    ~flush: (option(Js.Exn.t), Buffer.t) => unit
  ) => makeOptions = "";

  [@bs.module "stream"] [@bs.new] external make: unit => t = "Transform";
  [@bs.module "stream"] [@bs.new] external makeWith: (~options: makeOptions) => t = "Transform";

};

module PassThrough = {
  include Transform.Impl;
  type kind = [ passThrough ];
  type nonrec t = t([ passThrough ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t = "PassThrough";
};

include Base.Impl;
include Readable.Impl;
include Writable.Impl;

[@bs.send] external onError: (t('a), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
[@bs.send] external onClose: (t('a), [@bs.as "close"] _, unit => unit) => unit = "on";
[@unboxed] type cleanup = {unsubscribe: unit => unit};
[@bs.module "stream"] [@bs.val] external finished: (t('a), option(Js.Exn.t) => unit) => cleanup = "finished";