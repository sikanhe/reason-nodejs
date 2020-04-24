open Jest;
let process = Process.process;

describe("Console", () => {
  let c1 =
    Console.(
      make(
        consoleOptions(
          ~stderr=Process.stderr(process),
          ~ignoreErrors=false,
          ~colorMode=true,
          ~inspectOptions=Util.inspectOptions(),
          ~stdout=Process.stdout(process),
          (),
        ),
      )
    );

  let c2 =
    Console.make2({
      "stderr": Process.stderr(process),
      "ignoreErrors": false,
      "colorMode": true,
      "inspectOptions": Util.inspectOptions(),
      "stdout": Process.stdout(process),
    });

  c1->Console.logMany([|"a", "b"|]);
  c2->Console.table([|"hi", "bye"|]);
  c2->Console.table([|Js.Dict.fromArray([|("a", 1), ("b", 2)|])|]);

  test("New console instance should be defined", () => {
    ExpectJs.(expect(Js.Undefined.return(c1)) |> toBeDefined)
  });

  test("New console instance should be defined", () => {
    ExpectJs.(expect(Js.Undefined.return(c2)) |> toBeDefined)
  });
});
