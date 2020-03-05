module IncomingMessage = {

  type kind = [ Stream.readable | `IncomingMessage ];
  type t = Stream.t(Buffer.t, [ kind ]);

  module Impl = {
    include Stream.Readable.Impl;
    [@bs.get] external method_: Stream.t('data, [> kind ]) => string = "method";
    [@bs.get] external url: Stream.t('data, [> kind ]) => string = "url";
    [@bs.get] external port: Stream.t('data, [> kind ]) => int = "port";
    [@bs.get] external headers: Stream.t('data, [> kind ]) => Js.Dict.t(string) = "headers";
    [@bs.get] external rawHeaders: Stream.t('data, [> kind ]) => array(string) = "rawHeaders";
    [@bs.get] external rawTrailers: Stream.t('data, [> kind ]) => array(string) = "rawTrailers";
    [@bs.get] external connection: Stream.t('data, [> kind ]) => Net.Socket.t = "connection";
    [@bs.get] external aborted: Stream.t('data, [> kind ]) => bool = "aborted";
    [@bs.get] external complete: Stream.t('data, [> kind ]) => bool = "complete";
    [@bs.send] external destroy: Stream.t('data, [> kind ]) => unit = "destroy";
    [@bs.send] external destroyWithError: (Stream.t('data, [> kind ]), Js.Exn.t) => bool = "destroy";
    [@bs.send] external setTimeout: (Stream.t('data, [> kind ] as 'a), int) => Stream.t('data, [> kind ] as 'a) = "setTimeout";
    [@bs.send] external setTimeoutWithCallback: (Stream.t('data, [> kind ] as 'a), int, Stream.t('data, [> kind ] as 'a) => unit) => Stream.t('data, [> kind ] as 'a) = "setTimeout";
    [@bs.get] external socket: Stream.t('data, [> kind ]) => Stream.Duplex.t('data) = "socket";
    [@bs.get] external statusCode: Stream.t('data, [> kind ]) => int = "statusCode";
    [@bs.get] external statusMessage: Stream.t('data, [> kind ]) => string = "statusMessage";
    [@bs.get] external trailers: Stream.t('data, [> kind ]) => Js.Dict.t(string) = "trailers";
  };
  include Impl;
};

module ClientRequest = {

  type kind = [ Stream.duplex | `ClientRequest ];
  type nonrec t = Stream.t(Buffer.t, [ kind ]);

  module Impl = {
    include Stream.Duplex.Impl;

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

    [@bs.send] external onAbort: (Stream.t('data, [> kind]), [@bs.as "abort"] _, unit => unit) => unit = "on";
    [@bs.send] external onConnect: (
        Stream.t('data, [> kind]),
        [@bs.as "connect"] _,
        (
          Stream.t('data, [> IncomingMessage.kind ]),
          Stream.t('data, [> Net.Socket.kind ]),
          Buffer.t
        ) => unit
      ) => unit = "on";
    [@bs.send] external onContinue: (Stream.t('data, [> kind ]), [@bs.as "continue"] _, unit => unit) => unit = "on";
    [@bs.send] external onInformation: (Stream.t('data, [> kind ]), [@bs.as "information"] _, information('a) => unit) => unit = "on";
    [@bs.send] external onResponse: (Stream.t('data, [> kind ]), [@bs.as "response"] _, Stream.t('data, [> IncomingMessage.kind ]) => unit) => unit = "on";
    [@bs.send] external onSocket: (Stream.t('data, [> kind ]), [@bs.as "socket"] _, Stream.t('data, [> Net.Socket.kind ]) => unit) => unit = "on";
    [@bs.send] external onTimeout: (Stream.t('data, [> kind ]), [@bs.as "timeout"] _, unit => unit) => unit = "on";
    [@bs.send] external onUpgrade:
      (Stream.t('data, [> kind ]), [@bs.as "upgrade"] _, (Stream.t('data, [> IncomingMessage.kind ]), Stream.t('data, [> Net.Socket.kind ]), Buffer.t) => unit) => unit =
      "on";
    [@bs.send] external abort: Stream.t('data, [> kind ]) => unit = "abort";
    [@bs.get] external aborted: Stream.t('data, [> kind ]) => bool = "aborted";
    [@bs.send] external end_: Stream.t('data, [> kind ]) => unit = "end";
    [@bs.send] external endWithData: (Stream.t('data, [> kind ]), Buffer.t) => unit = "end";
    [@bs.send] external endWithCallback: (Stream.t('data, [> kind ]), unit => unit) => unit = "end";
    [@bs.send] external endWithDataCallback: (Stream.t('data, [> kind ]), Buffer.t, unit => unit) => unit = "end";
    [@bs.send] external flushHeaders: Stream.t('data, [> kind ]) => unit = "flushHeaders";
    [@bs.send] external getHeader: (Stream.t('data, [> kind ]), string) => 'a = "getHeader";
    [@bs.send] external maxHeadersCount: Stream.t('data, [> kind ]) => int = "maxHeadersCount";
    [@bs.send] external path: Stream.t('data, [> kind ]) => string = "path";
    [@bs.send] external reusedSocket: Stream.t('data, [> kind ]) => bool = "reusedSocket";
    [@bs.send] external setHeader: (Stream.t('data, [> kind ]), string, 'a) => unit = "setHeader";
    [@bs.send] external setHeaderArray: (Stream.t('data, [> kind ]), string, array('a)) => unit = "setHeader";
    [@bs.send] external setNoDelay: (Stream.t('data, [> kind ]), bool) => unit = "setNoDelay";
    [@bs.send] external setSocketKeepAlive: (Stream.t('data, [> kind ]), bool) => unit = "setSocketKeepAlive";
    [@bs.send] external setSocketKeepAliveWithDelay: (Stream.t('data, [> kind ]), bool, int) => unit = "setSocketKeepAlive";
    [@bs.send] external setTimeout: (Stream.t('data, [> kind ]), int) => unit = "setTimeout";
    [@bs.send] external setTimeoutWithCallback: (Stream.t('data, [> kind ]), int, unit => unit) => unit = "setTimeout";
    [@bs.send] external socket: Stream.t('data, [> kind ]) => Stream.t('data, [> Net.Socket.kind ]) = "socket";
    [@bs.send] external writableEnded: Stream.t('data, [> kind ]) => bool = "writableEnded";
    [@bs.send] external write: (Stream.t('data, [> kind ]), Buffer.t) => bool = "write";
    [@bs.send] external writeWithCallback: (Stream.t('data, [> kind ]), Buffer.t, unit => unit) => bool = "write";
  };

  include Impl;

};

module ServerResponse = {
  type kind = [ Stream.duplex | `ServerResponse ];
  type t('data) = Stream.t('data, [ kind ]);
  module Impl = {
    include Stream.Duplex.Impl;
    [@bs.get] external statusCode: Stream.t('data, [> kind ]) => int = "statusCode";
    [@bs.set] external setStatusCode: (Stream.t('data, [> kind ]), int) => unit = "statusCode";
    [@bs.send] external write: (Stream.t('data, [> kind ]), Buffer.t) => bool = "write";
    [@bs.send] external writeWithEncodingCallback: ( Stream.t('data, [> kind ]), Buffer.t, unit => unit) => bool = "write";
    [@bs.send] external writeStatus: (Stream.t('data, [> kind ]), int) => unit = "writeHead";
    [@bs.send] external cork: Stream.t('data, [> kind ]) => unit = "cork";
    [@bs.send] external end_: Stream.t('data, [> kind ]) => unit = "end";
    [@bs.send] external endWithData: (Stream.t('data, [> kind ]), Buffer.t) => unit = "end";
    [@bs.send] external endWithCallback: (Stream.t('data, [> kind ]), unit => unit) => unit = "end";
    [@bs.send] external endWithDataCallback: ( Stream.t('data, [> kind ]), Buffer.t, unit => unit) => unit = "end";
    [@bs.send] external uncork: Stream.t('data, [> kind ]) => unit = "uncork";
    [@bs.send] external flushHeaders: Stream.t('data, [> kind ]) => unit = "flushHeaders";
    [@bs.send] external getHeader: (Stream.t('data, [> kind ]), string) => 'a = "getHeader";
    [@bs.send] external getHeaderNames: Stream.t('data, [> kind ]) => array(string) = "getHeaderNames";
    [@bs.send] external getHeaders: Stream.t('data, [> kind ]) => Js.t({..}) = "getHeaders";
    [@bs.send] external hasHeader: (Stream.t('data, [> kind ]), string) => bool = "hasHeader";
    [@bs.get] external headersSent: Stream.t('data, [> kind ]) => bool = "headersSent";
    [@bs.send] external removeHeader: (Stream.t('data, [> kind ]), string) => unit = "removeHeader";
    [@bs.get] external sendDate: Stream.t('data, [> kind ]) => bool = "sendDate";
    [@bs.send] external setHeader: (Stream.t('data, [> kind ]), string, 'a) => unit = "setHeader";
    [@bs.send] external setHeaderArray: (Stream.t('data, [> kind ]), string, array('a)) => unit = "setHeader";
    [@bs.send] external setTimeout: (Stream.t('data, [> kind ]), int) => unit = "setTimeout";
    [@bs.send] external setTimeoutWithCallback: (Stream.t('data, [> kind ]), int, unit => unit) => unit = "setTimeout";
    [@bs.get] external socket: Stream.t('data, [> kind ]) => Net.Socket.t = "socket";
    [@bs.get] external statusMessage: Stream.t('data, [> kind ]) => string = "statusMessage";
    [@bs.get] external writableEnded: Stream.t('data, [> kind ]) => bool = "writableEnded";
    [@bs.get] external writableFinished: Stream.t('data, [> kind ]) => bool = "writableFinished";
    [@bs.send] external writeContinue: Stream.t('data, [> kind ]) => unit = "writeContinue";
    [@bs.send] external writeHead: (Stream.t('data, [> kind ] as 'a), int, Js.t({..})) => Stream.t('data, [> kind ] as 'a) = "writeHead";
    [@bs.send] external writeHeadWithMessage: (Stream.t('data, [> kind ] as 'a), int, string, Js.t({..})) => Stream.t('data, [> kind ] as 'a) = "writeHead";
    [@bs.send] external writeProcessing: Stream.t('data, [> kind ]) => unit = "writeProcessing";
  };

  include Impl;
};

module Agent = {
  type t;
  [@bs.send] external createConnection: (t, Js.t({..})) => Net.Socket.t = "createConnection";
  [@bs.send] external createConnectionWithCallback: (t, Js.t({..}), unit => unit) => Net.Socket.t = "createConnection";
  [@bs.send] external keepSocketAlive: (t, Stream.t('data, [> Net.Socket.kind ])) => unit = "keepSocketAlive";
  [@bs.send] external reuseSocket: (t, Stream.t('data, [> Net.Socket.kind ]), Stream.t('data, [> ClientRequest.kind ])) => unit = "reuseSocket";
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
    ~incomingMessage: Stream.t(Buffer.t, [> IncomingMessage.kind ])=?,
    ~serverResponse: Stream.t(Buffer.t, [> ServerResponse.kind ])=?,
    ~maxHeaderSize: int=?,
    unit
  ) =>
  createServerOptions =
  "";

[@bs.module "http"]
external createServer: ((Stream.t(Buffer.t, [> IncomingMessage.kind ]), Stream.t(Buffer.t, [> ServerResponse.kind ])) => unit) => Server.t =
  "createServer";

[@bs.module "http"]
external createServerWithOptions:
  (createServerOptions, (Stream.t(Buffer.t, [> IncomingMessage.kind ]), Stream.t(Buffer.t, [> ServerResponse.kind ])) => unit) => Server.t =
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
[@bs.module "http"] external requestWithCallback: (string, Stream.t(Buffer.t, [> IncomingMessage.kind ]) => unit) => ClientRequest.t = "request";
[@bs.module "http"] external requestWithOptions: (string, requestOptions) => ClientRequest.t = "request";
[@bs.module "http"] external requestWithOptionsCallback: (string, requestOptions, Stream.t(Buffer.t, [> IncomingMessage.kind ]) => unit) => ClientRequest.t = "request";
[@bs.module "http"] external requestUrl: Url.t => ClientRequest.t = "request";
[@bs.module "http"] external requestUrlWithCallback: (Url.t, Stream.t(Buffer.t, [> IncomingMessage.kind ]) => unit) => ClientRequest.t = "request";
[@bs.module "http"] external requestUrlWithOptions: (Url.t, requestOptions) => ClientRequest.t = "request";
[@bs.module "http"] external requestUrlWithOptionsCallback: (Url.t, requestOptions, Stream.t(Buffer.t, [> IncomingMessage.kind ]) => unit) => ClientRequest.t = "request";

[@bs.module "http"] external get: string => ClientRequest.t = "get";
[@bs.module "http"] external getWithCallback: (string, Stream.t(Buffer.t, [> IncomingMessage.kind ]) => unit) => ClientRequest.t = "get";
[@bs.module "http"] external getWithOptions: (string, requestOptions) => ClientRequest.t = "get";
[@bs.module "http"] external getWithOptionsCallback: (string, requestOptions, Stream.t(Buffer.t, [> IncomingMessage.kind ]) => unit) => ClientRequest.t = "get";

[@bs.module "http"] external getUrl: Url.t => ClientRequest.t = "get";
[@bs.module "http"] external getUrlWithCallback: (Url.t, Stream.t(Buffer.t, [> IncomingMessage.kind ]) => unit) => ClientRequest.t = "get";
[@bs.module "http"] external getUrlWithOptions: (Url.t, requestOptions) => ClientRequest.t = "get";
[@bs.module "http"] external getUrlWithOptionsCallback: (Url.t, requestOptions, Stream.t(Buffer.t, [> IncomingMessage.kind ]) => unit) => ClientRequest.t = "get";

[@bs.module "http"] external globalAgent: Agent.t = "globalAgent";
[@bs.module "http"] external maxHeaderSize: int = "maxHeaderSize";

type statusCodes = Js.Dict.t(string);
[@bs.module "http"] external _STATUS_CODES: statusCodes = "STATUS_CODES";

type methods = array(string);
[@bs.module "http"] external _METHODS: methods = "METHODS";

