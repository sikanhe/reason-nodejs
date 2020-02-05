module IncomingMessage = {
  include Stream.Readable;
  type t = Stream.t([ Stream.readable | `Http]);
  [@bs.get] external method_: t => string = "method";
  [@bs.get] external url: t => string = "url";
  [@bs.get] external port: t => int = "port";
  [@bs.get] external headers: t => Js.Dict.t(string) = "headers";
  [@bs.get] external rawHeaders: t => array(string) = "rawHeaders";
  [@bs.get] external rawTrailers: t => array(string) = "rawTrailers";
  [@bs.get] external connection: t => Net.Socket.t = "connection";
  [@bs.get] external aborted: t => bool = "aborted";
  [@bs.get] external complete: t => bool = "complete";
  [@bs.send] external destroy: t => unit = "destroy";
  [@bs.send] external destroyWithError: (t, Js.Exn.t) => bool = "destroy";
  [@bs.send] external setTimeout: (t, int, unit => unit) => t = "setTimeout";
  [@bs.get] external socket: t => Stream.t(Stream.duplex) = "socket";
  [@bs.get] external statusCode: t => int = "statusCode";
  [@bs.get] external statusMessage: t => string = "statusMessage";
  [@bs.get] external trailers: t => Js.Dict.t(string) = "trailers";
};

module ClientRequest = {
  include Stream.Duplex;
  type t = Stream.t([ Stream.duplex | `Http]);

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

  [@bs.send] external onAbort: (t, [@bs.as "abort"] _, unit => unit) => unit = "on";
  [@bs.send]
  external onConnect:
    (t, [@bs.as "connect"] _, (IncomingMessage.t, Net.Socket.t, Buffer.t) => unit) => unit =
    "on";
  [@bs.send] external onContinue: (t, [@bs.as "continue"] _, unit => unit) => unit = "on";
  [@bs.send]
  external onInformation: (t, [@bs.as "information"] _, information('a) => unit) => unit = "on";
  [@bs.send]
  external onResponse: (t, [@bs.as "response"] _, IncomingMessage.t => unit) => unit = "on";
  [@bs.send] external onSocket: (t, [@bs.as "socket"] _, Net.Socket.t => unit) => unit = "on";
  [@bs.send] external onTimeout: (t, [@bs.as "timeout"] _, unit => unit) => unit = "on";
  [@bs.send]
  external onUpgrade:
    (t, [@bs.as "upgrade"] _, (IncomingMessage.t, Net.Socket.t, Buffer.t) => unit) => unit =
    "on";
  [@bs.send] external abort: t => unit = "abort";
  [@bs.get] external aborted: t => bool = "aborted";
  [@bs.send] external end_: t => unit = "end";
  [@bs.send] external endWithData: (t, StringBuffer.t) => unit = "end";
  [@bs.send]
  external endWithDataEncoding:
    (
      t,
      StringBuffer.t,
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
    ) =>
    unit =
    "end";
  [@bs.send]
  external endWithDataEncodingCallback:
    (
      t,
      StringBuffer.t,
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
      ],
      unit => unit
    ) =>
    unit =
    "end";
  [@bs.send] external flushHeaders: t => unit = "flushHeaders";
  [@bs.send] external getHeader: (t, string) => 'a = "getHeader";
  [@bs.send] external maxHeadersCount: t => int = "maxHeadersCount";
  [@bs.send] external path: t => string = "path";
  [@bs.send] external reusedSocket: t => bool = "reusedSocket";
  [@bs.send] external setHeader: (t, string, 'a) => unit = "setHeader";
  [@bs.send] external setHeaderArray: (t, string, array('a)) => unit = "setHeader";
  [@bs.send] external setNoDelay: (t, bool) => unit = "setNoDelay";
  [@bs.send] external setSocketKeepAlive: (t, bool) => unit = "setSocketKeepAlive";
  [@bs.send] external setSocketKeepAliveWithDelay: (t, bool, int) => unit = "setSocketKeepAlive";
  [@bs.send] external setTimeout: (t, int) => unit = "setTimeout";
  [@bs.send] external setTimeoutWithCallback: (t, int, unit => unit) => unit = "setTimeout";
  [@bs.send] external socket: t => Stream.t(Net.Socket.t) = "socket";
  [@bs.send] external writableEnded: t => bool = "writableEnded";
  [@bs.send] external write: (t, StringBuffer.t) => bool = "writableEnded";
  [@bs.send]
  external writeWithEncoding:
    (
      t,
      StringBuffer.t,
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
    ) =>
    bool =
    "writableEnded";
  [@bs.send]
  external writeWithEncodingCallback:
    (
      t,
      StringBuffer.t,
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
      ],
      unit => unit
    ) =>
    bool =
    "writableEnded";
};

module ServerResponse = {
  include Stream.Duplex;
  type t = Stream.t([ Stream.duplex | `Http]);
  [@bs.get] external statusCode: t => int = "statusCode";
  [@bs.set] external setStatusCode: (t, int) => unit = "statusCode";
  [@bs.send] external write: (t, StringBuffer.t) => bool = "write";
  [@bs.send]
  external writeWithEncoding:
    (
      t,
      StringBuffer.t,
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
    ) =>
    bool =
    "writableEnded";
  [@bs.send]
  external writeWithEncodingCallback:
    (
      t,
      StringBuffer.t,
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
      ],
      unit => unit
    ) =>
    bool =
    "writableEnded";
  [@bs.send] external writeStatus: (t, int) => unit = "writeHead";
  [@bs.send] external cork: t => unit = "cork";
  [@bs.send] external end_: t => unit = "end";
  [@bs.send] external endWithData: (t, StringBuffer.t) => unit = "end";
  [@bs.send]
  external endWithDataEncoding:
    (
      t,
      StringBuffer.t,
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
    ) =>
    unit =
    "end";
  [@bs.send]
  external endWithDataEncodingCallback:
    (
      t,
      StringBuffer.t,
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
      ],
      unit => unit
    ) =>
    unit =
    "end";
  [@bs.send] external uncork: t => unit = "uncork";
  [@bs.send] external flushHeaders: t => unit = "flushHeaders";
  [@bs.send] external getHeader: (t, string) => 'a = "getHeader";
  [@bs.send] external getHeaderNames: t => array(string) = "getHeaderNames";
  [@bs.send] external getHeaders: t => Js.t({..}) = "getHeaders";
  [@bs.send] external hasHeader: (t, string) => bool = "hasHeader";
  [@bs.get] external headersSent: t => bool = "headersSent";
  [@bs.send] external removeHeader: (t, string) => unit = "removeHeader";
  [@bs.get] external sendDate: t => bool = "sendDate";
  [@bs.send] external setHeader: (t, string, 'a) => unit = "setHeader";
  [@bs.send] external setHeaderArray: (t, string, array('a)) => unit = "setHeader";
  [@bs.send] external setTimeout: (t, int) => unit = "setTimeout";
  [@bs.send] external setTimeoutWithCallback: (t, int, unit => unit) => unit = "setTimeout";
  [@bs.get] external socket: t => Net.Socket.t = "socket";
  [@bs.get] external statusMessage: t => string = "statusMessage";
  [@bs.get] external writableEnded: t => bool = "writableEnded";
  [@bs.get] external writableFinished: t => bool = "writableFinished";
  [@bs.send] external writeContinue: t => unit = "writeContinue";
  [@bs.send] external writeHead: (t, int, Js.t({..})) => t = "writeHead";
  [@bs.send] external writeHeadWithMessage: (t, int, string, Js.t({..})) => t = "writeHead";
  [@bs.send] external writeProcessing: t => unit = "writeProcessing";
};

module Agent = {
  type t;
  [@bs.send] external createConnection: (t, Js.t({..})) => Net.Socket.t = "createConnection";
  [@bs.send]
  external createConnectionWithCallback: (t, Js.t({..}), unit => unit) => Net.Socket.t =
    "createConnection";
  [@bs.send] external keepSocketAlive: (t, Stream.t(Stream.duplex)) => unit = "keepSocketAlive";
  [@bs.send]
  external reuseSocket: (t, Stream.t(Stream.duplex), ClientRequest.t) => unit = "reuseSocket";
  [@bs.send] external destroy: t => unit = "destroy";
  [@bs.get] external freeSockets: t => Js.t({..}) = "freeSockets";
  [@bs.send] external getName: (t, Js.t({..})) => string = "getName";
  [@bs.send] external maxFreeSockets: t => int = "maxFreeSockets";
  [@bs.send] external maxSockets: t => int = "maxSockets";
  [@bs.get] external requests: t => Js.t({..}) = "requests";
  [@bs.get] external sockets: t => Js.t({..}) = "sockets";
};

module Server = {
  type t;
  [@bs.send] external listen: (t, int) => unit = "listen";
  [@bs.send] external close: (t, int) => unit = "close";
  [@bs.get] external listening: t => bool = "listening";
  [@bs.send] external setTimeout: (t, int) => t = "setTimeout";
  [@bs.send] external setTimeoutWithCallback: (t, int, unit => unit) => t = "setTimeout";
  [@bs.get] external timeout: t => int = "timeout";
  [@bs.send] external keepAliveTimeout: (t, int) => unit = "keepAliveTimeout";
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
  createServerOptions =
  "";

[@bs.module "http"]
external createServer: ((IncomingMessage.t, ServerResponse.t) => unit) => Server.t =
  "createServer";

[@bs.module "http"]
external createServerWith:
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
    ~createConnection: unit => Net.Socket.t=?,
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
  requestOptions =
  "";

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
