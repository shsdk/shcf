check_mandatory_commands() {
  local cmd_needed="$*"

  local missing_counter=0
  for needed_command in $cmd_needed; do
    if ! hash "$needed_command" >/dev/null 2>&1; then
      printf "Command not found in PATH: %s\n" "$needed_command" >&2
      ((missing_counter++))
    fi
  done

  if ((missing_counter > 0)); then
    printf "Required commands %d are missing in PATH, aborting\n" "$missing_counter" >&2
    exit 1
  fi
} ## END: check_mandatory_commands()
