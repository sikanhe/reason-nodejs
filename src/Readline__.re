module Interface = {
  type t;
  type interfaceOptions;
  [@bs.obj] external interfaceOptions: (
    ~input: Stream__.t('data, [ Stream__.readable ]),
    ~output: Stream__.t('data, [ Stream__.writable ])=?,
    ~completer: (string, (string, (array(string), string)) => unit) => unit=?,
    ~terminal: bool=?,
    ~historySize: int=?,
    ~prompt: string=?,
    ~crlfDelay: int=?,
    ~removeHistoryDuplicates: bool=?,
    ~escapeCodeTimeout: int=?,
  ) => interfaceOptions = "";
  [@bs.send] external make: (t, interfaceOptions) => t = "createInterface";
  [@bs.send] external close: t => unit = "close";
  [@bs.send] external pause: t => unit = "pause";
  [@bs.send] external prompt: (t, Js.Undefined.t(bool)) => unit = "prompt";
  [@bs.send] external question: (t, string, (string) => unit) => unit = "question";
  [@bs.send] external resume: t => unit = "resume";
  [@bs.send] external setPrompt: (t, string) => unit = "setPrompt";
  [@bs.send] external write: (t, string) => unit = "write";
  type keyOptions;
  [@bs.obj] external keyOptions: (
    ~ctrl: bool=?,
    ~meta: bool=?,
    ~shift: bool=?,
    ~name: string=?,
  ) => keyOptions = "";
  [@bs.send] external writeKey: (
      t,
      Js.Null.t(string),
      keyOptions
    ) => unit = "write";
  [@bs.send] external writeKey2: (
      t,
      Js.Null.t(string),
      {.
        "ctrl": option(bool),
        "meta": option(bool),
        "shift": option(bool),
        "name": option(string),
      }
    ) => unit = "write";
  [@bs.get] [@bs.return nullable] external line: t => option(string) = "line";
  [@bs.get] [@bs.return nullable] external cursor: t => option(int) = "cursor";
  [@bs.send] external clearLine: (t, Stream__.t('data, [ Stream__.writable ]), int) => bool = "clearLine";
  [@bs.send] external clearScreenDown: (t, Stream__.t('data, Stream__.writable), unit => unit) => bool = "clearScreenDown";
  [@bs.send] external cursorTo: (
      t,
      Stream__.t('data, Stream__.writable),
      int,
      Js.Undefined.t(int),
      Js.Undefined.t(unit => unit)
    ) => bool = "cursorTo";
  [@bs.send] external moveCursor: (t, Stream__.t('data, Stream__.writable), int, int, Js.Undefined.t(unit => unit)) => bool = "moveCursor";
  
};
