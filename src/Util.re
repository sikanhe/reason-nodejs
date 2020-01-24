type inspectOptions;
[@bs.obj]
external makeInspectOptions:
  (
    ~showHidden: bool=?,
    ~depth: int=?,
    ~colors: bool=?,
    ~customInspect: bool=?,
    ~showProxy: bool=?,
    ~maxArrayLength: int=?,
    ~breakLength: int=?,
    ~compact: bool=?,
    ~sorted: bool=?,
    ~getters: bool=?,
    unit
  ) =>
  inspectOptions =
  "";