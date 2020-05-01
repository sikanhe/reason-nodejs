module Impl: {
  type t = pri string;
  [@bs.inline "ascii"]
  let ascii: t;
  [@bs.inline "utf8"]
  let utf8: t;
  [@bs.inline "utf16le"]
  let utf16le: t;
  [@bs.inline "usc2"]
  let usc2: t;
  [@bs.inline "base64"]
  let base64: t;
  [@bs.inline "latin1"]
  let latin1: t;
  [@bs.inline "binary"]
  let binary: t;
  [@bs.inline "hex"]
  let hex: t;
} = {
  type t = string;
  [@bs.inline "ascii"]
  let ascii = "ascii";
  [@bs.inline "utf8"]
  let utf8 = "utf8";
  [@bs.inline "utf16le"]
  let utf16le = "utf16le";
  [@bs.inline "usc2"]
  let usc2 = "usc2";
  [@bs.inline "base64"]
  let base64 = "base64";
  [@bs.inline "latin1"]
  let latin1 = "latin1";
  [@bs.inline "binary"]
  let binary = "binary";
  [@bs.inline "hex"]
  let hex = "hex";
};

include Impl;
