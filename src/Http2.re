/**
 * TODO: Some of the functions in this module use optional
 * named arguments for JS args that are optional. Evaluate
 * whether this is safe/future-proof. If not, refactor.
 */

type settingsObject;
[@bs.obj]
external settingsObject:
  (
    ~headerTableSize: int=?,
    ~enablePush: bool=?,
    ~initialWindowSize: int=?,
    ~maxFrameSize: int=?,
    ~maxConcurrentStreams: int=?,
    ~maxHeaderListSize: int=?,
    ~enableConnectProtocol: bool=?
  ) =>
  settingsObject;

module Http2Stream = {
  type kind = [ Stream.duplex | `Http2Stream];
  type t = Stream.subtype(Buffer.t, kind);
  module Impl = {
    include Stream.Duplex.Impl;
  };
  include Impl;
};

module ClientHttp2Stream = {
  type kind = [ Http2Stream.kind | `ClientHttp2Stream];
  type t = Stream.subtype(Buffer.t, kind);
  module Impl = {
    include Http2Stream.Impl;
  };
  include Impl;
};

module ServerHttp2Stream = {
  type kind = [ Http2Stream.kind | `ServerHttp2Stream];
  type t = Stream.subtype(Buffer.t, kind);
  module Impl = {
    include Http2Stream.Impl;
  };
  include Impl;
};

module Http2Session = {
  type t;
  [@bs.send] external onClose: (t, [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => t = "on";
  [@bs.send]
  external onConnect:
    (t, [@bs.as "connect"] _, [@bs.uncurry] (t, Stream.subtype(Buffer.t, [> Net.Socket.kind])) => unit) => t =
    "on";
  [@bs.send] external onError: (t, [@bs.as "error"] _, [@bs.uncurry] (Js.Exn.t) => unit) => t = "on";
  /** TODO: uncurry after release of bs-platform v7.3 */
  [@bs.send]
  external onFrameError:
    (t, [@bs.as "frameError"] _, (~type_: int, ~errorCode: int, ~streamId: int) => unit) => t =
    "on";
  /** TODO: uncurry after release of bs-platform v7.3 */
  [@bs.send]
  external onGoAway:
    (t, [@bs.as "goAway"] _, (~errorCode: int, ~lastStreamId: int, Buffer.t) => unit) => t =
    "on";
  [@bs.send]
  external onLocalSettings: (t, [@bs.as "localSettings"] _, [@bs.uncurry] (settingsObject) => unit) => t =
    "on";
  [@bs.send] external onPing: (t, [@bs.as "ping"] _, [@bs.uncurry] (Buffer.t) => unit) => t = "on";
  [@bs.send]
  external onRemoteSettings: (t, [@bs.as "remoteSettings"] _, [@bs.uncurry] (settingsObject) => unit) => t =
    "on";
  [@bs.send]
  external onStream:
    (
      t,
      [@bs.as "stream"] _,
      (
        . Stream.subtype(Buffer.t, [> Http2Stream.kind]),
        Js.t({
          ..
          "status": string,
          "content-type": string,
        }),
        int,
        array(Js.t({..}))
      ) =>
      unit
    ) =>
    t =
    "on";
  [@bs.send] external onTimeout: (t, [@bs.as "timeout"] _, [@bs.uncurry] (unit) => unit) => t = "on";
  [@bs.get] [@bs.return nullable] external alpnProtocol: t => option(string) = "alpnProtocol";
  [@bs.send] external close: t => unit = "close";
  [@bs.get] external closed: t => bool = "closed";
  [@bs.send] external destroy: t => unit = "destroy";
  [@bs.send] external destroyWithError: (t, Js.Exn.t) => unit = "destroy";
  [@bs.send] external destroyWithCode: (t, int) => unit = "destroy";
  [@bs.get] external destroyed: t => bool = "destroyed";
  [@bs.get] [@bs.return nullable] external encrypted: t => option(bool) = "encrypted";
  [@bs.send] external goaway: t => unit = "goaway";
  [@bs.send]
  external goawayWith: (t, ~code: int=?, ~lastStreamId: int=?, ~data: Buffer.t=?, unit) => unit =
    "goaway";
  [@bs.get]
  external localSettings:
    t =>
    {
      .
      "headerTableSize": int,
      "enablePush": bool,
      "initialWindowSize": int,
      "maxFrameSize": int,
      "maxConcurrentStreams": int,
      "maxHeaderListSize": int,
      "enableConnectProtocol": bool,
    } =
    "on";
  [@bs.get] [@bs.return nullable] external originSet: t => option(array(string)) = "originSet";
  [@bs.get] external pendingSettingsAck: t => bool = "pendingSettingsAck";
  [@bs.send]
  external ping: (t, (Js.Nullable.t(Js.Exn.t), int, Buffer.t) => unit) => bool = "ping";
  [@bs.send]
  external pingWith:
    (t, ~payload: Buffer.t, (Js.Nullable.t(Js.Exn.t), int, Buffer.t) => unit) => bool =
    "ping";
  [@bs.send] external ref: t => unit = "ref";
  [@bs.get]
  external remoteSettings:
    t =>
    {
      .
      "headerTableSize": int,
      "enablePush": bool,
      "initialWindowSize": int,
      "maxFrameSize": int,
      "maxConcurrentStreams": int,
      "maxHeaderListSize": int,
      "enableConnectProtocol": bool,
    } =
    "remoteSettings";
  [@bs.send] external setTimeout: (t, int, unit => unit) => unit = "setTimeout";
  [@bs.get] external socket: t => Net.TcpSocket.t = "socket";
  [@bs.get]
  external state:
    t =>
    {
      .
      "effectiveLocalWindowSize": int,
      "effectiveRecvDataLength": int,
      "nextStreamID": int,
      "localWindowSize": int,
      "lastProcStreamID": int,
      "remoteWindowSize": int,
      "deflateDynamicTableSize": int,
      "inflateDynamicTableSize": int,
    } =
    "state";
  [@bs.send]
  external settings:
    (t, settingsObject, ~callback: (Js.Null.t(Js.Exn.t), settingsObject, int) => unit=?) => unit =
    "settings";
  [@bs.get] external type_: t => int = "type";
};

module ServerHttp2Session = {
  include Http2Session;

  module Origin = {
    type t('a);
    type urlString = [ | `UrlString];
    type url = [ | `Url];
    type object_ = [ | `Object];
    type streamId = [ | `StreamId];
    external urlString: string => t(urlString) = "%identity";
    external url: Url.t => t(url) = "%identity";
    external object_: {. "origin": string} => t(object_) = "%identity";
    external streamId: int => t(streamId) = "%identity";
  };

  [@bs.send]
  external altsvc:
    (t, string, Origin.t([ Origin.urlString | Origin.url | Origin.object_ | Origin.streamId])) =>
    unit =
    "altsvc";

  [@bs.send] [@bs.variadic]
  external origin: array(Origin.t([ Origin.urlString | Origin.url | Origin.object_])) => unit =
    "origin";
};

module Http2ServerRequest = {
  type kind = [ Stream.readable | `Http2ServerRequest];
  type t = Stream.subtype(Buffer.t, [ kind]);
  module Impl = {
    include Stream.Readable.Impl;
    [@bs.send] external onAborted: (t, [@bs.as "aborted"] _, [@bs.uncurry] (unit) => unit) => t = "on";
    [@bs.send] external onClose: (t, [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => t = "on";
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
    [@bs.send]
    external setTimeout: (t, int, Http2Stream.t => unit) => Http2Stream.t = "setTimeout";
    [@bs.get]
    external socket: t => Stream.subtype(Buffer.t, [ Stream.duplex | `Socket | `TLSSocket]) =
      "socket";
    [@bs.get] external stream: t => Http2Stream.t = "stream";
    [@bs.get] external trailers: t => Js.t({..}) = "trailers";
    [@bs.get] external url: t => string = "url";
  };
  include Impl;
};

module Http2ServerResponse = {
  type kind = [ Stream.duplex | `Http2ServerResponse];
  type t = Stream.subtype(Buffer.t, [ kind]);
  module Impl = {
    include Stream.Duplex.Impl;
    [@bs.send] external onClose: (t, [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => t = "on";
    [@bs.send] external onFinish: (t, [@bs.as "finish"] _, [@bs.uncurry] (unit) => unit) => t = "on";
    [@bs.send] external setTrailers: (t, Js.t({..})) => unit = "setTrailers";
    [@bs.send] external end_: t => unit = "end";
    [@bs.send] external endWith: (t, ~data: Buffer.t=?, ~callback: unit => unit=?) => t = "end";
    [@bs.send] external getHeader: (t, string) => string = "getHeader";
    [@bs.send] external getHeaderNames: t => array(string) = "getHeaderNames";
    [@bs.send] external getHeaders: t => Js.t({..}) = "getHeaders";
    [@bs.send] external hasHeader: (t, string) => bool = "hasHeader";
    [@bs.send] external headersSent: t => bool = "headersSent";
    [@bs.send] external removeHeader: (t, string) => unit = "removeHeader";
    [@bs.send] external setHeader: (t, string) => unit = "setHeader";
    [@bs.send] external setHeaderArray: (t, array(string)) => unit = "setHeader";
    [@bs.send]
    external setTimeout: (t, int, Http2Stream.t => unit) => Http2Stream.t = "setTimeout";
    [@bs.get] external socket: t => Net.TcpSocket.t = "socket";
    [@bs.get] external statusCode: t => int = "statusCode";
    [@bs.get] external statusMessage: t => string = "statusMessage";
    [@bs.get] external stream: t => Http2Stream.t = "stream";
    [@bs.get] external writableEnded: t => bool = "writableEnded";
    [@bs.send] external write: (t, Buffer.t) => bool = "write";
    [@bs.send] external writeWith: (t, Buffer.t, ~callback: unit => unit=?) => bool = "write";
    [@bs.send] external writeContinue: t => unit = "writeContinue";
    [@bs.send] external writeHead: (t, int) => t = "writeHead";
    [@bs.send]
    external writeHeadWith: (t, int, ~message: string=?, ~headers: Js.t({..})=?) => t =
      "writeHead";
    [@bs.send]
    external createPushResponse: (t, Js.t({..}), (Js.Exn.t, ServerHttp2Stream.t) => unit) => unit =
      "writeHead";
  };
  include Impl;
};
