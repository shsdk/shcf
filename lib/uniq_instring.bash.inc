### -------------------------------------------------------------------
### uniq_instring: given a array with duplicating string, remove
###        duplicates and echo clean, non-duplicating array of string
### INPUT: $1 - character to filter (optional and
###             defaults to <space> char
###             NOTE: $filter right now just supports:
###                 * COMMA
###           --> without a valid $filter, string is
###               assumed to be space delimited
###        $@ - rest of string to process
### OUTPUT: $filter delimited uniq string
### -------------------------------------------------------------------
uniq_instring() {
  local filter=$1
  local string_input=
  local retval=

  ## check if a valid $filter is specified & remove for now
  ## from $string_input
  case $filter in
    COMMA)
      shift ## remove the filter
      string_input=$@
      string_input=$(echo $string_input|$SED_BIN 's/\, / /g'|$SED_BIN 's/\,$/ /g')
    ;;
    *) ## otherwise, all are part of $string_input
      string_input=$@
  esac

  retval=$(echo $string_input|$TR_BIN ' ' "\n"|$SORT_BIN|$UNIQ_BIN|$TR_BIN "\n" ' ')

  ## what was removed must be placed back(except for last part)
  case $filter in
    COMMA)
      retval=$(echo $retval|$SED_BIN 's/ /\, /g')
    ;;
  esac

  echo $retval
} ## END: uniq_instring()
