type t = string;

[@bs.module "querystring"] external parse: string => Js.Dict.t(string) = "parse";
[@bs.module "querystring"] external decode: string => Js.Dict.t(string) = "decode";
[@bs.module "querystring"] external stringify: Js.Dict.t(string) => string = "stringify";