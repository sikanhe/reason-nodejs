type https = [ `Https ];

module HttpsServer = {
  type kind = [ Tls.TlsSocket.kind | https ];
  type subtype('a) = Net.Socket.subtype([> kind ] as 'a);
  type supertype('a) = Net.Socket.subtype([< kind ] as 'a);
  type t = subtype(kind);

  module Impl = (T: { type t; }) => {
    include Tls.TlsServer.Impl(T);
  };

  include Impl({ type nonrec t = t; });

};

module Agent = {
  type t;
};

