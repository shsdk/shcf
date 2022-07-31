## corefiles_to_tempate - copies core files to template if it doesn’t exist. 
##   if exist, cross-check and ERROR if there are differences seen.
##
corefiles_to_template() {
  autoload_functions "define_rootpath"

  local corefiles="
    $INIT_CONF_FULLPATH
    $AUTOLOAD_FUNCTIONS_FULLPATH
  "
  
  local template_rootdir=$(define_rootpath "template")
  for each_corefile in $corefiles; do
     corefile_name=$($BASENAME_BIN $each_corefile)
     corefile_parentdirname=$($BASENAME_BIN $($DIRNAME_BIN $each_corefile))
     corefile_dest_full=$template_rootdir/$corefile_parentdirname/$corefile_name
     if [[ ! -e $corefile_dest_full ]]; then
        $CP_BIN $each_corefile $corefile_dest_full
     else
        ## TODO: Check if corefile exist, if so, make sure it has no diff. Otherwise, SHOUT
        :
     fi
  done
} ## END: corefiles_to_template()
