# Our Development Environment

# CMake

# Compiler - g++ or clang

# Setting up - Linux

# Setting up - Mac OS

## What about XCode
Most development on Mac OS is done with XCode.  Similar to the Visual Studio / Windows dynamic described below, the problem with you only using XCode is you are stuck with a Mac - you won't be able to develop anywhere else.  If you already have XCode installed, along with `g++`, then no need to remove it.  However I urge you to use VSCode and CMake to build your programs - **not the XCode user interface**.  Please remember, ultimately I can't force you to use any specific editor - I grade you on your C++ code - but you **will** need to understand CMake, you **will** need to understand how to use the commands to create project files, build executables, and launch tests.  If you learn all that, but still secretly use Xcode - I wish you all the best :)

# Setting up - Windows
The Windows operating system is *vastly* different than Linux and Mac OS - but wonderfuly capable of supporting C++ in its own right.  *However* - we will **not** use the most typical setup on Windows.

## What about Visual Studio?
You may have already done C++ development on Windows in Visual Studio.  Visual Studio should not be confused with VSCode - which is a lightweight, cross-platform code editor.  Visual Studio (proper) is a full blown Integrated Development Environment and contains Microsoft's proprietary C++ compiler.  Visual Studio is great - **however** - you need to be able to develop in a variety of environments if you want to be a professional developer.  Moreover - as you switch to different operating systems, Visual Studio is no longer an option for you - which puts you at a distinct disadvantage.  *I strongly encourage you to get comfortable with developing with CMake, clang/g++ using Cygwin on Windows - as described above.  By getting out of your comfort zone, you will learn a lot, and become a much more effective programmer.

Note - **CMake can work natively on Windows**.  CMake can also utilize Visual Studio to build C++ code, rather than `make` and `g++`, which you would normally use on Linux / Mac OS / Cygwin.  This is the beauty of CMake - it works with almost anything.  **If you already have a fully functioning Visual Studio C++ environment set up**, then feel free to install CMake directly on Windows.  You will be able to build all source code using just like in all of the rest of the examples (i.e. `cmake`).  Google will be your best friend here.  **If you have not used Visual Studio** before, don't go this route however - use Cygwin, as described above.

## But really, can I just use Visual Studio?
Go right ahead.  Just remember - you need to submit CMakeLists.txt with most of your assignments.  You **will** need to understand CMake, you **will** need to understand how to use the commands to create project files, build executables, and launch tests.  If you learn all that, but still secretly using Visual Studio - I wish you all the best :)


