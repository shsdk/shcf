## Getting the function-only removing autoload_functions
##
get_stripped_funcblock() {
   autoload_functions "get_autoload_line fileblock_after_autoload"

   ## function parameter(s)
   local func_fullpath=$1
   local fullpath_tmpfile=$2

   ## get autoload-line
   local al_line=$(get_autoload_line $func_fullpath)

   ## Add blank line between function
   echo "" >> $fullpath_tmpfile

   ## if no al_line, directly write to temp file
   ## Otherwise, write the function name, strip-off auto-load lines
   ## Dump the rest to temp file
   ##
   if [[ "$al_line" = "" ]]; then
       $CAT_BIN $func_fullpath >> $fullpath_tmpfile
   else
       local fname_only=$($BASENAME_BIN -s .bash.inc $func_fullpath)
       echo "$fname_only() {" >> $fullpath_tmpfile
       fileblock_after_autoload $func_fullpath $fullpath_tmpfile
   fi
} ## END: get_stripped_funcblock()
