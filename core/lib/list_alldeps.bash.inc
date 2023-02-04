## Actual lister of all dependencies regardless how it is declared (direct or indirect)
## INPUT: $1 - script_fullpath
## 
list_alldeps() {
     ## required deps
     autoload_functions "get_autoload_line isdeps_indirect get_autoload_varname getdeps_indirect getdeps_direct"

     ## function parameter(s)
     local script_fullpath=$1

     # get the 'autoloaded_functions' line
     #
     local al_line=$(get_autoload_line $script_fullpath)

     # direct declared? Get and write to p1_func.txt
     # indirect declared? Parse variable and write to p1_func.txt
     #
     local is_indirect=$(isdeps_indirect $al_line)

     local func_all=
     if [[ $is_indirect -eq $TRUE ]]; then
        local al_varname=$(get_autoload_varname $al_line)
        local func_all=$(getdeps_indirect $script_fullpath $al_varname)
     else
        func_all=$(getdeps_direct $al_line)
     fi

     echo $func_all
} ## END: list_alldeps()
