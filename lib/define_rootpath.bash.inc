## define_rootpath: Define where to put the 'lib'
##    or 'bin'. Either get from $rc_file for rootpath
##    or put it relative to $SHCF_PLATFORM
##
define_rootpath() {
    # define dependencies
    autoload_functions "case_shift get_rcfile"

    # define function parameter
    local projname=$(case_shift down $1)    

    # define local variables
    local retval=

    # 'shcf' or '-' means, relative to ShSDK root
    # non-shcf, get from rcfile
    if [[ "$projname" =~ shcf|- ]]; then
       retval=$SHCF_PLATFORM_ROOT
    else
       retval=$(get_rcfile proot $projname)
    fi
 
    # return string value    
    echo $retval   
} ## END: define_rootpath()
