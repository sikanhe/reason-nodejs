type t;

[@bs.val] external fromInt: int => t = "BigInt";
[@bs.val] external toInt: t => int = "Number";

let%private _NEGATIVE_ONE = fromInt(-1);

external (~-): t => t = "%negfloat";
external (+): (t, t) => t = "%addfloat";
external (-): (t, t) => t = "%subfloat";
external ( * ): (t, t) => t = "%mulfloat";
external (/): (t, t) => t = "%divfloat";
let (%): (t, t) => t = Obj.magic(mod_float);
let ( ** ): (t, t) => t = [%raw {|function (a, b) { return (a ** b); }|}];
external (land): (t, t) => t = "%andint";
external (lor): (t, t) => t = "%orint";
external (lxor): (t, t) => t = "%xorint";
let lnot: t => t = x => x lxor _NEGATIVE_ONE;
external (lsl): (t, t) => t = "%lslint";
external (asr): (t, t) => t = "%asrint";
