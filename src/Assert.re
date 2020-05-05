[@bs.module "assert"] external ok: 'a => unit = "ok";
[@bs.module "assert"] external equal: ('a, 'a) => unit = "equal";
[@bs.module "assert"] external notEqual: ('a, 'a) => unit = "notEqual";
[@bs.module "assert"] external deepEqual: ('a, 'a) => unit = "deepEqual";
[@bs.module "assert"] external notDeepEqual: ('a, 'a) => unit = "notDeepEqual";
[@bs.module "assert"] external strictEqual: ('a, 'a) => unit = "strictEqual";
[@bs.module "assert"]
external notStrictEqual: ('a, 'a) => unit = "notStrictEqual";
[@bs.module "assert"]
external deepStrictEqual: ('a, 'a) => unit = "deepStrictEqual";
[@bs.module "assert"]
external notDeepStrictEqual: ('a, 'a) => unit = "notDeepStrictEqual";

[@bs.module "assert"] external throws: (unit => 'a) => unit = "throws";
[@bs.module "assert"]
external throwsError: (unit => 'a, 'e) => unit = "throws";
[@bs.module "assert"]
external doesNotThrow: (unit => 'a) => unit = "doesNotThrow";
[@bs.module "assert"]
external doesNotThrowError: (unit => 'a, 'e) => unit = "doesNotThrow";

[@bs.module "assert"] external ifError: 'a => unit = "ifError";
[@bs.module "assert"]
external rejects: (unit => Js.Promise.t('a)) => unit = "rejects";
[@bs.module "assert"]
external rejectsError: (unit => Js.Promise.t('a), 'e) => unit = "rejects";
[@bs.module "assert"]
external doesNotReject: (unit => Js.Promise.t('a)) => unit = "doesNotReject";
[@bs.module "assert"]
external doesNotRejectError: (unit => Js.Promise.t('a), 'e) => unit =
  "doesNotReject";

module AssertionError = Errors.AssertionError;
