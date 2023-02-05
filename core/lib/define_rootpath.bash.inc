## define_rootpath: Define where to put the 'lib' or 'bin'.
##
define_rootpath() {
    # define dependencies
    autoload_functions "case_shift"

    # define function parameter
    local projname=$(case_shift down $1)    

    # define local variables
    local retval=

    # 'shcf' or '-' means, relative to ShSDK root
    # non-shcf, it's relative to 'project' dir
    if [[ "$projname" =~ shcf|- ]]; then
       retval=$SHCF_PLATFORM_ROOT
    elif [[ "$projname" =~ tpl|template ]]; then
       retval=$CONF_DIR/tpl/shcf_cli/new
    else
       retval=$($DIRNAME_BIN $SHCF_PLATFORM_ROOT)/projects/${projname}
    fi
 
    # return string value    
    echo $retval   
} ## END: define_rootpath()
