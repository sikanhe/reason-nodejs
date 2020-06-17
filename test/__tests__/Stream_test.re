open Jest;

describe("Stream", () => {
  testAsync("'Stream.Readable.make' should return a defined value", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let readable = makeReadableEmpty();
    expect(readable->Js.Undefined.return) |> toBeDefined |> resolve;
  });

  testAsync(
    "'Stream.Readable.make' should return an instance of 'Readable'", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let readable = makeReadableEmpty();
    expect(readable->Internal__JsTypeReflection.constructorName)
    |> toBe("Readable")
    |> resolve;
  });

  testAsync("'Stream.Writable.make' should return a defined value", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let writable = makeWritableEmpty();
    expect(writable->Js.Undefined.return) |> toBeDefined |> resolve;
  });

  testAsync(
    "'Stream.Writable.make' should return an instance of 'Writable'", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let writable = makeWritableEmpty();
    expect(writable->Internal__JsTypeReflection.constructorName)
    |> toBe("Writable")
    |> resolve;
  });

  testAsync("'Stream.Readable.pipe' returns a writable stream", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let readable = makeReadableEmpty();
    let writable = makeWritableEmpty();
    expect(Stream.pipe(readable, writable)) |> toBe(writable) |> resolve;
  });

  testAsync(
    "'Stream.Readable.destroyWithError' should emit 'error' event", resolve => {
    open! ExpectJs;
    open! Errors;
    let dummyError = Error.make("Destroyed")->Error.toJsExn;
    let () =
      StreamTestLib.makeReadableEmpty()
      ->Stream.onError(err => {
          Console.(console->dir(err));
          expect(err) |> toEqual(dummyError) |> resolve;
        })
      ->Stream.destroyWithError(dummyError)
      ->ignore;
    ();
  });

  testAsync(
    "'Stream.Readable.destroy' should return the exact same instance of 'Readable'",
    resolve => {
      open! ExpectJs;
      let readable = StreamTestLib.makeReadableEmpty();
      expect(readable->Stream.destroy) |> toBe(readable) |> resolve;
    },
  );
});