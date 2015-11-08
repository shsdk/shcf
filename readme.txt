WHAT IS SHCF?

It is a lightweight shell scripting framework which means, it interfere less with how you do the bash shell-scripting. 
In the near future, it would even allow you to make standalone bash shell script...


USAGE GUIDE:
  ~$ git clone https://github.com/icasimpan/shcf.git
  ~$ ./shcf/bin/shcf_init new your_project_dir/hello_world
  
  TODO: 
    * Add how to create simple function
    * Add how to get libraries from shcf_lib
  
CONTRIBUTING:
  See docs/howto_contribute.txt

INSPIRATIONS

1. Model-View-Controller(MVC) pattern

    I am not fully sure if I understand the MVC pattern correctly, but in my own understanding:
      * Model      - is the business logic or the "how" of this framework. It is the one that bears
                     the burden on how a specific functionality is to be carried out. In this framework,
                     you can see the 'model' inside "lib", like 'sqlQuery.bash.inc'
      * View       - is the frontliner, the one that faces the demanding customer, the end-user. Example
	             is the script created in 'bin'
      * Controller - is the mediator/middle-man directing the requests of the demanding customer(via 'View')
                     to the corresponding 'model'. For instance, we have a script that does an SQL query.
                     The script(also called the 'view'), having been asked by the demanding customer to do
                     an SQL query, would look up through the 'controller' if an sql-query 'model' can be found.
                     Controller then knows how to locate such 'model'. In this framework, controller is called
                     etc/controller.bash.inc which should be included in every scripts that uses this framework.
                     
2. auto-loading in PHP

    Having seen a lot of shell scripts with functions being duplicated across scripts made me realize how
    it is a maintenance nightmare. A slight change in functionality on the main tool it is supporting would 
    mean changing a lot of scripts. So I made a roughly similar functionality in  this framework so that 
    only one function would be made and will simply be called in each script that needs it. Maintenance would 
    be easily done quickly.

    In this framework, it can be seen in *lib/autoload_functions.bash.inc* and will be called in script something
    like 

       autoload_functions "func1 func2 func3 etc"


    The above way to call 'autoload_function' means that functions is directly accessible from 'lib' and NOT inside 
    directories within 'lib'. To reference a function stored in a directory within 'lib' prefix it with the directory 
    relative to 'lib'. For example to use sqlQuery function which is stored in 'lib/db/sql/mysql' and 'ishost_up'
    located in 'lib/box_mgt' you will call 'autoload_function' like

       autoload_functions "lib/db/sql/mysql/sqlQuery box_mgt/ishost_up"

    In short, calling stays relatively the same, only that you have to prefix each function with directory name in which 
    it is stored
