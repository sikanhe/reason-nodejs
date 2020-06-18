type tls = [ | `Tls];

module TlsSocket = {
  type kind('w, 'r) = [ Net__.Socket.kind('w, 'r) | tls];
  type subtype('w, 'r, 'ty) = Stream__.subtype([> kind('w, 'r)] as 'ty);
  type supertype('w, 'r, 'ty) = Stream__.subtype([< kind('w, 'r)] as 'ty);
  type t = Stream__.subtype(kind(Buffer.t, Buffer.t));
  module Events = {
    include Net__.TcpSocket.Events;
  };
  module Impl = {
    include Net__.TcpSocket.Impl;
    include Events;
  };
  include Impl;
};

module TlsServer = {
  type kind = [ Net__.Server.kind | tls];
  type subtype('ty) = Net__.Server.subtype([> kind] as 'ty);
  type supertype('ty) = Net__.Server.subtype([< kind] as 'ty);
  type t = Net__.Server.subtype(kind);
  module Events = {
    include Net__.TcpServer.Events;
  };
  module Impl = {
    include Net__.TcpServer.Impl;
    include Events;
  };
  include Impl;
};
