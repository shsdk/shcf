# Get all directly loaded functions list
# input: $* autoload line
#
getdeps_direct() {
  echo $*|$CUT_BIN -d' ' -f2-|$SED_BIN 's/"//g'
} ## END: getdeps_direct()
