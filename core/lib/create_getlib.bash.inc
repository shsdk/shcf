##==============================================================================
##~For getting a library function in either an existing project or in ShSDK.
##~
##~usage: shcf_cli getlib <project_name> <vendor_name>
##~  project_name    * existing project must be listed in 'shcf_cli projects'
##~                  * 'shcf' or '-' would mean relative to ShSDK root
##~
##==============================================================================
create_getlib() {
  local projname=$1
  local vendor_lib=$2

  ## list of functions to auto-load
  autoload_functions "usage define_rootpath"

  #show help if no parameters given
  [[ $# -lt 2 ]] && { echo "ERROR: Parameter(s) missing!"; usage getlib; exit $FAILED; }

  ## ..............................
  ## main function below
  ## ..............................
  local libname=$(            $BASENAME_BIN $vendor_lib | $CUT_BIN -d':' -f1)
  local tagname=$(            $BASENAME_BIN $vendor_lib | $TR_BIN ':' '-')
  local gitrepo_server_hint=$($DIRNAME_BIN  $vendor_lib)
  local gitrepo_server=
  local vendor_name=
  local dest_dir=

  ## Two types of vendor_lib can be given:
  ##   1. usual    location - shcf-lib/abs_value:v1.0
  ##   2. external location - github.com/kyoszen/shcf-lib/abs_value:v1.0
  ## So both MUST be usable.

  ## TODO: Add constant githubrepo_default to app_vars.conf
  if [[ "$gitrepo_server_hint" = "shcf-lib" ]]; then
    gitrepo_server="https://github.com/icasimpan/${gitrepo_server_hint}"
    vendor_name=${gitrepo_server_hint}
  else
    gitrepo_server="https://${gitrepo_server_hint}"
    vendor_name=$(basename ${gitrepo_server_hint})
  fi
  dest_dir=$(define_rootpath)/vendor/${vendor_name}/${libname}/
  $MKDIR_BIN -p $dest_dir ## Ensuring $dest_dir would exist

  ## Get this into disk, with only the most recent history
  git clone --depth=1 --branch $tagname $gitrepo_server $dest_dir

  ## TODO: Make the necessary cross-verifications:
  ##  1. vendor library's sha256sum 
  ##   => for x in $(find ./shcf-lib/abs_value -type f|grep -v .git|grep -v version_hash.cfg); do sha256sum $x; done|sha256sum|cut -d' ' -f1
  ##  2. sha256sum of library file only
  ##
  ##  3. Read dependencies.cfg of vendored library and get those too (if not yet in place).
} ## END: create_getlib()
