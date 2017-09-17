##=====================================
##~ create_projects: List available projects
##~ usage: shcf_cli projects
##~
##=====================================

create_projects() {
  autoload_functions "usage define_rootpath"

  ## NO parameters
  local rootpath=$(define_rootpath)
  echo "Projects Root Location: $rootpath"
  for each_project in $(ls -1d $rootpath/*); do
     echo " * $($BASENAME_BIN $each_project)"
  done
  echo
} ## END: create_projects()
