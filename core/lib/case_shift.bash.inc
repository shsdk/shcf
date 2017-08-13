case_shift() {
  local input_var=$*
  local case_wanted=$(echo $1|$TR_BIN A-Z a-z)
  shift 
  input_var=$*
  local ret_val=

  case $case_wanted in
     up*)
       ret_val=$(echo $input_var|$TR_BIN a-z A-Z)
     ;;
     *)
       ret_val=$(echo $input_var|$TR_BIN A-Z a-z)
     ;;
  esac

  echo $ret_val
} ## END: case_shift()
