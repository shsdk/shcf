## ----------------------------------------
## sqliteQuery() - does querying for sqlite
## INPUT : $1     - dbfile
##         $2-end - query
## OUTPUT : query result. 1 if unsuccessful
## ----------------------------------------

sqliteQuery() {
  local dbfile=$(echo $*|cut -d' ' -f1)
  local query=$(echo $*|cut -d' ' -f2-)
  local retval=1

  ## make sure $dbfile is found
  [[ -e $dbfile ]] && {
    retval=$(sqlite3 $dbfile "$query";)
  }

  echo $retval
} ## END: sqliteQuery()
