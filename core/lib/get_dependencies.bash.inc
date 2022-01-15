## assumed uniq (but not sorted from highest dependents to lowest)
get_dependencies() {
    ## required dependencies...
    autoload_functions "define_rootpath list_alldeps"

    ## accept script parameters
    local project=$1
    local script_name=$2

    # start from $shell_script
    local dynamic_rootpath=$(define_rootpath $project)
    local script_fullpath=$dynamic_rootpath/bin/$script_name
    local full_temproot=$($MKTEMP_BIN -d shcf_cli-spawn.XXXXXX --tmpdir=$TMP_DIR)  ## always process in SHCF_PLATFORM 

    local parse1_file=$full_temproot/p1_func.txt
    local func_all=$(list_alldeps $script_fullpath)  ## Get all the dependencies
    echo $func_all | $TR_BIN ' ' '\n' > $parse1_file

    ## DEBUGGING LINES SO FAR...
#    echo "[debug] func_all |$func_all|" 

    ### ===> LOOP THROUGH ALL DEPS
    local parse2_file=$full_temproot/p2_func.txt

    ## infinite loop throughout deps
    ## in 1st iteration: get the deps & all uniq from $parse1_file goes to $parse2_file
    ## $parse2_file exist? NO => break infinite loop
    ## otherwise, merge $parse1_file & $parse2_file & delete parse2_file. Do again till no more $parse2_file
    ##
    while [[ 1 ]]; do
        for each_func in $($CAT_BIN $parse1_file); do
            fullpath_lib=$dynamic_rootpath/lib/$each_func.bash.inc
            dep_of_dep=$(list_alldeps $fullpath_lib)
     #       echo "[debug] dep_of_dep |$dep_of_dep|"

            for each_subdep in $dep_of_dep; do  ## deps of deps, check and retain only those not in $parse1_file
               if [[ $(grep -c ^${each_subdep}$ $parse1_file) -eq 0 ]]; then
                  if [[ -e $parse2_file ]]; then
                     [[ $(grep -c ^${each_subdep}$ $parse2_file) -eq 0 ]] && echo $each_subdep >> $parse2_file
                  else
                     echo $each_subdep >> $parse2_file
                  fi
               fi
            done
        done
        ## check if $parse2_file created as it signifies there's more sub-dependencies seen
        [[ ! -e $parse2_file ]] && break
        $CAT_BIN $parse2_file >> $parse1_file
        rm $parse2_file
    done 

    ## return uniq deps via echo
    $CAT_BIN $parse1_file|$TR_BIN "\n" " "

} ## END: get_dependencies()
