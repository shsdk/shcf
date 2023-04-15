## for variable-based declaration of deps
##
getdeps_indirect() {
   local file=$1
   local deps_varname=$2

   ## Detect the function list the first time.
   ## Assume it's one line per function used...
   ##
   local retval=$($CAT_BIN $file | $SED_BIN -n -e "/$deps_varname\=/,/\"/ p" | $GREP_BIN -v $deps_varname | $GREP_BIN -v '"')

   ## $retval blank? Can't be blank, calling this function means there's a list of function detected already.
   ## Let's try again. Assume function list is  defined in one line.
   ##
   ## TODO: Better way is to detect for ending quote and parse for quoted list.
   ##
   if [[ "$retval" = "" ]]; then
       local oneline_funclist=$($CAT_BIN $file | $SED_BIN -n -e "/$deps_varname\=/,/\"/ p" | $GREP_BIN ^$deps_varname)
       local used_doublequote=$(echo $oneline_funclist|grep -c '"')  ## TODO: >1 means it's not single line func list

       if [[ $used_doublequote -eq $TRUE ]]; then
          retval=$(echo $oneline_funclist | $CUT_BIN -d'"' -f2)
       else
          retval=$(echo $oneline_funclist | $CUT_BIN -d"'" -f2)
       fi
   fi

   echo $retval
} ## END: getdeps_indirect()
