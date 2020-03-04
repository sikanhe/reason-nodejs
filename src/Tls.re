module TLSSocket = {
  type kind = [ Net.Socket.kind | `TLSSocket ];
  type t = Stream.t(Buffer.t, [ kind ]);
  module Impl = {
    include Net.Socket.Impl;
  };
  include Impl;
};
