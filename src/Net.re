type tcp = [ `Tcp ];
type icp = [ `Icp ];

type address = {
  [@bs.as "port"] port: int,
  [@bs.as "family"] family: string,
  [@bs.as "address"] address: string,
};

module Socket = {

  type readable = [ Stream.readable | Stream.socket ];
  type writable = [ Stream.writable | Stream.socket ];
  type duplex = [ Stream.duplex | Stream.socket ];

  type kind = [ Stream.socket ];
  type subtype('a) = Stream.subtype(Buffer.t, [> kind ] as 'a);
  type supertype('a) = Stream.subtype(Buffer.t, [< kind ] as 'a);
  type t = subtype(kind);

  module Base = {
    type nonrec kind = kind;
    type nonrec subtype('a) = subtype('a);
    type nonrec supertype('a) = supertype('a);
    type t = subtype(kind);
    type nonrec address = address;

    module Events = {
      [@bs.send] external onClose: (subtype('a), [@bs.as "close"] _, (. bool) => unit) => subtype('a) = "on";
      [@bs.send] external onConnect: (subtype('a), [@bs.as "connect"] _, (. unit) => unit) => subtype('a) = "on";
      [@bs.send] external onData: (subtype('a), [@bs.as "data"] _, (. Buffer.t) => unit) => subtype('a) = "on";
      [@bs.send] external onDrain: (subtype('a), [@bs.as "drain"] _, (. unit) => unit) => subtype('a) = "on";
      [@bs.send] external onEnd: (subtype('a), [@bs.as "end"] _, (. unit) => unit) => subtype('a) = "on";
      [@bs.send] external onError: (subtype('a), [@bs.as "error"] _, (. Js.Exn.t) => unit) => subtype('a) = "on";
      [@bs.send] external onLookup: (subtype('a), [@bs.as "lookup"] _, (. unit) => unit) => subtype('a) = "on";
      [@bs.send] external onReady: (subtype('a), [@bs.as "ready"] _, (. unit) => unit) => subtype('a) = "on";
      [@bs.send] external onTimeout: (subtype('a), [@bs.as "timeout"] _, (unit) => unit) => subtype('a) = "on";

      [@bs.send] external offClose: (subtype('a), [@bs.as "close"] _, (. bool) => unit) => subtype('a) = "off";
      [@bs.send] external offConnect: (subtype('a), [@bs.as "connect"] _, (. unit) => unit) => subtype('a) = "off";
      [@bs.send] external offData: (subtype('a), [@bs.as "data"] _, (. Buffer.t) => unit) => subtype('a) = "off";
      [@bs.send] external offDrain: (subtype('a), [@bs.as "drain"] _, (. unit) => unit) => subtype('a) = "off";
      [@bs.send] external offEnd: (subtype('a), [@bs.as "end"] _, (. unit) => unit) => subtype('a) = "off";
      [@bs.send] external offError: (subtype('a), [@bs.as "error"] _, (. Js.Exn.t) => unit) => subtype('a) = "off";
      [@bs.send] external offLookup: (subtype('a), [@bs.as "lookup"] _, (. unit) => unit) => subtype('a) = "off";
      [@bs.send] external offReady: (subtype('a), [@bs.as "ready"] _, (. unit) => unit) => subtype('a) = "off";
      [@bs.send] external offTimeout: (subtype('a), [@bs.as "timeout"] _, (. unit) => unit) => subtype('a) = "off";

      [@bs.send] external onCloseOnce: (subtype('a), [@bs.as "close"] _, (. bool) => unit) => subtype('a) = "once";
      [@bs.send] external onConnectOnce: (subtype('a), [@bs.as "connect"] _, (. unit) => unit) => subtype('a) = "once";
      [@bs.send] external onDataOnce: (subtype('a), [@bs.as "data"] _, (. Buffer.t) => unit) => subtype('a) = "once";
      [@bs.send] external onDrainOnce: (subtype('a), [@bs.as "drain"] _, (. unit) => unit) => subtype('a) = "once";
      [@bs.send] external onEndOnce: (subtype('a), [@bs.as "end"] _, (. unit) => unit) => subtype('a) = "once";
      [@bs.send] external onErrorOnce: (subtype('a), [@bs.as "error"] _, (. Js.Exn.t) => unit) => subtype('a) = "once";
      [@bs.send] external onLookupOnce: (subtype('a), [@bs.as "lookup"] _, (. unit) => unit) => subtype('a) = "once";
      [@bs.send] external onReadyOnce: (subtype('a), [@bs.as "ready"] _, (. unit) => unit) => subtype('a) = "once";
      [@bs.send] external onTimeoutOnce: (subtype('a), [@bs.as "timeout"] _, (. unit) => unit) => subtype('a) = "once";
    };

    module Impl = {
      include Stream.Base.Impl;
      include Events;
      [@bs.send] external address: subtype('a) => address = "address";
      [@bs.get] external bufferSize: subtype('a) => int = "bufferSize";
      [@bs.get] external bytesRead: subtype('a) => int = "bytesRead";
      [@bs.get] external bytesWritten: subtype('a) => int = "bytesWritten";
      [@bs.get] external connecting: subtype('a) => bool = "connecting";
      [@bs.get] external destroyed: subtype('a) => bool = "destroyed";
      [@bs.send] external destroy: (subtype('a), ~exn: Js.Exn.t=?, unit) => subtype('a) = "destroy";
      [@bs.get] external localAddress: subtype('a) => string = "localAddress";
      [@bs.get] external localPort: subtype('a) => int = "localPort";
      [@bs.send] external pause: subtype('a) => subtype('a) = "pause";
      [@bs.get] external pending: subtype('a) => bool = "pending";
      [@bs.send] external ref: subtype('a) => subtype('a) = "ref";
      [@bs.get] external remoteAddress: subtype('a) => string = "remoteAddress";
      [@bs.get] external remoteFamily: subtype('a) => string = "remoteFamily";
      [@bs.get] external remotePort: subtype('a) => int = "remotePort";
      [@bs.send] external resume: subtype('a) => subtype('a) = "resume";
      [@bs.send] external setKeepAlive: (subtype('a), ~enable: bool, ~delay: int) => subtype('a) = "setKeepAlive";
      [@bs.send] external setNoDelay: (subtype('a), ~noDelay: bool) => subtype('a) = "noDelay";
      [@bs.send] external setTimeout: (subtype('a), int, ~callback: [@bs.this] (subtype('a)) => unit=?) => subtype('a) = "setTimeout";
      [@bs.send] external unref: subtype('a) => subtype('a) = "unref";
      [@bs.send] external connectIcp: (
          subtype([> kind | icp ] as 'a),
          ~path: string,
          unit => unit
        ) => subtype('a) = "connect";
      [@bs.send] external connectTcp: (
          subtype([> kind | tcp ] as 'a),
          ~port: int,
          ~host: string,
          unit => unit
        ) => subtype('a) = "connect";
    };
    include Impl;

    type makeOptions;

    [@bs.obj] external makeOptions: (
      ~fd: int=?,
      ~readable: bool=?,
      ~writable: bool=?,
      unit
    ) => makeOptions = "";
 
    [@bs.module "net"] [@bs.new] external make: (~options: makeOptions=?, unit) => t = "Socket";

  };

  module Readable = {
    type kind = [ Stream.readable | Stream.socket ];
    type subtype('a) = Stream.Readable.subtype(Buffer.t, [> kind ] as 'a);
    type supertype('a) = Stream.Readable.subtype(Buffer.t, [< kind ] as 'a);
    type t = subtype(kind);
    type nonrec address = address;
    module Events = {
      include Stream.Readable.Events;
      include Base.Events;
    };
    module Impl = {
      include Stream.Readable.Impl;
      include Base.Impl;
      include Events;
      [@bs.send] external setEncoding: (
          subtype('a),
          [@bs.string] [
            | `ascii
            | `utf8
            | `utf16le
            | `usc2
            | `base64
            | `latin1
            | `binary
            | `hex
          ],
        ) => subtype('a)
        = "setEncoding";
    };
    include Impl;
    [@bs.module "net"] [@bs.new] external make: unit => t = "Socket";
  };

  module Writable = {
    type kind = [ Stream.writable | Stream.socket ];
    type subtype('a) = Stream.Writable.subtype(Buffer.t, [> kind ] as 'a);
    type supertype('a) = Stream.Writable.subtype(Buffer.t, [< kind ] as 'a);
    type t = subtype(kind);
    type nonrec address = address;
    module Events = {
      include Stream.Writable.Events;
      include Base.Events;
    };
    module Impl = {
      include Stream.Writable.Impl;
      include Base.Impl;
      include Events;
      [@bs.send] external end_: (subtype('a)) => subtype('a) = "end";
      [@bs.send] external write: (subtype('a), Buffer.t, ~callback: [@bs.this] subtype('a) => unit) => bool = "write";
    };
    include Impl;
    [@bs.module "net"] [@bs.new] external make: unit => t = "Socket";
  };

  module Duplex = {
    type kind = [ Stream.duplex | Stream.socket ];
    type subtype('a) = Stream.Duplex.subtype(Buffer.t, [> kind ] as 'a);
    type supertype('a) = Stream.Duplex.subtype(Buffer.t, [< kind ] as 'a);
    type t = subtype(kind);
    type nonrec address = address;
    module Events = {
      include Stream.Duplex.Events;
      include Readable.Events;
      include Writable.Events;
    };
    module Impl = {
      include Stream.Duplex.Impl;
      include Readable.Impl;
      include Writable.Impl;
      include Events;
    };
    include Impl;
    [@bs.module "net"] [@bs.new] external make: unit => t = "Socket";
  };

  module Impl = {
    include Base.Impl;
    include Base.Events;
  };

  include Impl;
  [@bs.module "net"] [@bs.new] external make: unit => t = "Socket";

};

module TcpSocket = {
  type nonrec kind = [ Socket.Duplex.kind | tcp ];
  type subtype('a) = Socket.Duplex.subtype([> kind ] as 'a);
  type supertype('a) = Socket.Duplex.subtype([< kind ] as 'a);
  type t = subtype(kind);
  module Impl = {
    include Socket.Impl;
    [@bs.send] external connect: (
      subtype('a),
      ~port: int,
      ~host: string,
      unit => unit,
    ) => subtype('a)
    = "connect";
  };
  include Impl;
  [@bs.module "net"] [@bs.new] external make: unit => t = "Socket";
};

module IcpSocket = {
  type kind = [ Socket.Duplex.kind | icp ];
  type subtype('a) = Socket.Duplex.subtype([> kind ] as 'a);
  type supertype('a) = Socket.Duplex.subtype([< kind ] as 'a);
  type t = subtype(kind);
  module Impl = {
    include Socket.Impl;
    [@bs.send] external connect: (
      subtype('a),
      ~path: string,
      unit => unit,
    ) => subtype('a)
    = "connect";
  };
  include Impl;
  [@bs.module "net"] [@bs.new] external make: unit => t = "Socket";
};

type tcpSocket = TcpSocket.t;
type icpSocket = IcpSocket.t;

module Server = {
  type kind = [ `Server ];
  type subtype('a) constraint 'a = [> kind ];
  type supertype('a) constraint 'a = [< kind ];
  type t = subtype(kind);
  module Events = {
    [@bs.send] external onClose: (subtype('a), [@bs.as "close"] _, (. unit) => unit) => subtype('a) = "on";
    [@bs.send] external onError: (subtype('a), [@bs.as "error"] _, (. unit) => unit) => subtype('a) = "on";
    [@bs.send] external onConnection: (subtype('a), [@bs.as "connection"] _, (. Socket.t) => unit) => subtype('a) = "on";
    [@bs.send] external onListening: (subtype('a), [@bs.as "listening"] _, (. unit) => unit) => subtype('a) = "on";
    [@bs.send] external offClose: (subtype('a), [@bs.as "close"] _, (. unit) => unit) => subtype('a) = "off";
    [@bs.send] external offError: (subtype('a), [@bs.as "error"] _, (. unit) => unit) => subtype('a) = "off";
    [@bs.send] external offConnection: (subtype('a), [@bs.as "connection"] _, (. Socket.t) => unit) => subtype('a) = "off";
    [@bs.send] external offListening: (subtype('a), [@bs.as "listening"] _, (. unit) => unit) => subtype('a) = "off";
    [@bs.send] external onCloseOnce: (subtype('a), [@bs.as "close"] _, (. unit) => unit) => subtype('a) = "once";
    [@bs.send] external onErrorOnce: (subtype('a), [@bs.as "error"] _, (. unit) => unit) => subtype('a) = "once";
    [@bs.send] external onConnectionOnce: (subtype('a), [@bs.as "connection"] _, (. Socket.t) => unit) => subtype('a) = "once";
    [@bs.send] external onListeningOnce: (subtype('a), [@bs.as "listening"] _, (. unit) => unit) => subtype('a) = "once";
  };
  module Impl = {
    include Events;
    [@bs.send] external close: (subtype('a), ~callback: Js.nullable(Js.Exn.t) => unit=?, unit) => subtype('a) = "close";
    [@bs.send] external getConnections: (subtype('a), (Js.nullable(Js.Exn.t), int) => unit) => subtype('a) = "getConnections";
    [@bs.set] external setMaxConnections: (subtype('a), int) => unit = "maxConnections";
    [@bs.get] external maxConnections: (subtype('a)) => int = "maxConnections";
    [@bs.send] external ref: (subtype('a)) => subtype('a) = "ref";
    [@bs.send] external unref: (subtype('a)) => subtype('a) = "unref";
    [@bs.get] external listening: (subtype('a)) => bool = "listening"
  };

  include Impl;

};

module TcpServer = {
  type kind = [ Server.kind | tcp ];
  type subtype('a) = Server.subtype([> kind ] as 'a);
  type supertype('a) = Server.subtype([< kind ] as 'a);
  type t = subtype(kind);
  module Events = {
    [@bs.send] external onClose: (subtype('a), [@bs.as "close"] _, (. unit) => unit) => subtype('a) = "on";
    [@bs.send] external onError: (subtype('a), [@bs.as "error"] _, (. unit) => unit) => subtype('a) = "on";
    [@bs.send] external onConnection: (subtype('a), [@bs.as "connection"] _, (. TcpSocket.t) => unit) => subtype('a) = "on";
    [@bs.send] external onListening: (subtype('a), [@bs.as "listening"] _, (. unit) => unit) => subtype('a) = "on";
    [@bs.send] external offClose: (subtype('a), [@bs.as "close"] _, (. unit) => unit) => subtype('a) = "off";
    [@bs.send] external offError: (subtype('a), [@bs.as "error"] _, (. unit) => unit) => subtype('a) = "off";
    [@bs.send] external offConnection: (subtype('a), [@bs.as "connection"] _, (. TcpSocket.t) => unit) => subtype('a) = "off";
    [@bs.send] external offListening: (subtype('a), [@bs.as "listening"] _, (. unit) => unit) => subtype('a) = "off";
    [@bs.send] external onCloseOnce: (subtype('a), [@bs.as "close"] _, (. unit) => unit) => subtype('a) = "once";
    [@bs.send] external onErrorOnce: (subtype('a), [@bs.as "error"] _, (. unit) => unit) => subtype('a) = "once";
    [@bs.send] external onConnectionOnce: (subtype('a), [@bs.as "connection"] _, (. TcpSocket.t) => unit) => subtype('a) = "once";
    [@bs.send] external onListeningOnce: (subtype('a), [@bs.as "listening"] _, (. unit) => unit) => subtype('a) = "once";
  };
  module Impl = {
    include Events;
    [@bs.send] external close: (subtype('a), ~callback: Js.nullable(Js.Exn.t) => unit=?, unit) => subtype('a) = "close";
    [@bs.send] external getConnections: (subtype('a), (Js.nullable(Js.Exn.t), int) => unit) => subtype('a) = "getConnections";
    [@bs.set] external setMaxConnections: (subtype('a), int) => unit = "maxConnections";
    [@bs.get] external maxConnections: (subtype('a)) => int = "maxConnections";
    [@bs.send] external ref: (subtype('a)) => subtype('a) = "ref";
    [@bs.send] external unref: (subtype('a)) => subtype('a) = "unref";
    [@bs.get] external listening: (subtype('a)) => bool = "listening"
  };
  include Impl;
  type listenOptions;
  [@bs.obj] external listenOptions: (
    ~port: int=?,
    ~host: string=?,
    ~backlog: int=?,
    ~exclusive: bool=?,
    ~ipv6Only: bool=?,
    unit
  ) => listenOptions = "";
  [@bs.module "net"] [@bs.new] external make: (unit) => t = "Server";
  [@bs.send] external listen: (t, ~port: int, ~host: string, ~callback: unit => unit=?, unit) => t = "listen";
  [@bs.send] external listenWith: (t, listenOptions, ~callback: unit => unit=?, unit) => t = "listen";

};

module IcpServer = {
  type kind = [ Server.kind | icp ];
  type subtype('a) = Server.subtype([> kind ] as 'a);
  type supertype('a) = Server.subtype([< kind ] as 'a);
  type t = subtype(kind);
  module Events = {
    [@bs.send] external onClose: (subtype('a), [@bs.as "close"] _, (. unit) => unit) => subtype('a) = "on";
    [@bs.send] external onError: (subtype('a), [@bs.as "error"] _, (. unit) => unit) => subtype('a) = "on";
    [@bs.send] external onConnection: (subtype('a), [@bs.as "connection"] _, (. IcpSocket.t) => unit) => subtype('a) = "on";
    [@bs.send] external onListening: (subtype('a), [@bs.as "listening"] _, (. unit) => unit) => subtype('a) = "on";
    [@bs.send] external offClose: (subtype('a), [@bs.as "close"] _, (. unit) => unit) => subtype('a) = "off";
    [@bs.send] external offError: (subtype('a), [@bs.as "error"] _, (. unit) => unit) => subtype('a) = "off";
    [@bs.send] external offConnection: (subtype('a), [@bs.as "connection"] _, (. IcpSocket.t) => unit) => subtype('a) = "off";
    [@bs.send] external offListening: (subtype('a), [@bs.as "listening"] _, (. unit) => unit) => subtype('a) = "off";
    [@bs.send] external onCloseOnce: (subtype('a), [@bs.as "close"] _, (. unit) => unit) => subtype('a) = "once";
    [@bs.send] external onErrorOnce: (subtype('a), [@bs.as "error"] _, (. unit) => unit) => subtype('a) = "once";
    [@bs.send] external onConnectionOnce: (subtype('a), [@bs.as "connection"] _, (. IcpSocket.t) => unit) => subtype('a) = "once";
    [@bs.send] external onListeningOnce: (subtype('a), [@bs.as "listening"] _, (. unit) => unit) => subtype('a) = "once";
  };
  module Impl = {
    include Events;
    [@bs.send] external close: (subtype('a), ~callback: Js.nullable(Js.Exn.t) => unit=?, unit) => subtype('a) = "close";
    [@bs.send] external getConnections: (subtype('a), (Js.nullable(Js.Exn.t), int) => unit) => subtype('a) = "getConnections";
    [@bs.set] external setMaxConnections: (subtype('a), int) => unit = "maxConnections";
    [@bs.get] external maxConnections: (subtype('a)) => int = "maxConnections";
    [@bs.send] external ref: (subtype('a)) => subtype('a) = "ref";
    [@bs.send] external unref: (subtype('a)) => subtype('a) = "unref";
    [@bs.get] external listening: (subtype('a)) => bool = "listening"
  };
  include Impl;
  type listenOptions;
  [@bs.obj] external listenOptions: (
    ~path: string=?,
    ~host: string=?,
    ~backlog: int=?,
    ~exclusive: bool=?,
    ~readableAll: bool=?,
    ~writableAll: bool=?,
    unit
  ) => listenOptions = "";
  [@bs.send] external listen: (t, ~path: string, ~callback: unit => unit=?, unit) => t = "listen";
  [@bs.send] external listenWith: (t, ~options: listenOptions, ~callback: unit => unit=?, unit) => t = "listen";

};

type server('a) = Server.subtype('a);
type tcpServer = server(TcpServer.kind);
type icpServer = server(IcpServer.kind);

[@bs.module "net"] [@bs.val] external isIP: string => bool = "isIP";
[@bs.module "net"] [@bs.val] external isIPv4: string => bool = "isIPv4";
[@bs.module "net"] [@bs.val] external isIPv6: string => bool = "isIPv6";
