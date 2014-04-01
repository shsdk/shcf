## ==========================================================================================
## FUNCTION : autoload_functions
## PURPOSE  : To check functions that are required, try to autoload them if NOT YET defined
##
## INPUT: array of $req_func
## OUTPUT: exit 1 - if any required function cannot be autoloaded (meaning, not found in standard
##          library location.
##
## TODO: (1) Allow loading functions from non-framework standard location
##       (2) allow directories inside standard location (e.g. mysql, network, etc)
## ==========================================================================================
autoload_functions()
{
    local req_func=$*
    local ret_val=0

    ## iterate through all $req_func, set $ret_val to 1
    ## if any required function cannot be autoloaded
    for each_func in $req_func; do
        func_name=`basename $each_func`
        ## if function undefined, try to auto-include (reference from specified location)
        type $func_name &> /dev/null || source $LIB_DIR/${each_func}.bash.inc

        ## recheck, ensure it has been defined.
        type $func_name &> /dev/null || (echo "ERROR: Missing required ${each_func}"; ret_val=1)
    done

    ## abort (exit 1) if any required func cannot be autoloaded
    [ $ret_val -eq 1 ] && exit $ret_val
} ## END: autoload_functions()
