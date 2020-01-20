type t = {
  href: string,
  origin: string,
  protocol: string,
  username: string,
  password: string,
  host: string,
  hostname: string,
  port: int,
  pathname: string,
  search: string,
  searchParams: Js.Dict.t(string),
  hash: string,
};

[@bs.module "url"] [@bs.new]
external make: (~input: string, ~base: string) => t = "URL";