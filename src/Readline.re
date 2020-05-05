module Interface = {
  type t;
  type interfaceOptions;
  [@bs.obj]
  external interfaceOptions:
    (
      ~input: Stream.Readable.subtype('w, Buffer.t, 'k),
      ~output: Stream.Writable.subtype(Buffer.t, 'r, 'k)=?,
      ~completer: (string, (string, (array(string), string)) => unit) => unit
                    =?,
      ~terminal: bool=?,
      ~historySize: int=?,
      ~prompt: string=?,
      ~crlfDelay: int=?,
      ~removeHistoryDuplicates: bool=?,
      ~escapeCodeTimeout: int=?,
      unit
    ) =>
    interfaceOptions;
  [@bs.send] external make: (t, interfaceOptions) => t = "createInterface";
  [@bs.send] external close: t => unit = "close";
  [@bs.send] external pause: t => unit = "pause";
  [@bs.send] external prompt: (t, Js.nullable(bool)) => unit = "prompt";
  [@bs.send]
  external question: (t, string, string => unit) => unit = "question";
  [@bs.send] external resume: t => unit = "resume";
  [@bs.send] external setPrompt: (t, string) => unit = "setPrompt";
  [@bs.send] external write: (t, string) => unit = "write";
  type keyOptions;
  [@bs.obj]
  external keyOptions:
    (~ctrl: bool=?, ~meta: bool=?, ~shift: bool=?, ~name: string=?) =>
    keyOptions;
  [@bs.send]
  external writeKey: (t, Js.Null.t(string), keyOptions) => unit = "write";
  [@bs.send]
  external writeKey2:
    (
      t,
      Js.Null.t(string),
      {
        .
        "ctrl": option(bool),
        "meta": option(bool),
        "shift": option(bool),
        "name": option(string),
      }
    ) =>
    unit =
    "write";
  [@bs.get] [@bs.return nullable] external line: t => option(string) = "line";
  [@bs.get] [@bs.return nullable]
  external cursor: t => option(int) = "cursor";
  [@bs.send]
  external clearLine:
    (t, Stream.Writable.subtype(Buffer.t, 'r, 'k), int) => bool =
    "clearLine";
  [@bs.send]
  external clearScreenDown:
    (t, Stream.Writable.subtype(Buffer.t, 'r, 'k), unit => unit) => bool =
    "clearScreenDown";
  [@bs.send]
  external cursorTo:
    (
      t,
      Stream.Writable.subtype(Buffer.t, 'r, 'k),
      int,
      Js.Undefined.t(int),
      Js.Undefined.t(unit => unit)
    ) =>
    bool =
    "cursorTo";
  [@bs.send]
  external moveCursor:
    (
      t,
      Stream.Writable.subtype(Buffer.t, 'r, 'k),
      int,
      int,
      Js.Undefined.t(unit => unit)
    ) =>
    bool =
    "moveCursor";
};
