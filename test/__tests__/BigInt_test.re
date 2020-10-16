open Jest;

describe("BigInt", () => {
  Random.init(84611);

  let fourHundred = 400;
  let randomInt = _ => Random.int(fourHundred);

  test("BigInt.(+)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a + b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) + fromInt(b)))
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

  test("BigInt.(*)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a * b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) * fromInt(b)))
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

  test("BigInt.(~-)", () => {
    let a = randomInt();
    let b = - a;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(- fromInt(a)))
      |> toEqual(BigInt.fromInt(b))
    );
  });

  test("BigInt.(%)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a mod b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) % fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(**)", () => {
    let a = randomInt();
    let b = Random.int(24);

    [@ocaml.warning "-3"]
    let c = Js.Math.pow_int(~base=a, ~exp=b);

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) ** fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(land)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a land b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) land fromInt(b)))
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

  test("BigInt.(lxor)", () => {
    let a = randomInt();
    let b = randomInt();
    let c = a lxor b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) lxor fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
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

  test("BigInt.(lsl)", () => {
    let a = 26;
    let b = 7;
    let c = a lsl b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) lsl fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });

  test("BigInt.(asr)", () => {
    let a = 32;
    let b = 5;
    let c = a asr b;

    Expect.(
      [@ocaml.warning "-44"] expect(BigInt.(fromInt(a) asr fromInt(b)))
      |> toEqual(BigInt.fromInt(c))
    );
  });
});
