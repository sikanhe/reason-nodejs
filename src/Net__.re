module Socket = {
  type kind = [ Stream__.duplex | `Socket ];
  type t = Stream__.t(Buffer.t, [ Stream.duplex | `Socket]);

  [@bs.module "net"] [@bs.new] external make: unit => t = "Socket";

  module Impl = {
    include Stream__.Duplex.Impl;
    type address = {
      [@bs.as "port"] port: int,
      [@bs.as "family"] family: string,
      [@bs.as "address"] address: string,
    };
    [@bs.send] external address: Stream__.t('data, [> kind ]) => address = "address";
    [@bs.get] external bufferSize: Stream__.t('data, [> kind ]) => int = "bufferSize";
    [@bs.get] external bytesRead: Stream__.t('data, [> kind ]) => int = "bytesRead";
    [@bs.get] external bytesWritten: Stream__.t('data, [> kind ]) => int = "bytesWritten";
    [@bs.get] external remoteAddress: Stream__.t('data, [> kind ]) => string = "remoteAddress";
    [@bs.get] external remoteFamily: Stream__.t('data, [> kind ]) => string = "remoteFamily";
    [@bs.get] external remotePort: Stream__.t('data, [> kind ]) => int = "remotePort";
  };

  include Impl;

};

module Server = {
  type t;
};

[@bs.module "net"] [@bs.val] external isIP: string => bool = "isIP";
[@bs.module "net"] [@bs.val] external isIPv4: string => bool = "isIPv4";
[@bs.module "net"] [@bs.val] external isIPv6: string => bool = "isIPv6";