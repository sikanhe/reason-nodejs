type contextifiedObject('a);

type createContextOptions;
[@bs.obj]
external createContextOptions:
  (
    ~name: string=?,
    ~origin: string=?,
    ~codeGeneration: {
                       .
                       "strings": bool,
                       "wasm": bool,
                     }
                       =?
  ) =>
  createContextOptions;
[@bs.val] [@bs.module "vm"]
external createContext: Js.t({..} as 'a) => contextifiedObject('a) =
  "createContext";
[@bs.val] [@bs.module "vm"]
external createContextWithOptions:
  (Js.t({..} as 'a), createContextOptions) => contextifiedObject('a) =
  "createContext";

module Script = {
  type t;
  type makeOptions;
  [@bs.obj]
  external makeOptions:
    (
      ~filename: string=?,
      ~lineOffset: int=?,
      ~columnOffset: int=?,
      ~cachedData: Buffer.t=?,
      ~produceCachedData: bool=?
    ) =>
    makeOptions;
  [@bs.new] [@bs.module "vm"] external make: string => t = "Script";
  [@bs.new] [@bs.module "vm"]
  external makeWithOptions: (string, makeOptions) => t = "Script";
  [@bs.send] external createCachedData: t => Buffer.t = "createCachedData";
  [@bs.send]
  external runInContext: (t, string, contextifiedObject('a)) => 'b =
    "runInContext";
  [@bs.send]
  external runInNewContext: (t, string, contextifiedObject('a)) => 'b =
    "runInNewContext";
  [@bs.send] external runInThisContext: (t, string) => 'a = "runInThisContext";
};
