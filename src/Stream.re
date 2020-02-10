
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
    [@bs.send] external onData: (t([> kind]), [@bs.as "data"] _, Buffer.t => unit) => unit = "on";
    [@bs.send] external onEnd: (t([> kind]), [@bs.as "end"] _, unit => unit) => unit = "on";
    [@bs.send] external onPause: (t([> kind]), [@bs.as "pause"] _, unit => unit) => unit = "on";
    [@bs.send] external onReadable: (t([> kind]), [@bs.as "readable"] _, Buffer.t => unit) => unit = "on";
    [@bs.send] external pipe: (t([> kind]), t([> writable]) as 'a) => 'a = "pipe";
    [@bs.send] external unpipe: (t([> kind]) as 'a, t([> writable])) => 'a = "unpipe";
  };
  [@bs.module "stream"] [@bs.new] external make: unit => t([> readable]) = "Readable";
  include Impl;
};

module Writable = {
  type kind = [ writable ];
  module Impl = {
    include Base.Impl;
    [@bs.send] external onDrain: (t([> kind]), [@bs.as "drain"] _, unit => unit) => unit = "on";
    [@bs.send] external onFinish: (t([> kind]), [@bs.as "finish"] _, unit => unit) => unit = "on";
    [@bs.send] external onPipe: (t([> kind]), [@bs.as "pipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external onUnpipe: (t([> kind]), [@bs.as "unpipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external cork: t([> kind]) => unit = "cork";
    [@bs.send] external uncork: t([> kind]) => unit = "uncork";
    [@bs.send] external destroy: t([> kind]) => unit = "destroy";
    [@bs.send] external destroyWithError: (t([> kind]), Js.Exn.t) => unit = "destroy";
    [@bs.get] external destroyed: t([> kind]) => bool = "destroy";
    [@bs.send] external end_: t([> kind]) => unit = "end";
    [@bs.send] external write: (t([> kind]), string, string) => unit = "write";
    [@bs.send] external setDefaultEncoding: (
        t([> kind]),
        [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => unit = "setDefaultEncoding";
    [@bs.get] external writable: t([> kind]) => bool = "writable";
    [@bs.get] external writableEnded: t([> kind]) => bool = "writableEnded";
    [@bs.get] external writableCorked: t([> kind]) => bool = "writableCorked";
    [@bs.get] external writableFinished: t([> kind]) => bool = "writableFinished";
    [@bs.get] external writableLength: t([> kind]) => int = "writableLength";
    [@bs.get] external writableHighWaterMark: t([> kind]) => int = "writableHighWaterMark";
    [@bs.get] external writableObjectMode: t([> kind]) => bool = "writableObjectMode";
  };
  [@bs.module "stream"] [@bs.new] external make: unit => t([> kind]) = "Writable";
  include Impl;
};

module Duplex = {
  type kind = [ duplex ];
  [@bs.module "stream"] [@bs.new] external make: unit => t([> duplex]) = "Duplex";
  module Impl = {
    // From Readable
    // [@bs.send] external onError: (t([> kind]), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
    [@bs.send] external onData: (t([> kind]), [@bs.as "data"] _, Buffer.t => unit) => unit = "on";
    // [@bs.send] external onClose: (t([> kind]), [@bs.as "close"] _, unit => unit) => unit = "on";
    [@bs.send] external onEnd: (t([> kind]), [@bs.as "end"] _, unit => unit) => unit = "on";
    [@bs.send] external pipe: (t([> kind]), t([> writable]) as 'a) => 'a = "pipe";
    [@bs.send] external unpipe: (t([> kind]) as 'a, t([> writable])) => 'a = "unpipe";

    // From Writable
    [@bs.send] external onClose: (t([> kind]), [@bs.as "close"] _, unit => unit) => unit = "on";
    [@bs.send] external onDrain: (t([> kind]), [@bs.as "drain"] _, unit => unit) => unit = "on";
    [@bs.send] external onError: (t([> kind]), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
    [@bs.send] external onFinish: (t([> kind]), [@bs.as "finish"] _, unit => unit) => unit = "on";
    [@bs.send] external onPipe: (t([> kind]), [@bs.as "pipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external onUnpipe: (t([> kind]), [@bs.as "unpipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external cork: t([> kind]) => unit = "cork";
    [@bs.send] external uncork: t([> kind]) => unit = "uncork";
    [@bs.send] external destroy: t([> kind]) => unit = "destroy";
    [@bs.send] external destroyWithError: (t([> kind]), Js.Exn.t) => unit = "destroy";
    [@bs.get] external destroyed: t([> kind]) => bool = "destroy";
    [@bs.send] external end_: t([> kind]) => unit = "end";
    [@bs.send] external write: (t([> kind]), string, string) => unit = "write";
    [@bs.send] external setDefaultEncoding: (
        t([> kind]),
        [@bs.string] [
          | `hex
          | `utf8
          | `ascii
          | `latin1
          | `base64
          | `ucs2
          | `base64
          | `binary
          | `utf16le
        ]
      ) => unit = "setDefaultEncoding";
    [@bs.get] external writable: t([> kind]) => bool = "writable";
    [@bs.get] external writableEnded: t([> kind]) => bool = "writableEnded";
    [@bs.get] external writableCorked: t([> kind]) => bool = "writableCorked";
    [@bs.get] external writableFinished: t([> kind]) => bool = "writableFinished";
    [@bs.get] external writableLength: t([> kind]) => int = "writableLength";
    [@bs.get] external writableHighWaterMark: t([> kind]) => int = "writableHighWaterMark";
    [@bs.get] external writableObjectMode: t([> kind]) => bool = "writableObjectMode";
  };
  type nonrec t = t([ kind ]);
};

module Transform = {
  type kind = [ transform ];
  type nonrec t = t([ kind ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t = "Transform";
  module Impl = {
    include Duplex.Impl;
  }
};

module PassThrough = {
  include Transform.Impl;
  type kind = [ passThrough ];
  type nonrec t = t([ kind ]);
  [@bs.module "stream"] [@bs.new] external make: unit => t = "PassThrough";
};

include Readable.Impl;
include Writable.Impl;

[@bs.send] external onError: (t('a), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
[@bs.send] external onClose: (t('a), [@bs.as "close"] _, unit => unit) => unit = "on";
[@unboxed] type cleanup = {unsubscribe: unit => unit};
[@bs.module "stream"] [@bs.val] external finished: (t('a), option(Js.Exn.t) => unit) => cleanup = "finished";