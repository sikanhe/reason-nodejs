type lookupOptions;
[@bs.obj]
external lookupOptions:
  (~family: int=?, ~hints: int=?, ~all: bool=?, ~verbatim: bool=?) => lookupOptions =
  "";

[@bs.module "dns"] external lookup: (string, (Js.Exn.t, string, int) => unit) => string = "lookup";
[@bs.module "dns"]
external lookupWithOptions: (string, lookupOptions, (Js.Exn.t, string, int) => unit) => string =
  "lookup";
