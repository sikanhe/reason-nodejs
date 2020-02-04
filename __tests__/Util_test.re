open Jest;

describe("Util.Types", () => {

  test("Util.Types.isAnyArrayBuffer(arrayBuffer) should return true", () => {
    open Expect;
    let arrayBuffer = Js.TypedArray2.ArrayBuffer.make(16);
    expect(arrayBuffer -> Util.Types.isAnyArrayBuffer) |> toEqual(true);
  });

  test("Util.Types.isAnyArrayBuffer(string) should return false", () => {
    open Expect;
    let str = "not array buffer"
    expect(str -> Util.Types.isAnyArrayBuffer) |> toEqual(false);
  });

});
