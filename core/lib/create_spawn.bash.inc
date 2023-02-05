##========================================================
##~Creates standalone version of an shcf-based script
##~Usage: shcf_cli spawn <project_name> [<script_name>]
##~  * <script_name> need not be specified
##========================================================
create_spawn() {
  ## list of functions to auto-load
  autoload_functions "case_shift define_rootpath get_dependencies get_stripped_funcblock fileblock_after_autoload"

  ## ----- function parameter
  ##
  local project=$(case_shift low $1)
  local script_name=$2

  local this_rootpath=$(define_rootpath "$project")
  [[ "$script_name" = "" ]] && {
    script_name=$(ls -1p $this_rootpath/bin/ 2> /dev/null | $GREP_BIN -v /$)
  } || { echo "ERROR: project name($project) not found or no script(s) inside it. Aborted."; echo; exit 1; }

  SPAWN_DIR=$this_rootpath/opt/spawned
  mkdir -p $SPAWN_DIR

  local temp_file=
  local app_defs_conf=

  for each_script in $script_name; do
     # xxxxxxxxxxxxxxx
     # main code below
     # xxxxxxxxxxxxxxx
     temp_file=$($MKTEMP_BIN /tmp/spawn-genXXXX) ## TODO: Check how to make it to $TMP_DIR

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
     app_defs_conf="${this_rootpath}/etc/app_defs.conf"
     if [[ -e "${app_defs_conf}" ]]; then
         $GREP_BIN -v ^# ${app_defs_conf} >> $temp_file
     fi

     # 3. Load etc/binaries.conf as is (minus comments)
     #
     $GREP_BIN -v ^# $this_rootpath/etc/binaries.conf >> $temp_file

     ## 4. Parse autoload_functions, writing first the one with
     ##           highest dependents down to lowest
     ##           --> order doesn't matter as per observation
     ## TODO: Found bug that it strips-off non-autoload parts too (checking details)
     ##
     for each_func in $(get_dependencies $project $each_script); do
         get_stripped_funcblock $this_rootpath/lib/$each_func.bash.inc $temp_file   ## the function minus 'autoload' part
     done

     ## 5. Load lines after 'autoload_functions' line till EOF
     fileblock_after_autoload $this_rootpath/bin/$each_script $temp_file
     [[ $(echo ${PIPESTATUS[@]} | $TR_BIN " " "+" | $BC_BIN) -gt 0 ]] && exit 1

     ## 6. Rename $temp_file to $SPAWNED_DIR/$each_script
     cp $temp_file ${SPAWN_DIR}/$each_script

     ## Remove temp file
     rm -rf $temp_file

     [[ $(echo ${PIPESTATUS[@]} | $TR_BIN " " "+" | $BC_BIN) -gt 0 ]] && exit 1
     echo "Spawn success for ${each_script}. See ${SPAWN_DIR}/${each_script}"
  done
} ## END: create_spawn()
