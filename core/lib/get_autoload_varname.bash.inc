## For indirect function autoloading, return the reference variable
## INPUT : autoload statement
## OUTPUT: variable name used to refer to functions to autoload
##
get_autoload_varname() {
   echo $*|$CUT_BIN -d' ' -f2|$SED_BIN 's/"//g'|$SED_BIN 's/\$//g'
} ## END: get_autoload_varname()
