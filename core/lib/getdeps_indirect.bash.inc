## for variable-based declaration of deps
##
getdeps_indirect() {
   local file=$1
   local deps_varname=$2

   ## return value here
   echo $($CAT_BIN $file | $SED_BIN -n -e "/$deps_varname\=/,/\"/ p" | $GREP_BIN -v $deps_varname | $GREP_BIN -v '"')
} ## END: getdeps_indirect()
