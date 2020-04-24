type https = [ | `Https];

module HttpsServer = {
  type kind = [ Tls.TlsServer.kind | https];
  type subtype('w, 'r, 'a) = Net.Server.subtype('w, 'r, [> kind] as 'a);
  type supertype('w, 'r, 'a) = Net.Server.subtype('w, 'r, [< kind] as 'a);
  type t = subtype(Buffer.t, Buffer.t, kind);
  module Events = {
    include Tls.TlsServer.Events;
  };
  module Impl = {
    include Tls.TlsServer.Impl;
    include Events;
  };
  include Impl;
};

module Agent = {
  type t;
  [@bs.send]
  external onKeylog: (t, [@bs.as "keylog"] _, [@bs.uncurry] (Buffer.t, Tls.TlsSocket.t) => unit) => t = "on";
  [@bs.send]
  external onKeylogOnce: (t, [@bs.as "keylog"] _, [@bs.uncurry] (Buffer.t, Tls.TlsSocket.t) => unit) => t =
    "once";
  [@bs.send]
  external offKeylog: (t, [@bs.as "keylog"] _, [@bs.uncurry] (Buffer.t, Tls.TlsSocket.t) => unit) => t = "off";
};
