usage() {
  echo "$($BASENAME_BIN $0) <cmd> [<cmd_params>]"
  echo " where:"
  echo "  * cmd        - command supported: 'new', 'lib'"
  echo "  * cmd_params - 'new' command accepts 'project_name'"
  echo

  exit $FAILED
} ## END: usage()
