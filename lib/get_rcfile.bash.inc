get_rcfile() {
  local prj_alias=$1

  autoload_functions "create_namespace"

  local proj_path=$($GREP_BIN ^$(create_namespace $prj_alias) $rc_file | $CUT_BIN -d'=' -f2)

  echo $proj_path
} ## END: get_rcfile()
