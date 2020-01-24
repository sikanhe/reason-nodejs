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

module ServerResponse = {
  include Stream.Writable;
  type t = Stream.t([ Stream.writable | `Http]);
  [@bs.get] external statusCode: t => int = "statusCode";
  [@bs.set] external setStatusCode: (t, int) => unit = "statusCode";
  [@bs.send] external writeCallback: (t, string, string, unit => unit) => unit = "write";
  [@bs.send] external writeStatus: (t, int) => unit = "writeHead";
  [@bs.send] external setHeader: (t, string, string) => unit = "setHeader";
  [@bs.send] external setHeaderArray: (t, string, array(string)) => unit = "setHeader";
  [@bs.send] external cork: t => unit = "cork";
  [@bs.send] external uncork: t => unit = "uncork";
  [@bs.send] external flushHeaders: t => unit = "flushHeaders";
  /** `getHeader` has unsafe polymorphic return type. */
  [@bs.send]
  external getHeader: (t, string) => 'a = "getHeader";
  [@bs.send] external getHeaderNames: t => string = "getHeaderNames";
  [@bs.send] external getHeaders: t => Js.t('a) = "getHeaders";
  [@bs.send] external hasHeader: (t, string) => bool = "hasHeader";
  [@bs.send] external headersSent: t => bool = "headersSent";
  [@bs.get] external writableEnded: t => bool = "writableEnded";
  [@bs.get] external writableFinished: t => bool = "writableFinished";
  [@bs.send] external writeContinue: t => unit = "writeContinue";
  [@bs.send] external writeHead: (t, int, Js.t('a)) => t = "writeHead";
  [@bs.send] external writeHeadWithMessage: (t, int, string, Js.t('a)) => t = "writeHead";
  [@bs.send] external writeProcessing: t => unit = "writeProcessing";
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


/**
 * TODO: consider moving this function to `Server.make`,
 * and letting `createServer` be an alias to that function.
 * Also, the `requestListener` argument is a function that
 * can take arbitrary arguments after the event name, and t's
 * not clear what its arity should be.
 */

[@bs.module "http"]
external createServer:

  (
    {
      .
      "IncomingMessage": Js.nullable(IncomingMessage.t),
      "ServerResponse": Js.nullable(ServerResponse.t),
      "maxHeaderSize": option(int),
    },
    (string, 'a) => unit
  ) =>
  Server.t =
  "createServer";

let createServer = (~incomingMessage=?, ~serverResponse=?, ~maxHeaderSize=?, requestListener) =>
  createServer(
    {
      "IncomingMessage":
        incomingMessage
        |> (
          fun
          | None => Js.Nullable.null
          | Some(a) => Js.Nullable.return(a)
        ),
      "ServerResponse":
        serverResponse
        |> (
          fun
          | None => Js.Nullable.null
          | Some(a) => Js.Nullable.return(a)
        ),
      "maxHeaderSize": maxHeaderSize,
    },
    requestListener,
  );
