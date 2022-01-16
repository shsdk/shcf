## fileblock_after_autoload
##   strips-off start of file till autoload line and append output to $tmp_file
##
fileblock_after_autoload() {
    local subject_file=$1
    local tmp_file=$2

    autoload_line=$($GREP_BIN -nv \# $subject_file|$GREP_BIN autoload_functions|cut -d':' -f1)
    $SED_BIN "1,${autoload_line}d" $subject_file >> $tmp_file
} ## END: fileblock_after_autoload()
