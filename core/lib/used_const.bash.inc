used_const() {
    local const_used=$1

    ## from etc/init.conf constants
    ## TODO: Make this auto-update depending on values set in
    ##       etc/init.conf
    ##
    local CONSTS_LIST="
        INVALID_VAL
        INVALID
        FAILED
        SUCCESS
        FALSE
        TRUE
    "

    is_used() {
        local const_name=$1

        local retval=0
        for found in $(echo $const_used | $TR_BIN "," " "); do
            [[ "$const_name" = "$found" ]] && { retval=1; break; }
        done

        echo $retval
    }

    local remove_this=
    for x in $CONSTS_LIST; do
         if [[ $const_used = "__NONE__" ]]; then
             remove_this="${remove_this}$\|"
         else
             [[ "$(is_used $x)" = "0"  ]] && remove_this="${remove_this}$\|"
         fi
    done

    ## returned string with excess "\|" removed
    echo ${remove_this%??}
} ## END: used_const()
