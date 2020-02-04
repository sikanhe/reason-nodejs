open Jest;

describe("Global", () => {

  test("dirname should be defined", () => {
    open ExpectJs;
    expect(Js.Undefined.return(Global.dirname)) |> toBeDefined;
  });

  test("dirname should be of type 'string'", () => {
    open Expect;
    expect(Global.dirname->Js.typeof) |> toEqual("string");
  });

  test("filename should be defined", () => {
    open ExpectJs;
    expect(Js.Undefined.return(Global.filename)) |> toBeDefined;
  });

  test("filename should be of type 'string'", () => {
    open Expect;
    expect(Global.filename->Js.typeof) |> toEqual("string");
  });

  test("'global' object should be defined", () => {
    open ExpectJs;
    expect(Js.Undefined.return(Global.global)) |> toBeDefined;
  });

  test("'global' object should be of type 'object'", () => {
    open Expect;
    expect(Global.global->Js.typeof) |> toEqual("object");
  });

  test("'require' function should be defined", () => {
    open ExpectJs;
    expect(Global.require->Js.Undefined.return) |> toBeDefined;
  });

  test("'require' function should be of type 'function'", () => {
    open Expect;
    expect(Global.require->Js.typeof) |> toEqual("function");
  });
  
  test("'require' fuction should return a defined value from a relative path", () => {
    open ExpectJs;
    expect(Global.require("path")->Js.Undefined.return) |> toBeDefined;
  });

  test("'require' fuction should successfully import a module object from a relative path", () => {
    open Expect;
    expect(Global.require("path")->Js.typeof) |> toEqual("object");
  });


});