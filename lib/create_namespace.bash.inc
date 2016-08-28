create_namespace() {
  autoload_functions "case_shift"
  local retval=
  
  retval=$(case_shift upper $1|$SED_BIN 's|/|_|g')'_SHCF_APPROOT'
  
  echo $retval  
} ## END: create_namespace()
