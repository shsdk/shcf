create_help() {
  ## include dependencies
  autoload_functions "usage case_shift"

  ## parameter
  local on_what=$(case_shift low $1)
  
  case $on_what in
      'new')
        usage new
      ;;
      'bin')
        usage bin
      ;;
      'lib')
        usage bin
      ;;
       *)
        usage help
      ;;
  esac

} ## END: create_help()
