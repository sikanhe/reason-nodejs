let c1 = Console.make({
  "stderr": Some(Process.stderr),
  "ignoreErrors": Some(false),
  "colorMode": Some(true),
  "inspectOptions": Some(Util.makeInspectOptions()),
  "stdout": Process.stdout,
})

let c2 = Console.make2({
  "stderr": Some(Process.stderr),
  "ignoreErrors": Some(false),
  "colorMode": Some(true),
  "inspectOptions": Some(Util.makeInspectOptions()),
  "stdout": Process.stdout,
});

let c3 = Console.make3(
  Console.consoleOptions(
    ~stderr=Process.stderr,
    ~ignoreErrors=false,
    ~colorMode=true,
    ~inspectOptions=Util.makeInspectOptions(),
    ~stdout=Process.stdout,
  )
);

c1->Console.logMany([|"a", "b"|])
c2->Console.table([|"hi", "bye"|])
c2->Console.table([|Js.Dict.fromArray([|("a", 1), ("b", 2)|])|])
