## ============================================================
## get_datarow() - given a colon-delimited flat-file database
##        like the *nix password file, output the line with
##        matching 1st column
## 
## INPUT: $1 - column1 uniq value
##        $2 - the flatfile database(full path)
## OUTPUT: the entire matching line
## ============================================================
get_datarow()
{
  local col1=$(echo $1|tr a-z A-Z)
  local dsource=$2

  local ret_val=$INVALID
  ret_val=$(grep "${col1}:" $dsource)

  ## return value
  echo $ret_val
} ## END: get_datarow()
