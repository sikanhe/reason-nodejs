
let data = "Sample text to write to a file!" -> BinaryLike.string;

let outputPath = Path.relative(
  ~from= Process.cwd(),
  ~to_="example__output.txt"
);

let writeStream = Fs.createWriteStream(outputPath);

let logErrorIfExists = (maybeError) => {
    switch (Js.Nullable.toOption(maybeError)) {
      | Some(err) => Js.log2("An error occurred", err);
      | None => ();
    };
  }

writeStream -> Stream.writeWith(
    data,
    ~callback=(maybeError) => {
      logErrorIfExists(maybeError);
      Js.log("Finished");
    },
    ()
  );

