open Jest;

describe("Stream", () => {
  testAsync("Stream.Readable.make should return a defined value", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let readable = makeReadableEmpty();
    expect(readable->Js.Undefined.return) |> toBeDefined |> resolve;
  });

  testAsync(
    "Stream.Readable.make should return an instance of 'Readable'", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let readable = makeReadableEmpty();
    expect(readable->Internal__JsTypeReflection.constructorName)
    |> toBe("Readable")
    |> resolve;
  });

  testAsync("Stream.Writable.make should return a defined value", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let writable = makeWritableEmpty();
    expect(writable->Js.Undefined.return) |> toBeDefined |> resolve;
  });

  testAsync(
    "Stream.Writable.make should return an instance of 'Writable'", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let writable = makeWritableEmpty();
    expect(writable->Internal__JsTypeReflection.constructorName)
    |> toBe("Writable")
    |> resolve;
  });

  testAsync("Stream.Readable.pipe returns a writable stream", resolve => {
    open! ExpectJs;
    open StreamTestLib;
    let readable = makeReadableEmpty();
    let writable = makeWritableEmpty();
    expect(Stream.pipe(readable, writable)) |> toBe(writable) |> resolve;
  });
});
