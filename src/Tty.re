type tty = [ | `Tty];

module ReadStream = {
  type kind = [ Net.Socket.readable | tty];
  type subtype('a) = Net.Socket.Readable.subtype([> kind] as 'a);
  type supertype('a) = Net.Socket.Readable.subtype([< kind] as 'a);
  type t = subtype(kind);
  module Impl = {
    include Net.Socket.Readable.Impl;
  };
  include Impl;
};

module WriteStream = {
  type kind = [ Net.Socket.writable | tty];
  type subtype('a) = Net.Socket.Writable.subtype([> kind] as 'a);
  type supertype('a) = Net.Socket.Writable.subtype([< kind] as 'a);
  type t = subtype(kind);
  module Impl = {
    include Net.Socket.Writable.Impl;
  };
  include Impl;
};
