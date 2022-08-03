##===================================================
##~Show the help instructions for supported commands.
##~usage: shcf_cli help <cmd>
##~
##~Supported <cmd> as follows:
##~     help
##~     new
##~     bin
##~     lib
##~     projects
##~
##===================================================

create_help() {
  ## include dependencies
  autoload_functions "usage ensure_proper_env case_shift"

  ## Alert and abort if env not set
  ensure_proper_env

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
      'help')
        usage help
      ;;
      *)
        echo "ERROR: Unknown command ($on_what)."
        usage help
      ;;
  esac

} ## END: create_help()
