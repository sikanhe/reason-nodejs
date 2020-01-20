type t;

module IncomingMessage = {
  type connection = {remoteAddress: string};
  type t = Stream.t([ Stream.readable | `Http]);

  include Stream.Readable;
  [@bs.get] external method_: t => string = "method";
  [@bs.get] external url: t => string = "url";
  [@bs.get] external port: t => int = "port";
  [@bs.get] external headers: t => Js.Dict.t(string) = "headers";
  [@bs.get] external connection: t => connection = "connection";
};

module ServerResponse = {
  type t = Stream.t([ Stream.writable | `Http]);

  include Stream.Writable;
  [@bs.get] external statusCode: t => int = "statusCode";
  [@bs.set] external setStatusCode: (t, int) => unit = "statusCode";
  [@bs.send]
  external writeCallback: (t, string, string, unit => unit) => unit = "write";
  [@bs.send] external writeStatus: (t, int) => unit = "writeHead";
  [@bs.send] external setHeader: (t, string, string) => unit = "setHeader";
  [@bs.send]
  external setHeaderArray: (t, string, array(string)) => unit = "setHeader";
};

type listener = (IncomingMessage.t, ServerResponse.t) => unit;
[@bs.module "http"] external createServer: listener => t = "createServer";
[@bs.send] external listen: (t, int) => unit = "listen";