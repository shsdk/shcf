## get the 'autoload' line
## input: $1 - the script full path
##
get_autoload_line() {
  echo $($GREP_BIN ^" *autoload_functions" $1|$GREP_BIN -v ^# | $HEAD_BIN -n1)
} ## END: get_autoload_line()
