get_rcfile() {
  ## declare dependencies first
  autoload_functions "create_namespace case_shift"

  ## function parameters
  local what_part=$(case_shift low $1) ## either: 'namespace' or 'proot' (default)
  local prj_alias=$2

  ## local variables/core logic
  local ret_val=
  local getpart='2'
  [[ "$what_part" = "namespace" ]] && getpart='1'
  ret_val=$($GREP_BIN ^$(create_namespace $prj_alias) $rc_file | $CUT_BIN -d'=' -f${getpart})

  echo $ret_val
} ## END: get_rcfile()
