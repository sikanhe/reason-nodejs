open Jest;

describe("Path", () => {
  test("basename should isolate filename with extension", () => {
    open Expect;
    expect(Path.Posix.basename("/tmp/myfile.html")) |> toBe("myfile.html");
  });

});
