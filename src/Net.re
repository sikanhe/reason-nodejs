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

  module Base = {
    type kind = [ Stream.socket ];
    type subtype('a) = Stream.subtype(Buffer.t, [> kind ] as 'a);
    type supertype('a) = Stream.subtype(Buffer.t, [< kind ] as 'a);
    type t = subtype(kind);
    module Impl = {
      [@bs.send] external address: subtype('a) => address = "address";
      [@bs.get] external bufferSize: subtype('a) => int = "bufferSize";
      [@bs.get] external bytesRead: subtype('a) => int = "bytesRead";
      [@bs.get] external bytesWritten: subtype('a) => int = "bytesWritten";
      [@bs.get] external remoteAddress: subtype('a) => string = "remoteAddress";
      [@bs.get] external remoteFamily: subtype('a) => string = "remoteFamily";
      [@bs.get] external remotePort: subtype('a) => int = "remotePort";
    };
    include Impl;
  };

  module Readable = {
    type kind = [ Stream.readable | Stream.socket ];
    type subtype('a) = Stream.subtype(Buffer.t, [> kind ] as 'a);
    type supertype('a) = Stream.subtype(Buffer.t, [< kind ] as 'a);
    type t = subtype(kind);
    module Impl = {
      include Stream.Readable.Impl;
      include Base.Impl;
    };
    include Impl;
  };

  module Writable = {
    type kind = [ Stream.writable | Stream.socket ];
    type subtype('a) = Stream.subtype(Buffer.t, [> kind ] as 'a);
    type supertype('a) = Stream.subtype(Buffer.t, [< kind ] as 'a);
    type t = subtype(kind);
    module Impl = {
      include Stream.Writable.Impl;
      include Base.Impl;
    };
    include Impl;
  };

  module Duplex = {
    type kind = [ Stream.duplex | Stream.socket ];
    type subtype('a) = Stream.subtype(Buffer.t, [> kind ] as 'a);
    type supertype('a) = Stream.subtype(Buffer.t, [< kind ] as 'a);
    type t = subtype(kind);
    module Impl = {
      include Stream.Duplex.Impl;
      include Base.Impl;
      include Readable.Impl;
      include Writable.Impl;
    };
    include Impl;
  };

  type kind = [ Duplex.kind ];
  type subtype('a) = Stream.subtype(Buffer.t, [> kind ] as 'a);
  type supertype('a) = Stream.subtype(Buffer.t, [< kind ] as 'a);
  type t = subtype(kind);

  module Impl = {
    include Duplex.Impl;
  };
  include Impl;
};

module TcpSocket = {
  type nonrec kind = [ Socket.kind | tcp ];
  type subtype('a) = Socket.subtype([> kind ] as 'a);
  type supertype('a) = Socket.subtype([< kind ] as 'a);
  type t = subtype(kind);
  module Impl = {
    include Socket.Impl;
  };
  include Impl;
};

module IcpSocket = {
  type kind = [ Socket.kind | icp ];
  type subtype('a) = Socket.subtype([> kind ] as 'a);
  type supertype('a) = Socket.subtype([< kind ] as 'a);
  type t = subtype(kind);
  module Impl = {
    include Socket.Impl;
  };
  include Impl;
};

type tcpSocket = TcpSocket.t;
type icpSocket = IcpSocket.t;

module Server = {
  type kind = [ `Server ];
  type subtype('a) constraint 'a = [> kind ];
  type supertype('a) constraint 'a = [< kind ];
  type t = subtype(kind);

  module Impl = (T: { type t; }) => {

    [@bs.send] external close: (T.t, ~callback: Js.nullable(Js.Exn.t) => unit=?, unit) => T.t = "close";
    [@bs.send] external onClose: (T.t, [@bs.as "close"] _, unit => unit) => T.t = "on";
    [@bs.send] external onError: (T.t, [@bs.as "error"] _, unit => unit) => T.t = "on";
    [@bs.send] external onConnection: (T.t, [@bs.as "connection"] _, unit => unit) => T.t = "on";
    [@bs.send] external getConnections: (T.t, (Js.nullable(Js.Exn.t), int) => unit) => T.t = "getConnections";
    [@bs.set] external setMaxConnections: (T.t, int) => unit = "maxConnections";
    [@bs.get] external maxConnections: (T.t) => int = "maxConnections";
    [@bs.send] external ref: (T.t) => T.t = "ref";
    [@bs.send] external unref: (T.t) => T.t = "unref";
    [@bs.get] external listening: (T.t) => bool = "listening"

  };

  include Impl({ type nonrec t = t; });

};

module TcpServer = {
  type kind = [ Server.kind | tcp ];
  type subtype('a) = Server.subtype([> kind ] as 'a);
  type supertype('a) = Server.subtype([< kind ] as 'a);
  type t = subtype(kind);

  module Impl = (T: { type t; }) => {

    [@bs.send] external close: (T.t, ~callback: Js.nullable(Js.Exn.t) => unit=?, unit) => T.t = "close";
    [@bs.send] external onClose: (T.t, [@bs.as "close"] _, unit => unit) => T.t = "on";
    [@bs.send] external onError: (T.t, [@bs.as "error"] _, unit => unit) => T.t = "on";
    [@bs.send] external onConnection: (T.t, [@bs.as "connection"] _, unit => unit) => T.t = "on";
    [@bs.send] external getConnections: (T.t, (Js.nullable(Js.Exn.t), int) => unit) => T.t = "getConnections";
    [@bs.set] external setMaxConnections: (T.t, int) => unit = "maxConnections";
    [@bs.get] external maxConnections: (T.t) => int = "maxConnections";
    [@bs.send] external ref: (T.t) => T.t = "ref";
    [@bs.send] external unref: (T.t) => T.t = "unref";
    [@bs.get] external listening: (T.t) => bool = "listening"

  };

  include Impl({ type nonrec t = t; });

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

  module Impl = (T: { type t; }) => {

    [@bs.send] external close: (T.t, ~callback: Js.nullable(Js.Exn.t) => unit=?, unit) => T.t = "close";
    [@bs.send] external onClose: (T.t, [@bs.as "close"] _, unit => unit) => T.t = "on";
    [@bs.send] external onError: (T.t, [@bs.as "error"] _, unit => unit) => T.t = "on";
    [@bs.send] external onConnection: (T.t, [@bs.as "connection"] _, unit => unit) => T.t = "on";
    [@bs.send] external getConnections: (T.t, (Js.nullable(Js.Exn.t), int) => unit) => T.t = "getConnections";
    [@bs.set] external setMaxConnections: (T.t, int) => unit = "maxConnections";
    [@bs.get] external maxConnections: (T.t) => int = "maxConnections";
    [@bs.send] external ref: (T.t) => T.t = "ref";
    [@bs.send] external unref: (T.t) => T.t = "unref";
    [@bs.get] external listening: (T.t) => bool = "listening"

  };

  include Impl({ type nonrec t = t; });

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
  [@bs.send] external listen: (~path: string, ~callback: unit => unit=?, unit) => t = "listen";
  [@bs.send] external listenWith: (~options: listenOptions, ~callback: unit => unit=?, unit) => t = "listen";

};

type server('a) = Server.subtype('a);
type tcpServer = server(TcpServer.kind);
type icpServer = server(IcpServer.kind);


[@bs.module "net"] [@bs.val] external isIP: string => bool = "isIP";
[@bs.module "net"] [@bs.val] external isIPv4: string => bool = "isIPv4";
[@bs.module "net"] [@bs.val] external isIPv6: string => bool = "isIPv6";
