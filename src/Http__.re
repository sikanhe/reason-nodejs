type http = [ | `Http];

type headersObject = {
    accept: option(string),
    [@bs.as "accept-language"]
    acceptLanguage: option(string),
    [@bs.as "accept-patch"]
    acceptPatch: option(string),
    [@bs.as "accept-ranges"]
    acceptRanges: option(string),
    [@bs.as "access-control-allow-credentials"]
    accessControlAllowCredentials: option(string),
    [@bs.as "access-control-allow-headers"]
    accessControlAllowHeaders: option(string),
    [@bs.as "access-control-allow-methods"]
    accessControlAllowMethods: string,
    [@bs.as "access-control-allow-origin"]
    accessControlAllowOrigin: option(string),
    [@bs.as "access-control-expose-headers"]
    accessControlExposeHeaders: option(string),
    [@bs.as "access-control-max-age"]
    accessControlMaxAge: option(string),
    age: option(string),
    allow: option(string),
    [@bs.as "alt-svc"]
    altSvc: option(string),
    authorization: option(string),
    [@bs.as "cache-control"]
    cacheControl: option(string),
    connection: option(string),
    [@bs.as "content-disposition"]
    contentDisposition: option(string),
    [@bs.as "content-encoding"]
    contentEncoding: option(string),
    [@bs.as "content-language"]
    contentLanguage: option(string),
    [@bs.as "content-length"]
    contentLenth: option(string),
    [@bs.as "content-location"]
    contentLocation: option(string),
    [@bs.as "content-range"]
    contentRange: option(string),
    [@bs.as "content-type"]
    contentType: option(string),
    cookie: option(string),
    date: option(string),
    expect: option(string),
    expires: option(string),
    forwarded: option(string),
    from: option(string),
    host: option(string),
    [@bs.as "if-match"]
    ifMatch: option(string),
    [@bs.as "if-modified-since"]
    ifModifiedSince: option(string),
    [@bs.as "if-none-match"]
    ifNoneMatch: option(string),
    [@bs.as "if-unmodified-since"]
    ifUnmodifiedSince: option(string),
    [@bs.as "last-modified"]
    lastModified: option(string),
    location: option(string),
    pragma: option(string),
    [@bs.as "proxy-authenticate"]
    proxyAuthenticate: option(string),
    [@bs.as "proxy-authorization"]
    proxyAuthorization: option(string),
    [@bs.as "public-key-pins"]
    publicKeyPins: option(string),
    range: option(string),
    referer: option(string),
    [@bs.as "retry-after"]
    retryAfter: option(string),
    [@bs.as "set-cookie"]
    setCookie: option(array(string)),
    [@bs.as "strict-transport-security"]
    strictTransportPolicy: option(string),
    tk: option(string),
    trailer: option(string),
    [@bs.as "transfer-encoding"]
    transferEncoding: option(string),
    upgrade: option(string),
    [@bs.as "user-agent"]
    userAgent: option(string),
    vary: option(string),
    via: option(string),
    warning: option(string),
    [@bs.as "www-authenticate"]
    wwwAuthenticate: option(string),
  };

module IncomingMessage = {
  type kind('r) = [ Stream__.readable('r) | `IncomingMessage];
  type subtype('r, 'a) = Stream__.subtype([> kind('r)] as 'a);
  type supertype('r, 'a) = Stream__.subtype([< kind('r)] as 'a);
  type t = Stream__.subtype([ kind(Buffer.t)]);
  module Events = {
    include Stream__.Readable.Events;
    [@bs.send]
    external onAborted:
      (subtype('r, 'a), [@bs.as "aborted"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('r, 'a) =
      "on";
    [@bs.send]
    external onClose:
      (subtype('r, 'a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('r, 'a) =
      "on";
    [@bs.send]
    external offAborted:
      (subtype('r, 'a), [@bs.as "aborted"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('r, 'a) =
      "off";
    [@bs.send]
    external offClose:
      (subtype('r, 'a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('r, 'a) =
      "off";
    [@bs.send]
    external onAbortedOnce:
      (subtype('r, 'a), [@bs.as "aborted"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('r, 'a) =
      "once";
    [@bs.send]
    external onCloseOnce:
      (subtype('r, 'a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('r, 'a) =
      "once";
  };

  module Impl = {
    include Stream__.Readable.Impl;
    include Events;
    [@bs.get] external method_: subtype('r, 'a) => string = "method";
    [@bs.get] external url: subtype('r, 'a) => string = "url";
    [@bs.get] external port: subtype('r, 'a) => int = "port";
    [@bs.get] external headers: subtype('r, 'a) => headersObject = "headers";
    [@bs.get]
    external rawHeaders: subtype('r, 'a) => array(string) = "rawHeaders";
    [@bs.get]
    external rawTrailers: subtype('r, 'a) => array(string) = "rawTrailers";
    [@bs.get]
    external connection: subtype('r, 'a) => Net__.TcpSocket.t = "connection";
    [@bs.get] external aborted: subtype('r, 'a) => bool = "aborted";
    [@bs.get] external complete: subtype('r, 'a) => bool = "complete";
    [@bs.send] external destroy: subtype('r, 'a) => unit = "destroy";
    [@bs.send]
    external destroyWithError: (subtype('r, 'a), Js.Exn.t) => bool =
      "destroy";
    [@bs.send]
    external setTimeout: (subtype('r, 'a), int) => subtype('r, 'a) =
      "setTimeout";
    [@bs.send]
    external setTimeoutWithCallback:
      (subtype('r, 'a), int, subtype('r, 'a) => unit) => subtype('r, 'a) =
      "setTimeout";
    [@bs.get]
    external socket: subtype('r, 'a) => Net__.TcpSocket.t = "socket";
    [@bs.get] external statusCode: subtype('r, 'a) => int = "statusCode";
    [@bs.get]
    external statusMessage: subtype('r, 'a) => string = "statusMessage";
    [@bs.get]
    external trailers: subtype('r, 'a) => Js.Dict.t(string) = "trailers";
  };
  include Impl;
};

module ClientRequest = {
  type kind('w, 'r) = [ Stream__.duplex('w, 'r) | `ClientRequest];
  type subtype('w, 'r, 'a) = Stream__.subtype([> kind('w, 'r)] as 'a);
  type supertype('w, 'r, 'a) = Stream__.subtype([< kind('w, 'r)] as 'a);
  type t = Stream__.subtype([ kind(Buffer.t, Buffer.t)]);
  type information = {
    httpVersion: string,
    httpVersionMajor: int,
    httpVersionMinor: int,
    statusCode: int,
    statusMessage: string,
    headers: headersObject,
    rawHeaders: array(string),
  };
  module Events = {
    include Stream__.Duplex.Events;
    [@bs.send]
    external onAbort:
      (
        subtype('w, 'r, 'a),
        [@bs.as "abort"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "on";
    [@bs.send]
    external onConnect:
      (
        subtype('w, 'r, 'a),
        [@bs.as "connect"] _,
        (IncomingMessage.t, Net__.TcpSocket.t, Buffer.t) => unit
      ) =>
      unit =
      "on";
    [@bs.send]
    external onContinue:
      (
        subtype('w, 'r, 'a),
        [@bs.as "continue"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "on";
    [@bs.send]
    external onInformation:
      (
        subtype('w, 'r, 'a),
        [@bs.as "information"] _,
        [@bs.uncurry] (information => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "on";
    [@bs.send]
    external onResponse:
      (
        subtype('w, 'r, 'a),
        [@bs.as "response"] _,
        [@bs.uncurry] (IncomingMessage.t => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "on";
    [@bs.send]
    external onSocket:
      (
        subtype('w, 'r, 'a),
        [@bs.as "socket"] _,
        [@bs.uncurry] (Net__.TcpSocket.t => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "on";
    [@bs.send]
    external onTimeout:
      (
        subtype('w, 'r, 'a),
        [@bs.as "timeout"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "on";
    [@bs.send]
    external onUpgrade:
      (
        subtype('w, 'r, 'a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (
          (IncomingMessage.t, Net__.TcpSocket.t, Buffer.t) => unit
        )
      ) =>
      subtype('w, 'r, 'a) =
      "on";

    [@bs.send]
    external offAbort:
      (
        subtype('w, 'r, 'a),
        [@bs.as "abort"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "off";
    [@bs.send]
    external offConnect:
      (
        subtype('w, 'r, 'a),
        [@bs.as "connect"] _,
        (IncomingMessage.t, Net__.TcpSocket.t, Buffer.t) => unit
      ) =>
      unit =
      "off";
    [@bs.send]
    external offContinue:
      (
        subtype('w, 'r, 'a),
        [@bs.as "continue"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "off";
    [@bs.send]
    external offInformation:
      (
        subtype('w, 'r, 'a),
        [@bs.as "information"] _,
        [@bs.uncurry] (information => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "off";
    [@bs.send]
    external offResponse:
      (
        subtype('w, 'r, 'a),
        [@bs.as "response"] _,
        [@bs.uncurry] (IncomingMessage.t => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "off";
    [@bs.send]
    external offSocket:
      (
        subtype('w, 'r, 'a),
        [@bs.as "socket"] _,
        [@bs.uncurry] (Net__.TcpSocket.t => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "off";
    [@bs.send]
    external offTimeout:
      (
        subtype('w, 'r, 'a),
        [@bs.as "timeout"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "off";
    [@bs.send]
    external offUpgrade:
      (
        subtype('w, 'r, 'a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (
          (IncomingMessage.t, Net__.TcpSocket.t, Buffer.t) => unit
        )
      ) =>
      subtype('w, 'r, 'a) =
      "off";

    [@bs.send]
    external onAbortOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "abort"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "once";
    [@bs.send]
    external onConnectOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "connect"] _,
        (IncomingMessage.t, Net__.Socket.subtype('w, 'r, 'c), Buffer.t) =>
        unit
      ) =>
      unit =
      "once";
    [@bs.send]
    external onContinueOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "continue"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "once";
    [@bs.send]
    external onInformationOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "information"] _,
        [@bs.uncurry] (information => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "once";
    [@bs.send]
    external onResponseOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "response"] _,
        [@bs.uncurry] (IncomingMessage.t => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "once";
    [@bs.send]
    external onSocketOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "socket"] _,
        [@bs.uncurry] (Net__.TcpSocket.t => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "once";
    [@bs.send]
    external onTimeoutOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "timeout"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "once";
    [@bs.send]
    external onUpgradeOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (
          (IncomingMessage.t, Net__.TcpSocket.t, Buffer.t) => unit
        )
      ) =>
      subtype('w, 'r, 'a) =
      "once";
  };
  module Impl = {
    include Stream__.Duplex.Impl;
    include Events;
    [@bs.send] external abort: subtype('w, 'r, 'a) => unit = "abort";
    [@bs.get] external aborted: subtype('w, 'r, 'a) => bool = "aborted";
    [@bs.send] external end_: subtype('w, 'r, 'a) => unit = "end";
    [@bs.send]
    external endWithData: (subtype('w, 'r, 'a), Buffer.t) => unit = "end";
    [@bs.send]
    external endWithCallback: (subtype('w, 'r, 'a), unit => unit) => unit =
      "end";
    [@bs.send]
    external endWithDataCallback:
      (subtype('w, 'r, 'a), Buffer.t, unit => unit) => unit =
      "end";
    [@bs.send]
    external flushHeaders: subtype('w, 'r, 'a) => unit = "flushHeaders";
    [@bs.send]
    external getHeader: (subtype('w, 'r, 'a), string) => 'any = "getHeader";
    [@bs.send]
    external maxHeadersCount: subtype('w, 'r, 'a) => int = "maxHeadersCount";
    [@bs.send] external path: subtype('w, 'r, 'a) => string = "path";
    [@bs.send]
    external reusedSocket: subtype('w, 'r, 'a) => bool = "reusedSocket";
    [@bs.send]
    external setHeader: (subtype('w, 'r, 'a), string, 'any) => unit =
      "setHeader";
    [@bs.send]
    external setHeaderArray:
      (subtype('w, 'r, 'a), string, array('any)) => unit =
      "setHeader";
    [@bs.send]
    external setNoDelay: (subtype('w, 'r, 'a), bool) => unit = "setNoDelay";
    [@bs.send]
    external setSocketKeepAlive: (subtype('w, 'r, 'a), bool) => unit =
      "setSocketKeepAlive";
    [@bs.send]
    external setSocketKeepAliveWithDelay:
      (subtype('w, 'r, 'a), bool, int) => unit =
      "setSocketKeepAlive";
    [@bs.send]
    external setTimeout: (subtype('w, 'r, 'a), int) => unit = "setTimeout";
    [@bs.send]
    external setTimeoutWithCallback:
      (subtype('w, 'r, 'a), int, unit => unit) => unit =
      "setTimeout";
    [@bs.send]
    external socket: subtype('w, 'r, 'a) => Net__.TcpSocket.t = "socket";
    [@bs.send]
    external writableEnded: subtype('w, 'r, 'a) => bool = "writableEnded";
    [@bs.send]
    external write: (subtype('w, 'r, 'a), Buffer.t) => bool = "write";
    [@bs.send]
    external writeWithCallback:
      (subtype('w, 'r, 'a), Buffer.t, unit => unit) => bool =
      "write";
  };

  include Impl;
};

module ServerResponse = {
  type kind('w, 'r) = [ Stream__.duplex('w, 'r) | `ServerResponse];
  type subtype('w, 'r, 'a) = Stream__.subtype([> kind('w, 'r)] as 'a);
  type supertype('w, 'r, 'a) = Stream__.subtype([< kind('w, 'r)] as 'a);
  type t = Stream__.subtype([ kind(Buffer.t, Buffer.t)]);
  module Events = {
    include Stream__.Duplex.Events;
    [@bs.send]
    external onClose:
      (
        subtype('w, 'r, 'a),
        [@bs.as "close"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "on";
    [@bs.send]
    external onFinish:
      (
        subtype('w, 'r, 'a),
        [@bs.as "finish"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "on";
    [@bs.send]
    external offClose:
      (
        subtype('w, 'r, 'a),
        [@bs.as "close"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "off";
    [@bs.send]
    external offFinish:
      (
        subtype('w, 'r, 'a),
        [@bs.as "finish"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "off";
    [@bs.send]
    external onCloseOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "close"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "once";
    [@bs.send]
    external onFinishOnce:
      (
        subtype('w, 'r, 'a),
        [@bs.as "finish"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'a) =
      "once";
  };
  module Impl = {
    include Stream__.Duplex.Impl;
    include Events;
    [@bs.get] external statusCode: subtype('w, 'r, 'a) => int = "statusCode";
    [@bs.set]
    external setStatusCode: (subtype('w, 'r, 'a), int) => unit = "statusCode";
    [@bs.send]
    external write: (subtype('w, 'r, 'a), Buffer.t) => bool = "write";
    [@bs.send]
    external writeWithEncodingCallback:
      (subtype('w, 'r, 'a), Buffer.t, unit => unit) => bool =
      "write";
    [@bs.send]
    external writeStatus: (subtype('w, 'r, 'a), int) => unit = "writeHead";
    [@bs.send] external cork: subtype('w, 'r, 'a) => unit = "cork";
    [@bs.send] external end_: subtype('w, 'r, 'a) => unit = "end";
    [@bs.send]
    external endWithData: (subtype('w, 'r, 'a), Buffer.t) => unit = "end";
    [@bs.send]
    external endWithCallback: (subtype('w, 'r, 'a), unit => unit) => unit =
      "end";
    [@bs.send]
    external endWithDataCallback:
      (subtype('w, 'r, 'a), Buffer.t, unit => unit) => unit =
      "end";
    [@bs.send] external uncork: subtype('w, 'r, 'a) => unit = "uncork";
    [@bs.send]
    external flushHeaders: subtype('w, 'r, 'a) => unit = "flushHeaders";
    [@bs.send]
    external getHeader: (subtype('w, 'r, 'a), string) => 'any = "getHeader";
    [@bs.send]
    external getHeaderNames: subtype('w, 'r, 'a) => array(string) =
      "getHeaderNames";
    [@bs.send]
    external getHeaders: subtype('w, 'r, 'a) => headersObject = "getHeaders";
    [@bs.send]
    external hasHeader: (subtype('w, 'r, 'a), string) => bool = "hasHeader";
    [@bs.get]
    external headersSent: subtype('w, 'r, 'a) => bool = "headersSent";
    [@bs.send]
    external removeHeader: (subtype('w, 'r, 'a), string) => unit =
      "removeHeader";
    [@bs.get] external sendDate: subtype('w, 'r, 'a) => bool = "sendDate";
    [@bs.send]
    external setHeader: (subtype('w, 'r, 'a), string, 'any) => unit =
      "setHeader";
    [@bs.send]
    external setHeaderArray:
      (subtype('w, 'r, 'a), string, array('any)) => unit =
      "setHeader";
    [@bs.send]
    external setTimeout: (subtype('w, 'r, 'a), int) => unit = "setTimeout";
    [@bs.send]
    external setTimeoutWithCallback:
      (subtype('w, 'r, 'a), int, unit => unit) => unit =
      "setTimeout";
    [@bs.get]
    external socket: subtype('w, 'r, 'a) => Net__.TcpSocket.t = "socket";
    [@bs.get]
    external statusMessage: subtype('w, 'r, 'a) => string = "statusMessage";
    [@bs.get]
    external writableEnded: subtype('w, 'r, 'a) => bool = "writableEnded";
    [@bs.get]
    external writableFinished: subtype('w, 'r, 'a) => bool =
      "writableFinished";
    [@bs.send]
    external writeContinue: subtype('w, 'r, 'a) => unit = "writeContinue";
    [@bs.send]
    external writeHead:
      (subtype('w, 'r, 'a), int, Js.t({..})) => subtype('w, 'r, 'a) =
      "writeHead";
    [@bs.send]
    external writeHeadWithMessage:
      (subtype('w, 'r, 'a), int, string, Js.t({..})) => subtype('w, 'r, 'a) =
      "writeHead";
    [@bs.send]
    external writeProcessing: subtype('w, 'r, 'a) => unit = "writeProcessing";
  };

  include Impl;
};

module Agent = {
  type t;
  [@bs.send]
  external createConnection: (t, Js.t({..})) => Net__.TcpSocket.t =
    "createConnection";
  [@bs.send]
  external createConnectionWithCallback:
    (t, Js.t({..}), unit => unit) => Net__.TcpSocket.t =
    "createConnection";
  [@bs.send]
  external keepSocketAlive: (t, Net__.TcpSocket.t) => unit = "keepSocketAlive";
  [@bs.send]
  external reuseSocket: (t, Net__.TcpSocket.t, ClientRequest.t) => unit =
    "reuseSocket";
  [@bs.send] external destroy: t => unit = "destroy";
  [@bs.get] external freeSockets: t => Js.t({..}) = "freeSockets";
  [@bs.send] external getName: (t, Js.t({..})) => string = "getName";
  [@bs.send] external maxFreeSockets: t => int = "maxFreeSockets";
  [@bs.send] external maxSockets: t => int = "maxSockets";
  [@bs.get] external requests: t => Js.t({..}) = "requests";
  [@bs.get] external sockets: t => Js.t({..}) = "sockets";
};

module Server = {
  type kind = [ Net__.TcpServer.kind | http];
  type subtype('a) = Net__.Server.subtype([> kind] as 'a);
  type supertype('a) = Net__.Server.subtype([< kind] as 'a);
  type t = subtype(kind);
  module Events = {
    include Net__.TcpServer.Events;
    [@bs.send]
    external onCheckContinue:
      (
        subtype('a),
        [@bs.as "checkContinue"] _,
        [@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onCheckExpectation:
      (
        subtype('a),
        [@bs.as "checkExpectation"] _,
        [@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onClientError:
      (
        subtype('a),
        [@bs.as "clientError"] _,
        [@bs.uncurry] ((Js.Exn.t, Net__.TcpSocket.t) => unit)
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onConnect:
      (
        subtype('a),
        [@bs.as "connect"] _,
        [@bs.uncurry] (
          (IncomingMessage.t, Net__.TcpSocket.t, Js.nullable(Buffer.t)) =>
          unit
        )
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onRequest:
      (
        subtype('a),
        [@bs.as "request"] _,
        [@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onUpgrade:
      (
        subtype('a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (
          (IncomingMessage.t, Net__.TcpSocket.t, Js.nullable(Buffer.t)) =>
          unit
        )
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onTimeout:
      (
        subtype('a),
        [@bs.as "timeout"] _,
        [@bs.uncurry] (Net__.TcpSocket.t => unit)
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external offCheckContinue:
      (
        subtype('a),
        [@bs.as "checkContinue"] _,
        [@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offCheckExpectation:
      (
        subtype('a),
        [@bs.as "checkExpectation"] _,
        [@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offClientError:
      (
        subtype('a),
        [@bs.as "clientError"] _,
        [@bs.uncurry] ((Js.Exn.t, Net__.TcpSocket.t) => unit)
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offConnect:
      (
        subtype('a),
        [@bs.as "connect"] _,
        [@bs.uncurry] (
          (IncomingMessage.t, Net__.TcpSocket.t, Js.nullable(Buffer.t)) =>
          unit
        )
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offRequest:
      (
        subtype('a),
        [@bs.as "request"] _,
        [@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offUpgrade:
      (
        subtype('a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (
          (IncomingMessage.t, Net__.TcpSocket.t, Js.nullable(Buffer.t)) =>
          unit
        )
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offTimeout:
      (
        subtype('a),
        [@bs.as "timeout"] _,
        [@bs.uncurry] (Net__.TcpSocket.t => unit)
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external onCheckContinueOnce:
      (
        subtype('a),
        [@bs.as "checkContinue"] _,
        [@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onCheckExpectationOnce:
      (
        subtype('a),
        [@bs.as "checkExpectation"] _,
        [@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onClientErrorOnce:
      (
        subtype('a),
        [@bs.as "clientError"] _,
        [@bs.uncurry] ((Js.Exn.t, Net__.TcpSocket.t) => unit)
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onConnectOnce:
      (
        subtype('a),
        [@bs.as "connect"] _,
        [@bs.uncurry] (
          (IncomingMessage.t, Net__.TcpSocket.t, Js.nullable(Buffer.t)) =>
          unit
        )
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onRequestOnce:
      (
        subtype('a),
        [@bs.as "request"] _,
        [@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onUpgradeOnce:
      (
        subtype('a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (
          (IncomingMessage.t, Net__.TcpSocket.t, Js.nullable(Buffer.t)) =>
          unit
        )
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onTimeoutOnce:
      (
        subtype('a),
        [@bs.as "timeout"] _,
        [@bs.uncurry] (Net__.TcpSocket.t => unit)
      ) =>
      subtype('a) =
      "once";
  };
  module Impl = {
    include Events;
    [@bs.send]
    external setTimeout:
      (subtype('a), int, [@bs.uncurry] (Net__.TcpSocket.t => unit)) => unit =
      "setTimeout";
    [@bs.get] external timeout: subtype('a) => int = "timeout";
    [@bs.send]
    external keepAliveTimeout: (subtype('a), int) => unit =
      "keepAliveTimeout";
    include Net__.TcpServer.Impl;
  };

  [@bs.send]
  external listen:
    (t, ~port: int, ~host: string, ~callback: unit => unit=?, unit) => t =
    "listen";

  include Impl;
};

type createServerOptions;

[@bs.obj]
external createServerOptions:
  (
    ~incomingMessage: IncomingMessage.t=?,
    ~serverResponse: ServerResponse.t=?,
    ~maxHeaderSize: int=?,
    unit
  ) =>
  createServerOptions;

[@bs.module "http"]
external createServer:
  ([@bs.uncurry] ((IncomingMessage.t, ServerResponse.t) => unit)) => Server.t =
  "createServer";

[@bs.module "http"]
external createServerWithOptions:
  (createServerOptions, (IncomingMessage.t, ServerResponse.t) => unit) =>
  Server.t =
  "createServer";

[@bs.module "http"] external _METHODS: array(string) = "METHODS";
[@bs.module "http"]
external _STATUS_CODES: Js.Dict.t(string) = "STATUS_CODES";

type requestOptions;
[@bs.obj]
external requestOptions:
  (
    ~agent: Agent.t=?,
    ~auth: string=?,
    ~createConnection: unit => Net__.TcpSocket.t=?,
    ~defaultPort: int=?,
    ~family: int=?,
    ~headers: headersObject=?,
    ~host: string=?,
    ~hostName: string=?,
    ~localAddress: string=?,
    ~lookup: (string, Dns.lookupOptions, (Js.Exn.t, string, int) => unit) =>
             string
               =?,
    ~maxHeaderSize: int=?,
    ~method: string=?,
    ~path: string=?,
    ~port: int=?,
    ~protocol: string=?,
    ~setHost: bool=?,
    ~socketPath: string=?,
    ~timeout: int=?
  ) =>
  requestOptions;

[@bs.module "http"] external request: string => ClientRequest.t = "request";
[@bs.module "http"]
external requestWithCallback:
  (string, IncomingMessage.t => unit) => ClientRequest.t =
  "request";
[@bs.module "http"]
external requestWithOptions: (string, requestOptions) => ClientRequest.t =
  "request";
[@bs.module "http"]
external requestWithOptionsCallback:
  (string, requestOptions, IncomingMessage.t => unit) => ClientRequest.t =
  "request";
[@bs.module "http"] external requestUrl: Url.t => ClientRequest.t = "request";
[@bs.module "http"]
external requestUrlWithCallback:
  (Url.t, IncomingMessage.t => unit) => ClientRequest.t =
  "request";
[@bs.module "http"]
external requestUrlWithOptions: (Url.t, requestOptions) => ClientRequest.t =
  "request";
[@bs.module "http"]
external requestUrlWithOptionsCallback:
  (Url.t, requestOptions, IncomingMessage.t => unit) => ClientRequest.t =
  "request";

[@bs.module "http"] external get: string => ClientRequest.t = "get";
[@bs.module "http"]
external getWithCallback:
  (string, IncomingMessage.t => unit) => ClientRequest.t =
  "get";
[@bs.module "http"]
external getWithOptions: (string, requestOptions) => ClientRequest.t = "get";
[@bs.module "http"]
external getWithOptionsCallback:
  (string, requestOptions, IncomingMessage.t => unit) => ClientRequest.t =
  "get";

[@bs.module "http"] external getUrl: Url.t => ClientRequest.t = "get";
[@bs.module "http"]
external getUrlWithCallback:
  (Url.t, IncomingMessage.t => unit) => ClientRequest.t =
  "get";
[@bs.module "http"]
external getUrlWithOptions: (Url.t, requestOptions) => ClientRequest.t = "get";
[@bs.module "http"]
external getUrlWithOptionsCallback:
  (Url.t, requestOptions, IncomingMessage.t => unit) => ClientRequest.t =
  "get";

[@bs.module "http"] external globalAgent: Agent.t = "globalAgent";
[@bs.module "http"] external maxHeaderSize: int = "maxHeaderSize";

type statusCodes = Js.Dict.t(string);
[@bs.module "http"] external _STATUS_CODES: statusCodes = "STATUS_CODES";

type methods = array(string);
[@bs.module "http"] external _METHODS: methods = "METHODS";