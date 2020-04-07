type https = [ `Https ];

module HttpsServer = {
  type kind = [ Tls.TlsServer.kind | https ];
  type subtype('a) = Net.Server.subtype([> kind ] as 'a);
  type supertype('a) = Net.Server.subtype([< kind ] as 'a);
  type t = subtype(kind);
  module Impl = {
    include Tls.TlsServer.Impl;
  };
  include Impl;
};

module Agent = {
  type t;
  [@bs.send] external onKeylog: (t, [@bs.as "keylog"]_, (Buffer.t, Tls.TlsSocket.t)) => unit = "on";
};

