# ---------------------------------------------------
# inline_help: Syntax usage based on header comment
#
# credits: Improved idea of Bashfoo auto_usage() -
#          https://github.com/zbigg/bashfoo.git
# ---------------------------------------------------
inline_help() {
  local source=$1

  ## source not given, auto-detect
  [[ -z $source ]] && {
    local idx="${#BASH_SOURCE[*]}"
    source="${BASH_SOURCE[$idx-1]]}"
  }
 
  $GREP_BIN ^##~ $source | $SED_BIN 's/##~//g'
} ## END: inline_help()
