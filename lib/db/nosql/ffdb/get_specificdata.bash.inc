## ----------------------------------------------------
## get_specificdata - get the specific data in a
##        specific row.
## INPUT: $1 - col1 unique value
##        $2 - full path to flatfile db(colon delimited)
##        $3 - specific column to get
## OUTPUT: specific data to be taken
## ----------------------------------------------------
get_specificdata()
{
    local col1=$1
    local dsource=$2
    local what_ds_column=$3           ## sample value like $dsptr_NE_INTF_VER

    local retval=$INVALID
    autoload_functions "db/nosql/ffdb/get_datarow"

    local raw_data=$(get_datarow "$RIS")
    retval=$(echo $raw_data|$CUT_BIN -d: -f${what_ds_column})

    ## return value
    echo $retval
} ## get_specificdata()
