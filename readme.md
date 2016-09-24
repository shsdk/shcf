[![Build status](https://travis-ci.org/icasimpan/shcf.svg)](https://travis-ci.org/icasimpan/shcf)
[![Code Climate](https://codeclimate.com/github/icasimpan/shcf/badges/gpa.svg)](https://codeclimate.com/github/icasimpan/shcf)

#WHAT IS SHCF?

  It is a Shell Scripting Development Kit (ShSDK) that currently supports bash.
  ShCF gives you the ability to develop shell scripts in bash in a lightweight
  manner, meaning, you can concentrate on the core logic of your scripts, NOT
  on how you would use the framework. ShCF is learnable in an hour, provided
  you already know how to do shell scripting and programming.

  In the near future, it would even allow you to make standalone bash shell scripts.


#QUICK GUIDE:
### 1. Create new script
Create a new shcf-based shell script
```sh
  ~$ git clone https://github.com/icasimpan/shcf.git
  ~$ ./shcf/init_env.sh
  ~$ shcf_cli new hello_world
```
### 2. Add basic logic
Add basic logic, let's say the greeter() function
```sh
  ~$ shcf_cli lib hello_world greeter
```
#### 2.1. Modify greeter function file
Modify hello_world/lib/greeter.bash.inc to say 'hello world'

#### 2.2. Update main script
Update main script hello_world/bin/hello_world so it calls `greeter'
       TIP: Add it to `autoload_functions' line

### 3. For adding another script
To create additional scripts into your project, say `whoami':
```sh
  ~$ shcf_cli hello_world whoami
```

### 4. Further help
Further usage, help is available. Just run:
```sh
  ~$ shcf_cli help
```

#DETAILED USAGE GUIDE:
### 1. Clone the shcf project:
```sh
  ~$ git clone https://github.com/icasimpan/shcf.git
```

### 2. Initialize the environment
```sh
  ~$ ./shcf/init_env.sh
   Platform environment has been set. See below:
   SHCF_PLATFORM_ROOT=/home/your_username/shcf
```
 At this point, you can use `shcf_cli'(located in `./shcf/bin') from any path so long as you didn't use `exit'.

### 3. Now, create a new project. Example, `hello_world'
```sh
  ~$ ./shcf/bin/shcf_cli new your_project_dir/hello_world
```
A successful creation should be something like below:

```sh
  ~$ ./shcf/bin/shcf_cli new your_project_dir/hello_world
    template script created in your_project_dir/hello_world/bin/hello_world
    Successful creation of your_project_dir/hello_world
```
### 4. Make the template binary in `bin' executable
```sh
    ~$ chmod u+x ./your_project_dir/bin/hello_world
```
### 5. Template script is not yet ready. If you insist on running it like below:
```sh
  ~ $ ./hello_world
```

Expect to see the following error:

```sh
    /home/your_username/your_project_dir/hello_world/lib/autoload_functions.bash.inc: line 26: /home/your_username/your_project_dir/hello_world/lib/rename_function1.bash.inc: No such file or directory
    ERROR: Missing required rename_function1
    /home/your_username/your_project_dir/hello_world/lib/autoload_functions.bash.inc: line 26: /home/your_username/your_project_dir/hello_world/lib/rename_function2.bash.inc: No such file or directory
    ERROR: Missing required rename_function2
    /home/your_username/your_project_dir/hello_world/lib/autoload_functions.bash.inc: line 26: /home/your_username/your_project_dir/hello_world/lib/rename_functionX.bash.inc: No such file or directory
    ERROR: Missing required rename_functionX
```

Template `View' (see MVC pattern in `INSPIRATION' section below) included 3 functions that where meant to be replaced or removed, hence the error. To fix the problem, go to the `Model' (or `lib' directory) and create a function named 'greeter()' (as file greeter.bash.inc) with contents below:

```sh
    greeter() {
       local message=$1
       echo "$message!"
    }
```

TIP: Another approach is to create a template file using command `shcf_cli lib hello_world greeter'

In `bin/hello_world', remove the 3 template functions namely:
```sh     
    rename_function1
    rename_function2
    rename_functionX
```

and replace it with `greeter'.

Below, the comment block:

```sh
    ## ..............................
    ## main utility tool starts below
    ## ..............................
```

add the line:

```sh
    greeter "Hello, World"
```

Of course, save the file.

Rerun, again.

```sh
    ~ $ ./hello_world
```
If you followed the instructions correctly, you should see the greeting:
```sh
    ~$ ./hello_world
      Hello, World!
```

### 6. Now, if you want to add additional script to your project, that is easy. Let's assume
      you want to create `whoami'. Just run the command:
```sh
    ~$ shcf_cli bin hello_world whoami
```

Same instructions as above, put the logic, make it executable and you're on.

### 7. For other usage, help is available. Just run:
```sh
    $ shcf_cli help
```

  TODO: 
* Add how to create simple function that returns a string
* Add how to get libraries from shcf_lib


#CONTRIBUTING:
  See docs/howto_contribute.txt


#INSPIRATIONS

## 1. Model-View-Controller(MVC) pattern

I am not fully sure if I understand the MVC pattern correctly, but in my own
    understanding:
* **Model**      - is the business logic or the "how" of this framework. It is 
                   the one that bears the burden on how a specific functionality 
                   is to be carried out. In this framework, you can see the 
                   'model' inside "lib", like 'sqlQuery.bash.inc'

* **View**       - is the frontliner, the one that faces the demanding customer,
                   the end-user. Example is the script created in 'bin'

* **Controller** - is the mediator/middle-man directing the requests of the 
                   demanding customer(via 'View') to the corresponding 'model'. 
                   For instance, we have a script that does an SQL query. The
                   script(also called the 'view'), having been asked by the 
                   demanding customer to do an SQL query, would look up through 
                   the 'controller' if an sql-query 'model' can be found.
                   Controller then knows how to locate such 'model'. In this 
                   framework, controller is called etc/controller.bash.inc which
                   should be included in every scripts that uses this framework.
                     
## 2. Autoloading in PHP

Having seen a lot of shell scripts with functions being duplicated across 
    scripts made me recognize a shell maintenance nightmare. A slight change 
    in functionality on the main tool would mean changing a lot of scripts.
    So I made a roughly similar functionality in  this framework so that only
    one function would be made and will simply be called in each script that 
    needs it. Maintenance would be quickly and easy.

In this framework, it can be seen in lib/autoload_functions.bash.inc and will be called in script something like 

```sh
   autoload_functions "func1 func2 func3 etc"
```

The above way to call 'autoload_function' means that functions is directly accessible from 'lib' and NOT inside directories within 'lib'. To reference a function stored in a directory within 'lib' prefix it with the directory relative to 'lib'. For example to use sqlQuery function which is stored in 'lib/db/sql/mysql' and 'ishost_up' located in 'lib/box_mgt' you will call 'autoload_function' like

```sh
   autoload_functions "lib/db/sql/mysql/sqlQuery box_mgt/ishost_up"
```
In short, auto-loading stays relatively the same. Just prefix a function with the directory where it is stored and no directory name prefix if it is in same level as autoload_functions.bash.inc.
