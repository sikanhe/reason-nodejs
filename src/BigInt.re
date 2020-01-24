type t;

[@bs.val]
external fromInt: int => t = "BigInt";
[@bs.val]
external toInt: t => int = "Number";
