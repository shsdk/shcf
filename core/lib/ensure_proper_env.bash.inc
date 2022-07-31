ensure_proper_env() {
    # Otherwise, ensure environment has been set:
    #
    [[ -z $SHCF_PLATFORM_ROOT ]] && { echo "[ERROR] SHCF environment not set. Run './shcf_cli init'"; exit 1; }
    echo
} ## END: ensure_proper_env()
