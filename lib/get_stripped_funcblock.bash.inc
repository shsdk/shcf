## Getting the function-only removing autoload_functions
##
get_stripped_funcblock() {
   autoload_functions "get_autoload_line get_file_maxlines"

   ## function parameter(s)
   local func_fullpath=$1
   local fullpath_tmpfile=$2

   ## get autoload-line
   local al_line=$(get_autoload_line $func_fullpath)

   ## TODO:
   ##       if no al_line, directly write to temp file
   ##       Otherwise, write the function name, strip-off auto-load lines
   ##       Dump the rest to temp file
   if [[ "$al_line" = "" ]]; then
       $CAT_BIN $func_fullpath >> $fullpath_tmpfile
   else
       local fname_only=$($BASENAME_BIN -s .bash.inc $func_fullpath)
       echo "$fname_only() {" >> $fullpath_tmpfile
       local file_maxline=$(get_file_maxlines $func_fullpath)
       local string2filter='autoload_functions'
       $GREP_BIN $string2filter -A $file_maxline $func_fullpath |$GREP_BIN -v $string2filter >> $fullpath_tmpfile    ## this may need to be in another function
   fi
} ## END: get_stripped_funcblock()
