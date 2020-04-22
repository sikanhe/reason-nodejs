module PerformanceEntry = {
  type t;
  [@bs.get] external duration: t => float = "duration";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external startTime: t => float = "startTime";
  [@bs.get] external entryType: t => string = "entryType";
  [@bs.get] external kind: t => int = "kind";
};

module PerformanceNodeTiming = {
  type t;
  // Extends PerformanceEntry:
  [@bs.get] external duration: t => float = "duration";
  [@bs.get] external name: t => string = "name";
  [@bs.get] external startTime: t => float = "startTime";
  [@bs.get] external entryType: t => string = "entryType";
  [@bs.get] external kind: t => int = "kind";
  // Specific to this class:
  [@bs.get] external bootstrapComplete: t => float = "bootstrapComplete";
  [@bs.get] external clusterSetupStart: t => float = "clusterSetupStart";
  [@bs.get] external clusterSetupEnd: t => float = "clusterSetupEnd";
  [@bs.get] external environment: t => float = "environment";
  [@bs.get] external loopStart: t => float = "loopStart";
  [@bs.get] external loopExit: t => float = "loopExit";
  [@bs.get] external moduleLoadStart: t => float = "moduleLoadStart";
  [@bs.get] external moduleLoadEnd: t => float = "moduleLoadEnd";
  [@bs.get] external nodeStart: t => float = "nodeStart";
  [@bs.get] external preloadModuleLoadStart: t => float = "preloadModuleLoadStart";
  [@bs.get] external preloadModuleLoadEnd: t => float = "preloadModuleLoadEnd";
  [@bs.get] external thirdPartyMainStart: t => float = "thirdPartyMainStart";
  [@bs.get] external thirdPartyMainEnd: t => float = "thirdPartyMainEnd";
  [@bs.get] external v8Start: t => float = "v8Start";
};

module Performance = {
  type t;
  [@bs.module "perf_hooks"] external performance: t = "performance";
  [@bs.send] external clearMarks: (t, unit) => unit = "clearMarks";
  [@bs.send] external clearMarksByName: (t, string) => unit = "clearMarks";
  [@bs.send] external mark: (t, unit) => unit = "mark";
  [@bs.send] external markWithName: (t, string) => unit = "mark";
  [@bs.send]
  external measure: (t, string, ~startMark: string, ~endMark: string) => unit = "measure";
  [@bs.get] external nodeTiming: t => PerformanceNodeTiming.t = "nodeTiming";
  [@bs.send] external now: t => float = "now";
  [@bs.send] external timerify: (unit => unit, unit) => unit = "timerify";
  [@bs.send] external timerifyU: ([@bs.uncurry] (unit => unit)) => (unit => unit) = "timerify";
};

module Histogram = {
  type t;
  [@bs.send] external disable: (t, unit) => bool = "disable";
  [@bs.send] external enable: (t, unit) => bool = "enable";
  [@bs.get] external exceeds: t => float = "exceeds";
  [@bs.get] external max: t => float = "max";
  [@bs.get] external mean: t => float = "mean";
  [@bs.get] external min: t => float = "min";
  [@bs.send] external percentile: (t, int) => float = "percentile";
  [@bs.send] external reset: t => unit = "reset";
  [@bs.send] external stddev: t => float = "stddev";
  // ES6 Map type not defined by BuckleScript as far as I can tell
  // [@bs.get] external percentiles: t => ES6Map.t(int, float) = "percentiles";
};

module PerformanceObserverEntryList = {
  type t;
  [@bs.send] external getEntries: t => array(PerformanceEntry.t) = "getEntries";
  [@bs.send]
  external getEntriesByName: (t, string, Js.Nullable.t(string)) => array(PerformanceEntry.t) =
    "getEntriesByName";
  let getEntriesByName = (entryList, ~type_=?, name) =>
    getEntriesByName(entryList, name, Js.Nullable.fromOption(type_));
  [@bs.send]
  external getEntriesByType: (t, string) => array(PerformanceEntry.t) = "getEntriesByType";
};

module PerformanceObserver = {
  type t;
  [@bs.module "perf_hooks"] [@bs.new]
  external make: ((PerformanceObserverEntryList.t, t) => unit) => t = "PerformanceObserver";
};

[@bs.module "perf_hooks"]
external monitorEventLoopDelay: Js.Nullable.t({. "resolution": float}) => Histogram.t =
  "eventLoopDelay";
let monitorEventLoopDelay = (~resolution=?, ()) =>
  monitorEventLoopDelay(Js.Nullable.fromOption(resolution));
