type tcp = [ | `Tcp];
type icp = [ | `Icp];

type address = {
  [@bs.as "port"]
  port: int,
  [@bs.as "family"]
  family: string,
  [@bs.as "address"]
  address: string,
};

module Socket = {
  type kind('w, 'r) = [ Stream2.socket('w, 'r)];
  type subtype('w, 'r, 'ty) = Stream2.subtype([> kind('w, 'r)] as 'ty);
  type supertype('w, 'r, 'ty) = Stream2.subtype([< kind('w, 'r)] as 'ty);
  type t('w, 'r) = Stream2.subtype(kind('w, 'r));

  module Events = {
    [@bs.send]
    external onClose:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "close"] _,
        [@bs.uncurry] (bool => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "on";
    [@bs.send]
    external onConnect:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "connect"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "on";
    [@bs.send]
    external onData:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "data"] _,
        [@bs.uncurry] (Buffer.t => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "on";
    [@bs.send]
    external onDrain:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "drain"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "on";
    [@bs.send]
    external onEnd:
      (subtype('w, 'r, 'ty), [@bs.as "end"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('w, 'r, 'ty) =
      "on";
    [@bs.send]
    external onError:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "error"] _,
        [@bs.uncurry] (Js.Exn.t => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "on";
    [@bs.send]
    external onLookup:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "lookup"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "on";
    [@bs.send]
    external onReady:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "ready"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "on";
    [@bs.send]
    external onTimeout:
      (subtype('w, 'r, 'ty), [@bs.as "timeout"] _, unit => unit) =>
      subtype('w, 'r, 'ty) =
      "on";

    [@bs.send]
    external offClose:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "close"] _,
        [@bs.uncurry] (bool => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "off";
    [@bs.send]
    external offConnect:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "connect"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "off";
    [@bs.send]
    external offData:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "data"] _,
        [@bs.uncurry] (Buffer.t => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "off";
    [@bs.send]
    external offDrain:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "drain"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "off";
    [@bs.send]
    external offEnd:
      (subtype('w, 'r, 'ty), [@bs.as "end"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('w, 'r, 'ty) =
      "off";
    [@bs.send]
    external offError:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "error"] _,
        [@bs.uncurry] (Js.Exn.t => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "off";
    [@bs.send]
    external offLookup:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "lookup"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "off";
    [@bs.send]
    external offReady:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "ready"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "off";
    [@bs.send]
    external offTimeout:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "timeout"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "off";

    [@bs.send]
    external onCloseOnce:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "close"] _,
        [@bs.uncurry] (bool => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "once";
    [@bs.send]
    external onConnectOnce:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "connect"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "once";
    [@bs.send]
    external onDataOnce:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "data"] _,
        [@bs.uncurry] (Buffer.t => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "once";
    [@bs.send]
    external onDrainOnce:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "drain"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "once";
    [@bs.send]
    external onEndOnce:
      (subtype('w, 'r, 'ty), [@bs.as "end"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('w, 'r, 'ty) =
      "once";
    [@bs.send]
    external onErrorOnce:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "error"] _,
        [@bs.uncurry] (Js.Exn.t => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "once";
    [@bs.send]
    external onLookupOnce:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "lookup"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "once";
    [@bs.send]
    external onReadyOnce:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "ready"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "once";
    [@bs.send]
    external onTimeoutOnce:
      (
        subtype('w, 'r, 'ty),
        [@bs.as "timeout"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      subtype('w, 'r, 'ty) =
      "once";
  };

  module Impl = {
    include Stream2.Duplex.Impl;
    include Events;
    [@bs.send] external address: subtype('w, 'r, 'ty) => address = "address";
    [@bs.get] external bufferSize: subtype('w, 'r, 'ty) => int = "bufferSize";
    [@bs.get] external bytesRead: subtype('w, 'r, 'ty) => int = "bytesRead";
    [@bs.get]
    external bytesWritten: subtype('w, 'r, 'ty) => int = "bytesWritten";
    [@bs.get] external connecting: subtype('w, 'r, 'ty) => bool = "connecting";
    [@bs.get] external destroyed: subtype('w, 'r, 'ty) => bool = "destroyed";
    [@bs.send]
    external destroy:
      (subtype('w, 'r, 'ty), ~exn: Js.Exn.t=?, unit) => subtype('w, 'r, 'ty) =
      "destroy";
    [@bs.get]
    external localAddress: subtype('w, 'r, 'ty) => string = "localAddress";
    [@bs.get] external localPort: subtype('w, 'r, 'ty) => int = "localPort";
    [@bs.send]
    external pause: subtype('w, 'r, 'ty) => subtype('w, 'r, 'ty) = "pause";
    [@bs.get] external pending: subtype('w, 'r, 'ty) => bool = "pending";
    [@bs.send]
    external ref: subtype('w, 'r, 'ty) => subtype('w, 'r, 'ty) = "ref";
    [@bs.get]
    external remoteAddress: subtype('w, 'r, 'ty) => string = "remoteAddress";
    [@bs.get]
    external remoteFamily: subtype('w, 'r, 'ty) => string = "remoteFamily";
    [@bs.get] external remotePort: subtype('w, 'r, 'ty) => int = "remotePort";
    [@bs.send]
    external resume: subtype('w, 'r, 'ty) => subtype('w, 'r, 'ty) = "resume";
    [@bs.send]
    external setKeepAlive:
      (subtype('w, 'r, 'ty), ~enable: bool, ~delay: int) =>
      subtype('w, 'r, 'ty) =
      "setKeepAlive";
    [@bs.send]
    external setNoDelay:
      (subtype('w, 'r, 'ty), ~noDelay: bool) => subtype('w, 'r, 'ty) =
      "noDelay";
    [@bs.send]
    external setTimeout:
      (
        subtype('w, 'r, 'ty),
        int,
        ~callback: [@bs.this] (subtype('w, 'r, 'ty) => unit)=?
      ) =>
      subtype('w, 'r, 'ty) =
      "setTimeout";
    [@bs.send]
    external unref: subtype('w, 'r, 'ty) => subtype('w, 'r, 'ty) = "unref";
    [@bs.send]
    external connectIcp:
      (subtype('w, 'r, [> kind('w, 'r) | icp] as 'ty), ~path: string, unit => unit) =>
      subtype('w, 'r, 'ty) =
      "connect";
    [@bs.send]
    external connectTcp:
      (
        subtype('w, 'r, [> kind('w, 'r) | tcp] as 'ty),
        ~port: int,
        ~host: string,
        unit => unit
      ) =>
      subtype('w, 'r, 'ty) =
      "connect";
  };
  include Impl;

  type makeOptions;

  [@bs.obj]
  external makeOptions:
    (~fd: int=?, ~readable: bool=?, ~writable: bool=?, unit) => makeOptions;

  [@bs.module "net"] [@bs.new]
  external make: (~options: makeOptions=?, unit) => t(Buffer.t, Buffer.t) = "Socket";
};

module TcpSocket = {
  type nonrec kind('w, 'r) = [ Socket.kind('w, 'r) | tcp];
  type t('w, 'r) = Stream2.subtype(kind('w, 'r));
  type subtype('w, 'r, 'ty) = Stream2.subtype([> kind('w, 'r)] as 'ty);
  type supertype('w, 'r, 'ty) = Stream2.subtype([< kind('w, 'r)] as 'ty);
  module Events = {
    include Socket.Events;
  };
  module Impl = {
    include Socket.Impl;
    include Events;
    [@bs.send]
    external connect:
      (subtype('w, 'r, 'ty), ~port: int, ~host: string, unit => unit) =>
      subtype('w, 'r, 'ty) =
      "connect";
  };
  include Impl;
  [@bs.module "net"] [@bs.new] external make: unit => t(Buffer.t, Buffer.t) = "Socket";
};

module IcpSocket = {
  type kind('w, 'r) = [ Socket.kind('w, 'r) | icp];
  type t('w, 'r) = Stream2.subtype(kind('w, 'r));
  type subtype('w, 'r, 'ty) = Stream2.subtype([> kind('w, 'r)] as 'ty);
  type supertype('w, 'r, 'ty) = Stream2.subtype([< kind('w, 'r)] as 'ty);
  module Events = {
    include Socket.Events;
  };
  module Impl = {
    include Socket.Impl;
    [@bs.send]
    external connect:
      (subtype('w, 'r, 'ty), ~path: string, unit => unit) =>
      subtype('w, 'r, 'ty) =
      "connect";
  };
  include Impl;
  [@bs.module "net"] [@bs.new] external make: unit => t(Buffer.t, Buffer.t) = "Socket";
};

module Server = {
  type kind = [ | `Server];
  type subtype('a) constraint 'a = [> kind];
  type supertype('a) constraint 'a = [< kind];
  type t('a) = subtype('a);
  module Events = {
    [@bs.send]
    external onClose:
      (subtype('a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onError:
      (subtype('a), [@bs.as "error"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onConnection:
      (
        subtype('a),
        [@bs.as "connection"] _,
        [@bs.uncurry] (Socket.t(Buffer.t, Buffer.t) => unit)
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onListening:
      (subtype('a), [@bs.as "listening"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "on";
    [@bs.send]
    external offClose:
      (subtype('a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offError:
      (subtype('a), [@bs.as "error"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offConnection:
      (
        subtype('a),
        [@bs.as "connection"] _,
        [@bs.uncurry] (Socket.t(Buffer.t, Buffer.t) => unit)
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offListening:
      (subtype('a), [@bs.as "listening"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "off";
    [@bs.send]
    external onCloseOnce:
      (subtype('a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onErrorOnce:
      (subtype('a), [@bs.as "error"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onConnectionOnce:
      (
        subtype('a),
        [@bs.as "connection"] _,
        [@bs.uncurry] (Socket.t(Buffer.t, Buffer.t) => unit)
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onListeningOnce:
      (subtype('a), [@bs.as "listening"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "once";
  };
  module Impl = {
    include Events;
    [@bs.send]
    external close:
      (subtype('a), ~callback: Js.nullable(Js.Exn.t) => unit=?, unit) =>
      subtype('a) =
      "close";
    [@bs.send]
    external getConnections:
      (subtype('a), (Js.nullable(Js.Exn.t), int) => unit) => subtype('a) =
      "getConnections";
    [@bs.set]
    external setMaxConnections: (subtype('a), int) => unit = "maxConnections";
    [@bs.get] external maxConnections: subtype('a) => int = "maxConnections";
    [@bs.send] external ref: subtype('a) => subtype('a) = "ref";
    [@bs.send] external unref: subtype('a) => subtype('a) = "unref";
    [@bs.get] external listening: subtype('a) => bool = "listening";
  };

  include Impl;
};

module TcpServer = {
  type kind = [ Server.kind | tcp];
  type t = Server.subtype(kind);
  type subtype('ty) = Server.subtype([> kind] as 'ty);
  type supertype('ty) = Server.subtype([< kind] as 'ty);
  module Events = {
    [@bs.send]
    external onClose:
      (subtype('a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onError:
      (subtype('a), [@bs.as "error"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onConnection:
      (
        subtype('a),
        [@bs.as "connection"] _,
        [@bs.uncurry] (TcpSocket.t(Buffer.t, Buffer.t) => unit)
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onListening:
      (subtype('a), [@bs.as "listening"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "on";
    [@bs.send]
    external offClose:
      (subtype('a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offError:
      (subtype('a), [@bs.as "error"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offConnection:
      (
        subtype('a),
        [@bs.as "connection"] _,
        [@bs.uncurry] (TcpSocket.t(Buffer.t, Buffer.t) => unit)
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offListening:
      (subtype('a), [@bs.as "listening"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "off";
    [@bs.send]
    external onCloseOnce:
      (subtype('a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onErrorOnce:
      (subtype('a), [@bs.as "error"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onConnectionOnce:
      (
        subtype('a),
        [@bs.as "connection"] _,
        [@bs.uncurry] (TcpSocket.t(Buffer.t, Buffer.t) => unit)
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onListeningOnce:
      (subtype('a), [@bs.as "listening"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "once";
  };
  module Impl = {
    include Events;
    [@bs.send]
    external close:
      (subtype('a), ~callback: Js.nullable(Js.Exn.t) => unit=?, unit) =>
      subtype('a) =
      "close";
    [@bs.send]
    external getConnections:
      (subtype('a), (Js.nullable(Js.Exn.t), int) => unit) => subtype('a) =
      "getConnections";
    [@bs.set]
    external setMaxConnections: (subtype('a), int) => unit = "maxConnections";
    [@bs.get] external maxConnections: subtype('a) => int = "maxConnections";
    [@bs.send] external ref: subtype('a) => subtype('a) = "ref";
    [@bs.send] external unref: subtype('a) => subtype('a) = "unref";
    [@bs.get] external listening: subtype('a) => bool = "listening";
  };
  include Impl;
  type listenOptions;
  [@bs.obj]
  external listenOptions:
    (
      ~port: int=?,
      ~host: string=?,
      ~backlog: int=?,
      ~exclusive: bool=?,
      ~ipv6Only: bool=?,
      unit
    ) =>
    listenOptions;
  [@bs.module "net"] [@bs.new] external make: unit => t = "Server";
  [@bs.send]
  external listen:
    (t, ~port: int, ~host: string, ~callback: unit => unit=?, unit) => t =
    "listen";
  [@bs.send]
  external listenWith: (t, listenOptions, ~callback: unit => unit=?, unit) => t =
    "listen";
};

module IcpServer = {
  type kind = [ Server.kind | icp];
  type t = Server.subtype(kind);
  type subtype('ty) = Server.subtype([> kind] as 'ty);
  type supertype('ty) = Server.subtype([< kind] as 'ty);
  module Events = {
    [@bs.send]
    external onClose:
      (subtype('a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onError:
      (subtype('a), [@bs.as "error"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onConnection:
      (
        subtype('a),
        [@bs.as "connection"] _,
        [@bs.uncurry] (IcpSocket.t(Buffer.t, Buffer.t) => unit)
      ) =>
      subtype('a) =
      "on";
    [@bs.send]
    external onListening:
      (subtype('a), [@bs.as "listening"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "on";
    [@bs.send]
    external offClose:
      (subtype('a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offError:
      (subtype('a), [@bs.as "error"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offConnection:
      (
        subtype('a),
        [@bs.as "connection"] _,
        [@bs.uncurry] (IcpSocket.t(Buffer.t, Buffer.t) => unit)
      ) =>
      subtype('a) =
      "off";
    [@bs.send]
    external offListening:
      (subtype('a), [@bs.as "listening"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "off";
    [@bs.send]
    external onCloseOnce:
      (subtype('a), [@bs.as "close"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onErrorOnce:
      (subtype('a), [@bs.as "error"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onConnectionOnce:
      (
        subtype('a),
        [@bs.as "connection"] _,
        [@bs.uncurry] (IcpSocket.t(Buffer.t, Buffer.t) => unit)
      ) =>
      subtype('a) =
      "once";
    [@bs.send]
    external onListeningOnce:
      (subtype('a), [@bs.as "listening"] _, [@bs.uncurry] (unit => unit)) =>
      subtype('a) =
      "once";
  };
  module Impl = {
    include Events;
    [@bs.send]
    external close:
      (subtype('a), ~callback: Js.nullable(Js.Exn.t) => unit=?, unit) =>
      subtype('a) =
      "close";
    [@bs.send]
    external getConnections:
      (subtype('a), (Js.nullable(Js.Exn.t), int) => unit) => subtype('a) =
      "getConnections";
    [@bs.set]
    external setMaxConnections: (subtype('a), int) => unit = "maxConnections";
    [@bs.get] external maxConnections: subtype('a) => int = "maxConnections";
    [@bs.send] external ref: subtype('a) => subtype('a) = "ref";
    [@bs.send] external unref: subtype('a) => subtype('a) = "unref";
    [@bs.get] external listening: subtype('a) => bool = "listening";
  };
  include Impl;
  type listenOptions;
  [@bs.obj]
  external listenOptions:
    (
      ~path: string=?,
      ~host: string=?,
      ~backlog: int=?,
      ~exclusive: bool=?,
      ~readableAll: bool=?,
      ~writableAll: bool=?,
      unit
    ) =>
    listenOptions;
  [@bs.send]
  external listen: (t, ~path: string, ~callback: unit => unit=?, unit) => t =
    "listen";
  [@bs.send]
  external listenWith:
    (t, ~options: listenOptions, ~callback: unit => unit=?, unit) => t =
    "listen";
};

[@bs.module "net"] [@bs.val] external isIP: string => bool = "isIP";
[@bs.module "net"] [@bs.val] external isIPv4: string => bool = "isIPv4";
[@bs.module "net"] [@bs.val] external isIPv6: string => bool = "isIPv6";

