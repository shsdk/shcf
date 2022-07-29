## -----------------------------------------------------------------------------------------
## Cross-check and ensure binaries are located in either of the following paths:
##   * /usr
##   * /bin
##   * /sbin
##
## and IF path does not start with the above (and IT IS intentional), override it via
## etc/override_binsecurity.conf. Overridden variable should be prefixed with __. 
## Example, to override PYTHON3_BIN, define __PYTHON3_BIN. If multiple values are
## expected, delimit it with colon.
##
## For checking specific binary, pass the variable name without '$'
## -----------------------------------------------------------------------------------------
##
check_required_bin() {
  ##
  ## $binlist = Only needed if checking for specific binary.
  ## Defaults to checking src/etc/binaries.conf
  ##
  local binlist=${1:-"$($GREP_BIN -v ^\# $CONF_DIR/binaries.conf|$CUT_BIN -d'=' -f1)"}

  autoload_functions "found_inarray"

  for each_bin in $binlist; do
    if [[ "${!each_bin}" = "" ]]; then
        echo "[FATAL ERROR] Required '$each_bin' not installed. Aborting."
        exit 1
    ##
    ## NOTE: Ideally, only those NOT MATCHING the pattern should be filtered.
    ##       Can't find a working regex for it though. No-op statement is used instead
    ##
    elif [[ "${!each_bin}" =~ ^(/usr|/bin|/sbin) ]]; then
        :
    else
        ## Check if overridden. IF NOT, say so and exit (like below).
        ##
        or_eachbin=__${each_bin}

        or_found=$(found_inarray ${!each_bin} $(echo ${!or_eachbin}|$TR_BIN ":" " "))
        if [[ ${or_found} -ne 1 ]]; then
          echo "[FATAL ERROR] Suspicious binary detected for \$${each_bin}: ${!each_bin}"
          exit 1
        fi
    fi
  done
}
