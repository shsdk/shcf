##=====================================
##~ List down managed projects.
##~ usage: shcf_cli projects
##~
##=====================================
create_projects() {
  autoload_functions "ensure_proper_env define_rootpath"

  ## Alert and abort if env not set
  ensure_proper_env

  local rootpath=$(define_rootpath)
  echo "Projects Root Location: $rootpath"

  if [[ "$($LS_BIN -ld $rootpath/* 2>/dev/null)" ]]; then
    for each_project in $($LS_BIN -1d $rootpath/*); do
       echo " * $($BASENAME_BIN $each_project)"
    done
  else
    echo '--- NO PROJECTS YET ---'
    echo
    echo 'To create projects use command:'
    echo '  shcf_cli new'
  fi
  echo
} ## END: create_projects()
