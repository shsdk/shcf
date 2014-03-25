## -------------------------------------------------------------
## ishost_up - pings a $which_host to check if it is alive or not
## INPUT: ip address or FQDN of a host
## OUTPUT: positive number if $which_host is alive. 0 otherwise
## -------------------------------------------------------------

ishost_up() {
  local which_host=$1

  local host_type=`$UNAME_BIN`
  case "$host_type" in
    Linux)
       retval=`$PING_BIN -c 5 $which_host|$AWK_BIN -F\, '/received/ {print $2}'|$CUT_BIN -d' ' -f2`
       ;;
     CYGWIN*)
       retval=`$PING_BIN -n 5 $which_host|$AWK_BIN -F\, '/Received/ {print $2}'|$CUT_BIN -d' ' -f4`
       ;;
  esac

  echo $retval
} ## END: ishost_up()
