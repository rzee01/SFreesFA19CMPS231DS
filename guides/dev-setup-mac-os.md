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

## What about XCode?
Much development on Mac OS is done with XCode.  Similar to Visual Studio in the Windows environment, the problem with **only** using XCode is you are **stuck with a Mac** - you won't be able to develop anywhere else.  If you already have XCode installed, along with `g++`, then no need to remove it - in fact, parts of XCode are alway used (i.e. the compiler).  However I urge you to use VSCode and CMake to build your programs - **not the XCode user interface**.  

Please remember, ultimately I can't force you to use any specific editor - I grade you on your C++ code - but you **will** need to understand CMake, you **will** need to understand how to use the commands to create project files, build executables, and launch tests.  If you learn all that, but still secretly use Xcode - I wish you all the best :)

# Installation
## Homebrew
Homebrew is command-line (terminal) software distribution system for MacOS, inspired by package managers commonly found in Linux environments.  Brew tends to be the method of choice for installing software *among developers*, so it's good to get aquainted with it if you plan on doing any software development on an Mac.

First see if you already have `brew`:
```
$ brew --version
```
If you get a `command not found` message, follow the rest of the instructions in this section to install Homebrew.  If you already have it, I recommend you execute `brew update` to ensure you have the latest version.

To install `brew`, please visit the tool's homepage:  [https://brew.sh/](https://brew.sh/).

At the time of this writing, the command to install brew is as follows:
```
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"    
```
... *however, please use the most up to date installation procedure found on the home page*

**Note:**  In the above command, the `$` appears at the beginning of the line.  YOU DO NOT TYPE THAT, it is a placeholder for the "prompt", which probably looks something like this `your_machine_name:current_directory your_username$`.

### Pre-requisites while installing
1. You **must** have Administrator access on your machine.
2. If you have not previously installed Xcode, Homebrew will install the **Xcode Command Line Tools** - which installs the `clang` compiler suite, this is normal, and perfectly fine.
3. You can accept the default options for each step in the install. **Read all directions and prompts carefully!**.

*Note that if you have already used Xcode, it's likely Homebrew will not say anything about it - this is fine*.

*If Homebrew needs to install Xcode command line tools, expect that to be a **long** step - there is a lot to download and install, and it may look like nothing is happening*.

**DO NOT INTERRUPT THE INSTALLATION PROCESS**.

## Source code acquisition - git
The next tool we will install allows you to get the course's code, it's the source code versioning control utility - `git`.  We won't make heavy use of `git` in this course, but it is **the** tool software developers use to work with source code in teams, and often even individually.  

First, check if you already have installed git.  If you type `git --version` from the terminal, and see "git version 2.17 (Apple Git-113), or **any other version**, then you may safely skip the following step.

```
$ brew install git
```

## Compiler - g++ or clang
If you installed Homebrew, it means it's almost guaranteed that you have a compiler installed on your machine at this time.  **First, check if you do**:

```
$ clang --version
```

If after typing that command, you see a printout with something like the following, **you can skip installing a compiler - you already have one!**.

```
$ clang --version
Apple LLVM version 10.0.0 (clang-1000.10.44.4)
Target: x86_64-apple-darwin17.5.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

**If you get `command not found`**, then it means you **do not** have a C++ compiler installed on your Mac.  This may be because you failed to follow the directions above (i.e. installing Homewbrew).  You can install `clang` as follows:

```
$ brew install --with-toolchain llvm
$ echo 'export PATH="/usr/local/opt/llvm/bin:$PATH"' >> ~/.bash_profile
```
Again, if those commands are not working for you - **you did not follow the Homebrew installation steps** above.

## Build tool - `make`
It is very likely you already have `make` available on your Mac, it is usually installed along with the compiler / Homebrew - so if you followed the instructions above, you are likely OK.

```
$ make
make:  *** No targets sepcified and no makfile found. Stop.
```
If you see the message above after typing `make`, there is nothing you need to do - **`make` is installed**.  If you get a `command not found` type message, then do the following:

```
$ brew install make
```

## Project build tool - `CMake`
It is unlikely you already have `CMake` installed, so please follow these instructions carefully.

First - verify you don't already have `cmake`:
```
$ cmake
-bash: cmake: command not found
```
If you get actual output, instead of the `command not found` message, then you **already have `cmake` and do not need to install it**.

Install `cmake` using the following command:
```
$ brew install cmake
```

When typing `cmake --version`, you should not see version information - not a `command not found` message.

## Code Editor - VS Code
As with all the steps above, if you already have Visual Studio Code installed, you do not need to perform any steps here.  **Please note, Visual Studio IS NOT THE SAME AS Visual Studio Code**.  Microsoft borrows the "Visual Studio" name for a lot of products.  Visual Studio Code is a lightweight code editor - and installing something else is not appropriate on a Mac (the full-blown Visual Studio does not work for C++ development on a Macm, for example).

To install Visual Studio Code:
```
$ brew cask install visual-studio-code
$ alias vscode="open -a Visual\ Studio\ Code.app"
```

After doing this, Visual Studio Code will be available in Finder (command+space, type VSCode).  It is also available on the terminal by typing `vscode`.

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





