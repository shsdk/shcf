create_namespace() {
  local prj=$1
  
  local retval=
  autoload_functions "case_shift"
  
  retval=$(case_shift upper $prj|$SED_BIN 's|/|_|g')'_SHCF_APPROOT'
  
  echo $retval  
} ## END: create_namespace()
