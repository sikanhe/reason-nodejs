type readable = [ `Readable ];
type writable = [ `Writable ];
type duplex = [ readable | writable ];
type transform = [ duplex | `Transform ];
type passThrough = [ transform | `PassThrough ];
type objectMode = [ `ObjectMode ];

type t('data, 'ty);
type subtype('data, 'ty) = t('data, [> ] as 'ty);
type objectStream('data, 'ty) = t('data, [> objectMode ] as 'ty);

module Base = {
  module Impl = {
    [@bs.send] external onError: (t('data, [> ]), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
    [@bs.send] external onClose: (t('data, [> ]), [@bs.as "close"] _, unit => unit) => unit = "on";
  }
  include Impl;
};

module Readable = {
  type kind = [ readable ];
  type subtype('data, 'ty) = t('data, [> kind ] as 'ty);
  type supertype('data, 'ty) = t('data, [< kind ] as 'ty);
  module Impl = {
    include Base.Impl;
    [@bs.send] external onData: (subtype('data, 'ty), [@bs.as "data"] _, 'data => unit) => unit = "on";
    [@bs.send] external onEnd: (subtype('data, 'ty), [@bs.as "end"] _, unit => unit) => unit = "on";
    [@bs.send] external pipe: (subtype('data, 'ty), t('data, [> writable ]) as 'a) => 'a = "pipe";
    [@bs.send] external unpipe: (subtype('data, 'ty) as 'a, t('data, [> writable ])) => 'a = "unpipe";
  };
  include Impl;
  type nonrec t('data) = subtype('data, kind);
  type nonrec objectStream('data) = objectStream('data, [ readable | objectMode ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Readable";
};

let test = Readable.make();
Readable.onData(test, ignore);

module Writable = {
  type kind = [ writable ];
  type subtype('data, 'ty) = t('data, [> kind ] as 'ty);
  type supertype('data, 'ty) = t('data, [< kind ] as 'ty);
  module Impl = {
    include Base.Impl;
    [@bs.send] external onDrain: (subtype('data, 'ty), [@bs.as "drain"] _, unit => unit) => unit = "on";
    [@bs.send] external onFinish: (subtype('data, 'ty), [@bs.as "finish"] _, unit => unit) => unit = "on";
    [@bs.send] external onPipe: (subtype('data, 'ty), [@bs.as "pipe"] _, t('data, [> readable]) => unit) => unit = "on";
    [@bs.send] external onUnpipe: (subtype('data, 'ty), [@bs.as "unpipe"] _, t('data, [> readable]) => unit) => unit = "on";
    [@bs.send] external cork: subtype('data, 'ty) => unit = "cork";
    [@bs.send] external uncork: subtype('data, 'ty) => unit = "uncork";
    [@bs.send] external destroy: subtype('data, 'ty) => unit = "destroy";
    [@bs.send] external destroyWithError: (subtype('data, 'ty), Js.Exn.t) => unit = "destroy";
    [@bs.get] external destroyed: subtype('data, 'ty) => bool = "destroy";
    [@bs.send] external end_: subtype('data, 'ty) => unit = "end";
    [@bs.send] external write: (subtype('data, 'ty), 'data) => bool = "write";
    [@bs.send] external writeWith: (subtype('data, 'ty), 'data , ~callback: Js.Nullable.t(Js.Exn.t) => unit=?, unit) => bool = "write";
    [@bs.get] external writable: subtype('data, 'ty) => bool = "writable";
    [@bs.get] external writableEnded: subtype('data, 'ty) => bool = "writableEnded";
    [@bs.get] external writableCorked: subtype('data, 'ty) => bool = "writableCorked";
    [@bs.get] external writableFinished: subtype('data, 'ty) => bool = "writableFinished";
    [@bs.get] external writableLength: subtype('data, 'ty) => int = "writableLength";
    [@bs.get] external writableHighWaterMark: subtype('data, 'ty) => int = "writableHighWaterMark";
    [@bs.get] external writableObjectMode: subtype('data, 'ty) => bool = "writableObjectMode";
  };
  include Impl;
  type nonrec t('data) = subtype('data, kind);
  type nonrec objectStream('data) = objectStream('data, [ writable | objectMode ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Writable";

};

module Duplex = {
  type kind = [ duplex ];
  type subtype('data, 'ty) = t('data, [> kind ] as 'ty);
  type supertype('data, 'ty) = t('data, [< kind ] as 'ty);
  module Impl = {
    include Readable.Impl;
    include Writable.Impl;
  };
  include Impl;
  type nonrec t('data) = t('data, [ duplex ]);
  type nonrec objectStream('data) = objectStream('data, [ duplex | objectMode ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t(Buffer.t) = "Duplex";
};

module Transform = {
  type kind = [ transform ];
  type subtype('data, 'ty) = t('data, [> kind ] as 'ty);
  type supertype('data, 'ty) = t('data, [< kind ] as 'ty);
  module Impl = {
    include Duplex.Impl;
  };
  include Impl;
  type makeOptions;
  [@bs.obj] external makeOptions: (
    ~transform: (
        ~chunk: Buffer.t,
        ~encoding: string,
        ~callback: (option(Js.Exn.t), Buffer.t) => unit
      ) => Buffer.t,
    ~flush: (option(Js.Exn.t), Buffer.t) => unit
  ) => makeOptions = "";
  type nonrec t = t(Buffer.t, [ transform ]);
  type nonrec objectStream('data) = objectStream('data, [ transform | objectMode ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t = "Transform";
  [@bs.module "stream"] [@bs.new] external makeWith: (~options: makeOptions) => t = "Transform";

  // [@bs.module "stream"] [@bs.new] external makeObjectMode: unit => t = "Transform";
  // [@bs.module "stream"] [@bs.new] external makeObjectModeWith: (~options: makeOptions) => t = "Transform";

};

module PassThrough = {
  type kind = [ passThrough ];
  module Impl = {
    include Transform.Impl;
  };
  include Impl;
  type objectMode('data) = t('data, [ passThrough | `ObjectMode ]);
  type nonrec t = t(Buffer.t, [ passThrough ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t = "PassThrough";
};

include Base.Impl;
include Readable.Impl;
include Writable.Impl;

[@bs.send] external onError: (t('data, [> ]), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
[@bs.send] external onClose: (t('data, [> ]), [@bs.as "close"] _, unit => unit) => unit = "on";
[@unboxed] type cleanup = {unsubscribe: unit => unit};
[@bs.module "stream"] [@bs.val] external finished: (t('data, [> ]), option(Js.Exn.t) => unit) => cleanup = "finished";
let test = onError;