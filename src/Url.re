module SearchParams = {
  type t = {
    [@bs.as "append"]
    append: (~name: string, ~value: string) => unit,
    [@bs.as "delete"]
    delete: string => unit,
    [@bs.as "forEach"]
    forEach:
      ((~value: string, ~name: string=?, ~searchParams: t=?) => unit) => unit,
    [@bs.as "get"]
    get: string => Js.Null.t(string),
    [@bs.as "getAll"]
    getAll: string => array(string),
    [@bs.as "has"]
    has: string => bool,
    [@bs.as "set"]
    set: (~name: string, ~value: string) => unit,
    [@bs.as "sort"]
    sort: unit => unit,
    [@bs.as "toString"]
    toString: unit => string,
    // [@bs.as "[Symbol.iterator]"] iteratorSymbol: unit => iterator, // no type definition for 'iterator'
    // [@bs.as "values"] values: unit => iterator, // no type definition for 'iterator'
    // [@bs.as "entries"] entries: unit => iterator, // no type definition for 'iterator'
    // [@bs.as "keys"] keys: unit => iterator, // no type definition for 'iterator'
  };
  [@bs.new] external empty: unit => t = "URLSearchParams";
  [@bs.new] external fromString: string => t = "URLSearchParams";
  [@bs.new] external fromDict: Js.Dict.t(string) => t = "URLSearchParams";
  // [@bs.new] external fromIterable: iterable => t = "URLSearchParams"; // no type definition for 'iterator'
};

type t = {
  hash: string,
  host: string,
  hostname: string,
  href: string,
  origin: string,
  password: string,
  pathname: string,
  port: int,
  protocol: string,
  search: string,
  searchParams: SearchParams.t,
  username: string,
  toString: unit => string,
  toJson: unit => Js.Json.t,
};

[@bs.module "url"] [@bs.new] external make: string => t = "URL";
[@bs.module "url"] [@bs.new]
external fromBaseString: (~input: string, ~base: string) => t = "URL";
[@bs.module "url"] [@bs.new]
external fromBaseUrl: (~input: string, ~base: t) => t = "URL";

[@bs.module "url"] external domainToASCII: string => string = "domainToASCII";
[@bs.module "url"]
external domainToUnicode: string => string = "domainToUnicode";
[@bs.module "url"] external fileURLToPath: t => string = "fileURLToPath";
[@bs.module "url"]
external fileStringToPath: string => string = "fileURLToPath";

type urlFormatOptions = {
  .
  "auth": bool,
  "fragment": bool,
  "search": bool,
  "unicode": bool,
};

[@bs.module "url"]
external format:
  (
    t,
    {
      .
      "auth": Js.Nullable.t(bool),
      "fragment": Js.Nullable.t(bool),
      "search": Js.Nullable.t(bool),
      "unicode": Js.Nullable.t(bool),
    }
  ) =>
  string =
  "format";
let format = (~auth=?, ~fragment=?, ~search=?, ~unicode=?, url) =>
  format(
    url,
    {
      "auth": Js.Nullable.fromOption(auth),
      "fragment": Js.Nullable.fromOption(fragment),
      "search": Js.Nullable.fromOption(search),
      "unicode": Js.Nullable.fromOption(unicode),
    },
  );

[@bs.module "url"] external pathToFileURL: string => t = "pathToFileURL";
