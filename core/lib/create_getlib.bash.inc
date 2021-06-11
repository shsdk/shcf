##==============================================================================
##~(BETA) For getting a contrib library into existing project.
##~
##~usage: shcf_cli getlib <vendor_library> <project_name>
##~  vendor_library  * default source defined in etc/app_defs.conf
##~                    Can be written as the examples below:
##~                      shcf-lib/abs_value:v1.0
##~                      abs_value:v1.0
##~                      abs_value:develop
##~                      abs_value:stable
##~  project_name    * existing project must be listed in 'shcf_cli projects'
##~
##==============================================================================
create_getlib() {
  local vendor_lib=$1
  local projname=$2

  ## list of functions to auto-load
  autoload_functions "usage define_rootpath"

  #show help if no parameters given
  [[ $# -lt 2 ]] && { echo "ERROR: Parameter(s) missing!"; usage getlib; exit $FAILED; }

  ## ..............................
  ## main function below
  ## ..............................
  local ABS_VENDORLIB=$($BASENAME_BIN $vendor_lib)
  local libname=$(       echo $ABS_VENDORLIB | $CUT_BIN -d':' -f1)
  local libversion_raw=$(echo $ABS_VENDORLIB | $CUT_BIN -d':' -f2)
  if [[ "$libversion_raw" =~ develop|stable ]]; then
     libversion="$libversion_raw/$libname"
  else
     libversion=$(echo $ABS_VENDORLIB|$TR_BIN ':' '-')
  fi

  local gitrepo_hint=$($DIRNAME_BIN  $vendor_lib)
  local gitrepo=
  local vendor_name=
  local dest_dir=

  ## Two types of vendor_lib can be given:
  ##   1. usual    location - shcf-lib/abs_value:v1.0
  ##   2. external location - github.com/kyoszen/shcf-lib/abs_value:v1.0
  ## So both MUST be usable.
  ## TODO: Implement #2 later

  ## TODO: if version (e.g. ':v1.0') is not given fallback to using latest "stable"
  ## Default "gitrepo_hint" MUST be 'shcf-lib' and need not be given.
  if [[ "$gitrepo_hint" =~ shcf-lib|. ]]; then
    gitrepo="${git_serverurl_default}/${git_reponame_default}"
    vendor_name=${git_reponame_default}
  else
    gitrepo="https://${gitrepo_hint}"
    vendor_name=$($BASENAME_BIN${gitrepo_hint})
  fi

  detected_rootdir=$(define_rootpath "$projname")
  dest_dir=${detected_rootdir}/vendor/${vendor_name}/${libname}/
  $MKDIR_BIN -p $dest_dir ## Ensuring $dest_dir would exist

  ## Get this into disk, with only the most recent history
  $GIT_BIN clone --depth=1 --branch $libversion $gitrepo $dest_dir

  ## TODO: Make the necessary cross-verifications:
  ##  1. vendor library's sha256sum 
  ##   => for x in $(find ./shcf-lib/abs_value -type f|grep -v .git|grep -v version_hash.cfg); do sha256sum $x; done|sha256sum|cut -d' ' -f1
  ##  2. sha256sum of library file only
  ##
  ##  3. Read dependencies.cfg of vendored library and get those too (if not yet in place).

  ## Copy now the library file, binaries and dependencies
  ## TODO:
  ##   * copy etc/init.conf to etc/app_vars.conf
  ##   * binaries.conf to etc/binaries.conf (MUST create a function that iterates over content of binaries.conf, and only insert those that are not yet there).
  $RSYNC_BIN -az ${dest_dir}/lib/${libname}.bash.inc ${detected_rootdir}/lib/contrib/
} ## END: create_getlib()
