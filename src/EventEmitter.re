/**
 * `Impl` is a functor which generates FFI bindings to Node's `EventEmitter`
 * class for any type `t`. This is not inherently type-safe. Type-safety can
 * be achieved by implementing the known `Event.t('a => 'b, t)` types
 */
module Impl = (T: {type t;}) => {
  /**
   * `addListener(emitter, event, listener)`
   *
   * Adds a new event listener function to the event emitter.
   */
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

  /**
   * `on(emitter, event, listener)`
   *
   * Adds a new event listener function to the event emitter.
   * Alias for `addListener`.
   */
  [@bs.send]
  external on: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t = "on";

  /**
   * `once(emitter, event, listener)`
   *
   * Adds a new **single-use** event listener function to the event
   * emitter. Then next time the given event is emitted, this listener
   * will fire exactly once, and then be removed from the emitter's
   * internal listener array.
   */
  [@bs.send]
  external once: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t = "once";

  /**
   * `off(emitter, event, listener)`
   *
   * Removes the listener function from the event emitter.
   *
   * The specified listener function is compared by **referential
   * equality** to each function in the emitter's internal listener
   * array.
   *
   * This means that, when the target listener is initially added, that
   * exact function reference must be maintained and provided here
   * in order to ensure removal.
   *
   * Alias for `removeListener`.
   */
  [@bs.send]
  external off: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t = "off";

  /**
   * `prependListener(emitter, event, listener)`
   *
   * Adds a new event listener function to the event emitter.
   *
   * Unlike `on` and `addListener`, `prependListener` adds the listener
   * function to the front of the internal listener array, ensuring
   * that this function is called before the rest of the listeners for
   * the given event.
   */
  [@bs.send]
  external prependListener: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t =
    "prependListener";

  /**
   * `prependListenerOnce(emitter, event, listener)`
   *
   * Adds a new **single-use** event listener function to the event
   * emitter. Then next time the given event is emitted, this listener
   * will fire exactly once, and then be removed from the emitter's
   * internal listener array.
   *
   * Unlike `once`, `prependListenerOnce` adds the listener function
   * to the front of the internal listener array, ensuring that this
   * function is called before the rest of the listeners for the
   * given event.
   */
  [@bs.send]
  external prependOnceListener: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t =
    "prependOnceListener";

  [@bs.send] external removeAllListeners: T.t => T.t = "removeAllListeners";

  /**
   * `removeListener(emitter, event, listener)`
   *
   * Removes the listener function from the event emitter.
   *
   * The specified listener function is compared by **referential
   * equality** to each function in the emitter's internal listener
   * array.
   *
   * This means that, when the target listener is initially added, that
   * exact function reference must be maintained and provided here
   * in order to ensure removal.
   */
  [@bs.send]
  external removeListener: (T.t, Event.t('a => 'b, T.t), 'a => 'b) => T.t =
    "removeListener";

  /**
   * `setMaxListeners(emitter, numberOfListeners)`
   *
   * Sets the maximum number of event listeners that may be added to
   * an event emitter before Node begins emitting warnings.
   *
   * By default, each event emitter has this value set to 10. This is
   * intended to warn the user about possible memory leaks.
   * `setMaxListeners` will increase this threshold.
   */
  [@bs.send]
  external setMaxListeners: (T.t, int) => T.t = "setMaxListeners";
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