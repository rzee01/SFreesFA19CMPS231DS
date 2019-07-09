title: Templates:  Review
---
class: center, middle, inverse
# Templates
A Review

---
# Useful data structures?

.split-left[
- We have built `ArrayList`, `Queue`, `Stack`, and `Deque`
- Unfortunately they only work with integers!
]

.split-right[
.callout[What about floats, doubles, strings, objects!]
]



---
# **Answer:**  Templates
Thankfully C++ has *templates*, which allow us to write generic containers (and algorithms) that can support *arbitrary* data types.

- They won't work for everything..
- **For example**:  Could we support floats with `Histogram`?

--
.info[Templates are the answer when there is a set of types that support the **operations** the data structure or algorithm uses]

---
# Template functions
Let's start simple, with a function we created a few weeks ago:

```c++
const int ASCENDING = 1;
const int DESCENDING = -1;
const int EQUAL = 0;
const int NO_ORDER = 42;

int classify(int, int, int);
```

.callout[What operations does a data type need to support for our classify function to work with it?]

---
# Template functions
We used `==`, `<=`, and `>=` to implement classify:
 - `int`, `short`, `long`
 - `char`, `double`, `float`


```c++
// Note the int data type can still be used for the constants, 
// these are return values, not actual data!
const int ASCENDING = 1;
const int DESCENDING = -1;
const int EQUAL = 0;
const int NO_ORDER = 42;

template<typename T>
int classify(T, T, T);
```

---
# What about Rationals?
Now we see a few C++ topics starting to converge
- Templates only work if the underlying type supports the operators the code expects.
- Our new types, such as `Rational` **should** be able to be used by the `classify` function.
- C++ `overloading` allows us to give a power up to our class - allowing it to be used in templated functions!

.callout[As long as we overload the `==`, `<=`, and `>=` operators, we'll be good to go!]

Let's look at some code...

---
# Adding more files to CMake
```cmake
cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

project (classify-rational)

enable_testing()
add_test( Tests testing)

include_directories(./includes)
include_directories(../utils)

add_library(classify includes/classify.cpp)  // Each code file is a library
add_library(rational includes/rational.cpp)  // we can add as many as we need.

add_executable(classify-ui main.cpp)
target_link_libraries(classify-ui classify)
target_link_libraries(classify-ui rational)

# Add another executable for testing
add_executable(testing test.cpp)
target_link_libraries(testing classify)
target_link_libraries(testing rational)
```

---
# Overloading Rational
If you are going to support *some* comparison operators, it is good practice to **support them all**

```c++
// Non-member functions
bool operator < (const Rational & r1, const Rational &r2);
bool operator <= (const Rational & r1, const Rational &r2);
bool operator > (const Rational & r1, const Rational &r2);
bool operator >= (const Rational & r1, const Rational &r2);
bool operator == (const Rational & r1, const Rational &r2);
bool operator != (const Rational & r1, const Rational &r2);
```
Typically, I like to keep overload functions very short - any complexity should be in basic member functions
```c++
// New member functions
int compareTo(const Rational & other) const;
bool equals(const Rational & other) const;
```

---
# CMake... fails
```bash
CMakeFiles/testing.dir/test.cpp.o: In function `____C_A_T_C_H____T_E_S_T____0()':
test.cpp:(.text+0x27105): undefined reference to `int classify<int>(int, int, int)'
test.cpp:(.text+0x2722d): undefined reference to `int classify<int>(int, int, int)'
test.cpp:(.text+0x27355): undefined reference to `int classify<int>(int, int, int)'
CMakeFiles/testing.dir/test.cpp.o: In function `____C_A_T_C_H____T_E_S_T____2()':
test.cpp:(.text+0x27655): undefined reference to `int classify<int>(int, int, int)'
test.cpp:(.text+0x2777d): undefined reference to `int classify<int>(int, int, int)'
CMakeFiles/testing.dir/test.cpp.o:test.cpp:(.text+0x278a5): more undefined references to `int classify<int>(int, int, int)' follow
CMakeFiles/testing.dir/test.cpp.o: In function `____C_A_T_C_H____T_E_S_T____8()':
test.cpp:(.text+0x286ce): undefined reference to `int classify<Rational>(Rational, Rational, Rational)'
test.cpp:(.text+0x28802): undefined reference to `int classify<Rational>(Rational, Rational, Rational)'
test.cpp:(.text+0x28936): undefined reference to `int classify<Rational>(Rational, Rational, Rational)'
test.cpp:(.text+0x28a6a): undefined reference to `int classify<Rational>(Rational, Rational, Rational)'
collect2: error: ld returned 1 exit status
CMakeFiles/testing.dir/build.make:96: recipe for target 'testing' failed
make[2]: *** [testing] Error 1
CMakeFiles/Makefile2:180: recipe for target 'CMakeFiles/testing.dir/all' failed
make[1]: *** [CMakeFiles/testing.dir/all] Error 2
Makefile:94: recipe for target 'all' failed
make: *** [all] Error 2
```

---
# Templates aren't libraries
Recall that templates are never part of an executable... the compiler uses them to **generate** new code, for the particular data type you use the template with.

This means the compiler needs to understand a bit more, and the linking step needs to be a bit more sophisticated...

1. We implement templates in **headers** only.
2. We do not need to refer to them as libraries.

---
# Corrected CMakelist.txt
```cmake
cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

# This names our project
project (classify-rational)

enable_testing()
add_test( Tests testing)

include_directories(./includes)
include_directories(../utils)

add_executable(classify-ui main.cpp)

add_executable(testing test.cpp)
```
.callout[Happily, this is actually a lot simpler than our initial try!]

---
# Designing good templates
Our header only implementation works nicely, and we are able to classify the order of `Rational` numbers.
- One thing to notice is that our parameters are passed **by value**.
- For `ints` and other primitives, this makes perfect sense.
- ... But for `Rational`, it's not so clear cut.

--
.callout[Do we really want to copy numerator and denominator?]

--
.callout[What about even more complex objects,  that hold even more data?]

---
# Prefer pass-by-reference
If you look at most templates, **pass by reference** is heavily used.
- This is **not** because the template wants to change the value of the parameter.
- It is because the template does not want to **assume** that the parameters can be copied cheaply.

```c++
template<typename T>
int classify(const T & a, const T &b, const T &c){
    ...
}
```
.callout[**Important**:  the use of `const` is valuable - because once you've changed to pass-by-reference, you open yourself up to bugs and confusion.  `const` allows the compiler to verify that the contents of the variables to not change.]


---
# Templates for Containers
We should be able to hold lists of `Rational` numbers!

```cpp
#include <stdexcept>
// Don't write "using namespace std" in template headers

template <typename T>
class ArrayList
{
public:
    ArrayList();
    void prepend(T value);
    void append(T value);
    T get(int index) const;                // Note, not every int turned to T
    int find(T value) const;               // Indexes are ints no matter what
    int length() const;                    // type of data is in the array!
    static const int CAPACITY = 100;

private:
    T data[ArrayList::CAPACITY];
    int count;
};
```

---
# Multiple types in an list?
**Nope**, templates don't let you do that (unless you apply more complex techniques).

- `T` is a variable, resolved **at compile time**.
- `T` can only be one thing at a time, for a given template code unit.

--
- When defining a method that accepts a list of things of type `T`, everything in the list *must* be of type T. 
- When defining a class that holds multiple things of type `T`, the instance of the class can only hold type `T`!

.callout[
There is nothing stopping you from creating multiple `ArrayLists` with different types for `T` though:
] 
```cpp
ArrayList<int> intList;             // OK
ArrayList<float> floatList;         // OK 
ArrayList<Rational> rationalList;   // OK
intList.append(Rational(1,3));      // Compiler error - type mismatch
```

---
# More abilities...
Let's override the `[]` operator to allow indexing...

```cpp
template <typename T>
class ArrayList
{
public:
    ...
    T get(int index) const;
    ...
    T & operator[] (const int);   // < new overload
};
```
- Why are we returning using reference?
--

- Can we just implement this by calling `get`?
 - There are pros/cons to re-using get.  We'd need to drop the `const` and make it a proper `l-value`
 - An `l-value` is an expression that can appear on the left side of `=` assignment.  By definition, something which is const cannot!

---
# Now we've got something...!
- We have a re-usable ArrayList
- We can use it with any data type that supports relational operators
- Now it's worth refining it, adding lots of features - because it's not a "one off" solution!

.callout[
- C++ includes a **Standard Template Library** (STL), which provides us with *many* data structures and algorithms.
- It's called STL because in order to make them useful, the must all be template functions/classes!
]

---
# Why this class is not over.
You are probably thinking... so this class is now just about learning STL?
--
.callout[
- **No!**, if you call yourself a computer scientist, you need to understand how classic data structures and algorithms actually work.
 - ... so you know which to use, for the problems you need to solve
 - ... so you can *apply* the knowledge in domains where the STL won't help you
]
--

- Throughout the rest of the semester, we will follow a pattern:
 1. We will learn how to create a simple implementation of a classic data structure or algorithm.
 2. Once we've got it, we'll switch to studying the STL implementation - which will be more sophisticated.
 3. Repeat for the next data structure of algorithm.
