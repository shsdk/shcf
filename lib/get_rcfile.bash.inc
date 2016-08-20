get_rcfile() {
  local prj_alias=$(echo $1|$SED_BIN 's|/|_|g')

  autoload_functions "case_shift"

  ## a project named 'maeng' would have an entry 'MAENG_SHCF_APPROOT' in $rc_file
  local proj_path=$($GREP_BIN ^$(case_shift up $prj_alias)_SHCF_APPROOT $rc_file | $CUT_BIN -d'=' -f2)

  echo $proj_path
} ## END: get_rcfile()
