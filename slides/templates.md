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
Let's start simple, with one of the functions we created a few weeks ago:

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
# Templates aren't just libraries
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
