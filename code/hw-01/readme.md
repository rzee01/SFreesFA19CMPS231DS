# Homework 1 - Stacks and Queues
Write a main program that accepts 2 strings from the user.  Implement (and call) a function that accepts two strings, and returns **true or false**, based on whether the two strings are **mirrors** - as in, string (1) is the same as string (2) read in reverse. 

 Ignore white space and punctuation, and ignore case

**For example**:
- `"abc def"` and `"f eDC ba"` would be **true**
- `aba` and `bab` would be **false**.

*Note - this has nothing to do with palindromes :)*.

## Requirements
Your function (`mirrors`) must use one (STL) stack and one (STL) queue to determine whether or not the two strings are mirror images of each other. 

The general algorithm should be as follows:
- **Step 1**:  For string 1, place each character in a queue
- **Step 2**:  For String 2, place each character in a stack
- **Step 3**:  Loop until both the stack and queue are empty - pop and dequeue one character at a time.  If the characters popped and dequeued don’t match, or if the stack becomes empty before the queue (or vice versa), then the strings are not mirror images.

**Failure to use a stack and queue as explained above will result in zero credit -** the purpose of this exercise is to gain experience with the STL queue and stack.

## Submission Requirements
I have provided you a directory structure with code files ready for use.  In `main.cpp` you should write your program that accepts two strings from the user, and calls `mirrors`.  In `includes/mirror.h` and `includes/mirror.cpp` you should add your implementation of the mirror fucntion.  `test.cpp` contains the set of test cases that I will use to grade your work.

**Please zip up the entire directory structure** (remove the `/build` directory, so you aren't including executables) and submit to Moodle by the submission deadline.

**You do not need to include `utils/catch.hpp` in your zip file - just the folder with the homework code.  I will provide the `catch.hpp` library.