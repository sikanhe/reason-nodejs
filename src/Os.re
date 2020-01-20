[@bs.module "os"] [@bs.val] external eol: string = "EOL";
[@bs.module "os"] [@bs.val] external arch: string = "arch";

type cpuTimes = {
  user: int,
  nice: int,
  sys: int,
  idle: int,
  irq: int,
};
type cpu = {
  model: string,
  speed: string,
  times: cpuTimes,
};
[@bs.module "os"] [@bs.val] external cpus: unit => array(cpu) = "cpus";
[@bs.module "os"] [@bs.val] external endianness: unit => string = "endianness";
[@bs.module "os"] [@bs.val] external freemem: unit => int = "freemem";
[@bs.module "os"] [@bs.val] external getPriority: int => int = "getPriority";
[@bs.module "os"] [@bs.val] external homeDir: unit => string = "homeDir";
[@bs.module "os"] [@bs.val] external hostname: unit => string = "hostname";
[@bs.module "os"] [@bs.val]
external loadavg: unit => array(float) = "loadavg";
[@bs.module "os"] [@bs.val] external platform: unit => string = "platform";
[@bs.module "os"] [@bs.val] external release: unit => string = "release";
[@bs.module "os"] [@bs.val]
external setPriority: (int, int) => unit = "setPriority";
[@bs.module "os"] [@bs.val] external tmpdir: unit => string = "tmpdir";
[@bs.module "os"] [@bs.val] external totalmem: unit => int = "totalmem";
[@bs.module "os"] [@bs.val] external type_: unit => string = "type";
[@bs.module "os"] [@bs.val] external uptime: unit => int = "uptime";