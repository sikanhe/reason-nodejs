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
  })
});
