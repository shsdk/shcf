usage() {

$CAT_BIN << _BLOCK_
 $($BASENAME_BIN $0) <cmd> [<cmd_params>]
  where:
   * cmd        - command supported: 'new', 'lib', 'bin'
   * cmd_params - Depends on command. See below:

  Command specific parameters:
    new       requires <project_name>
    bin       requires <project_name> <script_name>
    lib       requires <project_name> <lib_name>
_BLOCK_
  exit $FAILED
} ## END: usage()
