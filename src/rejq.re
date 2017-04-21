let rejq filter => Printf.printf "got filter '%s'" filter;

let filter = {
  open Cmdliner;
  let doc = "<jq filter>";
  let docv = "<jq filter>";
  Arg.(required & pos 0 (some string) None & info [] ::docv ::doc)
};

let cmd = {
  open Cmdliner;
  let doc = "";
  let version = "%%VERSION%%";
  let exits = Term.default_exits;
  (Term.(const rejq $ filter), Term.info "rejq" ::doc ::version ::exits)
};

let () = Cmdliner.Term.(exit @@ eval cmd);
