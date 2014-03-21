### -------------------------------------------------
### mresult_sql:
### INPUT:
### OUTPUT:
### AUTHOR:
### -------------------------------------------------

mresult_sql() {
    local ncolumn=$1
    shift

    local query_result=$@
    if [ "$query_result" != "" ]; then
        local j=0
        local tempVar=
        for each_entry in $query_result; do
            ## elements on even index is the hash so put "/" at the end.
            ## Otherwise, simply concatenate previous hash with current element index
            [ `expr $j % $ncolumn` -eq 0 ] && tempVar=${each_entry}"/" || tempVar=${tempVar}${each_entry}

            ## @odd numbered index, that means that pattern is now complete(hash/file) so
            ## record to arr1 array and cleanup $tempVar for next iteration
            [ `expr $j % $ncolumn` -eq 1 ] && arr1=("${arr1[@]}" $tempVar) && tempVar=
            j=$((j+1))
        done

        local arr_len=$((${#arr1[@]}-1))
        local retval="
            `for ((i=0; i<=$arr_len; i++)); do echo ${arr1[$i]}; done`
        "
    fi

    echo $retval
} ## END: mresult_sql()
