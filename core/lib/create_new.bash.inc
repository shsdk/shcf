##======================================================
##~For creating a new shcf-based shell project.
##~Usage: shcf_cli new <project_name>
##~ * project_name - cannot have an 'shcf' in it's name.
##~
##======================================================

create_new() {
    ## load dependencies
    autoload_functions "usage create_bin case_shift error_message create_namespace define_rootpath"

    ## function parameters
    local project=$(case_shift low $1)

    ## show help if no parameters given
    [[ $# -eq 0 ]] && { echo "ERROR: Parameter(s) missing!"; usage new; exit $FAILED; }

    ##
    ## core logic below...
    ##
    ## Ban usage of 'shcf' in project name. Reserve for communicating with shcf tool
    [[ $(echo $project | $GREP_BIN -c shcf) -gt 0 ]] && {
      error_message "ERROR: Reserved name 'shcf' cannot be used. Aborting.";
    }

    ## put projects in predictable location by default, outside 'core ShSDK'
    local project_root=$(define_rootpath "$project")

    ## Make sure no existing conflicting project name exist. Otherwise, inform.
    [[ -d $project_root ]] && { error_message "ERROR: Project '$project' exist. Aborting."; }

    ## copy template for new shcf
    local template_rootdir=$SHCF_PLATFORM_ROOT/etc/tpl/shcf_cli/new

    mkdir -p $project_root
    cp -Rfp $template_rootdir/* $project_root
    local initial_skeleton=$?

    new_entity=$($BASENAME_BIN $project)
    create_bin $project $new_entity
    if [[ $initial_skeleton -eq $SUCCESS ]] && [[ $? -eq $SUCCESS ]]; then
       echo "Successful creation of $project"
    else
       error_message "Failure creating $project"
    fi
} ## END: create_new()
