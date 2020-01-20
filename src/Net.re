module Socket = {
  include Stream.Duplex;
  type t = Stream.t([ Stream.duplex]);

  [@bs.module "net"] [@bs.new] external make: unit => t = "Socket";
  type address = {
    port: int,
    family: string,
    address: string,
  };
  [@bs.send] external address: t => address = "address";
  [@bs.get] external bufferSize: t => int = "bufferSize";
  [@bs.get] external bytesRead: t => int = "bytesRead";
  [@bs.get] external bytesWritten: t => int = "bytesWritten";
  [@bs.get] external remoteAddress: t => string = "remoteAddress";
  [@bs.get] external remoteFamily: t => string = "remoteFamily";
  [@bs.get] external remotePort: t => int = "remotePort";
};

[@bs.module "net"] [@bs.val] external isIP: string => bool = "isIP";
[@bs.module "net"] [@bs.val] external isIPv4: string => bool = "isIPv4";
[@bs.module "net"] [@bs.val] external isIPv6: string => bool = "isIPv6";