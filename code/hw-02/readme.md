# Homework 2 - Manipulating Linked List
Extend the Linked List that we created (**not STL!**) to support the following two methods:

```
void SplitAndSwitch()  
```
This function splits the list evenly (if there are an odd number of items, make the “first half” larger) and moves the second half to the front.  For example:


Current List:		`1, 3, 6, 7, 3, 6, 4`

After calling SplitAndSwitch on the list, you should have the following:

`3, 6, 4, 1, 3, 6, 7`

```
void Reverse ()
```
Reverses the entire list. 

Current List:		`1, 3, 6, 7, 3, 6, 4`

After calling Reverse on the list, you should have the following:

`4, 6, 3, 7, 6, 3, 1`

## Requirements
You must implement the above methods as **member functions** of the linked list class we created in class.

Failure to implement them as proper member functions will receive no credit.

## Submission Requirements
I have provided you a directory structure with code files ready for use.  In `main.cpp` you may create a program to use the methods as you see fit.  In `includes/linked-list.h` you are given the linked list implementation which you must extend.    

`test.cpp` contains the set of test cases that I will use to grade your work.

**Please zip up the entire directory structure** (remove the `/build` directory, so you aren't including executables) and submit to Moodle by the submission deadline.

**You do not need to include `utils/catch.hpp` in your zip file - just the folder with the homework code.  I will provide the `catch.hpp` library.