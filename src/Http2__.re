type settingsObject;

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
  type kind('w, 'r) = [ Stream__.duplex('w, 'r) | `Http2Stream];
  type subtype('w, 'r, 'ty) = Stream__.subtype([> kind('w, 'r)] as 'ty);
  type supertype('w, 'r, 'ty) = Stream__.subtype([< kind('w, 'r)] as 'ty);
  type t('w, 'r) = Stream__.subtype(kind('w, 'r));
  module Events = {
    include Stream__.Duplex.Events;
  };
  module Impl = {
    include Stream__.Duplex.Impl;
    [@bs.get] external aborted: subtype('w, 'r, 'ty) => bool = "aborted";
    [@bs.get] external bufferSize: subtype('w, 'r, 'ty) => int = "bufferSize";
    [@bs.get] external closed: subtype('w, 'r, 'ty) => bool = "closed";
    [@bs.get] external destroyed: subtype('w, 'r, 'ty) => bool = "destroyed";
    [@bs.get]
    external endAfterHeaders: subtype('w, 'r, 'ty) => bool =
      "endAfterHeaders";
    [@bs.get] [@bs.return nullable]
    external id: subtype('w, 'r, 'ty) => option(int) = "id";
    [@bs.get] external pending: subtype('w, 'r, 'ty) => bool = "pending";
    [@bs.get] external rstCode: subtype('w, 'r, 'ty) => int = "rstCode";
    [@bs.get]
    external sentHeaders: subtype('w, 'r, 'ty) => bool = "sentHeaders";
  };
  include Impl;
};

module ClientHttp2Stream = {
  type kind('w, 'r) = [ Http2Stream.kind('w, 'r) | `ClientHttp2Stream];
  type subtype('w, 'r, 'ty) = Stream__.subtype([> kind('w, 'r)] as 'ty);
  type supertype('w, 'r, 'ty) = Stream__.subtype([< kind('w, 'r)] as 'ty);
  type t('w, 'r) = Stream__.subtype(kind('w, 'r));
  module Events = {
    include Http2Stream.Events;
  };
  module Impl = {
    include Http2Stream.Impl;
  };
  include Impl;
};

module ServerHttp2Stream = {
  type kind('w, 'r) = [ Http2Stream.kind('w, 'r) | `ServerHttp2Stream];
  type subtype('w, 'r, 'ty) = Stream__.subtype([> kind('w, 'r)] as 'ty);
  type supertype('w, 'r, 'ty) = Stream__.subtype([< kind('w, 'r)] as 'ty);
  type t = Stream__.subtype(kind(Buffer.t, Buffer.t));
  module Events = {
    include Http2Stream.Events;
  };
  module Impl = {
    include Http2Stream.Impl;
  };
  include Impl;
};

module Http2Session = {
  type t;
  [@bs.send]
  external onClose: (t, [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) => t =
    "on";
  [@bs.send]
  external onConnect:
    (t, [@bs.as "connect"] _, [@bs.uncurry] ((t, Net__.Socket.t) => unit)) => t =
    "on";
  [@bs.send]
  external onError:
    (t, [@bs.as "error"] _, [@bs.uncurry] (Js.Exn.t => unit)) => t =
    "on";
  [@bs.send]
  external onFrameError:
    (
      t,
      [@bs.as "frameError"] _,
      [@bs.uncurry] ((~type_: int, ~errorCode: int, ~streamId: int) => unit)
    ) =>
    t =
    "on";
  [@bs.send]
  external onGoAway:
    (
      t,
      [@bs.as "goAway"] _,
      [@bs.uncurry] ((~errorCode: int, ~lastStreamId: int, Buffer.t) => unit)
    ) =>
    t =
    "on";
  [@bs.send]
  external onLocalSettings:
    (t, [@bs.as "localSettings"] _, [@bs.uncurry] (settingsObject => unit)) =>
    t =
    "on";
  [@bs.send]
  external onPing:
    (t, [@bs.as "ping"] _, [@bs.uncurry] (Buffer.t => unit)) => t =
    "on";
  [@bs.send]
  external onRemoteSettings:
    (t, [@bs.as "remoteSettings"] _, [@bs.uncurry] (settingsObject => unit)) =>
    t =
    "on";
  [@bs.send]
  external onStream:
    (
      t,
      [@bs.as "stream"] _,
      (
        t,
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
  [@bs.send]
  external onTimeout:
    (t, [@bs.as "timeout"] _, [@bs.uncurry] (unit => unit)) => t =
    "on";
  [@bs.get] [@bs.return nullable]
  external alpnProtocol: t => option(string) = "alpnProtocol";
  [@bs.send] external close: t => unit = "close";
  [@bs.get] external closed: t => bool = "closed";
  [@bs.send] external destroy: t => unit = "destroy";
  [@bs.send] external destroyWithError: (t, Js.Exn.t) => unit = "destroy";
  [@bs.send] external destroyWithCode: (t, int) => unit = "destroy";
  [@bs.get] external destroyed: t => bool = "destroyed";
  [@bs.get] [@bs.return nullable]
  external encrypted: t => option(bool) = "encrypted";
  [@bs.send] external goaway: t => unit = "goaway";
  [@bs.send]
  external goawayWith:
    (t, ~code: int=?, ~lastStreamId: int=?, ~data: Buffer.t=?, unit) => unit =
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
  [@bs.get] [@bs.return nullable]
  external originSet: t => option(array(string)) = "originSet";
  [@bs.get] external pendingSettingsAck: t => bool = "pendingSettingsAck";
  [@bs.send]
  external ping: (t, (Js.Nullable.t(Js.Exn.t), int, Buffer.t) => unit) => bool =
    "ping";
  [@bs.send]
  external pingWith:
    (
      t,
      ~payload: Buffer.t,
      (Js.Nullable.t(Js.Exn.t), int, Buffer.t) => unit
    ) =>
    bool =
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
  [@bs.send]
  external setTimeout: (t, int, unit => unit) => unit = "setTimeout";
  [@bs.get] external socket: t => Net__.TcpSocket.t = "socket";
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
    (
      t,
      settingsObject,
      ~callback: (Js.Null.t(Js.Exn.t), settingsObject, int) => unit=?
    ) =>
    unit =
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
    (
      t,
      string,
      Origin.t(
        [ Origin.urlString | Origin.url | Origin.object_ | Origin.streamId],
      )
    ) =>
    unit =
    "altsvc";

  [@bs.send] [@bs.variadic]
  external origin:
    array(Origin.t([ Origin.urlString | Origin.url | Origin.object_])) =>
    unit =
    "origin";
};

module Http2ServerRequest = {
  type kind('r) = [ Stream__.readable('r) | `Http2ServerRequest];
  type subtype('r, 'ty) = Stream__.subtype([> kind('r)] as 'ty);
  type supertype('r, 'ty) = Stream__.subtype([< kind('r)] as 'ty);
  type t = Stream__.subtype(kind(Buffer.t));
  module Impl = {
    include Stream__.Readable.Impl;
    [@bs.send]
    external onAborted:
      (
        subtype('r, 'ty),
        [@bs.as "aborted"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('r, 'ty) =
      "on";
    [@bs.send]
    external onClose:
      (subtype('r, 'ty), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('r, 'ty) =
      "on";
    [@bs.get] external aborted: subtype('r, 'ty) => bool = "aborted";
    [@bs.get] external authority: subtype('r, 'ty) => string = "authority";
    [@bs.get] external complete: subtype('r, 'ty) => bool = "complete";
    [@bs.send] external destroy: subtype('r, 'ty) => unit = "destroy";
    [@bs.send]
    external destroyWithError: (subtype('r, 'ty), Js.Exn.t) => unit =
      "destroy";
    [@bs.get] external headers: subtype('r, 'ty) => Js.t({..}) = "headers";
    [@bs.get]
    external httpVersion: subtype('r, 'ty) => string = "httpVersion";
    [@bs.get] external method_: subtype('r, 'ty) => string = "method";
    [@bs.get]
    external rawHeaders: subtype('r, 'ty) => array(string) = "rawHeaders";
    [@bs.get]
    external rawTrailers: subtype('r, 'ty) => array(string) = "rawTrailers";
    [@bs.get] external scheme: subtype('r, 'ty) => string = "scheme";
    [@bs.send]
    external setTimeout:
      (subtype('r, 'ty), int, unit => unit) => subtype('r, 'ty) =
      "setTimeout";
    [@bs.get]
    external socket:
      t =>
      Stream__.subtype(
        [< Net__.Socket.kind('w, 'r) | Tls__.TlsSocket.kind('w, 'r)],
      ) =
      "socket";
    [@bs.get] external stream: t => Stream__.t = "stream";
    [@bs.get] external trailers: t => Js.t({..}) = "trailers";
    [@bs.get] external url: t => string = "url";
  };
  include Impl;
};

module Http2ServerResponse = {
  type kind = [ Stream__.stream | `Http2ServerResponse];
  type subtype('ty) = Stream__.subtype([> kind] as 'ty);
  type supertype('ty) = Stream__.subtype([< kind] as 'ty);
  type t = Stream__.subtype(kind);
  module Impl = {
    include Stream__.Duplex.Impl;
    [@bs.send]
    external onClose:
      (subtype('ty), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('ty) =
      "on";
    [@bs.send]
    external onFinish:
      (subtype('ty), [@bs.as "finish"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('ty) =
      "on";
    [@bs.send]
    external setTrailers: (subtype('ty), Js.t({..})) => unit = "setTrailers";
    [@bs.send] external end_: subtype('ty) => unit = "end";
    [@bs.send]
    external endWith:
      (subtype('ty), ~data: Buffer.t=?, ~callback: unit => unit=?) =>
      subtype('ty) =
      "end";
    [@bs.send]
    external getHeader: (subtype('ty), string) => string = "getHeader";
    [@bs.send]
    external getHeaderNames: subtype('ty) => array(string) =
      "getHeaderNames";
    [@bs.send]
    external getHeaders: subtype('ty) => Js.t({..}) = "getHeaders";
    [@bs.send]
    external hasHeader: (subtype('ty), string) => bool = "hasHeader";
    [@bs.send] external headersSent: subtype('ty) => bool = "headersSent";
    [@bs.send]
    external removeHeader: (subtype('ty), string) => unit = "removeHeader";
    [@bs.send]
    external setHeader: (subtype('ty), string) => unit = "setHeader";
    [@bs.send]
    external setHeaderArray: (subtype('ty), array(string)) => unit =
      "setHeader";
    [@bs.send]
    external setTimeout:
      (subtype('ty), int, unit => unit) => Http2Stream.t('w, 'r) =
      "setTimeout";
    [@bs.get] external socket: subtype('ty) => Net__.TcpSocket.t = "socket";
    [@bs.get] external statusCode: subtype('ty) => int = "statusCode";
    [@bs.get]
    external statusMessage: subtype('ty) => string = "statusMessage";
    [@bs.get]
    external stream: subtype('ty) => Http2Stream.t('w, 'r) = "stream";
    [@bs.get] external writableEnded: subtype('ty) => bool = "writableEnded";
    [@bs.send] external write: (subtype('ty), Buffer.t) => bool = "write";
    [@bs.send]
    external writeWith:
      (subtype('ty), Buffer.t, ~callback: unit => unit=?) => bool =
      "write";
    [@bs.send] external writeContinue: subtype('ty) => unit = "writeContinue";
    [@bs.send]
    external writeHead: (subtype('ty), int) => subtype('ty) = "writeHead";
    [@bs.send]
    external writeHeadWith:
      (subtype('ty), int, ~message: string=?, ~headers: Js.t({..})=?) =>
      subtype('ty) =
      "writeHead";
    [@bs.send]
    external createPushResponse:
      (
        subtype('ty),
        Js.t({..}),
        [@bs.uncurry] ((Js.Exn.t, ServerHttp2Stream.t) => unit)
      ) =>
      unit =
      "writeHead";
  };
  include Impl;
};