type tls = [ | `Tls];

module TlsSocket = {
  type kind = [ Net.TcpSocket.kind | tls];
  type subtype('w, 'r, 'a) = Net.Socket.subtype('w, 'r, [> kind] as 'a);
  type supertype('w, 'r, 'a) = Net.Socket.subtype('w, 'r, [< kind] as 'a);
  type t = Net.TcpSocket.subtype(Buffer.t, Buffer.t, kind);
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
  type kind = [ Net.TcpServer.kind | tls];
  type subtype('w, 'r, 'a) = Net.Server.subtype('w, 'r, [> kind] as 'a);
  type supertype('w, 'r, 'a) = Net.Server.subtype('w, 'r, [< kind] as 'a);
  type t = subtype(Buffer.t, Buffer.t, kind);
  module Events = {
    include Net.TcpServer.Events;
  };
  module Impl = {
    include Net.TcpServer.Impl;
    include Events;
  };
  include Impl;
};
