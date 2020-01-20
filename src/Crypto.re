module Hash = {
  include Stream.Transform;
  type t = Stream.t([ Stream.transform | `Hash]);

  [@bs.send] external copy: t => t = "copy";

  [@bs.send] external digest: t => Buffer.t = "digest";

  [@bs.send]
  external digestWithEncoding:
    (
      t,
      [@bs.string] [
        | `hex
        | `utf8
        | `ascii
        | `latin1
        | `base64
        | `ucs2
        | `base64
        | `binary
        | `utf16le
      ]
    ) =>
    string =
    "digest";

  [@bs.send] external update: (t, string) => unit = "update";
  [@bs.send]
  external updateWithEncoding:
    (
      t,
      [@bs.string] [
        | `hex
        | `utf8
        | `ascii
        | `latin1
        | `base64
        | `ucs2
        | `base64
        | `binary
        | `utf16le
      ]
    ) =>
    unit =
    "update";
  [@bs.send] external updateBuffer: (t, Buffer.t) => unit = "update";
  [@bs.send]
  external updateDataView: (t, Js.TypedArray2.DataView.t) => unit = "update";
};

module Hmac = {
  include Stream.Transform;
  type t = Stream.t([ Stream.transform | `Hmac]);

  [@bs.send] external digest: t => Buffer.t = "digest";

  [@bs.send]
  external digestWithEncoding:
    (
      t,
      [@bs.string] [
        | `hex
        | `utf8
        | `ascii
        | `latin1
        | `base64
        | `ucs2
        | `base64
        | `binary
        | `utf16le
      ]
    ) =>
    string =
    "digest";

  [@bs.send] external update: (t, string) => unit = "update";
  [@bs.send]
  external updateWithEncoding:
    (
      t,
      [@bs.string] [
        | `hex
        | `utf8
        | `ascii
        | `latin1
        | `base64
        | `ucs2
        | `base64
        | `binary
        | `utf16le
      ]
    ) =>
    unit =
    "update";
  [@bs.send] external updateBuffer: (t, Buffer.t) => unit = "update";
  [@bs.send]
  external updateDataView: (t, Js.TypedArray2.DataView.t) => unit = "update";
};

[@bs.module "crypto"]
external createHash:
  (
  [@bs.string]
  [
    | [@bs.as "sha256"] `SHA256
    | [@bs.as "sha512"] `SHA512
    | [@bs.as "sha384"] `SHA384
    | [@bs.as "sha1"] `SHA1
    | [@bs.as "md5"] `MD5
  ]
  ) =>
  Hash.t =
  "createHash";

[@bs.module "crypto"]
external createHmac:
  (
    [@bs.string] [
      | [@bs.as "sha256"] `SHA256
      | [@bs.as "sha512"] `SHA512
      | [@bs.as "sha384"] `SHA384
      | [@bs.as "sha1"] `SHA1
      | [@bs.as "md5"] `MD5
    ],
    ~key: string
  ) =>
  Hmac.t =
  "createHmac";