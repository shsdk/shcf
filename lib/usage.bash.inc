usage() {
    local cmd=$1  


case $cmd in
    'main')

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

    ;;

   'new')
$CAT_BIN << _BLOCK_
shcf new help here
_BLOCK_
    ;;

   'bin')
$CAT_BIN << _BLOCK_
shcf bin help here
_BLOCK_
    ;;

   'lib')
$CAT_BIN << _BLOCK_
shcf lib help here
_BLOCK_
    ;;

   *)
$CAT_BIN << _BLOCK_
CATCHALL HELP
_BLOCK_
    ;;
esac

  exit $FAILED
} ## END: usage()
