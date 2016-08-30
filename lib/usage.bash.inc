usage() {
  ## function parameter(s)
  local cmd=$1


  case $cmd in
    new)
$CAT_BIN << __BLOCK__
For creating a new shcf-based shell project.
Usage: $main_cmd new <project_name>
 * project_name - cannot have an 'shcf' in it's name.
                  Depending on usage, can be anywhere
                  you have permission to write.

__BLOCK__
    ;;

    bin)
$CAT_BIN << __BLOCK__
For creating a shell script in either an existing project or in ShSDK.
usage: $main_cmd bin <project_name> <script_name>
  project_name    * existing project must be listed in '$main_cmd show rcfile'
                  * 'shcf' or '-' would mean relative to ShSDK root.

__BLOCK__
    ;;

    lib)
$CAT_BIN << __BLOCK__
For creating a library function in either an existing project or in ShSDK.
usage: $main_cmd lib <project_name> <lib_name>
  project_name    * existing project must be listed in '$main_cmd show rcfile'
                  * 'shcf' or '-' would mean relative to ShSDK root.

__BLOCK__
    ;;

    help)
$CAT_BIN << __BLOCK__
Show the help instructions for supported commands.
usage: $main_cmd help <cmd>

Supported <cmd> as follows:
     new
     bin
     lib
     show

__BLOCK__
    ;;

    show)
$CAT_BIN << __BLOCK__
Displays the contents of an entity.
usage: $main_cmd show <entity>

  Supported <entity> as follows:
    rcfile

__BLOCK__
    ;;

    *)
$CAT_BIN << __BLOCK__
usage: $main_cmd <cmd> [<cmd_params>]
where:
  * cmd        - Command supported, see below.
  * cmd_params - Depends on command. See below.

 Command specific parameters:
   new       requires <project_name>
   bin       requires <project_name> <script_name>
   lib       requires <project_name> <lib_name>
   show      requires <entity>

 For usage per command, use '$main_cmd help <cmd>'
__BLOCK__
    ;;
  esac

  exit $FAILED
} ## END: usage()
