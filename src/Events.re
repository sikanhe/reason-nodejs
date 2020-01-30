
module EventEmitter = {

  module Impl = (T: { type t; }) => {

    [@bs.module "events"] [@bs.new] external make: unit => T.t = "EventEmitter";
    [@bs.send] external addListener: (T.t, string, Js.t({..}) => unit) => unit = "addListener";
    [@bs.send] external emit: (T.t, string, Js.t({..})) => unit = "emit";
    [@bs.send] external eventNames: T.t => array(string) = "eventNames";
    [@bs.send] external getMaxListeners: T.t => int = "getMaxListeners";
    [@bs.send] external listenerCount: (T.t, string) => int = "listenerCount";
    [@bs.send] external listeners: (T.t, string) => array(Js.t({..})) = "listeners";
    [@bs.send] external off: (T.t, string, Js.t({..}) => unit) => T.t = "off";
    [@bs.send] external on: (T.t, string, Js.t({..}) => unit) => T.t = "on";
    [@bs.send] external once: (T.t, string, Js.t({..}) => unit) => T.t = "once";
    [@bs.send] external prependListener: (T.t, string, Js.t({..}) => unit) => T.t = "prependListener";
    [@bs.send] external prependOnceListener: (T.t, string, Js.t({..}) => unit) => T.t = "prependOnceListener";
    [@bs.send] external removeAllListeners: (T.t, string) => T.t = "removeAllListeners";
    [@bs.send] external removeListener: (T.t, string, Js.t({..}) => unit) => T.t = "removeListener";
    [@bs.send] external setMaxListeners: (T.t, int) => T.t = "setMaxListener";
    [@bs.send] external rawListeners: (T.t, string) => Js.t({..}) => unit = "rawListeners";

  };

  type t;

  include Impl({ type nonrec t = t; });

  [@bs.module "events"] [@bs.scope "EventEmitter"] external defaultMaxListeners: int => unit = "defaultMaxListeners";
  [@bs.module "events"] [@bs.scope "EventEmitter"] external errorMonitor: Js.Types.symbol = "errorMonitor";

};

[@bs.module "events"] [@bs.val] external once: (EventEmitter.t, string) => Js.Promise.t(array('a)) = "once";


/**
 * According to MDN the AsyncIterator class is experimental:
 * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/AsyncIterator
 * 
 * However, Node does not treat this data type as experimental or deprecated:
 * https://nodejs.org/docs/latest/api/events.html#events_events_on_emitter_eventname
 */

// type asyncIterator('a);
// [@bs.module "events"] [@bs.val] external on: (EventEmitter.t, string) => asyncIterator('a) = "on";

