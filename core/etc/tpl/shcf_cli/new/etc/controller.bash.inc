## =================================================================================================================
## FILENAME: controller.bash.inc
## PURPOSE : controller (mediator) script between the models(individual functions) and view(each individual scripts)
## =================================================================================================================

TOOL_ROOTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../ && pwd )"
LIB_DIR=$TOOL_ROOTDIR/lib
CONF_DIR=$TOOL_ROOTDIR/etc
LOG_DIR=$TOOL_ROOTDIR/log
TMP_DIR=$TOOL_ROOTDIR/tmp
VENDOR_DIR=$TOOL_ROOTDIR/vendor                                     ## for vendor, aka 3rdparty
TEMPLATE_DIR=$CONF_DIR/tpl
[[ -e $CONF_DIR/app_paths.conf ]] && . $CONF_DIR/app_paths.conf     # application specific paths

. $CONF_DIR/init.conf
. $LIB_DIR/autoload_functions.bash.inc

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

