type t = {
  dir: string,
  root: string,
  base: string,
  name: string,
  ext: string,
};

[@bs.module "path"] external basename: string => string = "basename";

[@bs.module "path"] external basenameExt: (string, string) => string = "basename";

[@bs.module "path"] external delimiter: string = "delimiter";

[@bs.module "path"] external dirname: string => string = "dirname";

[@bs.module "path"] external extname: string => string = "extname";

[@bs.module "path"] external format: t => string = "format";

[@bs.module "path"] external isAbsolute: string => bool = "isAbsolute";

[@bs.module "path"] [@bs.splice] external join: array(string) => string = "join";

[@bs.module "path"] external join2: (string, string) => string = "join";

[@bs.module "path"] external normalize: string => string = "normalize";

[@bs.module "path"] external parse: string => t = "parse";

[@bs.module "path"] external relative: (~from: string, ~to_: string) => string = "relative";

[@bs.module "path"] [@bs.splice] external resolve: array(string) => string = "resolve";

[@bs.module "path"] external sep: string = "sep";

[@bs.module "path"] external toNamespacedPath: string => string = "toNamespacedPath";

module Posix = {
  [@bs.module "path"] [@bs.scope "posix"] external basename: string => string = "basename";

  [@bs.module "path"] [@bs.scope "posix"]
  external basenameExt: (string, string) => string = "basename";

  [@bs.module "path"] [@bs.scope "posix"] external delimiter: string = "delimiter";

  [@bs.module "path"] [@bs.scope "posix"] external dirname: string => string = "dirname";

  [@bs.module "path"] [@bs.scope "posix"] external extname: string => string = "extname";

  [@bs.module "path"] [@bs.scope "posix"] external format: t => string = "format";

  [@bs.module "path"] [@bs.scope "posix"] external isAbsolute: string => bool = "isAbsolute";

  [@bs.module "path"] [@bs.scope "posix"] [@bs.splice]
  external join: array(string) => string = "join";

  [@bs.module "path"] [@bs.scope "posix"] external join2: (string, string) => string = "join";

  [@bs.module "path"] [@bs.scope "posix"] external normalize: string => string = "normalize";

  [@bs.module "path"] [@bs.scope "posix"] external parse: string => t = "parse";

  [@bs.module "path"] [@bs.scope "posix"]
  external relative: (~from: string, ~to_: string) => string = "relative";

  [@bs.module "path"] [@bs.scope "posix"] [@bs.splice]
  external resolve: array(string) => string = "resolve";

  [@bs.module "path"] [@bs.scope "posix"] external sep: string = "sep";

  [@bs.module "path"] [@bs.scope "posix"]
  external toNamespacedPath: string => string = "toNamespacedPath";
};

module Win32 = {
  [@bs.module "path"] [@bs.scope "win32"] external basename: string => string = "basename";

  [@bs.module "path"] [@bs.scope "win32"]
  external basenameExt: (string, string) => string = "basename";

  [@bs.module "path"] [@bs.scope "win32"] external delimiter: string = "delimiter";

  [@bs.module "path"] [@bs.scope "win32"] external dirname: string => string = "dirname";

  [@bs.module "path"] [@bs.scope "win32"] external extname: string => string = "extname";

  [@bs.module "path"] [@bs.scope "win32"] external format: t => string = "format";

  [@bs.module "path"] [@bs.scope "win32"] external isAbsolute: string => bool = "isAbsolute";

  [@bs.module "path"] [@bs.scope "win32"] [@bs.splice]
  external join: array(string) => string = "join";

  [@bs.module "path"] [@bs.scope "win32"] external join2: (string, string) => string = "join";

  [@bs.module "path"] [@bs.scope "win32"] external normalize: string => string = "normalize";

  [@bs.module "path"] [@bs.scope "win32"] external parse: string => t = "parse";

  [@bs.module "path"] [@bs.scope "win32"]
  external relative: (~from: string, ~to_: string) => string = "relative";

  [@bs.module "path"] [@bs.scope "win32"] [@bs.splice]
  external resolve: array(string) => string = "resolve";

  [@bs.module "path"] [@bs.scope "win32"] external sep: string = "sep";

  [@bs.module "path"] [@bs.scope "win32"]
  external toNamespacedPath: string => string = "toNamespacedPath";
};
