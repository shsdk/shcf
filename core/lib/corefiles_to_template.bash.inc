## corefiles_to_tempate - copies core files to template if it doesn’t exist. 
##   if exist, cross-check and ERROR if there are differences seen.
##
corefiles_to_template() {
  autoload_functions "define_rootpath error_message"

  local corefiles="
    INIT_CONF
    AUTOLOAD_FUNCTIONS
  "
  
  local the_corefile=
  local each_corefile=
  local corefile_name=
  local corefile_parentdirname=
  local corefile_dest_full=
  local the_coresha256=
  local each_sha256sum=
  local template_rootdir=$(define_rootpath "template")
  for each_file in $corefiles; do
     ## Prep the core filepath
     ##
     the_corefile=${each_file}_FULLPATH
     each_corefile=${!the_corefile}
     corefile_name=$($BASENAME_BIN $each_corefile)
     corefile_parentdirname=$($BASENAME_BIN $($DIRNAME_BIN $each_corefile))
     corefile_dest_full=$template_rootdir/$corefile_parentdirname/$corefile_name

     ## Prep the sha256sum per core file
     ##
     the_coresha256=${each_file}_SHA256SUM
     each_sha256sum=${!the_coresha256}
     if [[ ! -e $corefile_dest_full ]]; then
        $CP_BIN $each_corefile $corefile_dest_full
     else
        ## Get the file's sha256sum. IF different, SHOUT!
        actual_sha256sum=$($SHA256SUM_BIN $each_corefile|$CUT_BIN -d' ' -f1)
        if [[ "$actual_sha256sum" != "$each_sha256sum" ]]; then
            error_message "ERROR: Corefile ($each_file) sha256 different ($actual_sha256sum) than expected($each_sha256sum)"
        fi
     fi
  done
} ## END: corefiles_to_template()
