type fd = pri int;
type path = string;

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

[@bs.obj]
external writeFileOption:
  (
    ~encoding: [@bs.string] [
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
                 =?,
    ~mode: int=?,
    ~flag: string=?,
    unit
  ) =>
  _ =
  "";

[@bs.obj]
external mkdirOption: (~recursive: bool=?, ~mode: int=?, unit) => _ = "";

type appendFileOptions;
[@bs.obj]
external appendFileOptions:
  (
    ~encoding: [@bs.string] [
                 | `hex
                 | `utf8
                 | `ascii
                 | `latin1
                 | `base64
                 | `ucs2
                 | `base64
                 | `binary
                 | `utf16le
               ],
    ~mode: int=?,
    ~flag: [@bs.string] [
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
           ]
             =?,
    unit
  ) =>
  appendFileOptions =
  "";

type readFileOptions;
[@bs.obj]
external readFileOptions:
  (
    ~flag: [@bs.string] [
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
           ]
             =?,
    unit
  ) =>
  readFileOptions =
  "";

type readFileStringOptions;
[@bs.obj]
external readFileStringOptions:
  (
    ~encoding: [@bs.string] [
                 | `hex
                 | `utf8
                 | `ascii
                 | `latin1
                 | `base64
                 | `ucs2
                 | `base64
                 | `binary
                 | `utf16le
               ],
    ~flag: [@bs.string] [
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
           ]
             =?,
    unit
  ) =>
  readFileStringOptions =
  "";

type writeFileUint8ArrayOptions;
[@bs.obj]
external writeFileUint8ArrayOptions:
  (
    ~encoding: [@bs.string] [
                 | `hex
                 | `utf8
                 | `ascii
                 | `latin1
                 | `base64
                 | `ucs2
                 | `base64
                 | `binary
                 | `utf16le
               ],
    ~mode: int=?,
    ~flag: [@bs.string] [
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
           ]
             =?,
    unit
  ) =>
  writeFileUint8ArrayOptions =
  "";

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

  [@bs.send] external isFile: t => bool = "isFile";
  [@bs.send] external isDirectory: t => bool = "isDirectory";
  [@bs.send] external isBlockDevice: t => bool = "isBlockDevice";
  [@bs.send] external isCharacterDevice: t => bool = "isCharacterDevice";
  [@bs.send] external isSymbolicLink: t => bool = "isSymbolicLink";
  [@bs.send] external isFIFO: t => bool = "isFIFO";
  [@bs.send] external isSocket: t => bool = "isSocket";
};

[@bs.module "fs"]
external readdirSync: string => array(string) = "readdirSync";

[@bs.module "fs"] external renameSync: (string, string) => unit = "renameSync";
[@bs.module "fs"] external ftruncateSync: (fd, int) => unit = "ftruncateSync";
[@bs.module "fs"]
external truncateSync: (string, int) => unit = "truncateSync";
[@bs.module "fs"]
external chownSync: (string, ~uid: int, ~gid: int) => unit = "chownSync";
[@bs.module "fs"]
external fchownSync: (fd, ~uid: int, ~gid: int) => unit = "fchownSync";
[@bs.module "fs"] external readlinkSync: string => string = "readlinkSync";
[@bs.module "fs"] external unlinkSync: string => unit = "unlinkSync";
[@bs.module "fs"] external rmdirSync: string => unit = "rmdirSync";

[@bs.module "fs"]
external openSync:
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
    ]
  ) =>
  unit =
  "openSync";

[@bs.module "fs"] [@bs.val]
external openSyncMode:
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
    ~mode: int,
    unit
  ) =>
  fd =
  "openSync";

[@bs.val] [@bs.module "fs"]
external readFileSync: string => string = "readFileSync";

[@bs.val] [@bs.module "fs"]
external readFileSyncWithEncoding:
  (
    string,
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
  "readFileSync";

[@bs.val] [@bs.module "fs"] external existsSync: string => bool = "existsSync";

type writeFileSyncOptions;
[@bs.obj]
external writeFileSyncOptions:
  (
    ~encoding: [@bs.string] [
                 | `hex
                 | `utf8
                 | `ascii
                 | `latin1
                 | `base64
                 | `ucs2
                 | `base64
                 | `binary
                 | `utf16le
               ],
    ~mode: int=?,
    ~flag: [@bs.string] [
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
           ]
             =?,
    unit
  ) =>
  writeFileSyncOptions =
  "";

[@bs.val] [@bs.module "fs"]
external writeFileSync: (string, string) => unit = "writeFileSync";

[@bs.val] [@bs.module "fs"]
external writeFileSyncWith: (string, string, writeFileSyncOptions) => unit =
  "writeFileSync";

module Handle = {
  type t;

  [@bs.send]
  external appendFile: (t, Buffer.t, appendFileOptions) => Js.Promise.t(unit) =
    "appendFile";

  [@bs.send]
  external appendFileWith: (t, Buffer.t) => Js.Promise.t(unit) = "appendFile";

  [@bs.send] external chmod: (t, int) => Js.Promise.t(unit) = "chmod";
  [@bs.send] external chown: (t, int, int) => Js.Promise.t(unit) = "chown";
  [@bs.send] external close: t => Js.Promise.t(unit) = "close";
  [@bs.send] external datasync: t => Js.Promise.t(unit) = "datasync";
  [@bs.send] external fd: t => fd = "fd";

  type readInfo = {
    bytesRead: int,
    buffer: Buffer.t,
  };
  [@bs.send]
  external read:
    (t, Buffer.t, ~offset: int, ~length: int, ~position: int) =>
    Js.Promise.t(readInfo) =
    "read";

  [@bs.send] external readFile: t => Js.Promise.t(Buffer.t) = "read";

  [@bs.send]
  external readFileWith: (t, readFileOptions) => Js.Promise.t(Buffer.t) =
    "read";

  type readFileStringOptions;
  [@bs.obj]
  external readFileStringOptions:
    (
      ~encoding: [@bs.string] [
                   | `hex
                   | `utf8
                   | `ascii
                   | `latin1
                   | `base64
                   | `ucs2
                   | `base64
                   | `binary
                   | `utf16le
                 ],
      ~flag: [@bs.string] [
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
             ]
               =?,
      unit
    ) =>
    readFileStringOptions =
    "";

  [@bs.send]
  external readFileString: (t, readFileStringOptions) => Js.Promise.t(string) =
    "read";

  [@bs.send] external stat: t => Js.Promise.t(Stat.t) = "stat";
  [@bs.send] external sync: t => Js.Promise.t(unit) = "sync";
  [@bs.send]
  external truncate: (t, ~length: int=?, unit) => Js.Promise.t(unit) =
    "truncate";

  type writeInfo = {bytesWritten: int};

  [@bs.send]
  external writeBuffer: (t, Buffer.t) => Js.Promise.t(writeInfo) = "write";
  [@bs.send]
  external writeBufferOffset:
    (t, Buffer.t, ~offset: int) => Js.Promise.t(writeInfo) =
    "write";
  [@bs.send]
  external writeBufferRange:
    (t, Buffer.t, ~offset: int, ~length: int, ~position: int) =>
    Js.Promise.t(writeInfo) =
    "write";

  [@bs.send]
  external writeString: (t, string) => Js.Promise.t(writeInfo) = "write";
  [@bs.send]
  external writeStringOffset:
    (t, string, ~offset: int) => Js.Promise.t(writeInfo) =
    "write";
  [@bs.send]
  external writeStringRange:
    (t, string, ~offset: int, ~length: int, ~position: int) =>
    Js.Promise.t(writeInfo) =
    "write";
  [@bs.send]
  external writeStringPosition:
    (t, string, ~position: int) => Js.Promise.t(writeInfo) =
    "write";
  [@bs.send]
  external writeStringPositionWithEncoding:
    (
      t,
      string,
      ~position: int,
      ~encoding: [@bs.string] [
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
    Js.Promise.t(writeInfo) =
    "write";

  type writeFileStringOptions;
  [@bs.obj]
  external writeFileStringOptions:
    (
      ~encoding: [@bs.string] [
                   | `hex
                   | `utf8
                   | `ascii
                   | `latin1
                   | `base64
                   | `ucs2
                   | `base64
                   | `binary
                   | `utf16le
                 ],
      ~mode: int=?,
      ~flag: [@bs.string] [
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
             ]
               =?,
      unit
    ) =>
    writeFileStringOptions =
    "";

  [@bs.send]
  external writeFileString: (t, string) => Js.Promise.t(unit) = "writeFile";

  [@bs.send]
  external writeFileStringWith:
    (t, string, writeFileStringOptions) => Js.Promise.t(unit) =
    "writeFile";

  type writeFileBufferOptions;
  [@bs.obj]
  external writeFileBufferOptions:
    (
      ~encoding: [@bs.string] [
                   | `hex
                   | `utf8
                   | `ascii
                   | `latin1
                   | `base64
                   | `ucs2
                   | `base64
                   | `binary
                   | `utf16le
                 ],
      ~mode: int=?,
      ~flag: [@bs.string] [
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
             ]
               =?,
      unit
    ) =>
    writeFileBufferOptions =
    "";

  [@bs.send]
  external writeFileBuffer: (t, Buffer.t) => Js.Promise.t(unit) = "writeFile";

  [@bs.send]
  external writeFileBufferWith:
    (t, Buffer.t, writeFileBufferOptions) => Js.Promise.t(unit) =
    "writeFile";

  [@bs.send]
  external writeFileUint8Array:
    (t, Js.TypedArray2.Uint8Array.t) => Js.Promise.t(unit) =
    "writeFile";

  [@bs.send]
  external writeFileUint8ArrayWith:
    (t, Js.TypedArray2.Uint8Array.t, writeFileUint8ArrayOptions) =>
    Js.Promise.t(unit) =
    "writeFile";
};

[@bs.module "fs"] [@bs.scope "promises"]
external access: string => Js.Promise.t(unit) = "access";
[@bs.module "fs"] [@bs.scope "promises"]
external accessWithMode: (string, ~mode: int) => Js.Promise.t(unit) =
  "access";

[@bs.module "fs"] [@bs.scope "promises"]
external appendFile: (string, string, appendFileOptions) => Js.Promise.t(unit) =
  "appendFile";

[@bs.module "fs"] [@bs.scope "promises"]
external appendFileWith:
  (string, string, appendFileOptions) => Js.Promise.t(unit) =
  "appendFile";

type appendFileBufferOptions;
[@bs.obj]
external appendFileBufferOptions:
  (
    ~encoding: [@bs.string] [
                 | `hex
                 | `utf8
                 | `ascii
                 | `latin1
                 | `base64
                 | `ucs2
                 | `base64
                 | `binary
                 | `utf16le
               ],
    ~mode: int=?,
    ~flag: [@bs.string] [
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
           ]
             =?,
    unit
  ) =>
  appendFileBufferOptions =
  "";

[@bs.module "fs"] [@bs.scope "promises"]
external appendFileBuffer: (string, Buffer.t) => Js.Promise.t(unit) =
  "appendFile";

[@bs.module "fs"] [@bs.scope "promises"]
external appendFileBufferWith:
  (string, Buffer.t, appendFileBufferOptions) => Js.Promise.t(unit) =
  "appendFile";

[@bs.module "fs"] [@bs.scope "promises"]
external chmod: (string, ~mode: int) => Js.Promise.t(unit) = "chmod";

[@bs.module "fs"] [@bs.scope "promises"]
external chown: (string, ~uid: int, ~gid: int) => Js.Promise.t(unit) =
  "chown";

[@bs.module "fs"] [@bs.scope "promises"]
external copyFile: (string, ~dest: string) => Js.Promise.t(unit) = "copyFile";

[@bs.module "fs"] [@bs.scope "promises"]
external copyFileFlag:
  (string, ~dest: string, ~flag: string) => Js.Promise.t(unit) =
  "copyFile";

[@bs.module "fs"] [@bs.scope "promises"]
external lchmod: (string, ~mode: int) => Js.Promise.t(unit) = "lchmod";

[@bs.module "fs"] [@bs.scope "promises"]
external link: (~existingPath: string, ~newPath: string) => Js.Promise.t(unit) =
  "link";

[@bs.module "fs"] [@bs.scope "promises"]
external lstat: string => Js.Promise.t(Stat.t) = "lstat";

[@bs.module "fs"] [@bs.scope "promises"]
external lstatBigInt: (string, bool) => Js.Promise.t(Stat.t) = "lstat";

type mkdirOptions;
[@bs.obj]
external mkdirOptions: (~recursive: bool=?, ~mode: int=?, unit) => mkdirOptions =
  "";

[@bs.module "fs"] [@bs.scope "promises"]
external mkdir: (string, mkdirOptions) => Js.Promise.t(unit) = "mkdir";

[@bs.module "fs"] [@bs.scope "promises"]
external mkdirWith: (string, mkdirOptions) => Js.Promise.t(unit) = "mkdir";

type mdktempOptions;
[@bs.obj]
external mdktempOptions:
  (
    ~encoding: [@bs.string] [
                 | `hex
                 | `utf8
                 | `ascii
                 | `latin1
                 | `base64
                 | `ucs2
                 | `base64
                 | `binary
                 | `utf16le
               ],
    unit
  ) =>
  mdktempOptions =
  "";

[@bs.module "fs"] [@bs.scope "promises"]
external mkdtemp: (string, mdktempOptions) => Js.Promise.t(unit) = "mkddtemp";

[@bs.module "fs"] [@bs.scope "promises"]
external mkdtempWith: (string, mdktempOptions) => Js.Promise.t(unit) =
  "mkddtemp";

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
    ]
  ) =>
  Js.Promise.t(Handle.t) =
  "open";

[@bs.module "fs"] [@bs.scope "promises"]
external openWithMode:
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
    ~mode: int
  ) =>
  Js.Promise.t(Handle.t) =
  "open";

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

type createReadStreamOptions;
[@bs.obj]
external createReadStreamOptions:
  (
    ~flags: string=?,
    ~encoding: string=?,
    ~fd: fd=?,
    ~mode: int=?,
    ~autoClose: bool=?,
    ~emitClose: bool=?,
    ~start: int=?,
    ~_end: int=?,
    ~highWaterMark: int=?,
    unit
  ) =>
  createReadStreamOptions =
  "";

[@bs.module "fs"]
external createReadStream: path => ReadStream.t = "createReadStream";
[@bs.module "fs"]
external createReadStreamWith: (path, createReadStreamOptions) => ReadStream.t =
  "createReadStream";