open Jest;

describe("Process", () => {
  test("cwd should be of type 'string'", () => {
    ExpectJs.(
      expect(Process.cwd(Process.process, ())->Js.typeof)
      |> toEqual("string")
    )
  })
});