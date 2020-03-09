module TLSSocket = {
  type kind = [ Net.Socket.kind | `TLSSocket ];
  type t = Stream.t(Buffer.t, [ kind ]);
  module Impl = {
    include Net.Socket.Impl;
  };
  include Impl;
};

module Server = {
  type kind = [ Net.Server.kind | `TLSServer ];
  type t = Net.server([ kind ]);
  module Impl = {
    include Net.Server.Impl;
  };
  include Impl;
};
