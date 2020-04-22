/**
 * TODO:
 *
 * Not sure if the functor approach is the best way to use this module. But it
 * does allow us to "lock in" the data types we want to use across contexts.
 *
 * There may be some other issues with this implementaiton due to a naive
 * understanding of how data is passed/shared, as well as how local thread contexts
 * work.
 *
 * We should revisit this with concrete tests to determine the best design.
 */
module MessagePort = {
  type t('a);
  [@bs.send] external onClose: (t('a), [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => t('a) = "on";
  [@bs.send] external onMessage: (t('a), [@bs.as "message"] _, [@bs.uncurry] ('a) => unit) => t('a) = "on";
  [@bs.send] external close: t('a) => unit = "close";
  [@bs.send] external postMessage: (t('a), 'a) => unit = "postMessage";
  [@bs.send] external ref: t('a) => unit = "ref";
  [@bs.send] external start: t('a) => unit = "start";
  [@bs.send] external unref: t('a) => unit = "unref";

  module WithMessageType = (T: {type message;}) => {
    type nonrec t = t(T.message);
    [@bs.send] external onClose: (t, [@bs.as "close"] _, [@bs.uncurry] (unit) => unit) => t = "on";
    [@bs.send] external onMessage: (t, [@bs.as "message"] _, [@bs.uncurry] (T.message) => unit) => t = "on";
    [@bs.send] external close: t => unit = "close";
    [@bs.send] external postMessage: (t, T.message) => unit = "postMessage";
    [@bs.send] external ref: t => unit = "ref";
    [@bs.send] external start: t => unit = "start";
    [@bs.send] external unref: t => unit = "unref";
  };
};

module MessageChannel = {
  type t('message1, 'message2);
  [@bs.module "worker_threads"] [@bs.new]
  external make: unit => t('message1, 'message2) = "MessageChannel";
  [@bs.get] external port1: t('message1, 'message2) => MessagePort.t('message1) = "port1";
  [@bs.get] external port2: t('message1, 'message2) => MessagePort.t('message2) = "port2";

  module WithMessageTypes = (T: {
                               type message1;
                               type message2;
                             }) => {
    type nonrec t = t(T.message1, T.message2);
    [@bs.module "worker_threads"] [@bs.new] external make: unit => t = "MessageChannel";
    [@bs.get] external port1: t => MessagePort.t(T.message1) = "port1";
    [@bs.get] external port2: t => MessagePort.t(T.message2) = "port2";
  };
};

type workerResourceLimits = {
  [@bs.as "maxYoungGenerationSizeMb"]
  maxYoungGenerationSizeMb: int,
  [@bs.as "maxOldGenerationSizeMb"]
  maxOldGenerationSizeMb: int,
  [@bs.as "codeRangeSizeMb"]
  codeRangeSizeMb: int,
};

module Worker = {
  type t('a);

  type makeOptions('a);
  [@bs.obj]
  external makeOptions:
    (
      ~argv: array(string)=?,
      ~env: Js.t({..})=?,
      ~eval: bool=?,
      ~execArgv: array(string)=?,
      ~stdin: bool=?,
      ~stdout: bool=?,
      ~stderr: bool=?,
      ~workerData: 'a=?,
      ~resourceLimits: workerResourceLimits=?,
      unit
    ) =>
    makeOptions('a);

  [@bs.module "worker_threads"] [@bs.new]
  external make: (~file: string, ~options: makeOptions('a)=?, unit) => t('a) = "Worker";
  [@bs.send] external onError: (t('a), [@bs.as "error"] _, [@bs.uncurry] (Js.Exn.t) => unit) => t('a) = "on";
  [@bs.send] external onMessage: (t('a), [@bs.as "message"] _, [@bs.uncurry] ('a) => unit) => t('a) = "on";
  [@bs.send] external onExit: (t('a), [@bs.as "exit"] _, [@bs.uncurry] (int) => unit) => t('a) = "on";
  [@bs.send] external onOnline: (t('a), [@bs.as "online"] _, [@bs.uncurry] (unit) => unit) => t('a) = "on";
  [@bs.send] external postMessage: (t('a), 'a) => unit = "postMessage";
  [@bs.send] external ref: t('a) => unit = "ref";
  [@bs.send] external resourceLimits: t('a) => workerResourceLimits = "workerResourceLimits";
  [@bs.get] external stderr: t('a) => Stream.subtype('a, Stream.readable) = "stderr";
  [@bs.get] external stdin: t('a) => Stream.subtype('a, Stream.writable) = "stdin";
  [@bs.get] external stdout: t('a) => Stream.subtype('a, Stream.readable) = "stdout";
  [@bs.send] external terminate: t('a) => Js.Promise.t(int) = "terminate";
  [@bs.get] external threadId: t('a) => int = "threadId";
  [@bs.send] external unref: t('a) => unit = "unref";

  module WithMessageType = (T: {type message;}) => {
    type nonrec t = t(T.message);

    type nonrec makeOptions = makeOptions(T.message);
    [@bs.obj]
    external makeOptions:
      (
        ~argv: array(string)=?,
        ~env: Js.t({..})=?,
        ~eval: bool=?,
        ~execArgv: array(string)=?,
        ~stdin: bool=?,
        ~stdout: bool=?,
        ~stderr: bool=?,
        ~workerData: T.message=?,
        ~resourceLimits: workerResourceLimits=?,
        unit
      ) =>
      makeOptions;

    [@bs.module "worker_threads"] [@bs.new]
    external make: (~file: string, ~options: makeOptions=?, unit) => t = "Worker";
    [@bs.send] external onError: (t, [@bs.as "error"] _, [@bs.uncurry] (Js.Exn.t) => unit) => t = "on";
    [@bs.send] external onMessage: (t, [@bs.as "message"] _, [@bs.uncurry] (T.message) => unit) => t = "on";
    [@bs.send] external onExit: (t, [@bs.as "exit"] _, [@bs.uncurry] (int) => unit) => t = "on";
    [@bs.send] external onOnline: (t, [@bs.as "online"] _, [@bs.uncurry] (unit) => unit) => t = "on";
    [@bs.send] external postMessage: (t, T.message) => unit = "postMessage";
    [@bs.send] external ref: t => unit = "ref";
    [@bs.send] external resourceLimits: t => workerResourceLimits = "workerResourceLimits";
    [@bs.get] external stderr: t => Stream.subtype('a, Stream.readable) = "stderr";
    [@bs.get] external stdin: t => Stream.subtype('a, Stream.writable) = "stdin";
    [@bs.get] external stdout: t => Stream.subtype('a, Stream.readable) = "stdout";
    [@bs.send] external terminate: t => Js.Promise.t(int) = "terminate";
    [@bs.get] external threadId: t => int = "threadId";
    [@bs.send] external unref: t => unit = "unref";
  };
};

[@bs.val] [@bs.module "worker_threads"] external isMainThread: bool = "isMainThread";
[@bs.val] [@bs.module "worker_threads"]
external moveMessagePortToContext:
  (MessagePort.t('a), VM.contextifiedObject('b)) => MessagePort.t('a) =
  "moveMessagePortToContext";
[@bs.val] [@bs.module "worker_threads"] [@bs.return nullable]
external parentPort: option(MessagePort.t('a)) = "parentPort";
[@bs.val] [@bs.module "worker_threads"] [@bs.return nullable]
external receiveMessageOnPort: MessagePort.t('a) => option(Js.t({..})) = "receiveMessageOnPort";
[@bs.val] [@bs.module "worker_threads"]
external resourceLimits: workerResourceLimits = "resourceLimits";
[@bs.val] [@bs.module "worker_threads"] external _SHARE_ENV: Js.Types.symbol = "SHARE_ENV";
[@bs.val] [@bs.module "worker_threads"] external threadId: int = "threadId";
[@bs.val] [@bs.module "worker_threads"] external workerData: 'a = "workerData";

module WithMessageType = (T: {type message;}) => {
  module Worker =
    Worker.WithMessageType({
      type nonrec message = T.message;
    });
  [@bs.val] [@bs.module "worker_threads"] external isMainThread: bool = "isMainThread";
  [@bs.val] [@bs.module "worker_threads"]
  external moveMessagePortToContext:
    (MessagePort.t(T.message), VM.contextifiedObject('b)) => MessagePort.t(T.message) =
    "moveMessagePortToContext";
  [@bs.val] [@bs.module "worker_threads"] [@bs.return nullable]
  external parentPort: option(MessagePort.t(T.message)) = "parentPort";
  [@bs.val] [@bs.module "worker_threads"] [@bs.return nullable]
  external receiveMessageOnPort: MessagePort.t(T.message) => option(Js.t({..})) =
    "receiveMessageOnPort";
  [@bs.val] [@bs.module "worker_threads"]
  external resourceLimits: workerResourceLimits = "resourceLimits";
  [@bs.val] [@bs.module "worker_threads"] external _SHARE_ENV: Js.Types.symbol = "SHARE_ENV";
  [@bs.val] [@bs.module "worker_threads"] external threadId: int = "threadId";
  [@bs.val] [@bs.module "worker_threads"] external workerData: T.message = "workerData";
};
