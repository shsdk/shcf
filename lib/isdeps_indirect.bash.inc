# See if autoloading is direct or indirect
# returns $TRUE if direct. Otherwise, $FALSE
#
# hack-fix: Can't seem to grep for a literal '$', so workaround is there...
#
isdeps_indirect() {
    echo $* | $SED_BIN 's/\$/__waVARTAG__/g'|$GREP_BIN -c __waVARTAG__
} ## END: isdeps_direct()
