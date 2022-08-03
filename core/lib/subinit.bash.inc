## subinit() - extension to 'init', since it's somehow impossible to run
##    when init calls a subshell
##
subinit() {
    autoload_functions "ensure_proper_env corefiles_to_template"

    ## Alert and abort if env not set
    ensure_proper_env

    ## Complete the contents of tpl...
    corefiles_to_template
}
