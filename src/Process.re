include Node_process;

[@bs.module "process"] [@bs.val]
external hrtime: unit => (int, int) = "hrtime";
[@bs.module "process"] [@bs.scope "hrtime"]  [@bs.val]
external hrtimeBigInt: unit => BigInt.t = "bigint";
[@bs.module "process"] [@bs.val] external stderr: Net.Socket.t = "stderr";
[@bs.module "process"] [@bs.val] external stdin: Net.Socket.t = "stdin";
[@bs.module "process"] [@bs.val] external stdout: Net.Socket.t = "stdout";