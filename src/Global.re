[@bs.val] external dirname: string = "__dirname"
[@bs.val] external filename: string = "__filename"
[@bs.val] external global: Js.t({..}) = "global";
[@bs.val] external require: string => unit = "require";