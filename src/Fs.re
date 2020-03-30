module Dirent = {
  type t;
  [@bs.send] external isBlockDevice: t => bool = "isBlockDevice";
  [@bs.send] external isCharacterDevice: t => bool = "isCharacterDevice";
  [@bs.send] external isDirectory: t => bool = "isDirectory";
  [@bs.send] external isFIFO: t => bool = "isFIFO";
  [@bs.send] external isFile: t => bool = "isFile";
  [@bs.send] external isSocket: t => bool = "isSocket";
  [@bs.send] external isSymbolicLink: t => bool = "isSymbolicLink";
  [@bs.get] external name: t => string = "name";
};

module Dir = {
  type t;
  [@bs.send] external close: t => Js.Promise.t(unit) = "close";
  [@bs.send] external closeWithCallback: (t, Js.nullable(Js.Exn.t) => unit) => unit = "close";
  [@bs.send] external closeSync: t => unit = "closeSync";
  [@bs.get] external path: t => string = "path";
  [@bs.send] external read: t => Js.Promise.t(Js.nullable(Dirent.t)) = "read";
  [@bs.send] external readWithCallback: (t, (Js.Exn.t, Js.nullable(Dirent.t)) => unit) => unit = "read";
  [@bs.send] external readSync: t => Js.nullable(Dirent.t) = "readSync";
};

module Stats = {
  type t = {
    [@bs.as "dev"] dev: int,
    [@bs.as "ino"] ino: int,
    [@bs.as "mode"] mode: int,
    [@bs.as "nlink"] nlink: int,
    [@bs.as "uid"] uid: int,
    [@bs.as "gid"] gid: int,
    [@bs.as "rdev"] rdev: int,
    [@bs.as "size"] size: int,
    [@bs.as "blksize"] blksize: int,
    [@bs.as "blocks"] blocks: int,
    [@bs.as "atimeMs"] atimeMs: float,
    [@bs.as "mtimeMs"] mtimeMs: float,
    [@bs.as "ctimeMs"] ctimeMs: float,
    [@bs.as "birthtimeMs"] birthtimeMs: float,
    [@bs.as "atime"] atime: string,
    [@bs.as "mtime"] mtime: string,
    [@bs.as "ctime"] ctime: string,
    [@bs.as "birthtime"] birthtime: string,
  };

  /** `isFile(stats)` Returns true if the `stats` object describes a file. */
  [@bs.send] external isFile: t => bool = "isFile";
  /** `isDirectory(stats)` Returns true if the `stats` object describes a directory. */
  [@bs.send] external isDirectory: t => bool = "isDirectory";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a block device. */
  [@bs.send] external isBlockDevice: t => bool = "isBlockDevice";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a character device. */
  [@bs.send] external isCharacterDevice: t => bool = "isCharacterDevice";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a symbolic link. */
  [@bs.send] external isSymbolicLink: t => bool = "isSymbolicLink";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a first-in-first-out (FIFO) pipe. */
  [@bs.send] external isFIFO: t => bool = "isFIFO";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a socket. */
  [@bs.send] external isSocket: t => bool = "isSocket";
};

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

type fd = pri int;
type path = string;

type writeFileOptions;
[@bs.obj] external writeFileOptions: (~mode: int=?, ~flag: string=?, unit) => writeFileOptions = "";

type appendFileOptions;
[@bs.obj] external appendFileOptions: (
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
[@bs.obj] external readFileOptions:
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

/**
 * `readdirSync(path)`
 * Reads the contents of a directory, returning an array of strings representing
 * the paths of files and sub-directories. **Execution is synchronous and blocking**.
 */
[@bs.module "fs"] external readdirSync: string => array(string) = "readdirSync";

/**
 * `renameSync(~oldPath, ~newPath)
 * Renames/moves the file located at `~oldPath` to `~newPath`. **Execution is
 * synchronous and blocking**.
 */
[@bs.module "fs"] external renameSync: (~oldPath: string, ~newPath: string) => unit = "renameSync";
[@bs.module "fs"] external ftruncateSync: (fd, int) => unit = "ftruncateSync";
[@bs.module "fs"] external truncateSync: (string, int) => unit = "truncateSync";
[@bs.module "fs"] external chownSync: (string, ~uid: int, ~gid: int) => unit = "chownSync";
[@bs.module "fs"] external fchownSync: (fd, ~uid: int, ~gid: int) => unit = "fchownSync";
[@bs.module "fs"] external readlinkSync: string => string = "readlinkSync";
[@bs.module "fs"] external unlinkSync: string => unit = "unlinkSync";

/**
 * `rmdirSync(dirPath)
 * **Note: (recursive removal is experimental).**
 * Removes the directory at `dirPath`. **Execution is synchronous and blocking**.
 */
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
  fd =
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

[@bs.val] [@bs.module "fs"] external readFileSync: (string) => Buffer.t = "readFileSync";
[@bs.val] [@bs.module "fs"] external readFileSyncWith: (string, readFileOptions) => Buffer.t = "readFileSync";
[@bs.val] [@bs.module "fs"] external existsSync: (string) => bool = "existsSync";

type writeFileSyncOptions;
[@bs.obj] external writeFileSyncOptions:
  (
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

[@bs.val] [@bs.module "fs"] external writeFileSync: (string, Buffer.t) => unit = "writeFileSync";
[@bs.val] [@bs.module "fs"] external writeFileSyncWith: (string, Buffer.t, writeFileSyncOptions) => unit = "writeFileSync";

module Handle = {
  type t;

  [@bs.send] external appendFile: (t, Buffer.t, appendFileOptions) => Js.Promise.t(unit) = "appendFile";
  [@bs.send] external appendFileWith: (t, Buffer.t) => Js.Promise.t(unit) = "appendFile"; 
  [@bs.send] external chmod: (t, int) => Js.Promise.t(unit) = "chmod";
  [@bs.send] external chown: (t, int, int) => Js.Promise.t(unit) = "chown";
  [@bs.send] external close: t => Js.Promise.t(unit) = "close";
  [@bs.send] external datasync: t => Js.Promise.t(unit) = "datasync";
  [@bs.send] external fd: t => fd = "fd";

  type readInfo = {
    bytesRead: int,
    buffer: Buffer.t,
  };

  [@bs.send] external read: (t, Buffer.t, ~offset: int, ~length: int, ~position: int) => Js.Promise.t(readInfo) = "read";
  [@bs.send] external readFile: t => Js.Promise.t(Buffer.t) = "read";
  [@bs.send] external readFileWith: (t, readFileOptions) => Js.Promise.t(Buffer.t) = "read";

  [@bs.send] external stat: t => Js.Promise.t(Stats.t) = "stat";
  [@bs.send] external sync: t => Js.Promise.t(unit) = "sync";
  [@bs.send] external truncate: (t, ~length: int=?, unit) => Js.Promise.t(unit) = "truncate";

  type writeInfo = {bytesWritten: int};

  [@bs.send] external write: (t, Buffer.t) => Js.Promise.t(writeInfo) = "write";
  [@bs.send] external writeOffset: (t, Buffer.t, ~offset: int) => Js.Promise.t(writeInfo) = "write";
  [@bs.send] external writeRange: (t, Buffer.t, ~offset: int, ~length: int, ~position: int) => Js.Promise.t(writeInfo) = "write";


  type writeFileOptions;
  [@bs.obj] external writeFileOptions:
    (
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
    writeFileOptions =
    "";

  [@bs.send] external writeFile: (t, Buffer.t) => Js.Promise.t(unit) = "writeFile";
  [@bs.send] external writeFileWith: (t, Buffer.t, writeFileOptions) => Js.Promise.t(unit) = "writeFile";

};

[@bs.module "fs"] [@bs.scope "promises"] external access: string => Js.Promise.t(unit) = "access";
[@bs.module "fs"] [@bs.scope "promises"] external accessWithMode: (string, ~mode: int) => Js.Promise.t(unit) = "access";

[@bs.module "fs"] [@bs.scope "promises"] external appendFile:
  (string, string, appendFileOptions) => Js.Promise.t(unit) = "appendFile";

[@bs.module "fs"] [@bs.scope "promises"] external appendFileWith:
  (string, string, appendFileOptions) => Js.Promise.t(unit) =
  "appendFile";

type appendFileBufferOptions;
[@bs.obj] external appendFileBufferOptions:
  (
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
external lstat: string => Js.Promise.t(Stats.t) = "lstat";

[@bs.module "fs"] [@bs.scope "promises"]
external lstatBigInt: (string, bool) => Js.Promise.t(Stats.t) = "lstat";

type mkdirOptions;
[@bs.obj]
external mkdirOptions: (~recursive: bool=?, ~mode: int=?, unit) => mkdirOptions = "";

[@bs.module "fs"] [@bs.scope "promises"]
external mkdir: (string, mkdirOptions) => Js.Promise.t(unit) = "mkdir";

[@bs.module "fs"] [@bs.scope "promises"]
external mkdirWith: (string, mkdirOptions) => Js.Promise.t(unit) = "mkdir";

type mdktempOptions;
[@bs.obj]
external mdktempOptions: (unit) => mdktempOptions = "";

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
  type kind = [ Stream.writable | `FileSystem ];
  type subtype('data, 'a) = Stream.Writable.subtype('data, [> kind] as 'a);
  type supertype('data, 'a) = Stream.Writable.subtype('data, [< kind] as 'a);
  type t = subtype(Buffer.t, [ kind ]);
  module Impl = {
    include Stream.Writable.Impl;
    [@bs.send] external bytesWritten: subtype('data, [> kind ]) => int = "bytesWritten";
    [@bs.send] external path: subtype('data, [> kind ]) => string = "path";
    [@bs.send] external pending: subtype('data, [> kind ]) => bool = "pending";
    [@bs.send] external onOpen: (subtype('data, [> kind ]), [@bs.as "open"] _, fd => unit) => unit = "on";
    [@bs.send] external onReady: (subtype('data, [> kind ]), [@bs.as "ready"] _, unit => unit) => unit = "on";
  };
  include Impl;
};

module ReadStream = {
  type kind = [ Stream.readable | `FileSystem ];
  type subtype('data, 'a) = Stream.Readable.subtype('data, [> kind] as 'a);
  type supertype('data, 'a) = Stream.Readable.subtype('data, [< kind] as 'a);
  type t = subtype(Buffer.t, [ kind ]);
  module Impl = {
    include Stream.Readable.Impl;
    [@bs.send] external bytesRead: subtype('data, [> kind ]) => int = "bytesWritten";
    [@bs.send] external path: subtype('data, [> kind ]) => string = "path";
    [@bs.send] external pending: subtype('data, [> kind ]) => bool = "pending";
    [@bs.send] external onOpen: (subtype('data, [> kind ]), [@bs.as "open"] _, fd => unit) => unit = "on";
    [@bs.send] external onReady: (subtype('data, [> kind ]), [@bs.as "ready"] _, unit => unit) => unit = "on";
  };
  include Impl;
};

type createReadStreamOptions;
[@bs.obj]
external createReadStreamOptions:
  (
    ~flags: string=?,
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

type createWriteStreamOptions;
[@bs.obj]
external createWriteStreamOptions:
  (
    ~flags: string=?,
    ~fd: fd=?,
    ~mode: int=?,
    ~autoClose: bool=?,
    ~emitClose: bool=?,
    ~start: int=?,
    ~fs: Js.t({..})=?,
    unit
  ) =>
  createReadStreamOptions =
  "";
[@bs.module "fs"]
external createWriteStream: path => WriteStream.t = "createWriteStream";

[@bs.module "fs"]
external createWriteStreamWith: (path, createWriteStreamOptions) => WriteStream.t = "createWriteStream";