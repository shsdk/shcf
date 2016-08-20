#!/bin/bash

[[ ! -z $SHCF_PLATFORM_ROOT ]] && {
  echo "WARNING: SHCF Platform environment already set as show below. Run 'exit' first.";
  echo "  SHCF_PLATFORM_ROOT=$SHCF_PLATFORM_ROOT"
  exit 1;
}

## NOTE: Make sure to follow the format below (for jenkins [Environment Script Plugin] compatibility)
##    echo "SHCF_PLATFORM_ROOT=$SHCF_PLATFORM_ROOT"
##
## See details in https://wiki.jenkins-ci.org/display/JENKINS/Environment+Script+Plugin

## allow custom path for development purposes.
[[ ! -z $1 ]] && export SHCF_PLATFORM_ROOT=$1 || export SHCF_PLATFORM_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )"/ && pwd )"
echo "SHCF_PLATFORM_ROOT=$SHCF_PLATFORM_ROOT"
bash

