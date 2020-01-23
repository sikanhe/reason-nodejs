let c1 = Console.make2(
  Console.consoleOptions(
    ~stderr=Stream.make(),
    ~ignoreErrors=false,
    ~colorMode=true,
    ~inspectOptions=Util.makeInspectOptions(),
    ~stdout=Stream.make(),
  )
);

let c2 = Console.make({
  "stderr": Some(Stream.make()),
  "ignoreErrors": Some(false),
  "colorMode": Some(true),
  "inspectOptions": Some(Util.makeInspectOptions()),
  "stdout": Stream.make(),
})
