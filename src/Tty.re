type tty = [ `Tty ];

module ReadStream = {
  type kind = [ Stream.readable | Net.Socket.kind | tty ];
  type subtype('a) = Net.Socket.subtype([> kind ] as 'a);
  type supertype('a) = Net.Socket.subtype([< kind ] as 'a);
  type t = subtype(kind);
  include Net.Socket.Impl;
};
