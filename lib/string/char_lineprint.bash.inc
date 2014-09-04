## -----------------------------------------------------------
## char_lineprint - prints a character 40 times forming a line
## INPUT: $1 - char2print (- default)
##        $2 - number of times to print (40 default)
## -----------------------------------------------------------
char_lineprint () {
  local char2print=$1
  local numchars=$2
 
  [[ "$char2print" = "" ]] && char2print='-'
  [[ "$numchars"   = "" ]] && numchars=40
  printf -v line '%*s' "$numchars"
  echo ${line// /$char2print}
} ## END: char_lineprint()
