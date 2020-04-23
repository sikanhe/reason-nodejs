type tty = [ | `Tty];

module ReadStream = {
  type kind = [ Stream.readable | tty];
  type subtype('a) = Stream.subtype(Buffer.t, Buffer.t, [> kind] as 'a);
  type supertype('a) = Stream.subtype(Buffer.t, Buffer.t, [< kind] as 'a);
  type t = subtype(kind);
  module Events = {
    include Stream.Readable.Events;
  };
  module Impl = {
    include Stream.Readable.Impl;
  };
  include Events;
  include Impl;
};

module WriteStream = {
  type kind = [ Stream.writable | tty];
  type subtype('a) = Stream.subtype(Buffer.t, Buffer.t, [> kind] as 'a);
  type supertype('a) = Stream.subtype(Buffer.t, Buffer.t, [< kind] as 'a);
  type t = subtype(kind);
  module Events = {
    include Stream.Writable.Events;
  };
  module Impl = {
    include Stream.Writable.Impl;
  };
  include Events;
  include Impl;
};
