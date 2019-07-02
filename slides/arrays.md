title: Arrays:  Review
---
class: center, middle, inverse
# Arrays

---
# A variable, vs. a *structure*
This course is called Data Structures - so we should start defining what that exactly is...

- A data structure is a *thing* that stores data, in which you can perform operations on.
- These operations might be something like `insert`, `remove`, `update`, `find`.
- Some data structures are more elaborate - but most offer these types of functionality.

.callout[A key principle to understand is that data structures can have different performance characterstics, depending on their design.]

An array is *barely* a data structure - it is a raw slab of memory - and the rest is up to you!

---
# What is an array?
If we want to store 5 integers, we can do so by creating 5 variables..

```cpp
int value0, value1, value2, value3, value4;
```
This might seem OK, but if these variables represent related things, you probably will want to perform operations on them **together**.

```cpp
// Add 5 to all of them
for (int i = 0; i < 5; i++ ) {
    // whoops... can't really reference the variables!
    // DON'T EVER DO THIS
    if ( i == 0 ) {
        value0 += 5;
    } else if ( i == 1 ) {
        value1 += 5;
    } ...
}
```

---
# Let's back up... what's a variable?
A variable is a **named address**.  When we create a variable, we are really defining an easier to understand label, which refers to a specific memory address.

In C++ (not all languages) a variable also has a **fixed** data type.  This is because, when declaring a variable, the compiler must know precisely how many `bytes` to research in memory, at the given address.

```c++
short  (usually 2 bytes)    float  (usually 4 bytes)
int    (usually 4 bytes)    double (usually 8 bytes)
long   (usually 8 bytes)    bool   (alway 1 byte)
char   (alway 1 byte)
```

.callout[What is significant about the number of bytes a data type occupies?  What is significant about `unsigned`?]

---
# Modern C++ data types
Programmers actually sort of hate the word "usually"

Experience tells us "usually" means "sometimes there will be bugs".
C++ offers use the `sizeof` operator to always be able to tell exactly how many bytes a data type is.

```c++
cout << sizeof(int) << endl;
```
C++ has introduced (C++11) new data types to take out the guess work, and some prefer to use them.

```cpp
int8_t      int16_t     int32_t     int64_t
uint8_t     uint16_t    uint32_t    uint64_t
```

There is no analog to this for `float` or `double`.

---
# Back to Arrays
```cpp
int value0, value1, value2, value3, value4;
```
The 5 variables created above could reside **anywhere** in memory - their addresses are (somewhat) randomly assigned.

However, when we use an array, we allocate all the variables **contiguously** - right next to each other.

```cpp
int values[5];
```
The fact that they are next to eachother unlocks some power.

If we know the `values` array starts at address `100`, then where **must** the third element reside?

---
# Indexing
An array's name is linked to an address.  Since the array's name is **also** tied to a specific data type, with a fixed size, we can use an **integer** to index into the array:

```cpp
values[2] = 10; // Set the 3rd integer to 10
```

Note, that isn't putting `10` into address `102`, it's putting 10 into address `100 + sizeof(int) * 2`

Using an integer allows us to solve our problem from earlier

```cpp
// Add 5 to all of them
for (int i = 0; i < 5; i++ ) {
    values[i] += 5;
}
```

---
# What's in an array?
When we allocate an array, the elements are present, but there is garbage in each.
```c++
int values[5];
cout << values[3] << endl; // Will print nonsense
```

Sometimes, when creating the array, we know what should be in it.
```c++
int values[5] = {32, 43, 54, 65, 76};
```
This isn't all that common in practice though...

---
# Filling an array
Arrays are usually filled *sequentially* - although not always.

.split-left[
```c++
// Fill array with values directly
for (int i = 0; i < SIZE; i++ ) {
    values[i] = i;
}
```
]
.split-right[
```c++
// Fill array with user input
int input, count = 0;
do {
    cin >> input;
    if (input != -1) {
        values[count] = input;
    }
} while (count < SIZE && input != -1);
```
]

.callout[Notice that sometime the array won't be filled - **partially** filled arrays are common]

---
# Partially filled array
.split-left[
```c++
// Fill array with user input
int input, count = 0;
do {
    cin >> input;
    if (input != -1) {
        values[count] = input;
    }
} while (count < SIZE && input != -1);
```
]

.split-right[
How would we print the elements inside `values`?

Would the following be OK?
```c++
for ( int i = 0; i < SIZE; i++) {
    cout << values[i] << endl;
}
```
]

.callout[Note, when arrays can be *partially* filled, we have a **maximum capacity** and a **current count** - and these are two *separate things*!]

---
# Partially filled array
When holding arrays in our program, there are three things we actually need to hold on to:
1. The array itself (which tells us where the array is in memory)
2. The maximum capacity of the array
3. The current count of how many elements have real data in them.

.info[This is the first crack in the array's armor... it places all the burden on you.]

---
# Overflows and unintialized
.split-left[
```c++
int values[5];
values[0] = 10;
values[1] = 15;
cout << values[2] << endl; // Uh oh
values[42] = 9;  // Really Uh Oh...
```
]
.split-right[
- We'll soon see that there are better data structures for holding lists of things.
- We will use **classes** to tie together concepts like data, bounds, and state - protecting ourselves from these issues.
]

---
# Arrays and Functions
Passing arrays to functions, as parameters, can be a bit confusing
- Declaring an array parameter uses special notation
- You **must** also pass the current `count`, otherwise the function receiving the array won't know where it ends!
- You might need to also send the maximum capacity - if the function intends on growing the array.

```c++
void foo(int values[], int count, int size);
```
If the function will change the current count, you might want to pass that variable *by reference*
```c++
void foo(int values[], int & count, int size);
```

---
# Operations on an Array
- **`int find(int values, int count, int key)`**
    return index where `key` is found in `values` with `count` elements
- **`bool append(int values, int count, int size, int value)`** Add value to the end of values, if there is room
- **`bool prepend(int values, int count, int size, int value)`** Add value to beginning of values, if there is room
- **`bool insert(int values, int count, int size, int value, int index)`** Add value at index `i`, if there is room

.callout[Let's use this for practice - we can create simple unit tests to check behavior.]

---
# Random Access
- Array support random access nicely.
- Random access means you can reference (read or write) to any (valid) element, at any time

```c++
int values[50];

values[rand()%50] = 42; // truly random!

for ( int i =0 ; i < 50; i+= 3) {  // skipping
    values[i] = 4; 
}
```

---
# Example:  Histogram
Allow the user to enter as many integers they want, but the numbers need to be between 0-99.  They can enter -1 to indicate they are done.  **Print the number of times each number was entered** (omitting numbers that were never entered).
- Create an array of size 100
- Initialize them all to 0
- for every number the user types in... call `sample(input)`
  - validate it is between 0 and 99 (inclusive)
  - increment the value stored at the element corresponding to the input
- When the user is done (-1 is entered), print out all the array indices whose value is > 0.

.callout[**Let's not forget TDD!**]
