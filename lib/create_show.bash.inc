create_show() {
  autoload_functions "usage case_shift"

  ## parameters
  local what2show=$(case_shift low $1)

  #show help if no parameters given
  [[ $# -lt 1 ]] && { echo "ERROR: Parameter(s) missing!"; usage show; exit $FAILED; }

  ## main code
  case $what2show in 
    rcfile)
       [[ -e $rc_file ]] && $CAT_BIN $rc_file || echo "NOTE: $rc_file does not exist yet!"
    ;;

    *)
      echo "ERROR: Unsupported entity($what2show)"
      usage show
    ;;
  esac 
} ## END: create_show()
