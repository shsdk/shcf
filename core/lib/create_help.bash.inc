##===================================================
##~Show the help instructions for supported commands.
##~usage: shcf_cli help <cmd>
##~
##~Supported <cmd> as follows:
##~     new
##~     bin
##~     lib
##~     getlib
##~     projects
##~
##===================================================

create_help() {
  ## include dependencies
  autoload_functions "usage case_shift"

  ## parameter
  local on_what=$(case_shift low $1)

  #show help if no parameters given
  [[ $# -lt 1 ]] && { echo "ERROR: Parameter(s) missing!"; usage help; exit $FAILED; }

  
  case $on_what in
      'new')
        usage new
      ;;
      'bin')
        usage bin
      ;;
      'lib')
        usage lib
      ;;
      'projects')
        usage projects
      ;;
      'getlib')
        usage getlib
      ;;
      *)
        echo "ERROR: Unknown command ($on_what)."
        usage help
      ;;
  esac

} ## END: create_help()
