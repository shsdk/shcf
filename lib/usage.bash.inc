usage() {
  ## include dependencies
  autoload_functions "inline_help"

  ## function parameter(s)
  local cmd=$1

  ## Flexible usage/syntax showing for lib functions.
  ## Put header comment that conforms to inline_help()
  ## standard and you're ok. Otherwise, show main help.
  ##
  local file2help=$LIB_DIR/create_${cmd}.bash.inc
  [[ -e $file2help ]] && inline_help $file2help || inline_help

  exit $FAILED
} ## END: usage()
