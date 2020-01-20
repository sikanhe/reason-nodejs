type t;

[@bs.val]
external make: int => t = "BigInt";
[@bs.val]
external toInt: t => int = "Number";
