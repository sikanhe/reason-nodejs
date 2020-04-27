type lookupOptions;
[@bs.obj]
external lookupOptions:
  (~family: int=?, ~hints: int=?, ~all: bool=?, ~verbatim: bool=?) =>
  lookupOptions;
[@bs.module "dns"] [@bs.scope "promise"]
external lookup:
  string =>
  Js.Promise.t(
    array({
      .
      "address": string,
      "family": int,
    }),
  ) =
  "lookup";
[@bs.module "dns"] [@bs.scope "promise"]
external lookupWithOptions:
  (string, lookupOptions) =>
  Js.Promise.t(
    array({
      .
      "address": string,
      "family": int,
    }),
  ) =
  "lookup";
[@bs.module "dns"] [@bs.scope "promise"]
external lookupService:
  (string, int) =>
  Js.Promise.t({
    .
    "hostname": string,
    "service": string,
  }) =
  "lookupService";
[@bs.module "dns"] [@bs.scope "promise"]
external resolve4: string => Js.Promise.t(array(string)) = "resolve4";
[@bs.module "dns"] [@bs.scope "promise"]
external resolve4TTL:
  (string, [@bs.as {json| {"ttl": true} |json}] _) =>
  Js.Promise.t(array(string)) =
  "resolve4";
[@bs.module "dns"] [@bs.scope "promise"]
external resolve6: string => Js.Promise.t(array(string)) = "resolve6";
[@bs.module "dns"] [@bs.scope "promise"]
external resolve6TTL:
  (string, [@bs.as {json| {"ttl": true} |json}] _) =>
  Js.Promise.t(array(string)) =
  "resolve6";
[@bs.module "dns"] [@bs.scope "promise"]
external resolveAny: string => Js.Promise.t(array(Js.t({..}))) =
  "resolveAny";
[@bs.module "dns"] [@bs.scope "promise"]
external resolveCname: string => Js.Promise.t(array(string)) =
  "resolveCname";
[@bs.module "dns"] [@bs.scope "promise"]
external resolveMx:
  string =>
  Js.Promise.t(
    array({
      .
      "priority": int,
      "exchange": string,
    }),
  ) =
  "resolveMx";
[@bs.module "dns"] [@bs.scope "promise"]
external resolveNaptr:
  string =>
  Js.Promise.t(
    array({
      .
      "flags": string,
      "service": string,
      "regexp": string,
      "replacement": string,
      "order": int,
      "preference": int,
    }),
  ) =
  "resolveNaptr";
[@bs.module "dns"] [@bs.scope "promise"]
external resolveNs: string => Js.Promise.t(array(string)) = "resolveNs";
[@bs.module "dns"] [@bs.scope "promise"]
external resolvePtr: string => Js.Promise.t(array(string)) = "resolvePtr";
[@bs.module "dns"] [@bs.scope "promise"]
external resolveSoa:
  string =>
  Js.Promise.t(
    array({
      .
      "nsname": string,
      "hostmaster": string,
      "serial": float,
      "refresh": int,
      "retry": int,
      "expire": int,
      "minttl": int,
    }),
  ) =
  "resolveSoa";

[@bs.module "dns"] [@bs.scope "promise"]
external resolveSrv:
  string =>
  Js.Promise.t(
    array({
      .
      "priority": int,
      "weight": int,
      "port": int,
      "name": string,
    }),
  ) =
  "resolveSrv";
[@bs.module "dns"] [@bs.scope "promise"]
external resolveTxt: string => Js.Promise.t(array(array(string))) =
  "resolveTxt";
[@bs.module "dns"] [@bs.scope "promise"]
external reverse: string => Js.Promise.t(array(string)) = "reverse";
[@bs.module "dns"] [@bs.scope "promise"]
external setServers: array(string) => Js.Promise.t(unit) = "setServers";

module CallbackAPI = {
  [@bs.module "dns"]
  external lookup: (string, (Js.Exn.t, string, int) => unit) => string =
    "lookup";
  [@bs.module "dns"]
  external lookupWithOptions:
    (string, lookupOptions, (Js.Exn.t, string, int) => unit) => string =
    "lookup";
  [@bs.module "dns"]
  external getServers: unit => array(string) = "getServers";
  [@bs.module "dns"]
  external resolveAny:
    (string, (Js.Exn.t, array(Js.t({..}))) => unit) => unit =
    "resolveAny";
  [@bs.module "dns"]
  external resolve4: (string, (Js.Exn.t, array(string)) => unit) => unit =
    "resolve4";
  [@bs.module "dns"]
  external resolve4TTL:
    (
      string,
      [@bs.as {json| {"ttl": true} |json}] _,
      (
        Js.Exn.t,
        array({
          .
          "address": string,
          "ttl": int,
        })
      ) =>
      unit
    ) =>
    unit =
    "resolve4";
  [@bs.module "dns"]
  external resolve6: (string, (Js.Exn.t, array(string)) => unit) => unit =
    "resolve6";
  [@bs.module "dns"]
  external resolve6TTL:
    (
      string,
      [@bs.as {json| {"ttl": true} |json}] _,
      (
        Js.Exn.t,
        array({
          .
          "address": string,
          "ttl": int,
        })
      ) =>
      unit
    ) =>
    unit =
    "resolve6";
  [@bs.module "dns"]
  external resolveCname: (string, (Js.Exn.t, array(string)) => unit) => unit =
    "resolveCname";
  [@bs.module "dns"]
  external resolveMx:
    (
      string,
      (
        Js.Exn.t,
        array({
          .
          "exchange": string,
          "priority": int,
        }),
      )
    ) =>
    unit =
    "resolveMx";
  [@bs.module "dns"]
  external resolveNaptr:
    (
      string,
      (
        Js.Exn.t,
        array({
          .
          "flags": string,
          "service": string,
          "regexp": string,
          "replacement": string,
          "order": int,
          "preference": int,
        })
      ) =>
      unit
    ) =>
    unit =
    "resolveNaptr";
  [@bs.module "dns"]
  external resolveNs: (string, (Js.Exn.t, array(string))) => unit =
    "resolveNs";
  [@bs.module "dns"]
  external resolvePtr: (string, (Js.Exn.t, array(string))) => unit =
    "resolvePtr";
  [@bs.module "dns"]
  external resolveSoa:
    (
      string,
      (
        Js.Exn.t,
        {
          .
          "nsname": string,
          "hostmaster": string,
          "serial": float,
          "refresh": int,
          "retry": int,
          "expire": int,
          "minttl": int,
        }
      ) =>
      unit
    ) =>
    unit =
    "resolveSoa";
  [@bs.module "dns"]
  external resolveSrv:
    (
      string,
      (
        Js.Exn.t,
        array({
          .
          "priority": int,
          "weight": int,
          "port": int,
          "name": string,
        })
      ) =>
      unit
    ) =>
    unit =
    "resolveSrv";
  [@bs.module "dns"]
  external resolveTxt: (string, (Js.Exn.t, array(array(string)))) => unit =
    "resolveTxt";
  [@bs.module "dns"]
  external reverse: (string, (Js.Exn.t, array(string)) => unit) => unit =
    "reverse";
  [@bs.module "dns"]
  external setServers: array(string) => unit = "setServers";
};
