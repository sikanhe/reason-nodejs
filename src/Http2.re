
/**
 * TODO: Some of the functions in this module use optional
 * named arguments for JS args that are optional. Evaluate
 * whether this is safe/future-proof. If not, refactor.
 */

type settingsObject;
[@bs.obj] external settingsObject: (
  ~headerTableSize: int=?,
  ~enablePush: bool=?,
  ~initialWindowSize: int=?,
  ~maxFrameSize: int=?,
  ~maxConcurrentStreams: int=?,
  ~maxHeaderListSize: int=?,
  ~enableConnectProtocol: bool=?
) => settingsObject = "";

module Http2Stream = {
  type t = Stream.t([ Stream.duplex | `Http2 ]);
};

module Http2Session = {
  type t;
  [@bs.send] external onClose: (t, [@bs.as "close"] _, unit => unit) => unit = "on";
  [@bs.send] external onConnect: (t, [@bs.as "connect"] _, (t, Net.Socket.t) => unit) => unit = "on";
  [@bs.send] external onError: (t, [@bs.as "error"] _, Js.Exn.t => unit) => unit = "on";
  [@bs.send] external onFrameError: (t, [@bs.as "frameError"] _, (~type_:int, ~errorCode:int, ~streamId:int) => unit) => unit = "on";
  [@bs.send] external onGoAway: (t, [@bs.as "goAway"] _, (~errorCode:int, ~lastStreamId:int, Buffer.t) => unit) => unit = "on";
  [@bs.send] external onLocalSettings: (t, [@bs.as "localSettings"] _, settingsObject => unit) => unit = "on";
  [@bs.send] external onPing: (t, [@bs.as "ping"] _, Buffer.t => unit) => unit = "on";
  [@bs.send] external onRemoteSettings: (t, [@bs.as "remoteSettings"] _, settingsObject => unit) => unit = "on";
  [@bs.send] external onStream: (
      t,
      [@bs.as "stream"] _,
      (
        Http2Stream.t,
        Js.t({.. "status": string, "content-type": string}),
        int,
        array(Js.t({..}))
      ) => unit
    ) => unit = "on";
  [@bs.send] external onTimeout: (t, [@bs.as "timeout"] _, unit => unit) => unit = "on";
  [@bs.get] [@bs.return nullable] external alpnProtocol: t => option(string) = "alpnProtocol";
  [@bs.send] external close: t => unit = "close";
  [@bs.get] external closed: t => bool = "closed";
  [@bs.send] external destroy: t => unit = "destroy";
  [@bs.send] external destroyWithError: (t, Js.Exn.t) => unit = "destroy";
  [@bs.send] external destroyWithCode: (t, int) => unit = "destroy";
  [@bs.get] external destroyed: t => bool = "destroyed";
  [@bs.get] [@bs.return nullable] external encrypted: t => option(bool) = "encrypted";
  [@bs.send] external goaway: t => unit = "goaway";
  [@bs.send] external goawayWith: (t, ~code:int=?, ~lastStreamId: int=?, ~data: Buffer.t=?, unit) => unit = "goaway";
  [@bs.get] external localSettings: t => {.
    "headerTableSize": int,
    "enablePush": bool,
    "initialWindowSize": int,
    "maxFrameSize": int,
    "maxConcurrentStreams": int,
    "maxHeaderListSize": int,
    "enableConnectProtocol": bool,
  } = "on";
  [@bs.get] [@bs.return nullable] external originSet: t => option(array(string)) = "originSet";
  [@bs.get] external pendingSettingsAck: t => bool = "pendingSettingsAck";
  [@bs.send] external ping: (t, (Js.Nullable.t(Js.Exn.t), int, Buffer.t) => unit) => bool = "ping";
  [@bs.send] external pingWith: (t, ~payload: BinaryLike.t, (Js.Nullable.t(Js.Exn.t), int, Buffer.t) => unit) => bool = "ping";
  [@bs.send] external ref: t => unit = "ref";
  [@bs.get] external remoteSettings: t => {. 
      "headerTableSize": int,
      "enablePush": bool,
      "initialWindowSize": int,
      "maxFrameSize": int,
      "maxConcurrentStreams": int,
      "maxHeaderListSize": int,
      "enableConnectProtocol": bool,
    } = "remoteSettings";
  [@bs.send] external setTimeout: (t, int, unit => unit) => unit = "setTimeout";
  [@bs.get] external socket: t => Stream.t([ Stream.duplex | `Socket | `TLSSocket ]) = "socket";
  [@bs.get] external state: t => {
      .
      "effectiveLocalWindowSize": int,
      "effectiveRecvDataLength": int,
      "nextStreamID": int,
      "localWindowSize": int,
      "lastProcStreamID": int,
      "remoteWindowSize": int,
      "deflateDynamicTableSize": int,
      "inflateDynamicTableSize": int,
    } = "state";
  [@bs.send] external settings: (
    t,
    settingsObject,
    ~callback: (Js.Null.t(Js.Exn.t), settingsObject, int) => unit=?
  ) => unit = "settings";
  [@bs.get] external type_: t => int = "type";

};

module ServerHttp2Session = {
  include Http2Session;

  module Origin = {
    type t('a);
    type urlString = [ | `UrlString ];
    type url = [ | `Url ];
    type object_ = [ | `Object ];
    type streamId = [ | `StreamId ];
    external urlString: string => t(urlString) = "%identity";
    external url: Url.t => t(url) = "%identity";
    external object_: {. "origin": string } => t(object_) = "%identity";
    external streamId: int => t(streamId) = "%identity";
  };

  [@bs.send] external altsvc: (
    t,
    string,
    Origin.t([ Origin.urlString | Origin.url | Origin.object_ | Origin.streamId ])
  ) => unit = "altsvc";

  [@bs.send] [@bs.variadic]
  external origin: (array(Origin.t([ Origin.urlString | Origin.url | Origin.object_ ]))) => unit = "origin";

};



