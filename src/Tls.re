
module TLSSocket = {
  type t = Stream.t([ Stream.duplex | `Socket | `TLSSocket ]);

};