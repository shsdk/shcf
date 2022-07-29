### -------------------------------------------------
### found_inarray: checks if a string is found
### INPUT  : $* --> 1st word is the keyword to find
### OUTPUT : 1 - IF FOUND. 0 Otherwise
### -------------------------------------------------

found_inarray() {
  local var2find=$1
  shift

  echo "$*"|$GREP_BIN -c $var2find
} ## END: found_inarray()
