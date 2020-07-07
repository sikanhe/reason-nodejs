type tty = [ | `Tty];

module ReadStream = {
  type kind('r) = [ Stream.readable('r) | tty];
  type subtype('r, 'ty) = Stream.subtype([> kind('r)] as 'ty);
  type supertype('r, 'ty) = Stream.subtype([< kind('r)] as 'ty);
  type t = Stream.subtype(kind(Buffer.t));
  module Events = {
    include Stream.Readable.Events;
  };
  module Impl = {
    include Stream.Readable.Impl;
    [@bs.get] external isRaw: t => bool = "isRaw";
    [@bs.get] external isTTY: t => bool = "isTTY";
    [@bs.send] external setRawMode: (t, bool) => t = "setRawMode";
    external unsafeCoerceToSocket: t => Net.Socket.t = "%identity";
    external unsafeCoerceFromSocket: Net.Socket.t => t = "%identity";
    external unsafeCoerceToReadable: t => Stream.Readable.t(Buffer.t) =
      "%identity";
    external unsafeCoerceFromReadable: Stream.Readable.t(Buffer.t) => t =
      "%identity";
  };
  include Events;
  include Impl;
};

module WriteStream = {
  type kind('w) = [ Stream.writable('w) | tty];
  type subtype('w, 'ty) = Stream.subtype([> kind('w)] as 'ty);
  type supertype('w, 'ty) = Stream.subtype([< kind('w)] as 'ty);
  type t = Stream.subtype(kind(Buffer.t));
  module Events = {
    include Stream.Writable.Events;
    [@bs.send]
    external onResize:
      (subtype('w, 'ty), [@bs.as "resize"] _, [@bs.uncurry] (unit => unit)) =>
      unit =
      "on";
    [@bs.send]
    external offResize:
      (subtype('w, 'ty), [@bs.as "resize"] _, [@bs.uncurry] (unit => unit)) =>
      unit =
      "off";
    [@bs.send]
    external onResizeOnce:
      (subtype('w, 'ty), [@bs.as "resize"] _, [@bs.uncurry] (unit => unit)) =>
      unit =
      "once";
  };
  module Impl = {
    include Stream.Writable.Impl;
    [@bs.send]
    external clearLineLeft:
      (t, [@bs.as {json|-1|json}] _, ~callback: unit => unit=?, unit) => bool =
      "clearLine";
    [@bs.send]
    external clearLineRight:
      (t, [@bs.as {json|1|json}] _, ~callback: unit => unit=?, unit) => bool =
      "clearLine";
    [@bs.send]
    external clearLine:
      (t, [@bs.as {json|0|json}] _, ~callback: unit => unit=?, unit) => bool =
      "clearLine";
    [@bs.send]
    external clearScreenDown: (t, ~callback: unit => unit=?, unit) => bool =
      "clearScreenDown";
    [@bs.get] external columns: t => int = "columns";
    [@bs.send] external getColorDepth: t => int = "getColorDepth";
    [@bs.send]
    external getColorDepthFromEnv: (t, Js.Dict.t('ty)) => int =
      "getColorDepth";
    [@bs.send] external getWindowSize: t => (int, int) = "getWindowSize";
    [@bs.send] external hasColors: (t, int) => bool = "hasColors";
    [@bs.send]
    external hasColorsFromEnv: (t, int, Js.Dict.t('ty)) => bool = "hasColors";
    [@bs.send] external hasAtLeast16Colors: t => bool = "hasColors";
    [@bs.get] external isTTY: t => bool = "isTTY";
    external unsafeCoerceToSocket: t => Net.Socket.t = "%identity";
    external unsafeCoerceFromSocket: Net.Socket.t => t = "%identity";
    external unsafeCoerceToWritable: t => Stream.Writable.t(Buffer.t) =
      "%identity";
    external unsafeCoerceFromWritable: Stream.Writable.t(Buffer.t) => t =
      "%identity";
  };
  include Events;
  include Impl;
};

[@bs.module "tty"] external isatty: Fs.fd => bool = "isatty";