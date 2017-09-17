##=====================================
##~ List down managed projects.
##~ usage: shcf_cli projects
##~
##=====================================

create_projects() {
  autoload_functions "define_rootpath"

  local rootpath=$(define_rootpath)
  echo "Projects Root Location: $rootpath"
  for each_project in $($LS_BIN -1d $rootpath/*); do
     echo " * $($BASENAME_BIN $each_project)"
  done
  echo
} ## END: create_projects()
