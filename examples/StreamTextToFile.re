
let data =
  "Sample text to write to a file!"
  -> BinaryLike.string;

let outputPath =
  Process.cwd()
  ->Path.relative(~from=_, ~to_="example__output.txt");

let writeStream = Fs.createWriteStream(outputPath);
writeStream -> Stream.onFinish(() => Js.log("Done"))
writeStream -> Stream.write(data);

