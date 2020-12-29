type tls = [ | `Tls];

module TlsSocket = {
  type kind('w, 'r) = [ Net.Socket.kind('w, 'r) | tls];
  type subtype('w, 'r, 'ty) = Stream.subtype([> kind('w, 'r)] as 'ty);
  type supertype('w, 'r, 'ty) = Stream.subtype([< kind('w, 'r)] as 'ty);
  type t = Stream.subtype(kind(Buffer.t, Buffer.t));
  module Events = {
    include Net.TcpSocket.Events;
  };
  module Impl = {
    include Net.TcpSocket.Impl;
    include Events;
  };
  include Impl;
};

module TlsServer = {
  type kind = [ Net.Server.kind | tls];
  type subtype('ty) = Net.Server.subtype([> kind] as 'ty);
  type supertype('ty) = Net.Server.subtype([< kind] as 'ty);
  type t = Net.Server.subtype(kind);
  module Events = {
    include Net.TcpServer.Events;
  };
  module Impl = {
    include Net.TcpServer.Impl;
    include Events;
  };
  include Impl;
};
