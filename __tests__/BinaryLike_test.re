open Jest;
describe("BinaryLike", () => {
  open Js.TypedArray2;

  let string_ = "test1234";
  let binaryLikeString = string_->BinaryLike.string;

  let buffer_ = Buffer.fromArray([| 1, 2, 3, 4 |]);
  let binaryLikeBuffer = BinaryLike.buffer(buffer_)

  let uInt8Array = Uint8Array.make([|1, 2, 3, 4|]);
  let binaryLikeUint8Array = BinaryLike.uInt8Array(uInt8Array);

  let int8Array = Int8Array.make([|1, 2, 3, 4|]);
  let binaryLikeInt8Array = BinaryLike.int8Array(int8Array);

  test("BinaryLike.classify(string) should return a 'String' variant", () => {
    open ExpectJs;
    expect(
        switch(BinaryLike.classify(binaryLikeString)) {
          | String(_) => true
          | _ => false
        }) |> toBe(true)
  });

  test("BinaryLike.classify(buffer) should return a 'Buffer' variant", () => {
    open ExpectJs;
    expect(
        switch(BinaryLike.classify(binaryLikeBuffer)) {
          | Buffer(_) => true
          | _ => false
        }) |> toBe(true)
  });

  test("BinaryLike.classify(uInt8Array) should return a 'Uint8Array' variant", () => {
    open ExpectJs;
    expect(
        switch(BinaryLike.classify(binaryLikeUint8Array)) {
          | Uint8Array(_) => true
          | _ => false
        }) |> toBe(true)
  });

  test("BinaryLike.classify(int8Array) should return a 'int8Array' variant", () => {
    open ExpectJs;
    expect(
        switch(BinaryLike.classify(binaryLikeInt8Array)) {
          | Int8Array(_) => true
          | _ => false
        }) |> toBe(true)
  });

  ();
});
