include Node_fs;

module Constants = {
  [@bs.module "fs"] [@bs.val] [@bs.scope "constants"]
  external f_ok: int = "F_OK";
  [@bs.module "fs"] [@bs.val] [@bs.scope "constants"]
  external w_ok: int = "W_OK";
  [@bs.module "fs"] [@bs.val] [@bs.scope "constants"]
  external r_ok: int = "R_OK";
  [@bs.module "fs"] [@bs.val] [@bs.scope "constants"]
  external x_ok: int = "X_OK";
};

[@bs.deriving jsConverter]
type flags = [
  | [@bs.as "r"] `Read
  | [@bs.as "r+"] `ReadWrite
  | [@bs.as "rs+"] `ReadWriteSync
  | [@bs.as "w"] `Write
  | [@bs.as "wx"] `WriteFailIfExists
  | [@bs.as "w+"] `WriteRead
  | [@bs.as "wx+"] `WriteReadFailIfExists
  | [@bs.as "a"] `Append
  | [@bs.as "ax"] `AppendFailIfExists
  | [@bs.as "a+"] `AppendRead
  | [@bs.as "ax+"] `AppendReadFailIfExists
];

module Stat = {
  type t = {
    dev: int,
    ino: int,
    mode: int,
    nlink: int,
    uid: int,
    gid: int,
    rdev: int,
    size: int,
    blksize: int,
    blocks: int,
    atimeMs: float,
    mtimeMs: float,
    ctimeMs: float,
    birthtimeMs: float,
    atime: string,
    mtime: string,
    ctime: string,
    birthtime: string,
  };
};

[@bs.module "fs"] [@bs.val]
external openSync:
  (
    path,
    ~flags: [@bs.string] [
              | [@bs.as "r"] `Read
              | [@bs.as "r+"] `ReadWrite
              | [@bs.as "rs+"] `ReadWriteSync
              | [@bs.as "w"] `Write
              | [@bs.as "wx"] `WriteFailIfExists
              | [@bs.as "w+"] `WriteRead
              | [@bs.as "wx+"] `WriteReadFailIfExists
              | [@bs.as "a"] `Append
              | [@bs.as "ax"] `AppendFailIfExists
              | [@bs.as "a+"] `AppendRead
              | [@bs.as "ax+"] `AppendReadFailIfExists
            ],
    ~mode: int=?,
    unit
  ) =>
  fd =
  "openSync";

module Handle = {
  type t;

  [@bs.send]
  external appendFile:
    (
      t,
      Node_buffer.t,
      {
        .
        "encoding": Js.Nullable.t(string),
        "mode": option(int),
        "flag": option(string),
      }
    ) =>
    Js.Promise.t(unit) =
    "appendFile";
  let appendFile = (handle, ~encoding=?, ~mode=?, ~flag=?, data) => {
    appendFile(
      handle,
      data,
      {
        "encoding": encoding->Js.Nullable.fromOption,
        "mode": mode,
        "flag":
          switch (flag) {
          | Some(flag) => Some(flagsToJs(flag))
          | None => None
          },
      },
    );
  };

  [@bs.send] external chmod: (t, int) => Js.Promise.t(unit) = "chmod";
  [@bs.send] external chown: (t, int, int) => Js.Promise.t(unit) = "chown";
  [@bs.send] external close: t => Js.Promise.t(unit) = "close";
  [@bs.send] external datasync: t => Js.Promise.t(unit) = "datasync";
  [@bs.send] external fd: t => fd = "fd";

  type readInfo = {
    bytesRead: int,
    buffer: Node_buffer.t,
  };
  [@bs.send]
  external read:
    (t, Node_buffer.t, ~offset: int, ~length: int, ~position: int) =>
    Js.Promise.t(readInfo) =
    "read";
  [@bs.send]
  external readFile:
    (t, {. "flag": option(string)}) => Js.Promise.t(Node_buffer.t) =
    "read";
  let readFile = (handle, ~flag=?, ()) => {
    readFile(
      handle,
      {
        "flag":
          switch (flag) {
          | Some(flag) => Some(flagsToJs(flag))
          | None => None
          },
      },
    );
  };

  [@bs.send]
  external readFileWithEncoding:
    (
      t,
      {
        .
        "encoding": string,
        "flag": option(string),
      }
    ) =>
    Js.Promise.t(string) =
    "read";

  let readFileWithEncoding = (handle, ~flag=?, ~encoding) => {
    readFileWithEncoding(
      handle,
      {
        "encoding": encoding,
        "flag":
          switch (flag) {
          | Some(flag) => Some(flagsToJs(flag))
          | None => None
          },
      },
    );
  };

  [@bs.send] external stat: t => Js.Promise.t(Stat.t) = "stat";
  [@bs.send] external sync: t => Js.Promise.t(unit) = "sync";
  [@bs.send]
  external truncate: (t, ~length: int=?, unit) => Js.Promise.t(unit) =
    "truncate";

  type writeInfo = {bytesWritten: int};

  [@bs.send]
  external write:
    (fd, Node_buffer.t, ~offset: int=?, ~length: int=?, ~position: int=?) =>
    Js.Promise.t(writeInfo) =
    "write";

  [@bs.send]
  external writeString:
    (t, string, ~position: int, ~encoding: string) => Js.Promise.t(writeInfo) =
    "write";

  let writeString = (handle, ~position, ~encoding="utf8", content) =>
    writeString(handle, content, ~position, ~encoding);

  [@bs.send]
  external writeFile:
    (
      t,
      Node_buffer.t,
      {
        .
        "encoding": Js.Nullable.t(string),
        "mode": option(int),
        "flag": option(string),
      }
    ) =>
    Js.Promise.t(unit) =
    "writeFile";

  let writeFile = (handle, data, ~encoding=?, ~mode=?, ~flag=?, ()) => {
    writeFile(
      handle,
      data,
      {
        "encoding": encoding->Js.Nullable.fromOption,
        "mode": mode,
        "flag":
          switch (flag) {
          | Some(flag) => Some(flagsToJs(flag))
          | None => None
          },
      },
    );
  };
};

module Promises = {
  [@bs.module "fs"] [@bs.scope "promises"]
  external open_:
    (
      path,
      [@bs.string] [
        | [@bs.as "r"] `Read
        | [@bs.as "r+"] `ReadWrite
        | [@bs.as "rs+"] `ReadWriteSync
        | [@bs.as "w"] `Write
        | [@bs.as "wx"] `WriteFailIfExists
        | [@bs.as "w+"] `WriteRead
        | [@bs.as "wx+"] `WriteReadFailIfExists
        | [@bs.as "a"] `Append
        | [@bs.as "ax"] `AppendFailIfExists
        | [@bs.as "a+"] `AppendRead
        | [@bs.as "ax+"] `AppendReadFailIfExists
      ],
      ~mode: int=?,
      unit
    ) =>
    Js.Promise.t(Handle.t) =
    "open";
};

module WriteStream = {
  include Stream.Writable;
  type t = Stream.t([ Stream.writable | `FileSystem]);

  [@bs.send] external bytesWritten: t => int = "bytesWritten";
  [@bs.send] external path: t => string = "path";
  [@bs.send] external pending: t => bool = "pending";
  [@bs.send]
  external onClose: (t, [@bs.as "close"] _, unit => unit) => unit = "on";
  [@bs.send]
  external onOpen: (t, [@bs.as "open"] _, fd => unit) => unit = "on";
  [@bs.send]
  external onReady: (t, [@bs.as "ready"] _, unit => unit) => unit = "on";
};

module ReadStream = {
  include Stream.Readable;
  type t = Stream.t([ Stream.readable | `FileSystem]);

  [@bs.send] external bytesRead: t => int = "bytesWritten";
  [@bs.send] external path: t => string = "path";
  [@bs.send] external pending: t => bool = "pending";
  [@bs.send]
  external onClose: (t, [@bs.as "close"] _, unit => unit) => unit = "on";
  [@bs.send]
  external onOpen: (t, [@bs.as "open"] _, fd => unit) => unit = "on";
  [@bs.send]
  external onReady: (t, [@bs.as "ready"] _, unit => unit) => unit = "on";
};

[@bs.module "fs"]
external createReadStream:
  (
    path,
    {
      .
      "flags": option(string),
      "encoding": option(string),
      "fd": option(fd),
      "mode": option(int),
      "autoClose": option(bool),
      "emitClose": option(bool),
      "start": option(int),
      "end": option(int),
      "highWaterMark": option(int),
    }
  ) =>
  ReadStream.t =
  "createReadStream";

let createReadStream =
    (
      path,
      ~flags=?,
      ~encoding=?,
      ~fd=?,
      ~mode=?,
      ~autoClose=?,
      ~emitClose=?,
      ~start=?,
      ~end_=?,
      ~highWaterMark=?,
      (),
    ) => {
  createReadStream(
    path,
    {
      "flags":
        switch (flags) {
        | Some(flag) => Some(flagsToJs(flag))
        | None => None
        },
      "encoding": encoding,
      "fd": fd,
      "mode": mode,
      "autoClose": autoClose,
      "emitClose": emitClose,
      "start": start,
      "end": end_,
      "highWaterMark": highWaterMark,
    },
  );
};

[@bs.module "fs"]
external createWriteStream:
  (
    path,
    {
      .
      "flags": option(string),
      "encoding": option(string),
      "fd": option(fd),
      "mode": option(int),
      "autoClose": option(bool),
      "emitClose": option(bool),
      "start": option(int),
    }
  ) =>
  WriteStream.t =
  "createWriteStream";

let createWriteStream =
    (
      path,
      ~flags=?,
      ~encoding=?,
      ~fd=?,
      ~mode=?,
      ~autoClose=?,
      ~emitClose=?,
      ~start=?,
      (),
    ) => {
  createWriteStream(
    path,
    {
      "flags":
        switch (flags) {
        | Some(flag) => Some(flagsToJs(flag))
        | None => None
        },
      "encoding": encoding,
      "fd": fd,
      "mode": mode,
      "autoClose": autoClose,
      "emitClose": emitClose,
      "start": start,
    },
  );
};