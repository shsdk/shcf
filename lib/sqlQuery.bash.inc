## ----------------------------------------------------------------------------
## sqlQuery - given query in "$1", ouput the query result
##
## NOTE: following variables must be defined. Otherwise, abort query
##       * $mysql_server
##       * $mysql_database
##       * $mysql_user
##       * $mysql_password
## TODO: modify later to remove security issue(password shown) in "ps aux"
## ----------------------------------------------------------------------------
sqlQuery() {
  local given_query="$1"
  local query_output=

  ## ensure that db vars are used
  if [[ -z "$mysql_server"   ]] || \
     [[ -z "$mysql_database" ]] || \
     [[ -z "$mysql_user"     ]] || \
     [[ -z "$mysql_password" ]]
  then
     echo '[ERROR] sqlQuery(): needed credentials/info missing.'
     echo '  Ensure following variables are defined:'
     echo '  * $mysql_server'
     echo '  * $mysql_database'
     echo '  * $mysql_user'
     echo '  * $mysql_password'
     exit 1
  fi

  ## now, do the query
  query_output=$(echo "$given_query" | $MYSQL_BIN --host     $mysql_server   \
                                                  --database $mysql_database \
                                                  --user     $mysql_user     \
                                                  --password=$mysql_password \
                                                  --skip-column-name)

  ## return output
  echo "$query_output"
} ## END: sqlQuery()
