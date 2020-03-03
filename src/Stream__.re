
type t('a, 'ty);
type readable = [ `Readable ];
type writable = [ `Writable ];
type duplex = [ readable | writable ];
type transform = [ duplex | `Transform ];
type passThrough = [ transform | `PassThrough ];

module Base = {
  module Impl = {
    [@bs.send] external onError: (t('a, [> ]), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
    [@bs.send] external onClose: (t('a, [> ]), [@bs.as "close"] _, unit => unit) => unit = "on";
  }
  include Impl;
};

module Readable = {
  type kind = [ readable ];
  module Impl = {
    include Base.Impl;
    [@bs.send] external onData: (t('data, [> readable ]), [@bs.as "data"] _, 'data => unit) => unit = "on";
    [@bs.send] external onEnd: (t('data, [> readable ]), [@bs.as "end"] _, unit => unit) => unit = "on";
    [@bs.send] external pipe: (t('data, [> readable ]), t('data, [> writable ]) as 'a) => 'a = "pipe";
    [@bs.send] external unpipe: (t('data, [> readable ]) as 'a, t('data, [> writable ])) => 'a = "unpipe";
  };
  [@bs.module "stream"] [@bs.new] external make: unit => t([> readable ], Buffer.t) = "Readable";
  include Impl;
};

module Writable = {
  type kind = [ writable ];
  module Impl = {
    include Base.Impl;
    [@bs.send] external onDrain: (t('data, [> writable ]), [@bs.as "drain"] _, unit => unit) => unit = "on";
    [@bs.send] external onFinish: (t('data, [> writable ]), [@bs.as "finish"] _, unit => unit) => unit = "on";
    [@bs.send] external onPipe: (t('data, [> writable ]), [@bs.as "pipe"] _, t('data, [> readable]) => unit) => unit = "on";
    [@bs.send] external onUnpipe: (t('data, [> writable ]), [@bs.as "unpipe"] _, t('data, [> readable]) => unit) => unit = "on";
    [@bs.send] external cork: t('data, [> writable ]) => unit = "cork";
    [@bs.send] external uncork: t('data, [> writable ]) => unit = "uncork";
    [@bs.send] external destroy: t('data, [> writable ]) => unit = "destroy";
    [@bs.send] external destroyWithError: (t('data, [> writable ]), Js.Exn.t) => unit = "destroy";
    [@bs.get] external destroyed: t('data, [> writable ]) => bool = "destroy";
    [@bs.send] external end_: t('data, [> writable ]) => unit = "end";
    [@bs.send] external write: (t('data, [> writable ])) => bool = "write";
    [@bs.send] external writeWith: (t('data, [> writable ]), ~callback: Js.Nullable.t(Js.Exn.t) => unit=?, unit) => bool = "write";
    [@bs.get] external writable: t('data, [> writable ]) => bool = "writable";
    [@bs.get] external writableEnded: t('data, [> writable ]) => bool = "writableEnded";
    [@bs.get] external writableCorked: t('data, [> writable ]) => bool = "writableCorked";
    [@bs.get] external writableFinished: t('data, [> writable ]) => bool = "writableFinished";
    [@bs.get] external writableLength: t('data, [> writable ]) => int = "writableLength";
    [@bs.get] external writableHighWaterMark: t('data, [> writable ]) => int = "writableHighWaterMark";
    [@bs.get] external writableObjectMode: t('data, [> writable ]) => bool = "writableObjectMode";
  };
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t, [ writable ]) = "Writable";
  include Impl;
};

module Duplex = {
  type kind = [ duplex ];
  [@bs.module "stream"] [@bs.new] external make: unit => t([ duplex ], Buffer.t) = "Duplex";
  module Impl = {
    include Readable.Impl;
    include Writable.Impl;
  };
  type nonrec t('data) = t('data, [ duplex ]);
};

module Transform = {
  type kind = [ transform ];

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

  type nonrec t('data) = t('data, [ transform ]);

  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Transform";
  [@bs.module "stream"] [@bs.new] external makeWith: (~options: makeOptions) => t(Buffer.t) = "Transform";

};

module PassThrough = {
  include Transform.Impl;
  type kind = [ passThrough ];
  type nonrec t('data) = t('data, [ passThrough ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t('data) = "PassThrough";
};

include Base.Impl;
include Readable.Impl;
include Writable.Impl;

[@bs.send] external onError: (t('data, [> ]), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
[@bs.send] external onClose: (t('data, [> ]), [@bs.as "close"] _, unit => unit) => unit = "on";
[@unboxed] type cleanup = {unsubscribe: unit => unit};
[@bs.module "stream"] [@bs.val] external finished: (t('data, [> ]), option(Js.Exn.t) => unit) => cleanup = "finished";
let test = onError;