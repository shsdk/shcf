get_file_maxlines() {
  $WC_BIN -l $1| $CUT_BIN -d' ' -f1
} ## END: get_file_maxlines()
