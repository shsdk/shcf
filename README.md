[![basher install](https://www.basher.it/assets/logo/basher_install.svg)](https://www.basher.it/package/)
[![rpm](https://img.shields.io/badge/rpm-packagecloud.io-844fec.svg)](https://packagecloud.io/app/icasimpan/shcf/search?q=rpm)
[![deb](https://img.shields.io/badge/deb-packagecloud.io-844fec.svg)](https://packagecloud.io/app/icasimpan/shcf/search?q=deb)

# WHAT IS SHCF?

  It is a Shell Scripting Development Kit (ShSDK) that currently supports bash.
  ShCF helps you develop bash shell scripts in a lightweight manner.
  This means that you can focus on the core logic of your scripts, NOT on how you use the framework.

  ShCF is learnable in an hour or less, provided you already know how to do shell scripting and programming.

  In the near future, it would even allow you to make standalone bash shell scripts.

# BASHER USERS:

Install shcf as follows:
```
~$ basher install github.com/shsdk/shcf
~$ shcf_init.sh
```
Then read the quick guide except the git clone part which is already done by `basher`

# QUICK GUIDE:
### 1. Create new script
Create a new shcf-based shell script
```sh
  ~$ git clone https://github.com/shsdk/shcf.git
  ~$ ./shcf/init.sh
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
  ~$ shcf_cli bin hello_world whoami
```

### 4. Further help
Further usage, help is available. Just run:
```sh
  ~$ shcf_cli help
```

# DETAILED USAGE GUIDE:
### 1. Clone the shcf project:
```sh
  ~$ git clone https://github.com/shsdk/shcf.git
```

### 2. Initialize the environment
```sh
  ~$ ./init.sh
   Platform environment has been set. See below:
   SHCF_PLATFORM_ROOT=/home/your_username/shcf/core
```
 At this point, you can use `shcf_cli` from any path.

### 3. Now, create a new project. Example, `hello_world`
```sh
  ~$ shcf_cli new your_project_dir/hello_world
```
A successful creation should be something like below:

```sh
  ~$ shcf_cli new your_project_dir/hello_world
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

TIP: Another approach is to create a template file using command `shcf_cli lib hello_world greeter`

In `bin/hello_world`, remove the 3 template functions namely:
```sh     
    rename_function1
    rename_function2
    rename_functionX
```

and replace it with `greeter`.

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
    ~$ ./hello_world
```
If you followed the instructions correctly, you should see the greeting:
```sh
    ~$ ./hello_world
      Hello, World!
```

### 6. Now, if you want to add additional script to your project, that is easy. Let's assume
      you want to create `whoami`. Just run the command:
```sh
    ~$ shcf_cli bin hello_world whoami
```

Same instructions as above, put the logic, make it executable and you're on.

### 7. For other usage, help is available. Just run:
```sh
    ~$ shcf_cli help
```

# Standalone Script

*NOTE: This is still an early version and might not work fully*

If you need a standalone version of an shcf-based script, use the following:
```sh
    ~$ shcf_cli spawn hello_world hello_world
```
This assumes that your project is named `hello_world` and the main script to access it is `hello_world`

# PACKAGE BUILDS:

For people who are more comfortable with the usual package installation, SHCF is now available 
for the two major Linux packages: rpm and deb.

To install rpm, run the following:
```
curl -s https://packagecloud.io/install/repositories/icasimpan/shcf/script.rpm.sh | sudo bash
```

For deb installation, run:
```
~$ curl -s https://packagecloud.io/install/repositories/icasimpan/shcf/script.deb.sh | sudo bash
```

Package hosting generously provided by Package Cloud. Visit https://packagecloud.io for details.
 

# CONTRIBUTING:
  See docs/howto_contribute.txt

# INSPIRATIONS

## 1. Model-View-Controller(MVC) pattern
   
|What           | Brief Description                                                                                        | Framework Implementation     |
|---------------|----------------------------------------------------------------------------------------------------------|------------------------------|
|**Model**      |Business logic or the "how". Does the heavy lifting on how specific functionality is carried out.         |`lib` (e.g sqlQuery.bash.inc) |
|**View**       |The frontliner, the one that faces the demanding customer, the end-user.                                  | scripts created in `bin`     |
|**Controller** |Mediator/middle-man directing the requests of the demanding customer(via 'View') to corresponding 'model'.|`etc/controller.bash.inc`     |

## 2. Autoloading in PHP

I've seen a lot of shell scripts and coded a lot myself. As the code grows, so does the maintenance nightmare.
Function duplication is one such headache that needs to be addressed.

In this framework, it can be seen in lib/autoload_functions.bash.inc and will be called in script something like 

```sh
   autoload_functions "func1 func2 func3 etc"
```

The above way to call 'autoload_function' means that functions is directly accessible from 'lib' and NOT in subdirectories.

Autoloading is very flexible and you can re-arrange libraries as you see fit. For example to use sqlQuery function which is stored in 'lib/db/sql/mysql' and 'ishost_up' located in 'lib/box_mgt' you will call 'autoload_function' like

```sh
   autoload_functions "lib/db/sql/mysql/sqlQuery box_mgt/ishost_up"
```
In short, auto-loading stays relatively the same. Just prefix a function with the directory where it is stored and no directory name prefix if it is in same level as autoload_functions.bash.inc.

## 3. Drupal concept of custom and contrib modules

As you may have noticed by now, Auto-loading is very flexible. But my high-level experience of drupal clarified how auto-loading should be done right.
Libraries that is specific to your script MUST be created inside `lib/custom` while those that are reusable and comes from external sources (e.g. https://github.com/shsdk/shcf-lib) should be in `lib/contrib`.

This concept is not yet enforced in the ShCF but will be in the near future.
