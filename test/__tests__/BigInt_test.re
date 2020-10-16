open Jest;

describe("BigInt", () => {
  Random.init(84611);

  let fourHundred = 400;
  let randomInt = _ => Random.int(fourHundred);

  test(
    "'BigInt.fromInt' and 'BigInt.toInt' are associative operations for all 32-bit integers",
    () => {
      let arrA = Belt.Array.makeByU(1000, (. _) => Random.int(1000000));
      let arrB = Belt.Array.map(arrA, BigInt.fromInt);
      let arrC = Belt.Array.map(arrB, BigInt.toInt);
      Expect.(expect(arrA) |> toEqual(arrC));
    },
  );

  test("BigInt.add", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a + b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(add(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(+)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a + b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) + fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.subtract", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a - b;

    Expect.(
      [@ocaml.warning "-44"]
      expect(BigInt.(subtract(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(-)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a - b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) - fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.multiply", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a * b;

    Expect.(
      [@ocaml.warning "-44"]
      expect(BigInt.(multiply(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(*)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a * b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) * fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.divide", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a / b;

    Expect.(
      [@ocaml.warning "-44"]
      expect(BigInt.(divide(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(/)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a / b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) / fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.negate", () => {
    let a = randomInt();
    let b = - a;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(negate(fromInt(a))))
      |> toEqual(BigInt.fromInt(b))
    );
  });

  test("BigInt.(~-)", () => {
    let a = randomInt();
    let b = - a;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(- fromInt(a)))
      |> toEqual(BigInt.fromInt(b))
    );
  });

  test("BigInt.modulo", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a mod b;

    Expect.(
      [@ocaml.warning "-44"]
      expect(BigInt.(modulo(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(mod)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a mod b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) mod fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.power", () => {
    let a = Random.int(6);
    let b = Random.int(8);

    [@ocaml.warning "-3"]
    let c = Js.Math.pow_int(~base=a, ~exp=b);

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(power(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(**)", () => {
    let a = Random.int(6);
    let b = Random.int(8);

    [@ocaml.warning "-3"]
    let c = Js.Math.pow_int(~base=a, ~exp=b);

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) ** fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.logicalAnd", () => {
    let a = Random.int(256);
    let b = Random.int(256);
    let c = a land b;

    Expect.(
      [@ocaml.warning "-44"]
      expect(BigInt.(logicalAnd(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(land)", () => {
    let a = Random.int(256);
    let b = Random.int(256);
    let c = a land b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) land fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.logicalOr", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a lor b;

    Expect.(
      [@ocaml.warning "-44"]
      expect(BigInt.(logicalOr(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(lor)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a lor b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) lor fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.logicalXor", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a lxor b;

    Expect.(
      [@ocaml.warning "-44"]
      expect(BigInt.(logicalXor(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(lxor)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a lxor b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) lxor fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.logicalNot", () => {
    let a = randomInt();
    let b = lnot(a);

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(logicalNot(fromInt(a))))
      |> toEqual(BigInt.fromInt(b))
    );
  });

  test("BigInt.(lnot)", () => {
    let a = randomInt();
    let b = lnot(a);

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(lnot(fromInt(a))))
      |> toEqual(BigInt.fromInt(b))
    );
  });

  test("BigInt.logicalShiftLeft", () => {
    let a = 26;
    let b = 7;
    let c = a lsl b;

    Expect.(
      [@ocaml.warning "-44"]
      expect(BigInt.(logicalShiftLeft(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(lsl)", () => {
    let a = 26;
    let b = 7;
    let c = a lsl b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) lsl fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.arithmeticShiftRight", () => {
    let a = 32;
    let b = 4;
    let c = a asr b;

    Expect.(
      [@ocaml.warning "-44"]
      expect(BigInt.(arithmeticShiftRight(fromInt(a), fromInt(b))))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(asr)", () => {
    let a = 32;
    let b = 4;
    let c = a asr b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) asr fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });
});
