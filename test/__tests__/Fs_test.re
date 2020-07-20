open Fs;
open Jest;
open Js.Promise;

describe("Fs", () => {
  testPromise("readFile should read entire file", () => {
    open_(Global.filename, Flag.read)
    |> then_(fh =>
         Fs.FileHandle.readFile(fh)
         |> then_(buffer =>
              FileHandle.close(fh) |> then_(_ => resolve(buffer))
            )
       )
    |> then_(buffer => {
         let needle = "Random string: Gh2e71pdHhPxU";
         Expect.(
           expect(buffer->Buffer.indexOfString(needle))
           |> toBeGreaterThan(0)
           |> resolve
         );
       })
  });
  testPromise("readFileWith should read entire file as a string", () => {
    open_(Global.filename, Flag.read)
    |> then_(fh =>
         Fs.FileHandle.readFileWith(fh, ~encoding="UTF-8")
         |> then_(buffer =>
              FileHandle.close(fh) |> then_(_ => resolve(buffer))
            )
       )
    |> then_(content => {
         let needle = "Random string: uCF6c5f3Arrq";
         Expect.(
           expect(Js.String.indexOf(needle, content))
           |> toBeGreaterThan(0)
           |> resolve
         );
       })
  });
});
