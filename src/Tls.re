module TLSSocket = {
  type kind = [ Net.Socket.kind | `TLSSocket ];
  type t = Stream.t([ kind ]);
  module Impl = {
    include Net.Socket.Impl;
  };
  include Impl;
};