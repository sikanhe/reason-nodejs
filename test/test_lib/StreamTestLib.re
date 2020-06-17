/** Creates a readable stream with no functionality */
let makeReadableEmpty = () => {
  open Stream.Readable;
  let options =
    makeOptions(
      ~destroy=
        [@bs.this] (_, err, done_) => {done_(~err=Js.Nullable.toOption(err));},
      ~read=[@bs.this] (_, _size) => (),
      ~autoDestroy=true,
      (),
    );
  make(options);
};

/** Creates a writable stream with no functionality */
let makeWritableEmpty = () => {
  open Stream.Writable;
  let options =
    makeOptions(
      ~destroy=[@bs.this] (_, err, done_) => {done_(~err=Js.Nullable.toOption(err));},
      ~write=[@bs.this] (_, _, _) => (),
      ~autoDestroy=true,
      (),
    );
  make(options);
};