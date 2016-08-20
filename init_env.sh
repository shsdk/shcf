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

## TODO: Add some form of help (--help) for guidance
##
## allow custom path for development purposes.
[[ ! -z $1 ]] && export SHCF_PLATFORM_ROOT=$1 || export SHCF_PLATFORM_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )"/ && pwd )"

## add to $PATH SHCF_PLATFORM_ROOT/bin for easy usage
export PATH=$SHCF_PLATFORM_ROOT/bin:$PATH
echo "Platform environment has been set. See below:"
echo "  SHCF_PLATFORM_ROOT=$SHCF_PLATFORM_ROOT"
bash
