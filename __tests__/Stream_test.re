open Jest;

let makePlainReadable = () => {
  open Stream.Readable;
  let options = makeOptions(
    ~destroy=[@bs.this] (_, _, done_) => {
      done_(~err=None)
    },
    ~read=[@bs.this] (_, _) => (),
    ()
  );
  make(options);
};

describe("Stream", () => {

  testAsync("Stream.Readable.make should return a defined value", (resolve) => {
    open! ExpectJs;
    let readable = makePlainReadable();
    expect(readable->Js.Undefined.return) |> toBeDefined |> resolve;
  });

  testAsync("Stream.Readable.make should return an instance of 'Readable'", (resolve) => {
    open! ExpectJs;
    let readable = makePlainReadable();
    expect(readable -> Internal__JsTypeReflection.constructorName) |> toBe("Readable") |> resolve;
  });

});

