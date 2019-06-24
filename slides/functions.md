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
 
---
# Counting
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
```
// Don't do this
while (true) {
    // do some stuff
    if ( stop condition) {
        break;
    }
}
```

```
// Do this
while (! stop condition) {
    // do some stuff
}
```

**The logic that controls loop iteration stay in the loop structure**.

The logic that *performs* the work of the loop stays within the loop **body**.

---
# `for` loop anti-patterns

```c++
for(; input %2 != 0;) {
    cout << "Sorry you entered an odd number, try again:";
    cin  >> input;
}
```

You've proven to the reader you know how to "hack" a `for` loop.  Congratulations, the reader of your code would prefer not to work with you any more :)

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
// What is wrong with this solution?
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
# Your mission...

Signs of a good programmer:
1. Your code works.
2. Anyone reading your code knows that it works, without running it themselves.
3. "Anyone" includes those with less mature programming skills than you.

Always read your code through the eyes of a stranger.  Would you code make sense to them?

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

---
# Parameters

---
# Pass by value

---
# Pass by reference

---
# Why pass by reference
1. To avoid memory copies!
2. To allow the function to (meaninfully) change values stored in parameters

*More on these in a moment - we don't want to do this unless it is worth it!*

---
# Parameter Anti-patterns
**Flags** - if `true` do one thing, otherwise another 

```c++
// What does true mean?
sum = compute_total(array, true)
```
Functions should do **one thing**.

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