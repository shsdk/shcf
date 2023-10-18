#!/usr/bin/env bash

## ---------------------------------------
## https://github.com/shsdk/shcf/issues/20
##    Added support for basherpm/basher
## ---------------------------------------

## Is it a symlink? readlink binary would tell us, silence means it is NOT a symlink
##
actual_file=$(readlink "$0")

bootpath=$(dirname $"0")
[[ "$actual_file" != "" ]] && bootpath=$(dirname "$actual_file")

## Assemble the fullpath
##
"${bootpath}/core/bin/shcf_cli" init
