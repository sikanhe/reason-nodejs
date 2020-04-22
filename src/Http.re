type http = [ | `Http];

module IncomingMessage = {
  type kind = [ Stream.readable | `IncomingMessage];
  type subtype('data, 'a) = Stream.subtype('data, [> kind] as 'a);
  type supertype('data, 'a) = Stream.subtype('data, [< kind] as 'a);
  type t = subtype(Buffer.t, [ kind]);
  module Events = {
    include Stream.Readable.Events;
    [@bs.send]
    external onAborted:
      (subtype('data, 'a), [@bs.as "aborted"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external onClose:
      (subtype('data, 'a), [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external offAborted:
      (subtype('data, 'a), [@bs.as "aborted"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external offClose:
      (subtype('data, 'a), [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external onAbortedOnce:
      (subtype('data, 'a), [@bs.as "aborted"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "once";
    [@bs.send]
    external onCloseOnce:
      (subtype('data, 'a), [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "once";
  };
  module Impl = {
    include Stream.Readable.Impl;
    include Events;
    [@bs.get] external method_: subtype('data, 'a) => string = "method";
    [@bs.get] external url: subtype('data, 'a) => string = "url";
    [@bs.get] external port: subtype('data, 'a) => int = "port";
    [@bs.get] external headers: subtype('data, 'a) => Js.Dict.t(string) = "headers";
    [@bs.get] external rawHeaders: subtype('data, 'a) => array(string) = "rawHeaders";
    [@bs.get] external rawTrailers: subtype('data, 'a) => array(string) = "rawTrailers";
    [@bs.get] external connection: subtype('data, 'a) => Net.TcpSocket.t = "connection";
    [@bs.get] external aborted: subtype('data, 'a) => bool = "aborted";
    [@bs.get] external complete: subtype('data, 'a) => bool = "complete";
    [@bs.send] external destroy: subtype('data, 'a) => unit = "destroy";
    [@bs.send] external destroyWithError: (subtype('data, 'a), Js.Exn.t) => bool = "destroy";
    [@bs.send]
    external setTimeout: (subtype('data, 'a), int) => subtype('data, 'a) = "setTimeout";
    [@bs.send]
    external setTimeoutWithCallback:
      (subtype('data, 'a), int, subtype('data, 'a) => unit) => subtype('data, 'a) =
      "setTimeout";
    [@bs.get] external socket: subtype('data, 'a) => Net.Socket.subtype('b) = "socket";
    [@bs.get] external statusCode: subtype('data, 'a) => int = "statusCode";
    [@bs.get] external statusMessage: subtype('data, 'a) => string = "statusMessage";
    [@bs.get] external trailers: subtype('data, 'a) => Js.Dict.t(string) = "trailers";
  };
  include Impl;
};

module ClientRequest = {
  type kind = [ Stream.duplex | `ClientRequest];
  type subtype('data, 'a) = Stream.subtype('data, [> kind] as 'a);
  type supertype('data, 'a) = Stream.subtype('data, [< kind] as 'a);
  type t = subtype(Buffer.t, [ kind]);
  type information('a) = {
    .
    "httpVersion": string,
    "httpVersionMajor": int,
    "httpVersionMinor": int,
    "statusCode": int,
    "statusMessage": string,
    "headers": Js.t({..} as 'a),
    "rawHeaders": array(string),
  };
  module Events = {
    include Stream.Duplex.Events;
    [@bs.send]
    external onAbort:
      (subtype('data, 'a), [@bs.as "abort"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external onConnect:
      (
        subtype('data, 'a),
        [@bs.as "connect"] _,
        (IncomingMessage.subtype('data, 'b), Net.Socket.subtype('c), Buffer.t) => unit
      ) =>
      unit =
      "on";
    [@bs.send]
    external onContinue:
      (subtype('data, 'a), [@bs.as "continue"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external onInformation:
      (subtype('data, 'a), [@bs.as "information"] _, [@bs.uncurry] (information('b)) => unit) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external onResponse:
      (
        subtype('data, 'a),
        [@bs.as "response"] _,
        [@bs.uncurry] (IncomingMessage.subtype('data, 'b)) => unit
      ) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external onSocket:
      (subtype('data, 'a), [@bs.as "socket"] _, [@bs.uncurry] (Net.TcpSocket.t) => unit) =>
      subtype('data, 'a) =
      "on";
    [@bs.send]
    external onTimeout:
      (subtype('data, 'a), [@bs.as "timeout"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external onUpgrade:
      (
        subtype('data, 'a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (IncomingMessage.subtype('data, 'b), Net.TcpSocket.t, Buffer.t) => unit
      ) =>
      subtype('data, 'a) =
      "on";

    [@bs.send]
    external offAbort:
      (subtype('data, 'a), [@bs.as "abort"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external offConnect:
      (
        subtype('data, 'a),
        [@bs.as "connect"] _,
        (IncomingMessage.subtype('data, 'b), Net.Socket.subtype('c), Buffer.t) => unit
      ) =>
      unit =
      "off";
    [@bs.send]
    external offContinue:
      (subtype('data, 'a), [@bs.as "continue"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external offInformation:
      (subtype('data, 'a), [@bs.as "information"] _, [@bs.uncurry] (information('b)) => unit) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external offResponse:
      (
        subtype('data, 'a),
        [@bs.as "response"] _,
        [@bs.uncurry] (IncomingMessage.subtype('data, 'b)) => unit
      ) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external offSocket:
      (subtype('data, 'a), [@bs.as "socket"] _, [@bs.uncurry] (Net.TcpSocket.t) => unit) =>
      subtype('data, 'a) =
      "off";
    [@bs.send]
    external offTimeout:
      (subtype('data, 'a), [@bs.as "timeout"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external offUpgrade:
      (
        subtype('data, 'a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (IncomingMessage.subtype('data, 'b), Net.TcpSocket.t, Buffer.t) => unit
      ) =>
      subtype('data, 'a) =
      "off";

    [@bs.send]
    external onAbortOnce:
      (subtype('data, 'a), [@bs.as "abort"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "once";
    [@bs.send]
    external onConnectOnce:
      (
        subtype('data, 'a),
        [@bs.as "connect"] _,
        (IncomingMessage.subtype('data, 'b), Net.Socket.subtype('c), Buffer.t) => unit
      ) =>
      unit =
      "once";
    [@bs.send]
    external onContinueOnce:
      (subtype('data, 'a), [@bs.as "continue"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "once";
    [@bs.send]
    external onInformationOnce:
      (subtype('data, 'a), [@bs.as "information"] _, [@bs.uncurry] (information('b)) => unit) =>
      subtype('data, 'a) =
      "once";
    [@bs.send]
    external onResponseOnce:
      (
        subtype('data, 'a),
        [@bs.as "response"] _,
        [@bs.uncurry] (IncomingMessage.subtype('data, 'b)) => unit
      ) =>
      subtype('data, 'a) =
      "once";
    [@bs.send]
    external onSocketOnce:
      (subtype('data, 'a), [@bs.as "socket"] _, [@bs.uncurry] (Net.TcpSocket.t) => unit) =>
      subtype('data, 'a) =
      "once";
    [@bs.send]
    external onTimeoutOnce:
      (subtype('data, 'a), [@bs.as "timeout"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "once";
    [@bs.send]
    external onUpgradeOnce:
      (
        subtype('data, 'a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (IncomingMessage.subtype('data, 'b), Net.TcpSocket.t, Buffer.t) => unit
      ) =>
      subtype('data, 'a) =
      "once";
  };
  module Impl = {
    include Stream.Duplex.Impl;
    include Events;
    [@bs.send] external abort: subtype('data, 'a) => unit = "abort";
    [@bs.get] external aborted: subtype('data, 'a) => bool = "aborted";
    [@bs.send] external end_: subtype('data, 'a) => unit = "end";
    [@bs.send] external endWithData: (subtype('data, 'a), Buffer.t) => unit = "end";
    [@bs.send] external endWithCallback: (subtype('data, 'a), unit => unit) => unit = "end";
    [@bs.send]
    external endWithDataCallback: (subtype('data, 'a), Buffer.t, unit => unit) => unit = "end";
    [@bs.send] external flushHeaders: subtype('data, 'a) => unit = "flushHeaders";
    [@bs.send] external getHeader: (subtype('data, 'a), string) => 'any = "getHeader";
    [@bs.send] external maxHeadersCount: subtype('data, 'a) => int = "maxHeadersCount";
    [@bs.send] external path: subtype('data, 'a) => string = "path";
    [@bs.send] external reusedSocket: subtype('data, 'a) => bool = "reusedSocket";
    [@bs.send] external setHeader: (subtype('data, 'a), string, 'any) => unit = "setHeader";
    [@bs.send]
    external setHeaderArray: (subtype('data, 'a), string, array('any)) => unit = "setHeader";
    [@bs.send] external setNoDelay: (subtype('data, 'a), bool) => unit = "setNoDelay";
    [@bs.send]
    external setSocketKeepAlive: (subtype('data, 'a), bool) => unit = "setSocketKeepAlive";
    [@bs.send]
    external setSocketKeepAliveWithDelay: (subtype('data, 'a), bool, int) => unit =
      "setSocketKeepAlive";
    [@bs.send] external setTimeout: (subtype('data, 'a), int) => unit = "setTimeout";
    [@bs.send]
    external setTimeoutWithCallback: (subtype('data, 'a), int, unit => unit) => unit =
      "setTimeout";
    [@bs.send] external socket: subtype('data, 'a) => Net.TcpSocket.t = "socket";
    [@bs.send] external writableEnded: subtype('data, 'a) => bool = "writableEnded";
    [@bs.send] external write: (subtype('data, 'a), Buffer.t) => bool = "write";
    [@bs.send]
    external writeWithCallback: (subtype('data, 'a), Buffer.t, unit => unit) => bool = "write";
  };

  include Impl;
};

module ServerResponse = {
  type kind = [ Stream.duplex | `ServerResponse];
  type subtype('data, 'a) = Stream.subtype('data, [> kind] as 'a);
  type supertype('data, 'a) = Stream.subtype('data, [< kind] as 'a);
  type t = subtype(Buffer.t, [ kind]);
  module Events = {
    include Stream.Duplex.Events;
    [@bs.send]
    external onClose:
      (subtype('data, 'a), [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external onFinish:
      (subtype('data, 'a), [@bs.as "finish"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "on";
    [@bs.send]
    external offClose:
      (subtype('data, 'a), [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external offFinish:
      (subtype('data, 'a), [@bs.as "finish"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "off";
    [@bs.send]
    external onCloseOnce:
      (subtype('data, 'a), [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "once";
    [@bs.send]
    external onFinishOnce:
      (subtype('data, 'a), [@bs.as "finish"] _, [@bs.uncurry] (unit) => unit) => subtype('data, 'a) =
      "once";
  };
  module Impl = {
    include Stream.Duplex.Impl;
    include Events;
    [@bs.get] external statusCode: subtype('data, 'a) => int = "statusCode";
    [@bs.set] external setStatusCode: (subtype('data, 'a), int) => unit = "statusCode";
    [@bs.send] external write: (subtype('data, 'a), Buffer.t) => bool = "write";
    [@bs.send]
    external writeWithEncodingCallback: (subtype('data, 'a), Buffer.t, unit => unit) => bool =
      "write";
    [@bs.send] external writeStatus: (subtype('data, 'a), int) => unit = "writeHead";
    [@bs.send] external cork: subtype('data, 'a) => unit = "cork";
    [@bs.send] external end_: subtype('data, 'a) => unit = "end";
    [@bs.send] external endWithData: (subtype('data, 'a), Buffer.t) => unit = "end";
    [@bs.send] external endWithCallback: (subtype('data, 'a), unit => unit) => unit = "end";
    [@bs.send]
    external endWithDataCallback: (subtype('data, 'a), Buffer.t, unit => unit) => unit = "end";
    [@bs.send] external uncork: subtype('data, 'a) => unit = "uncork";
    [@bs.send] external flushHeaders: subtype('data, 'a) => unit = "flushHeaders";
    [@bs.send] external getHeader: (subtype('data, 'a), string) => 'any = "getHeader";
    [@bs.send] external getHeaderNames: subtype('data, 'a) => array(string) = "getHeaderNames";
    [@bs.send] external getHeaders: subtype('data, 'a) => Js.t({..}) = "getHeaders";
    [@bs.send] external hasHeader: (subtype('data, 'a), string) => bool = "hasHeader";
    [@bs.get] external headersSent: subtype('data, 'a) => bool = "headersSent";
    [@bs.send] external removeHeader: (subtype('data, 'a), string) => unit = "removeHeader";
    [@bs.get] external sendDate: subtype('data, 'a) => bool = "sendDate";
    [@bs.send] external setHeader: (subtype('data, 'a), string, 'any) => unit = "setHeader";
    [@bs.send]
    external setHeaderArray: (subtype('data, 'a), string, array('any)) => unit = "setHeader";
    [@bs.send] external setTimeout: (subtype('data, 'a), int) => unit = "setTimeout";
    [@bs.send]
    external setTimeoutWithCallback: (subtype('data, 'a), int, unit => unit) => unit =
      "setTimeout";
    [@bs.get] external socket: subtype('data, 'a) => Net.TcpSocket.t = "socket";
    [@bs.get] external statusMessage: subtype('data, 'a) => string = "statusMessage";
    [@bs.get] external writableEnded: subtype('data, 'a) => bool = "writableEnded";
    [@bs.get] external writableFinished: subtype('data, 'a) => bool = "writableFinished";
    [@bs.send] external writeContinue: subtype('data, 'a) => unit = "writeContinue";
    [@bs.send]
    external writeHead: (subtype('data, 'a), int, Js.t({..})) => subtype('data, 'a) =
      "writeHead";
    [@bs.send]
    external writeHeadWithMessage:
      (subtype('data, 'a), int, string, Js.t({..})) => subtype('data, 'a) =
      "writeHead";
    [@bs.send] external writeProcessing: subtype('data, 'a) => unit = "writeProcessing";
  };

  include Impl;
};

module Agent = {
  type t;
  [@bs.send] external createConnection: (t, Js.t({..})) => Net.TcpSocket.t = "createConnection";
  [@bs.send]
  external createConnectionWithCallback: (t, Js.t({..}), unit => unit) => Net.TcpSocket.t =
    "createConnection";
  [@bs.send] external keepSocketAlive: (t, Net.TcpSocket.t) => unit = "keepSocketAlive";
  [@bs.send] external reuseSocket: (t, Net.TcpSocket.t, ClientRequest.t) => unit = "reuseSocket";
  [@bs.send] external destroy: t => unit = "destroy";
  [@bs.get] external freeSockets: t => Js.t({..}) = "freeSockets";
  [@bs.send] external getName: (t, Js.t({..})) => string = "getName";
  [@bs.send] external maxFreeSockets: t => int = "maxFreeSockets";
  [@bs.send] external maxSockets: t => int = "maxSockets";
  [@bs.get] external requests: t => Js.t({..}) = "requests";
  [@bs.get] external sockets: t => Js.t({..}) = "sockets";
};

module Server = {
  type kind = [ Net.TcpServer.kind | http];
  type subtype('a) = Net.Server.subtype([> kind] as 'a);
  type supertype('a) = Net.Server.subtype([< kind] as 'a);
  type t = subtype(kind);
  module Events = {
    include Net.TcpServer.Events;
    [@bs.send]
    external onCheckContinue:
      (
        subtype('a),
        [@bs.as "checkContinue"] _,
        [@bs.uncurry] (IncomingMessage.t, ServerResponse.t) => unit
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onCheckExpectation:
      (
        subtype('a),
        [@bs.as "checkExpectation"] _,
        [@bs.uncurry] (IncomingMessage.t, ServerResponse.t) => unit
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onClientError:
      (subtype('a), [@bs.as "clientError"] _, [@bs.uncurry] (Js.Exn.t, Net.TcpSocket.t) => unit) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onConnect:
      (
        subtype('a),
        [@bs.as "connect"] _,
        [@bs.uncurry] (IncomingMessage.t, Net.TcpSocket.t, Js.nullable(Buffer.t)) => unit
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onRequest:
      (subtype('a), [@bs.as "request"] _, [@bs.uncurry] (IncomingMessage.t, ServerResponse.t) => unit) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onUpgrade:
      (
        subtype('a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (IncomingMessage.t, Net.TcpSocket.t, Js.nullable(Buffer.t)) => unit
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onTimeout:
      (subtype('a), [@bs.as "timeout"] _, [@bs.uncurry] (Net.TcpSocket.t) => unit) => subtype('a) =
      "on";
    [@bs.send]
    external offCheckContinue:
      (
        subtype('a),
        [@bs.as "checkContinue"] _,
        [@bs.uncurry] (IncomingMessage.t, ServerResponse.t) => unit
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offCheckExpectation:
      (
        subtype('a),
        [@bs.as "checkExpectation"] _,
        [@bs.uncurry] (IncomingMessage.t, ServerResponse.t) => unit
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offClientError:
      (subtype('a), [@bs.as "clientError"] _, [@bs.uncurry] (Js.Exn.t, Net.TcpSocket.t) => unit) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offConnect:
      (
        subtype('a),
        [@bs.as "connect"] _,
        [@bs.uncurry] (IncomingMessage.t, Net.TcpSocket.t, Js.nullable(Buffer.t)) => unit
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offRequest:
      (subtype('a), [@bs.as "request"] _, [@bs.uncurry] (IncomingMessage.t, ServerResponse.t) => unit) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offUpgrade:
      (
        subtype('a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (IncomingMessage.t, Net.TcpSocket.t, Js.nullable(Buffer.t)) => unit
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offTimeout:
      (subtype('a), [@bs.as "timeout"] _, [@bs.uncurry] (Net.TcpSocket.t) => unit) => subtype('a) =
      "off";
    [@bs.send]
    external onCheckContinueOnce:
      (
        subtype('a),
        [@bs.as "checkContinue"] _,
        [@bs.uncurry] (IncomingMessage.t, ServerResponse.t) => unit
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onCheckExpectationOnce:
      (
        subtype('a),
        [@bs.as "checkExpectation"] _,
        [@bs.uncurry] (IncomingMessage.t, ServerResponse.t) => unit
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onClientErrorOnce:
      (subtype('a), [@bs.as "clientError"] _, [@bs.uncurry] (Js.Exn.t, Net.TcpSocket.t) => unit) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onConnectOnce:
      (
        subtype('a),
        [@bs.as "connect"] _,
        [@bs.uncurry] (IncomingMessage.t, Net.TcpSocket.t, Js.nullable(Buffer.t)) => unit
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onRequestOnce:
      (subtype('a), [@bs.as "request"] _, [@bs.uncurry] (IncomingMessage.t, ServerResponse.t) => unit) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onUpgradeOnce:
      (
        subtype('a),
        [@bs.as "upgrade"] _,
        [@bs.uncurry] (IncomingMessage.t, Net.TcpSocket.t, Js.nullable(Buffer.t)) => unit
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onTimeoutOnce:
      (subtype('a), [@bs.as "timeout"] _, [@bs.uncurry] (Net.TcpSocket.t) => unit) => subtype('a) =
      "once";
  };
  module Impl = {
    include Events;
    [@bs.send]
    external setTimeout: (subtype('a), int, [@bs.uncurry] (Net.TcpSocket.t) => unit) => unit = "setTimeout";
    [@bs.get] external timeout: subtype('a) => int = "timeout";
    [@bs.send] external keepAliveTimeout: (subtype('a), int) => unit = "keepAliveTimeout";
    include Net.TcpServer.Impl;
  };
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
external createServer: ((IncomingMessage.t, ServerResponse.t) => unit) => Server.t =
  "createServer";

[@bs.module "http"]
external createServerWithOptions:
  (createServerOptions, (IncomingMessage.t, ServerResponse.t) => unit) => Server.t =
  "createServer";

[@bs.module "http"] external _METHODS: array(string) = "METHODS";
[@bs.module "http"] external _STATUS_CODES: Js.Dict.t(string) = "STATUS_CODES";

type requestOptions;
[@bs.obj]
external requestOptions:
  (
    ~agent: Agent.t=?,
    ~auth: string=?,
    ~createConnection: unit => Net.TcpSocket.t=?,
    ~defaultPort: int=?,
    ~family: int=?,
    ~headers: Js.t({..})=?,
    ~host: string=?,
    ~hostName: string=?,
    ~localAddress: string=?,
    ~lookup: (string, Dns.lookupOptions, (Js.Exn.t, string, int) => unit) => string=?,
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
external requestWithCallback: (string, IncomingMessage.t => unit) => ClientRequest.t = "request";
[@bs.module "http"]
external requestWithOptions: (string, requestOptions) => ClientRequest.t = "request";
[@bs.module "http"]
external requestWithOptionsCallback:
  (string, requestOptions, IncomingMessage.t => unit) => ClientRequest.t =
  "request";
[@bs.module "http"] external requestUrl: Url.t => ClientRequest.t = "request";
[@bs.module "http"]
external requestUrlWithCallback: (Url.t, IncomingMessage.t => unit) => ClientRequest.t = "request";
[@bs.module "http"]
external requestUrlWithOptions: (Url.t, requestOptions) => ClientRequest.t = "request";
[@bs.module "http"]
external requestUrlWithOptionsCallback:
  (Url.t, requestOptions, IncomingMessage.t => unit) => ClientRequest.t =
  "request";

[@bs.module "http"] external get: string => ClientRequest.t = "get";
[@bs.module "http"]
external getWithCallback: (string, IncomingMessage.t => unit) => ClientRequest.t = "get";
[@bs.module "http"] external getWithOptions: (string, requestOptions) => ClientRequest.t = "get";
[@bs.module "http"]
external getWithOptionsCallback:
  (string, requestOptions, IncomingMessage.t => unit) => ClientRequest.t =
  "get";

[@bs.module "http"] external getUrl: Url.t => ClientRequest.t = "get";
[@bs.module "http"]
external getUrlWithCallback: (Url.t, IncomingMessage.t => unit) => ClientRequest.t = "get";
[@bs.module "http"] external getUrlWithOptions: (Url.t, requestOptions) => ClientRequest.t = "get";
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
