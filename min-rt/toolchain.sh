#!/usr/bin/env bash
set -euo pipefail

case "$1" in
  link)
    profile=$2
    cc=$3
    cflags=$4
    target=$5
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
      *) echo "Unsupported backend profile: $profile" >&2; exit 1 ;;
    esac
    if [[ "$cflags" == default ]]; then
      cflags=$default_cflags
    fi
    read -r -a cc_args <<< "$cflags"
    exec "$cc" -g -O2 -Wall "${cc_args[@]}" min-rt.s \
      "$backend/globals.s" "../$backend/libmincaml.S" ../stub.c -lm -o "$target"
    ;;
  run)
    read -r -a runner_args <<< "$2"
    exec "${runner_args[@]}" "$3"
    ;;
  *) echo "Expected link or run" >&2; exit 1 ;;
esac
