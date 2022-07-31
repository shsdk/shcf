##======================================================
##~For initializing shcf environment.
##~Usage: shcf_cli init
##~
##======================================================

create_init() {
  [[ ! -z $SHCF_PLATFORM_ROOT ]] && {
    echo "WARNING: SHCF Platform environment already set as show below.";
    echo "  SHCF_PLATFORM_ROOT=$SHCF_PLATFORM_ROOT"
    echo "Initialize to a different directory? Run 'exit' first.";
    echo
    exit 1;
  }

  ## NOTE: Make sure to follow the format below (for jenkins [Environment Script Plugin] compatibility)
  ##    echo "SHCF_PLATFORM_ROOT=$SHCF_PLATFORM_ROOT"
  ##
  ## See details in https://wiki.jenkins-ci.org/display/JENKINS/Environment+Script+Plugin

  ## TODO: Add some form of help (--help) for guidance
  ##
  ## allow custom path for development purposes.
  shift ## discard real $1. It's 'init' itself
  [[ ! -z $1 ]] && export SHCF_PLATFORM_ROOT=$1 || export SHCF_PLATFORM_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../ && pwd )"

  ## add to $PATH SHCF_PLATFORM_ROOT/bin for easy usage
  export PATH=$SHCF_PLATFORM_ROOT/bin:$PATH
  echo "Platform environment has been set. See below:"
  echo "  SHCF_PLATFORM_ROOT=$SHCF_PLATFORM_ROOT"
  bash

  ## ..during 'exit', show reminder that platform exited.
  echo "  Thanks for using shcf ShSDK. SHCF_PLATFORM_ROOT unset."
  echo '  => https://github.com/shsdk/shcf'
  echo
  exit 0
} ## END: create_init()
