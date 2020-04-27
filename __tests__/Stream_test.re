open Jest;

describe("Stream", () => {
  testAsync("Stream.makeReadable should create a Stream.Readable.t", (done_) => {
    open! ExpectJs;

    open Stream.Readable;
    let options = makeOptions(
      ~destroy=[@bs.this] (_, _, done_) => {
        done_(~err=None)
      },
      ~read=[@bs.this] (_, _) => (),
      ()
    );
    let readable = make(options, );

    expect(readable->Js.Undefined.return) |> toBeDefined |> done_;

  })
});
