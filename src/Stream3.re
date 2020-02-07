type t('a);
type readable = [ | `Readable];
type writable = [ | `Writable];
type duplex = [ readable | writable];
type transform = [ duplex | `Transform];

module Readable = {
  module Impl = (T: { type t; }) => {
    [@bs.module "stream"] [@bs.new] external make: unit => t([> readable]) = "Readable";
    [@bs.send] external onError: (T.t, [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
    [@bs.send] external onData: (T.t, [@bs.as "data"] _, Buffer.t => unit) => unit = "on";
    [@bs.send] external onClose: (T.t, [@bs.as "close"] _, unit => unit) => unit = "on";
    [@bs.send] external onEnd: (T.t, [@bs.as "end"] _, unit => unit) => unit = "on";
    [@bs.send] external pipe: (T.t, t([> writable]) as 'a) => 'a = "pipe";
    [@bs.send] external unpipe: (T.t as 'a, t([> writable])) => 'a = "unpipe";
  };
  type nonrec t = t(readable);
  include Impl({ type nonrec t = t });
};

module Writable = {
  module Impl = (T: { type t; }) => {
    [@bs.module "stream"] [@bs.new] external make: unit => T.t = "Writable";
    [@bs.send] external onClose: (T.t, [@bs.as "close"] _, unit => unit) => unit = "on";
    [@bs.send] external onDrain: (T.t, [@bs.as "drain"] _, unit => unit) => unit = "on";
    [@bs.send] external onError: (T.t, [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
    [@bs.send] external onFinish: (T.t, [@bs.as "finish"] _, unit => unit) => unit = "on";
    [@bs.send] external onPipe: (T.t, [@bs.as "pipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external onUnpipe: (T.t, [@bs.as "unpipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external cork: T.t => unit = "cork";
    [@bs.send] external uncork: T.t => unit = "uncork";
    [@bs.send] external destroy: T.t => unit = "destroy";
    [@bs.send] external destroyWithError: (T.t, Js.Exn.t) => unit = "destroy";
    [@bs.get] external destroyed: T.t => bool = "destroy";
    [@bs.send] external end_: T.t => unit = "end";
    [@bs.send] external write: (T.t, string, string) => unit = "write";
    [@bs.send] external setDefaultEncoding: (
        t([> writable]),
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
    [@bs.get] external writable: T.t => bool = "writable";
    [@bs.get] external writableEnded: T.t => bool = "writableEnded";
    [@bs.get] external writableCorked: T.t => bool = "writableCorked";
    [@bs.get] external writableFinished: T.t => bool = "writableFinished";
    [@bs.get] external writableLength: T.t => int = "writableLength";
    [@bs.get] external writableHighWaterMark: T.t => int = "writableHighWaterMark";
    [@bs.get] external writableObjectMode: T.t => bool = "writableObjectMode";
  };
  type nonrec t = t(writable);
};

module Duplex = {
  type nonrec t = t(duplex);
  include Readable.Impl({ type nonrec t = t; });
  include Writable.Impl({ type nonrec t = t; });
  [@bs.module "stream"] [@bs.new] external make: unit => t = "Duplex";
};

module Transform = {
  include Duplex;
  [@bs.module "stream"] [@bs.new] external make: unit => t = "Transform";
};

module PassThrough = {
  include Transform;
  [@bs.module "stream"] [@bs.new] external make: unit => t = "PassThrough";
};

include Readable.Impl({ type nonrec t = t(readable)});
include Writable.Impl({ type nonrec t = t(writable)});

[@bs.send] external onError: (t('a), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
[@bs.send] external onClose: (t('a), [@bs.as "close"] _, unit => unit) => unit = "on";
[@unboxed] type cleanup = {unsubscribe: unit => unit};
[@bs.module "stream"] [@bs.val] external finished: (t('a), option(Js.Exn.t) => unit) => cleanup = "finished";

//////////////////////////////////////////////////////
type stream = {
  stream: unit => unit
};


module HttpStream = {

  type httpStream = [ duplex | `Http ];

  type nonrec t = t([ httpStream ]);

  module Impl = (T: {
    type t;
  }) => {
    [@bs.send] external testHttp1: T.t => unit = "test1";
    [@bs.scope "HttpStream"] [@bs.val] external make: stream => T.t = "make";
  };

  include Readable.Impl({ type nonrec t = t; });
  include Impl({ type nonrec t = t; });
  
};

module Http2Stream = {

  type http2Stream = [ HttpStream.httpStream | `Http2 ];
  type nonrec t = t([ http2Stream ]);

  module Impl = (T: {
    type t;
  }) => {
    [@bs.send] external testHttp2: (T.t, int) => T.t = "testHttp2";
    [@bs.scope "Http2Stream"] [@bs.val] external make: stream => T.t = "make";
  };

  include HttpStream.Impl({ type nonrec t = t; });
  include Impl({ type nonrec t = t; });

};

// module Test = {

//   let a = HttpStream.make({ stream: () => () });
//   let b = onClose(a, () => ());
//   let c = HttpStream.testHttp1(a);

//   let a2 = Http2Stream.make({ stream: () => () });
//   let x = Http2Stream.testHttp2(a2, 0);
//   let y = Http2Stream.testHttp1(a2);
//   let y = Http2Stream.testHttp1(a);

// };


