
/**
 * TODO: Some of the functions in this module use optional
 * named arguments for JS args that are optional. Evaluate
 * whether this is safe/future-proof. If not, refactor.
 */

type settingsObject;
[@bs.obj] external settingsObject: (
  ~headerTableSize: int=?,
  ~enablePush: bool=?,
  ~initialWindowSize: int=?,
  ~maxFrameSize: int=?,
  ~maxConcurrentStreams: int=?,
  ~maxHeaderListSize: int=?,
  ~enableConnectProtocol: bool=?
) => settingsObject = "";

module Http2Stream = {
  type kind = [ Stream.duplex | `Http2Stream ];
  type t = Stream.t(Buffer.t, [ kind ]);
  module Impl = {
    include Stream.Duplex.Impl;

  };
  include Impl;
};

module ClientHttp2Stream = {
  type kind = [ Http2Stream.kind | `ClientHttp2Stream ];
  type t = Stream.t(Buffer.t, [ kind ]);
  module Impl = {
    include Http2Stream.Impl;

  };
  include Impl;
};

module ServerHttp2Stream = {
  type kind = [ Http2Stream.kind | `ServerHttp2Stream ];
  type t = Stream.t(Buffer.t, [ kind ]);
  module Impl = {
    include Http2Stream.Impl;

  };
  include Impl;
};

module Http2Session = {
  type t;
  [@bs.send] external onClose: (t, [@bs.as "close"] _, unit => unit) => unit = "on";
  [@bs.send] external onConnect: (t, [@bs.as "connect"] _, (t, Stream.t(Buffer.t, [> Net.Socket.kind ])) => unit) => unit = "on";
  [@bs.send] external onError: (t, [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
  [@bs.send] external onFrameError: (t, [@bs.as "frameError"] _, (~type_:int, ~errorCode:int, ~streamId:int) => unit) => unit = "on";
  [@bs.send] external onGoAway: (t, [@bs.as "goAway"] _, (~errorCode:int, ~lastStreamId:int, Buffer.t) => unit) => unit = "on";
  [@bs.send] external onLocalSettings: (t, [@bs.as "localSettings"] _, settingsObject => unit) => unit = "on";
  [@bs.send] external onPing: (t, [@bs.as "ping"] _, Buffer.t => unit) => unit = "on";
  [@bs.send] external onRemoteSettings: (t, [@bs.as "remoteSettings"] _, settingsObject => unit) => unit = "on";
  [@bs.send] external onStream: (
      t,
      [@bs.as "stream"] _,
      (
        Stream.t(Buffer.t, [> Http2Stream.kind ]),
        Js.t({.. "status": string, "content-type": string}),
        int,
        array(Js.t({..}))
      ) => unit
    ) => unit = "on";
  [@bs.send] external onTimeout: (t, [@bs.as "timeout"] _, unit => unit) => unit = "on";
  [@bs.get] [@bs.return nullable] external alpnProtocol: t => option(string) = "alpnProtocol";
  [@bs.send] external close: t => unit = "close";
  [@bs.get] external closed: t => bool = "closed";
  [@bs.send] external destroy: t => unit = "destroy";
  [@bs.send] external destroyWithError: (t, Js.Exn.t) => unit = "destroy";
  [@bs.send] external destroyWithCode: (t, int) => unit = "destroy";
  [@bs.get] external destroyed: t => bool = "destroyed";
  [@bs.get] [@bs.return nullable] external encrypted: t => option(bool) = "encrypted";
  [@bs.send] external goaway: t => unit = "goaway";
  [@bs.send] external goawayWith: (t, ~code:int=?, ~lastStreamId: int=?, ~data: Buffer.t=?, unit) => unit = "goaway";
  [@bs.get] external localSettings: t => {.
    "headerTableSize": int,
    "enablePush": bool,
    "initialWindowSize": int,
    "maxFrameSize": int,
    "maxConcurrentStreams": int,
    "maxHeaderListSize": int,
    "enableConnectProtocol": bool,
  } = "on";
  [@bs.get] [@bs.return nullable] external originSet: t => option(array(string)) = "originSet";
  [@bs.get] external pendingSettingsAck: t => bool = "pendingSettingsAck";
  [@bs.send] external ping: (t, (Js.Nullable.t(Js.Exn.t), int, Buffer.t) => unit) => bool = "ping";
  [@bs.send] external pingWith: (t, ~payload: Buffer.t, (Js.Nullable.t(Js.Exn.t), int, Buffer.t) => unit) => bool = "ping";
  [@bs.send] external ref: t => unit = "ref";
  [@bs.get] external remoteSettings: t => {. 
      "headerTableSize": int,
      "enablePush": bool,
      "initialWindowSize": int,
      "maxFrameSize": int,
      "maxConcurrentStreams": int,
      "maxHeaderListSize": int,
      "enableConnectProtocol": bool,
    } = "remoteSettings";
  [@bs.send] external setTimeout: (t, int, unit => unit) => unit = "setTimeout";
  [@bs.get] external socket: t => Net.TcpSocket.t = "socket";
  [@bs.get] external state: t => {
      .
      "effectiveLocalWindowSize": int,
      "effectiveRecvDataLength": int,
      "nextStreamID": int,
      "localWindowSize": int,
      "lastProcStreamID": int,
      "remoteWindowSize": int,
      "deflateDynamicTableSize": int,
      "inflateDynamicTableSize": int,
    } = "state";
  [@bs.send] external settings: (
    t,
    settingsObject,
    ~callback: (Js.Null.t(Js.Exn.t), settingsObject, int) => unit=?
  ) => unit = "settings";
  [@bs.get] external type_: t => int = "type";

};

module ServerHttp2Session = {
  include Http2Session;

  module Origin = {
    type t('a);
    type urlString = [ | `UrlString ];
    type url = [ | `Url ];
    type object_ = [ | `Object ];
    type streamId = [ | `StreamId ];
    external urlString: string => t(urlString) = "%identity";
    external url: Url.t => t(url) = "%identity";
    external object_: {. "origin": string } => t(object_) = "%identity";
    external streamId: int => t(streamId) = "%identity";
  };

  [@bs.send] external altsvc: (
    t,
    string,
    Origin.t([ Origin.urlString | Origin.url | Origin.object_ | Origin.streamId ])
  ) => unit = "altsvc";

  [@bs.send] [@bs.variadic]
  external origin: (array(Origin.t([ Origin.urlString | Origin.url | Origin.object_ ]))) => unit = "origin";

};

module Http2ServerRequest = {
  type kind = [ Stream.readable | `Http2ServerRequest ];
  type t = Stream.t(Buffer.t, [ kind ]);
  module Impl = {
    include Stream.Readable.Impl;
    [@bs.send] external onAborted: (t, [@bs.as "aborted"] _, unit => unit) => unit = "on";
    [@bs.send] external onClose: (t, [@bs.as "close"] _, unit => unit) => unit = "on";
    [@bs.get] external aborted: t => bool = "aborted";
    [@bs.get] external authority: t => string = "authority";
    [@bs.get] external complete: t => bool = "complete";
    [@bs.send] external destroy: t => unit = "destroy";
    [@bs.send] external destroyWithError: (t, Js.Exn.t) => unit = "destroy";
    [@bs.get] external headers: t => Js.t({..}) = "headers";
    [@bs.get] external httpVersion: t => string = "httpVersion";
    [@bs.get] external method_: t => string = "method";
    [@bs.get] external rawHeaders: t => array(string) = "rawHeaders";
    [@bs.get] external rawTrailers: t => array(string) = "rawTrailers";
    [@bs.get] external scheme: t => string = "scheme";
    [@bs.send] external setTimeout: (t, int, Http2Stream.t => unit) => Http2Stream.t = "setTimeout";
    [@bs.get] external socket: t => Stream.t(Buffer.t, [ Stream.duplex | `Socket | `TLSSocket ]) = "socket";
    [@bs.get] external stream: t => Http2Stream.t = "stream";
    [@bs.get] external trailers: t => Js.t({..}) = "trailers";
    [@bs.get] external url: t => string = "url";
  };
  include Impl;
};

module Http2ServerResponse = {

  type kind = [ Stream.duplex | `Http2ServerResponse ];
  type t = Stream.t(Buffer.t, [ kind ]);

  module Impl = {

    include Stream.Duplex.Impl;

    [@bs.send] external onClose: (Stream.t(Buffer.t, [> kind ]), [@bs.as "close"] _, unit => unit) => unit = "on";
    [@bs.send] external onFinish: (Stream.t(Buffer.t, [> kind ]), [@bs.as "finish"] _, unit => unit) => unit = "on";
    [@bs.send] external setTrailers: (Stream.t(Buffer.t, [> kind ]), Js.t({..})) => unit = "setTrailers";
    [@bs.send] external end_: Stream.t(Buffer.t, [> kind ]) => unit = "end";
    [@bs.send] external endWith: ( Stream.t(Buffer.t, [> kind ]), ~data: Buffer.t=?, ~callback: unit => unit=?) => t = "end";
    [@bs.send] external getHeader: (Stream.t(Buffer.t, [> kind ]), string) => string = "getHeader";
    [@bs.send] external getHeaderNames: Stream.t(Buffer.t, [> kind ]) => array(string) = "getHeaderNames";
    [@bs.send] external getHeaders: Stream.t(Buffer.t, [> kind ]) => Js.t({..}) = "getHeaders";
    [@bs.send] external hasHeader: (Stream.t(Buffer.t, [> kind ]), string) => bool = "hasHeader";
    [@bs.send] external headersSent: Stream.t(Buffer.t, [> kind ]) => bool = "headersSent";
    [@bs.send] external removeHeader: (Stream.t(Buffer.t, [> kind ]), string) => unit = "removeHeader";
    [@bs.send] external setHeader: (Stream.t(Buffer.t, [> kind ]), string) => unit = "setHeader";
    [@bs.send] external setHeaderArray: (Stream.t(Buffer.t, [> kind ]), array(string)) => unit = "setHeader";
    [@bs.send] external setTimeout: (Stream.t(Buffer.t, [> kind ]), int, Http2Stream.t => unit) => Http2Stream.t = "setTimeout";
    [@bs.get] external socket: Stream.t(Buffer.t, [> kind ]) => Net.TcpSocket.t = "socket";
    [@bs.get] external statusCode: Stream.t(Buffer.t, [> kind ]) => int = "statusCode";
    [@bs.get] external statusMessage: Stream.t(Buffer.t, [> kind ]) => string = "statusMessage";
    [@bs.get] external stream: Stream.t(Buffer.t, [> kind ]) => Http2Stream.t = "stream";
    [@bs.get] external writableEnded: Stream.t(Buffer.t, [> kind ]) => bool = "writableEnded";
    [@bs.send] external write: ( Stream.t(Buffer.t, [> kind ]), Buffer.t) => bool = "write";
    [@bs.send] external writeWith: ( Stream.t(Buffer.t, [> kind ]), Buffer.t, ~callback: unit => unit=?) => bool = "write";
    [@bs.send] external writeContinue: Stream.t(Buffer.t, [> kind ]) => unit = "writeContinue";
    [@bs.send] external writeHead: (Stream.t(Buffer.t, [> kind ] as 'a), int) => Stream.t(Buffer.t, [> kind ] as 'a) = "writeHead";
    [@bs.send] external writeHeadWith: (Stream.t(Buffer.t, [> kind ] as 'a), int, ~message: string=?, ~headers: Js.t({..})=?) => Stream.t(Buffer.t, [> kind ] as 'a) = "writeHead";
    [@bs.send] external createPushResponse: (Stream.t(Buffer.t, [> kind ]), Js.t({..}), (Js.Exn.t, ServerHttp2Stream.t) => unit) => unit = "writeHead";

  };

  include Impl;

};

