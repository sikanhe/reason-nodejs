open Jest;

describe("Console", () => {

  let c1 = Console.make({
    "stderr": Some(Process.stderr),
    "ignoreErrors": Some(false),
    "colorMode": Some(true),
    "inspectOptions": Some(Util.makeInspectOptions()),
    "stdout": Process.stdout,
  });

  test("New console instance should be created", () => {
    open ExpectJs;
    expect(Js.Undefined.return(c1)) |> toBeDefined;
  });

  c1->Console.logMany([|"a", "b"|])

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

c2->Console.table([|"hi", "bye"|])
c2->Console.table([|Js.Dict.fromArray([|("a", 1), ("b", 2)|])|])
