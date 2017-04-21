#!/usr/bin/env bash

set -e

export OCAML_VERSION="${1}"

make clean
opam switch "${OCAML_VERSION}"
eval `opam config env`
opam update
opam pin add -y rejq .
make
./rejq.native
git diff --exit-code
