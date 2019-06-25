title: Selection, Loops, and Functions:  Review
---
class: center, middle, inverse
# Review of Selection, Loops, and Functions

---
# Selection
- `if`, `else if`, `else`
- `switch`
- `y = x % 2 == 0 ? 8 : 9; // ternary operator`

1. Do you always need `else`?
2. What types of selections lend themselves to `switch` statements?
3. What do you think of the ternary operator?

---
# Formatting

Many hours have been wasted arguing about indentation and curly brace placement...

In the end **I don't care** - but pick one style.

```c++
// This is fine.
if (x == 4 ) {  
    cout << "This is four" << endl;
} else if ( x == 5) {
    cout << "This is five" << endl;
} else {
    cout << "I don't know what x is" << endl;
}
```

---
# Formatting

Many hours have been wasted arguing about indentation and curly brace placement...

In the end **I don't care** - but pick one style.

```c++
// This is fine too.
if (x == 4 ) {  
    cout << "This is four" << endl;
} 
else if ( x == 5) {
    cout << "This is five" << endl;
} 
else {
    cout << "I don't know what x is" << endl;
}
```

---
# Formatting

Many hours have been wasted arguing about indentation and curly brace placement...

In the end **I don't care** - but pick one style.

```c++
// ... also fine
if (x == 4 ) 
{  
    cout << "This is four" << endl;
} 
else if ( x == 5) 
{
    cout << "This is five" << endl;
} 
else 
{
    cout << "I don't know what x is" << endl;
}
```

---
# Formatting

Many hours have been wasted arguing about indentation and curly brace placement...

In the end **I don't care** - but pick one style.

```c++
// Don't tempt fate... leaving out curly braces opens you up to LOTS of errors
if (x == 4 ) 
    cout << "This is four" << endl;
else if ( x == 5) 
    cout << "This is five" << endl;
else 
    cout << "I don't know what x is" << endl;
```
*No bonus points are ever awarded for eliminating simple line numbers.  Spacing, consistency, and safety are your friends.*



---
# Formatting - Anti-patterns

I will return your work ungraded if I see this...

```c++
if (x == 4 ) 
cout << "This is four" << endl;
else if ( x == 5) 
cout << "This is five" << endl;
else 
cout << "I don't know what x is" << endl;
```

---
# Formatting - Anti-patterns

I will return your work ungraded if I see this... **or this**

```c++
if (x == 4 ) {
cout << "This is four" << endl;
}
else if ( x == 5) {
    cout << "This is five" << endl;}
else 
{
cout << "I don't know what x is" << endl;
}
```
**Indentation must be consistent**.

**Indentation is NOT optional**.

---
# Formatting - Anti-patterns

I am not a fan of tiny indentation...

```c++
if (x == 4 ) {
 cout << "This is four" << endl;
}
else if ( x == 5) {
 cout << "This is five" << endl;
}
else {
 cout << "I don't know what x is" << endl;
}
```
The entire point of indentation is to allow the reader's eye to understand structure, quickly.  Miniscule indentation just slows the reading process down.

---
# Logic - Anti-patterns

```c++
// Don't do this...
if ( x == 5) {
    if (y == 8) {
        cout << "X and Y are what I thought" << endl;
    }
}
```

```c++
// Do this...
if ( x == 5 && y == 8) {
    cout << "X and Y are what I thought" << endl;
}
```

---
# Logic - Anti-patterns

```c++
// Don't do this...
int z = 10;
if ( x == 5) {
    y = x + 5;
    z = 7;
    cout << y << z << endl;
} else {
    y = x + 5;
    cout << y << z << endl;
}
```

```c++
// Do this...
int z = 10;
y = x + 5;

if ( x == 5) {
    z = 7;   // Only statement unique to the condition belong in the if statement
} 
cout << y << z << endl;

```

---
# Practice
Let's write a program that asks the user to enter three numbers:
1. If the numbers are in ascending order, print the word "Ascending".
2. If the numbers are in descending order, print the word "Descending".
3. If the numbers are equal to each other, print the work "Equal".

*Let's think of some hypothetical test cases for this program...*

---
# Loops
- There are three types of loops in C++
 - `while`
 - `do` ... `while`
 - `for`

 Don't fall in love with either - they are each valuable, in specific contexts.

 To use the correct loop in the correct situation, you must understand your **stop** condition.

---
# Conditional Loops
- Ask the user for an even number:  
 - Will they type an odd number at all?  
 - Will they type 16 odd numbers before reading the prompt carefully?
 
- What is the **minimum** number of times you need to ask the user for input?

--

**Pre-Test** condition loops test before entering the loop the first time
```c++
while (should I do this?) {
    doThis();
}
```

--
**Post-Test** condition loops enter the loop, and then check to see if the body should be repeated.
```c++
do {
    doThis();
} while(should I still do this?);
```

---
# Counting Loops
- Do something `10` times.
- Do something `x` times.
- Do something for each of the items in this list.

**Each of these scenarios** have one thing in common - you can easily express the end condition by either:
1. The number of times through the loop
2. ...or a specific end and stop number, while iterating through what is in between.

Use for `for` loops for counting - not conditionals.

---
# `for` loop anti-patterns
- Don't count backwards unless you need to.
- Don't skip numbers unless there is a real need to.
- Don't stuff multiple variables into the same loop.

**Separate ITERATION control from LOGIC**
```c++
// Don't do this:
for (int x = 0; y = 3; z = 9; x < 10; x++; y--) {
    cout << x << y << z << endl;
}

// Do this.
int y = 3; z = 9;
for ( int x = 0; x < 10; x++ ) {
    cout << x << y << z << endl;
    y--;
}
```
*I don't even think the first example works, and I don't really want to know...*

---
# Stopping the loop

```c++
// Don't do this
while (true) {
    // do some stuff
    if ( stop condition) {
        break;
    }
}
```

```c++
// Do this
while (! stop condition) {
    // do some stuff
}
```

**The logic that controls loop iteration stay in the loop structure**.

The logic that *performs* the work of the loop stays within the loop **body**.

---

# `break` and `continue`

The `break` and `continue` keywords are tricky
- There are some valid, and reasonable uses for them
- Most of the time, they aren't the best choice
- They **obscure the behavior of the loop** to the reader

Stay away from `break` and `continue` in loops, unless the alternative would be even harder to understand, **and comment clearly**.



---
# `for` loop anti-patterns

```c++
for(; input %2 != 0;) {
    cout << "Sorry you entered an odd number, try again:";
    cin  >> input;
}
```

You've proven to the reader you know how to "hack" a `for` loop.  

Congratulations, the reader of your code would prefer not to work with you any more :)

---
# Early exit pattern
There are some problems that require you to *search*.
- For the numbers `73` - `5982`, are there any values divisible by both 19 and 73?

```c++
// What is wrong with this solution?
for (int i = 73; i <= 5982; i++) {
    if ( i % 19 == 0 && i % 73 == 0) {
        cout << "Yes! " << i << "is!" << endl;
        return 0;
    }
    else {
        cout << "Nope - couldn't find any" << endl;
        return 0;
    }
}
```

---
# Early exit pattern
There are some problems that require you to *search*.
- For the numbers `73` - `5982`, are there any values divisible by both 19 and 73?

```c++
// Learn to recognize the early exit pattern!
for (int i = 73; i <= 5982; i++) {
    if ( i % 19 == 0 && i % 73 == 0) {
        cout << "Yes! " << i << "is!" << endl;
        return 0;
    } // else... nothing - we haven't proven anything!
}
// Now we've exhausted all the possible values, we know there are none.
cout << "Nope - couldn't find any" << endl;
```

---
# Practice:  Prime Numbers
- Ask the user to enter a *positive* number (N).
- Write a program that outputs the first (N) prime numbers
- Format the output as a table

<img style="padding-top:1em;" src="../images/prime-table.png"/>

---
# Your mission...

Signs of a good programmer:
1. Your code works.
2. Anyone reading your code knows that it works, without running it themselves.
3. "Anyone" includes those with less mature programming skills than you.

Always read your code through the eyes of a stranger.  **Would your code make sense to them?**

**Disclaimer**:  Sometimes your code could contain *necessary* advanced syntax - that is OK.  However, always use the simplest correct solution possible.

---
# Why functions?
--

- **Code Reuse:**
    - DRY - **D**o **N**ot **R**epeat **Y**ourself!
    - Less code == Less bugs
    - Less code == Less maintenance
- **Abstraction:**
    - Our code is easier to understand in layers
    - If we name functions well, we don't need the details to understand what they do!

---
# Return Values
Functions must declare the type of data they will return.
- If your function need not return anything, use `void`.
- Choose your data types carefully!
- If you don't know what the return type is, then you don't know why you are writing the function.  **STOP**.

.callout[Your function should always have a clear, single purpose.]

---
# Parameters
Functions typically need to be passed data in order to do their job.
- Parameters should be well named, and again have a very clear purpose.
- You can have any number of parameters you wish (but try to keep the number to 3 or less)
- You must choose data types for your parameters - see last slide :)

---
# Pass by value
Let's trace the call stack, and associated **stack frames** through the following program:

```c++
#include <cmath>

int foo(int x, int y) {
    int z = x
    int x = min(x, y);
    int y = max(z, y);
    int w = (y / x ) + z;
    return w;
}

int main() {
    int x = 5;
    int y = 10;
    int z = 1;

    int w = foo(y, z);
    int s = foo(x, w);

    cout << x << y << z << w << s << endl;
}
```

---
# Sidebar:  Call Stack?
Whenever a function is called, it's **local variables**, parameters, are **allocated** on a slab of memory called the **stack frame**.

The **stack frame** is a fixed size, known at compile time.

The stack frame is placed at on top of the **call stack**.

The compiler generates code such that when a `return` statement is executed:
1. The value you return is saved wherever the caller has assigned it.
2. The entire **stack frame** associated with the function is deleted.

.callout[This is what facilitates automatic memory management of local variables]

---
# Practice:  Primes
How could we improve our prime number program from earlier using functions?
- `isPrime` function to return whether a given number is prime
- Leveral early exit pattern to avoid the use of `continue` and `break`
- Use functions to reduce complexity of the code
- Use functions to increase *testability* too... as we will see.

---
# Pass by reference
Pass by reference allow us to make changes *to the underlying* variable passed to a function.
```c++
#include <cmath>

int foo(int & a, int & b) {
    int d = a
    int a = min(a, y);
    int b = max(z, b);
    int e = (b / a ) + d;
    return e;
}

int main() {
    int x = 5;
    int y = 10;
    int z = 1;

    int w = foo(y, z);
    int s = foo(x, w);

    cout << x << y << z << w << s << endl;
}
```

---
# Take-aways
- The difference between pass-by-value and pass-by-reference is **subtle**, especially to the *caller*.
- The **names of variables** have absolutely no bearing on whether the underlying storage is shared between functions!

.callout[You will not master programming until you have a clear mental model of how the memory allocation of variables works!]

---
# Why pass by reference?
1. To avoid memory copies!
2. To allow the function to (meaningfully) change values stored in parameters

.callout[Pass by reference should NEVER be abused, or overused.  It is inherently confusing - and should only be used as necessary.]

.info[**The example on the previous slide is a HORRIBLE use of pass by reference and variable naming!**]
---
# Parameter Anti-patterns
**Flags** - if `true` do one thing, otherwise another 

```c++
// What does true mean?
sum = compute_total(array, true)
```
Functions should do **one thing**.

It should be very clear what that "one" thing is, by the name of your function.

---
# Abtraction Anti-patterns
Functions should do one thing...

```c++
int compute_sum_and_remove_evens(array)
```
This clearly does too things... why is this so bad?

---
# Pure Functions
- Functions should produce a single, well defined output.
- Functions should not have side effects

.callout[Code with pure functions is easier to read and maintain.  It should be your goal to make as many of your functions pure as possible.]

--

*But wait... what about pass by reference?*

---
# Functions w/ Side Effects
Sometimes we need side effects.  Often there are ways to make our functions pure using more complex language features, but sometimes there aren't...

```c++
int x, y, z
cin >> x >> y >> z;
sort(x, y, z);
cout << x << y << z;
```

This function sorts three numbers - it moves the values around to ensure
that the values stored in x, y, and z are in ascending order.

Before moving on - is there any way to do this without side effects?

---
# Side effects or not?
We always want to be clear about the effects of calling a function.
- The caller should never wonder what will happen
- The caller will not like you if you hide effects in documentation!
- Naming your functions well helps here...

```c++
int x, y, z
cin >> x >> y >> z;
sort_in_place(x, y, z);  // Now it's a whole lot clearer...
cout << x << y << z;
```

We will soon learn how C++ syntax can help the compiler highlight which functions can have side effects and which cannot as well.

---
# Function Prototypes
Our final point about functions is how to separate their **declartion** from their **definition**.

- **Function declaration**:  Things to compiler needs to know, to judge whether your code call the function correctly
 - The function's name, type of data returned, types of the parameters, and the number of parameters.

 ```c++
 double foo(double x, double y) {
     // The compiler does not care about
     // what your function DOES...
 }

 int main() {
     double x = foo('c', 16.4); // The compiler knows you messed up.
     int y = foo(15.3, 23.4); // The compiler suspects you may have messed up
     double z = foobar(10.2, 10.3); // The compiler knows you messed up.
     double w = foo(10, 5);  // The compiler knows this is OK
 }
```

---
# Function Prototypes
- Often, we wish to include the functions we use *after* `main`.  
- A compiler "compiles" code starting from the top of a file - so the following doesn't work.

```c++
 int main() {
     double x = foo('c', 16.4);     // The compiler doesn't know anything 
     int y = foo(15.3, 23.4);       // about foo.  So it throws an error
     double z = foobar(10.2, 10.3); // Foo is just as much as a 
     double w = foo(10, 5);         // mystery as foobar.
 }

 double foo(double x, double y) {
     // The compiler does not care about
     // what your function DOES...
 }
```

---
# Function Prototypes
- A function prototype is the **declaration**, without the body (definition)

```c++

 // Prototype
 double foo(double x, double y);

 int main() {
     double x = foo('c', 16.4);     // Now the compile can evaluate 
     int y = foo(15.3, 23.4);       // your usage of 'foo', without
     double z = foobar(10.2, 10.3); // knowing it's full definition.
     double w = foo(10, 5);         
 }

 double foo(double x, double y) {
     // The compiler does not care about
     // what your function DOES...
 }
```

---
# Compiling and Linking
Function prototype have a lot to do with how executables with multiple files are built.
- **main.cpp** - includes `foo.h`
- **foo.h** - contains prototype for `foo` function
- **foo.cpp** - contains definition for `foo` function

A compiler "compiles" each source code file (.cpp) **independently**.  

`main.cpp` can be compiled simply by referencing the prototype found in `foo.h`.

`foo.cpp` can be compiled without any include file at all!

A linker takes the output of each compiled source file (object files), and makes sure that all the symbols referenced in all the object files are resolved.  It then creates a single **executable** with all the symbols and definitions.

---
# One last benefit of functions
By dividing our programs into **functional units**, we can begin to **test** those **units**.
- Did our sort classifier (ascending, descending, equal) really work?
- Did our prime number program really work?

A core part of modern programming is automated **unit tests**, which consist of code specifically written to make test cases clear, repeatable, and quickly testable.  Proper function design is at the heart of unit testing.

.callout[Up next... unit testing with `catch.hpp`]