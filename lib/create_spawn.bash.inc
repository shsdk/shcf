### -------------------------------------------------
### create_spawn: Creates a standalone version of an
###        shcf-based shell script
### INPUT  : 
### OUTPUT :
### AUTHOR :
### -------------------------------------------------
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
  local temp_file=$($MKTEMP_BIN --tmpdir=$TMP_DIR spawn-genXXXX.sh)

  # 0. Write the 'shebang' line
  #
  echo '#!/bin/bash' > $temp_file

  ## [TODO] 1. Make sure etc/controller.bash.inc is untouched 
  ##           (get sha512 or whatever is available). Otherwise, abort.
  ##           ---> assumed untouched for now. Doesn't affect outcome yet.

  # 2. Load contents of etc/init.conf minus binaries
  # 
  $GREP_BIN -v ^# $this_rootpath/etc/init.conf | $GREP_BIN -v binaries.conf >> $temp_file

  # 3. Load etc/binaries.conf as is (minus comments)
  #
  $GREP_BIN -v ^# $this_rootpath/etc/binaries.conf >> $temp_file

  ## [TODO] 4. Parse autoload_functions, writing first the one with
  ##           highest dependents down to lowest
  ##           --> order doesn't matter as per observation
  for each_func in $(get_dependencies $project $script_name); do
      get_stripped_funcblock $this_rootpath/lib/$each_func.bash.inc $temp_file   ## the function minus 'autoload' part
  done

  ## [TODO] 5. Load lines after 'autoload_functions' line till EOF
  fileblock_after_autoload $this_rootpath/bin/$script_name $temp_file

  ## [TODO] 6. Rename $temp_file to $SPAWNED_DIR/$script_name
  cp $temp_file $SPAWNED_DIR/$script_name
} ## END: create_spawn()
