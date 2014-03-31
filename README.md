#shcf - (Simplified) Shell Coding Framework
====

###BEFORE ANYTHING ELSE

Framework is code so that it would work wherever it is checked-out.
However, just to be sure that the framework works, do a quick check.
Go to ftest directory and run *_runall.test*.
You should see something like below if framework is not broken:

```
$ ./_runall.test

------------------------------------------------
FUNCTION TEST COMPLIANCE:

*[OK] - autoload_functions.bash.inc
*[OK] - check_mandatory_commands.bash.inc
*[OK] - decrypt_password.bash.inc
 [OK] - delitem_inarray.bash.inc
 [OK] - encrypt_password.bash.inc
 [OK] - ishost_up.bash.inc
 [OK] - mresult_sql.bash.inc
*[OK] - sqlQuery.bash.inc
 [OK] - uniq_instring.bash.inc
 [OK] - valid_ip.bash.inc

NOTE: *[OK] - means that this function is ignored/no function tests planned for the short term

-------------------------------------------------

[testing] ishost_up()     ## check if you have internet connection. If none, this test here normally fails
 scenario 1 - OK
 scenario 2 - OK
[testing] encrypt_password() and decrypt_password()
 testing only scenario - OK
[testing] uniq_instring()
 only scenario - OK
[testing] valid_ip()
 scenario 1 - OK
 scenario 2 - OK
 scenario 3 - OK
[testing] delitem_inarray()
 scenario 1 - OK
[testing] mresult_sql()
 scenario 1 - OK
```


###QUICK USAGE GUIDE

Assuming framework is OK in your system after doing the "BEFORE ANYTHING ELSE" above, you have to do the following
to get started

1. Set the location of framework first. Assuming it is in $HOME/tools/shcf, you should
   do something like:
```
    tooldir=$HOME/tools/shcf              ## set rootdir of framework
```
2. From your script, source the controller:
```
    . etc/controller.bash.inc              ## source the controller
```
3. If you have framework functions to auto-include, declare it(separating each function
   with a space). Make sure though that the functions can be found in lib. For instance,
   a function with the name "func1" should be found as lib/func1.bash.inc. Do it like:

    autoload_functions "func1 func2 func3"  ## declare functions to use

4. In summary, you should have these 3 lines now in your script:
```
    tooldir=$HOME/tools/shcf                ## set rootdir of framework
    . etc/controller.bash.inc               ## source the controller
    autoload_functions "func1 func2 func3"  ## declare functions to use
```



###INSPIRATIONS

1. **Model-View-Controller(MVC) pattern**

    I am not fully sure if I understand the MVC pattern correctly, but in my own understanding:
      * Model      - is the business logic or the "how" of this framework. It is the one that bears
                     the burden on how a specific functionality is to be carried out. In this framework,
                     you can see the 'model' inside "lib", like 'sqlQuery.bash.inc'
      * View       - is the frontliner, the one that faces the demanding customer, the end-user. Up to 
                     this point, there are no example 'view' yet but it the near future, it is the script
                     that uses this framework which can be considered as the 'view'
      * Controller - is the mediator/middle-man directing the requests of the demanding customer(via 'View')
                     to the corresponding 'model'. For instance, we have a script that does an SQL query.
                     The script(also called the 'view'), having been asked by the demanding customer to do
                     an SQL query, would look up through the 'controller' if an sql-query 'model' can be found.
                     Controller then knows how to locate such 'model'. In this framework, controller is called
                     *etc/controller.bash.inc* which should be included in every scripts that uses this framework.
                     
2. **auto-loading in PHP**

    Having seen a lot of shell scripts with functions being duplicated across scripts made me realize how
    it is a maintenance nightmare. A slight change in functionality on the main tool it is supporting would 
    mean changing a lot of scripts. So I made a roughly similar functionality in  this framework so that 
    only one function would be made and will simply be called in each script that needs it. Maintenance would 
    be easily done quickly.

    In this framework, it can be seen in *lib/autoload_functions.bash.inc* and will be called in script something
    like 
```
       ...
       autoload_functions "func1 func2 func3 etc"
       ...
```
