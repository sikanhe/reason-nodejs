let c1 = Console.make(
  ~stderr=Stream.make(),
  ~ignoreErrors=false,
  ~colorMode=true,
  ~inspectOptions=Util.makeInspectOptions(),
  ~stdout=Stream.make(),
)