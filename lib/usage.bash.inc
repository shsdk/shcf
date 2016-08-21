usage() {
    local cmd=$1  


case $cmd in
   'new')
$CAT_BIN << _BLOCK_
For creating a new shcf-based shell project.
Usage: shcf_cli new <project_name>
 * project_name - cannot have an 'shcf' in it's name.
                  Depending on usage, can be anywhere
	          you have permission to write. 	
_BLOCK_
    ;;

   'bin')
$CAT_BIN << _BLOCK_
For creating a shell script in an existing project.
usage: shcf_cli bin <project_name> <script_name>
 * project name - should be an existing project as can
                  be seen from $rc_file.
_BLOCK_
    ;;

   'lib')
$CAT_BIN << _BLOCK_
For creating a library in an existing project.
usage: shcf_cli bin <project_name> <script_name>
 * project name - should be an existing project as can
                  be seen from $rc_file.
_BLOCK_
    ;;

    'help')
$CAT_BIN << _BLOCK_
Show the help instructions for supported commands.
usage: shcf_cli help <cmd>

  Supported <cmd> as follows:
     new
     bin
     lib
     show
_BLOCK_
    ;;

    'show')
$CAT_BIN << _BLOCK_
Displays the contents of an entity.
usage: shcf_cli show <entity>

  Supported <entity> as follows:
    rcfile
_BLOCK_
    ;;

   *)
$CAT_BIN << _BLOCK_
usage: $($BASENAME_BIN $0) <cmd> [<cmd_params>]
 where:
   * cmd        - Command supported, see below.
   * cmd_params - Depends on command. See below.

  Command specific parameters:
    new       requires <project_name>
    bin       requires <project_name> <script_name>
    lib       requires <project_name> <lib_name>
    show      requires <entity>

  For usage per command, use 'shcf_cli help <cmd>'
_BLOCK_
    ;;
esac

  exit $FAILED
} ## END: usage()
