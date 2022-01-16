##========================================================
##~For creating standalone version of an shcf-based script
##~Usage: shcf_cli spawn <project_name> <script_name>
##~
##========================================================
create_spawn() {
  ## list of functions to auto-load
  autoload_functions "case_shift define_rootpath get_dependencies get_stripped_funcblock fileblock_after_autoload"

  ## ----- function parameter
  ##
  local project=$(case_shift low $1)
  local script_name=$2

  # xxxxxxxxxxxxxxx
  # main code below
  # xxxxxxxxxxxxxxx
  local this_rootpath=$(define_rootpath "$project")
  local temp_file=$($MKTEMP_BIN /tmp/spawn-genXXXX) ## TODO: Check how to make it to $TMP_DIR

  # 0. Write the 'shebang' line
  #
  echo '#!/bin/bash' > $temp_file

  ## [TODO] 1. Make sure etc/controller.bash.inc is untouched 
  ##           (get sha512 or whatever is available). Otherwise, abort.
  ##           ---> assumed untouched for now. Doesn't affect outcome yet.

  # 2. Load contents of etc/init.conf without binaries.conf
  #    Add app_defs.conf contents if it exist
  #
  $GREP_BIN -v ^# $this_rootpath/etc/init.conf | $GREP_BIN -v binaries.conf | $GREP_BIN -v app_defs.conf >> $temp_file
  local app_defs_conf="${this_rootpath}/etc/app_defs.conf"
  if [[ -e "${app_defs_conf}" ]]; then
      $GREP_BIN -v ^# ${app_defs_conf} >> $temp_file
  fi

  # 3. Load etc/binaries.conf as is (minus comments)
  #
  $GREP_BIN -v ^# $this_rootpath/etc/binaries.conf >> $temp_file

  ## 4. Parse autoload_functions, writing first the one with
  ##           highest dependents down to lowest
  ##           --> order doesn't matter as per observation
  for each_func in $(get_dependencies $project $script_name); do
      get_stripped_funcblock $this_rootpath/lib/$each_func.bash.inc $temp_file   ## the function minus 'autoload' part
  done

  ## 5. Load lines after 'autoload_functions' line till EOF
  fileblock_after_autoload $this_rootpath/bin/$script_name $temp_file

  ## 6. Rename $temp_file to $SPAWNED_DIR/$script_name
  cp $temp_file ${this_rootpath}/opt/spawned/$script_name
} ## END: create_spawn()
