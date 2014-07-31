## ==========================================================================================
## FUNCTION : autoload_functions
## PURPOSE  : To check functions that are required, try to autoload them if NOT YET defined
##
## INPUT: array of $req_func
## OUTPUT: exit 1 - if any required function cannot be autoloaded (meaning, not found in standard
##          library location.
## ==========================================================================================
autoload_functions()
{
    local exit_code=0

    ## check first parameter. If it's a directory, then
    ## it is where functions should be loaded from
    local new_libdir=$1
    [[ -d $new_libdir ]] && {
      shift
      LIB_DIR=$new_libdir
     }
    
    ## iterate through all $*, set $exit_code to 1
    ## if any required function cannot be autoloaded
    for func_relpath in $*; do
        func_name=$(basename $func_relpath)
        ## if function undefined, try to auto-include (reference from specified location)
        type $func_name &> /dev/null || source "$LIB_DIR"/${func_relpath}.bash.inc

        ## recheck, ensure it has been defined.
        type $func_name &> /dev/null || {
          echo "ERROR: Missing required $func_relpath"
          exit_code=1
        }
    done

    ## abort (exit 1) if any required func cannot be autoloaded
    [[ $exit_code -eq 1 ]] && exit $exit_code
} ## END: autoload_functions()
