module Server = {
  type kind = [ Tls.Server.kind | `HttpsServer ];
  type t = Stream.t(Buffer.t, [ kind ]);
  module Impl = {
    include Net.Socket.Impl;
  };

  include Impl;
  [@bs.send] external close: t => t = "close";
};

module Agent = {

};

