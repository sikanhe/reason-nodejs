module Emitter1 = {
  include EventEmitter.Make();

  let uniqueSymbol: Js.Types.symbol = [%raw {|Symbol("emitter1")|}];

  module Events = {
    let symbol: Event.t(Js.Types.symbol => unit, t) = Event.fromSymbol(uniqueSymbol);
    let text: Event.t(string => unit, t) = Event.fromString("text");
    let integer: Event.t(int => unit, t) = Event.fromString("integer");
    let textAndInteger: Event.t((string, int) => unit, t) = Event.fromString("textAndInteger");
  };

};

