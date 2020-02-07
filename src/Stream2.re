type t('a);
type readable = [ | `Readable];
type writable = [ | `Writable];
type duplex = [ readable | writable];
type transform = [ duplex | `Transform];

module Readable = {
  module Impl = (T: {
    type nonrec t('a) = t([> readable] as 'a);
  }) => {
    [@bs.module "stream"] [@bs.new] external make: unit => t([> readable]) = "Readable";
    [@bs.send] external onError: (T.t('a), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
    [@bs.send] external onData: (T.t('a), [@bs.as "data"] _, Buffer.t => unit) => unit = "on";
    [@bs.send] external onClose: (T.t('a), [@bs.as "close"] _, unit => unit) => unit = "on";
    [@bs.send] external onEnd: (T.t('a), [@bs.as "end"] _, unit => unit) => unit = "on";
    [@bs.send] external pipe: (T.t('a), t([> writable])) => 'a = "pipe";
    [@bs.send] external unpipe: (T.t('a), t([> writable])) => 'a = "unpipe";
  };
  type nonrec t('a) = t([> readable ] as 'a);
  include Impl({ type nonrec t('a) = t('a); })
};

module Writable = {
  module Impl = (T: { type nonrec t('a) = t([> writable ] as 'a); }) => {
    [@bs.module "stream"] [@bs.new] external make: unit => T.t([> writable]) = "Writable";
    [@bs.send] external onClose: (T.t([> writable]), [@bs.as "close"] _, unit => unit) => unit = "on";
    [@bs.send] external onDrain: (T.t([> writable]), [@bs.as "drain"] _, unit => unit) => unit = "on";
    [@bs.send] external onError: (T.t([> writable]), [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
    [@bs.send] external onFinish: (T.t([> writable]), [@bs.as "finish"] _, unit => unit) => unit = "on";
    [@bs.send] external onPipe: (T.t([> writable]), [@bs.as "pipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external onUnpipe: (T.t([> writable]), [@bs.as "unpipe"] _, t([> readable]) => unit) => unit = "on";
    [@bs.send] external cork: T.t([> writable]) => unit = "cork";
    [@bs.send] external uncork: T.t([> writable]) => unit = "uncork";
    [@bs.send] external destroy: T.t([> writable]) => unit = "destroy";
    [@bs.send] external destroyWithError: (T.t([> writable]), Js.Exn.t) => unit = "destroy";
    [@bs.get] external destroyed: T.t([> writable]) => bool = "destroy";
    [@bs.send] external end_: T.t([> writable]) => unit = "end";
    [@bs.send] external write: (T.t([> writable]), string, string) => unit = "write";
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
    [@bs.get] external writable: T.t([> writable]) => bool = "writable";
    [@bs.get] external writableEnded: T.t([> writable]) => bool = "writableEnded";
    [@bs.get] external writableCorked: T.t([> writable]) => bool = "writableCorked";
    [@bs.get] external writableFinished: T.t([> writable]) => bool = "writableFinished";
    [@bs.get] external writableLength: T.t([> writable]) => int = "writableLength";
    [@bs.get] external writableHighWaterMark: T.t([> writable]) => int = "writableHighWaterMark";
    [@bs.get] external writableObjectMode: T.t([> writable]) => bool = "writableObjectMode";
  };
  type nonrec t('a) = t([> writable ] as 'a);
  include Impl({ type nonrec t('a) = t('a); });
};

module Duplex = {
  include Readable.Impl({ type nonrec t('a) = t([> readable ] as 'a); });
  include Writable.Impl({ type nonrec t('a) = t([> writable ] as 'a); });
  type nonrec t('a) = t([> duplex ] as 'a);
  [@bs.module "stream"] [@bs.new] external make: unit => t('a) = "Duplex";
};

module Transform = {
  include Duplex;
  [@bs.module "stream"] [@bs.new] external make: unit => t('a) = "Transform";
};

module PassThrough = {
  include Transform;
  [@bs.module "stream"] [@bs.new] external make: unit => t('a) = "PassThrough";
};

include Readable.Impl({ type nonrec t('a) = t([> readable ] as 'a); });
include Writable.Impl({ type nonrec t('a) = t([> writable ] as 'a); });

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

  module Impl = (T: {
    type nonrec t('a) = t([> httpStream ] as 'a);
  }) => {
    [@bs.send] external testHttp1: T.t('a) => unit = "test1";
    [@bs.scope "HttpStream"] [@bs.val] external make: stream => T.t('b) = "make";
  };

  include Readable.Impl({
    type nonrec t('a) = t([> readable ] as 'a);
  });

  type nonrec t('a) = t([> httpStream ] as 'a);

  include Impl({
    type nonrec t('a) = t('a);
  });
  
};

module Http2Stream = {

  type http2Stream = [ HttpStream.httpStream | `Http2 ];
  module Impl = (T: {
    type nonrec t('a) = t([> http2Stream ] as 'a);
  }) => {
    [@bs.send] external testHttp2: (T.t('a), int) => T.t('a) = "testHttp2";
    [@bs.scope "Http2Stream"] [@bs.val] external make: stream => T.t('a) = "make";
  };

  include HttpStream.Impl({ type nonrec t('a) = t([> HttpStream.httpStream ] as 'a); });
  include Impl({ type nonrec t('a) = t([> http2Stream ] as 'a); });
  type nonrec t = t([ http2Stream ]);

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


