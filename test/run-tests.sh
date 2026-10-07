#!/usr/bin/env bash
set -euo pipefail


## This is the script used in dune runtest

compiler=$1
ocaml=$2
profile=$3
cc=$4
cflags=$5
runner=$6

case "$profile" in
  dev|release|x86)
    backend=x86
    default_cflags='-m32 -fno-pie -no-pie'
    ;;
  ppc)
    backend=PowerPC
    default_cflags=''
    ;;
  sparc)
    backend=SPARC
    default_cflags=''
    ;;
  *)
    echo "Unsupported backend profile: $profile" >&2
    exit 1
    ;;
esac

if [[ "$cflags" == default ]]; then
  cflags=$default_cflags
fi
# Flags and runner arguments are whitespace-separated; shell expressions
# are deliberately not evaluated.
read -r -a cc_args <<< "$cflags"
read -r -a runner_args <<< "$runner"

# Match the Makefile's TESTS list. manyargs uses the selected backend's
# source directly, independently of the legacy to_* symlinks.
tests=(
  print sum-tail gcd sum fib ack even-odd
  adder adder2 funcomp cls-rec cls-bug cls-bug2 cls-reg-bug
  shuffle spill spill2 spill3 join-stack join-stack2 join-stack3
  join-reg join-reg2 non-tail-if non-tail-if2
  inprod inprod-rec inprod-loop matmul matmul-flat manyargs
)

mkdir -p results
for name in "${tests[@]}"; do
  source=$name.ml
  if [[ "$name" == manyargs ]]; then
    source=$backend/$name.ml
  fi
  base=results/$name
  cp "$source" "$base.ml"

  # Keep diagnostics separate from the stdout compared against OCaml.
  if ! (
    "$compiler" "$base" || exit "$?"
    "$cc" -g -O2 -Wall "${cc_args[@]}" \
      "$base.s" "../$backend/libmincaml.S" ../stub.c -lm -o "$base.exe" || exit "$?"
    "${runner_args[@]}" "./$base.exe" > "$base.actual" || exit "$?"
    "$ocaml" "$base.ml" > "$base.expected" || exit "$?"
  ) > "$base.log" 2>&1; then
    echo "FAIL ($backend): $name" >&2
    cat "$base.log" >&2
    exit 1
  fi

  if ! diff -u "$base.expected" "$base.actual"; then
    echo "FAIL ($backend): $name: output differs from OCaml" >&2
    cat "$base.log" >&2
    exit 1
  fi
done

echo "All ${#tests[@]} $backend tests passed."
