## =================================================================================================================
## FILENAME: controller.bash.inc
## PURPOSE : controller (mediator) script between the models(individual functions) and view(each individual scripts)
## =================================================================================================================

SHCF_ROOTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../ && pwd )"
LIB_DIR=$SHCF_ROOTDIR/lib
CONF_DIR=$SHCF_ROOTDIR/etc
LOG_DIR=$SHCF_ROOTDIR/log
TMP_DIR=$SHCF_ROOTDIR/tmp
VENDOR_DIR=$SHCF_ROOTDIR/vendor                                     ## for vendor, aka 3rdparty
TEMPLATE_DIR=$CONF_DIR/tpl
OPT_DIR=$SHCF_ROOTDIR/opt

. $CONF_DIR/init.conf
. $LIB_DIR/autoload_functions.bash.inc

## #40 - (OPTIONAL) Global initializer function
##
## Initializer function for updating initial variables depending on specific conditions.
## Typical example is an integration script that needs to be on HTTPS or not depending on where the function is run
## (local on http only or production - which is assumed to be in https).
##
## Of course this doesn't have to be set IF the application seemlessly auto-forwards http to https accordingly.
##
[[ -e $LIB_DIR/bootstrap.bash.inc ]] && source $LIB_DIR/bootstrap.bash.inc

## in each utility script, this controller should be  sourced + functions to autoload as follows:
## ----------------- START: autoloading -----------------------
## . $HOME/etc/controller.bash.inc
##
## functions_to_autoload="
## function1
## function2
## function_n
## "
## autoload_functions "$functions_to_autoload"
## ----------------- END: autoloading -----------------------

