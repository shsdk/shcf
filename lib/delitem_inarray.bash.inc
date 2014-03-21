### ----------------------------------------------------------
### delitem_inarray: given an array, delete all 
###        occurence of first var in $1
### INPUT: $1 - string in format <to_delete, str1, str2, strn>
### OUTPUT: echo the clean array
### ----------------------------------------------------------

delitem_inarray() {
    local todelete=$1
    shift

    local retval=$(echo $@|$SED_BIN "s/$todelete//g")
    echo $retval

    return $?
} ## END: delitem_inarray()

