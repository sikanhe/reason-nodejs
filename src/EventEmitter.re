/**
 * `Impl` is a functor which generates FFI bindings to Node's `EventEmitter`
 * class for any type `t`. This is not inherently type-safe. Type-safety can
 * be achieved by implementing the known `Event.t('a => 'b, t)` types
 */
module Impl = (T: {type t;}) => {
  [@bs.send]
  external addListener: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t =
    "addListener";
  [@bs.send]
  external emit: (T.t, Event.t('a => 'b, T.t), 'a) => bool = "emit";
  [@bs.get] external errorMonitor: T.t => Js.Types.symbol = "errorMonitor";
  [@bs.send]
  external eventNames:
    (T.t, Event.t('a => 'b, T.t)) => array(Event.t('a => 'b, T.t)) =
    "eventNames";
  [@bs.send] external getMaxListeners: T.t => int = "getMaxListeners";
  [@bs.send]
  external listenerCount: (T.t, Event.t('a => 'b, T.t)) => int =
    "listenerCount";
  [@bs.send]
  external listeners: (T.t, Event.t('a => 'b, T.t)) => array('a => 'b) =
    "listeners";
  [@bs.send]
  external on: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t = "on";
  [@bs.send]
  external once: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t = "once";
  [@bs.send]
  external off: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t = "off";
  [@bs.send]
  external prependListener: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t =
    "prependListener";
  [@bs.send]
  external prependOnceListener: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t =
    "prependOnceListener";
  [@bs.send] external removeAllListeners: T.t => T.t = "removeAllListeners";
  [@bs.send]
  external removeListener: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t =
    "removeListener";
  [@bs.send] external setMaxListeners: (T.t, int) => T.t = "setMaxListeners";

  [@bs.send]
  external onNewListener:
    (
      T.t,
      [@bs.as "newListener"] _,
      (Event.t('a => 'b, T.t), 'a => 'b) => unit
    ) =>
    T.t =
    "on";
  [@bs.send]
  external onRemoveListener:
    (
      T.t,
      [@bs.as "removeListener"] _,
      (Event.t('a => 'b, T.t), 'a => 'b) => unit
    ) =>
    T.t =
    "on";
};

/**
 * A generative functor that creates a unique type `t` with the `EventEmitter`
 * interface bindings.
*/
module Make = (()) => {
  type t;
  include Impl({
    type nonrec t = t;
  });
  [@bs.module "events"] [@bs.new] external make: unit => t = "EventEmitter";
};
