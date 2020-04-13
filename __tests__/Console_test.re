open Jest;
let process = Process.process;

describe("Console", () => {

  let c1 = Console.make(
    Console.consoleOptions(
    ~stderr=Process.stderr(process),
    ~ignoreErrors=false,
    ~colorMode=true,
    ~inspectOptions=Util.inspectOptions(),
    ~stdout=Process.stdout(process),
  ));

  let c2 = Console.make2({
    "stderr": Some(Process.stderr),
    "ignoreErrors": Some(false),
    "colorMode": Some(true),
    "inspectOptions": Some(Util.inspectOptions()),
    "stdout": Process.stdout(process),
  });

  c1->Console.logMany([|"a", "b"|])
  c2->Console.table([|"hi", "bye"|])
  c2->Console.table([|Js.Dict.fromArray([|("a", 1), ("b", 2)|])|])

  test("New console instance should be defined", () => {
    open ExpectJs;
    expect(Js.Undefined.return(c1)) |> toBeDefined;
  });

  test("New console instance should be defined", () => {
    open ExpectJs;
    expect(Js.Undefined.return(c2)) |> toBeDefined;
  });

});




