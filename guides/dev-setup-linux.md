# Our Development Environment
Our code environment is designed to be as similar as possible on all three major operating systems - Windows, MacOS, and Linux.  It is also designed to get you more accustomed to very popular software development tools used in industry.  No matter which OS you are using, I'm going to have you working from the command line (terminal) a fair amount, and using simple file-based tools rather than large integrated devleopment environments (IDEs) like Visual Studio, XCode, and Eclipse.

Please see additional details in the course lecture slides.  Here is an outline of the tools you will need to install:

- `git` - a tool for getting code, and sharing code
- `clang` or `g++` - a C++ compiler
- `make` - a tool for invoking `clang` or `g++` to build multi-file programs.
- `cmake` - a tool for configuring your project such that you can use `make`!
-  A code editor - I'll by using VSCode (Visual Studio Code), but other alternatives would be Sublime Text, Atom, and Notepad ++ (Windows).  I do recommend VSCode however.

## Tips for setting up your environment.
I cannot stress enough how important it is, as a software developer, **to read instructions carefully**.  Too many students, and professional developers, breeze through instructions, not reading carefully, executing install steps / commands without actually reading descriptions and prompts.  **It almost always results in mistakes**, which in a professional environment are *embarrasing* - because it makes it obvious you did not care enough about setting your machine up to warrant *reading*.  It's a wonderful way to leave an awful first impression. **Please get out of that habit** - read this document carefully.

**Sometimes installs go bad - and I will help you.**  *However, if it's clear to me that you simply didn't read, I won't help - I'll just tell you to read!*.

## Which Linux Distribution?
All of the following instructions assume the following:

1. You are using Ubuntu or Linux Mint - two Debian-based distributions.
2. You are working with a relatively "fresh" install.

*None of the above assumptions are requirements*.  If you are working on a different Linux distribution, I assure you all of the same tools are quite available.  If you have been working with your Linux installation for a while, then you likely have some, if not all, of the program we will use.

If you have any problems adapting the steps below for your particular machine, please let me know and I can assist you.

**If you do not have a Linux operating system installed on your computer**, please understand that Linux is NOT required.  See the [Windows](dev-setup-windows.html) or [Mac OS](dev-setup-mac-os.html) instructions for setting up the code environment on those operating systems.  If, however, you want to start working with Linux, and need help - let me know.

# Installation

**Note:**  You **must** have `sudo` (administrator) access on your machine.

## Source code acquisition - git
The first tool we will install allows you to get the course's code, it's the source code versioning control utility - `git`.  We won't make heavy use of `git` in this course, but it is **the** tool software developers use to work with source code in teams, and often even individually.  

First, check if you already have installed git.  If you type `git --version` from the terminal, and `Command "git" not found`, then you need to install it.

```
$ sudo apt install git
```

After installing, typing `git --version` should result in somethign like `git version x.xxx`, where `x.xxx` is the exact version number.  It is not critical to have an up to date `git` install for this course.


## Compiler - g++ or clang
You may use recent versions of `g++` or `clang` in this course.  First check what you have:

```
$ clang --version
$ g++ --version
```

If both of these print messages like `Command not found`, then you need to install a C++ compiler.  If you have `clang`, I recommend you have at least version 7.1, and if you have `g++`, I recommend you have at least version 5.2

If you need to install a compiler, I'm recommending you install the Ubuntu `dev-essentials`, which will give you the most up to date (and tested) development tools for C++.  

```
$ sudo apt-get install build-essential
```

After installing `build-essential`, you will have `g++` version 7 or above - which is perfect.

*You can also install `g++` and `clang` individually if you choose - but I do not recommend this option.*

## Build tool - `make`
If you have a C++ compiler, it is likely you also have `make` - but make sure.

```
$ make
make:  *** No targets sepcified and no makfile found. Stop.
```
If you see the message above after typing `make`, there is nothing you need to do - **`make` is installed**.  If you get a `command not found` type message, then do the following:

```
$ sudo apt install make
```

## Project build tool - `CMake`
It is unlikely you already have `CMake` installed, so please follow these instructions carefully.

First - verify you don't already have `cmake`:
```
$ cmake
Command 'make' not found, ...
```
If you get actual output, instead of the `command not found` message, then you **already have `cmake` and do not need to install it**.

Install `cmake` using the following command:
```
$ sudo apt install cmake
```

When typing `cmake --version`, you should not see version information - not a `command not found` message.

## Code Editor - VS Code
There are many C++ code editors available for Linux.  Since the Windows and Mac OS instruction work with Visual Studio Code, you might find it helpful to use the same editor as the rest of the class.

Instructions for install Visual Studio Code are found here:

- [Visual Studio Code - command line installation](https://code.visualstudio.com/docs/setup/linux)
- [Main Visual Code site, with downloadable installer](https://code.visualstudio.com)

On a relatively new Ubuntu installation (18.04 or above), you can just install VSCode by entering the following:

```
$ sudo snap install --classic code
```

# Verifying your setup
Finally, you'll want to make sure everything is setup correctly.  You can do this by downloading the course repository, and building/executing the first project - `/code/01-getting-started`.

First, create a directory on your machine where you want to put most of your development work, for example, `~/projects`.

```
$ mkdir ~/projects
$ cd ~/projects
```
Then, clone the course repository
```
$ git clone https://github.com/scottfrees/cmps231.git
```
Move into the code directory, and then the first project, where you should see 3 files and a directory:
```
$ cd cmps231/code
$ cd 01-getting-started
$ ls 
CmakeLists.txt  includes  main.cpp    test.cpp
```

Build the project by creating a `build` directory, moving into it, and executing `cmake`

```
$ mkdir build
$ cd build
$ cmake ..
```
That should kick off a bit of a process, since it's the first time `cmake` might be run.  Future times you invoke `cmake` will not require as much time.  At the end, you should see a message like "Build files have been written to..."

Build the *executabe* using `make`.

```
$ make
```

Remember that `make` is what actually compiles your code - `cmake` creates files that `make` uses to know how to do this.  When updating code, you simply use `make` to recompile.  You only need to run `cmake` when you add/remove/rename source code files!

Execute your program:

```
$ ./starting
Hello directly from main...
Hello from the hello file...
2 + 3 is 5
```

Now is a good time to make a change.  Launch the code editor:

```
$ vscode .
```

That will launch Visual Studio code, with the current folder open.  Make a change to the source code (maybe add another `cout` statement to main.cpp).  Recompile with `make`, and re-run by typing `./starting` again - **you should see the effects of your changes**.

```
$ make
$ ./starting
```

# Where to put your own work
I have two recommendations:

1. Create a directory **within** the course repository, `/code/work`.  Whenever you are doing labs, assignments, etc, put your projects in the `work` directory.
2. ... or ... create a separate directory, somewhere else on your machine for your work.  Just remember that it is likely you will need to link to source code I provide you when building your projects.





