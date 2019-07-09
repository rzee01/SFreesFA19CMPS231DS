title: STL Sequence Containers
---
class: center, middle, inverse
# STL Sequence Containers
Containers and Iterators

---
# Sequence Containers
Sequence containers are data structures which hold data that holds **ordered** sequences of data.

The different containers have different characteristics - some of which we have already discovered:
- `array` - a statically allocated, contiguous array with bounds checking.
- `vector` - a dynamically allocated, contiguous array with bounds checking.
- `deque` - a double ended queue, contiguously allocated.

.callout[
There are two others: `forward_list` and `list`, which we will look at soon.  These sequences do not hold contiguously allocated data - which has vast implications in their performance (both good and bad).
]


---
# Array
`array` is useful, but only when we truly know the capacity of the container.
```cpp
#include<array>

int main() {
    array<int, 6> ar = {1, 2, 3, 4, 5, 6}
    for ( int i = 0; i < ar.size(); i++ ) {
        cout << ar[i] << endl;  // overloads the [] operator
    }
}
```
- `size()` returns the capacity of the array... period.
- `max_size()` returns the same thing... ugh.
- This is for consistency with other containers - but understand that there is no "count".

---
# Array - size is not count

```c++
#include<array>

int main() {
    array<int, 3> ar;
    for ( int i = 0; i < ar.size(); i++ ) 
        cout << ar[i] << " "; 
    cout << endl;
}
```
```bash
-532006368
22076
-532006928
```
If you have a partially filled array, you still need to keep track of that.

---
# Array - size is not count

```c++
#include<array>

int main() {
    array<int, 3> ar;
>   arr.fill(42); // sets all elements to 42
    for ( int i = 0; i < ar.size(); i++ ) 
        cout << ar[i] << " "; 
    cout << endl;
}
```
```bash
42
42
42
```
`array` and all other contiguously allocated containers do not **assume** that you fill them sequentially, you may place a value into whatever element you want, at any time - **which is why there is no notion of count** built in.

---
# Vector
`array` is nice, but it's usually not the case that we clearly know the upper bounds of a list.  For the majority of use cases, you will want a container that **grows** as you add things.

A `vector` is an array-like structure, which can be **resized**.
- You can insert into the vector at will, however it is bit more complex.
- When inserting, the capacity will automatically increase as necessary.
- It will allocate itself efficiently - it does a good job in reserving extra space to avoid frequent resize.

A vector is usually the right choice in your program if you need a random-access, contiguously allocated container.  **However**, we'll see that all be the most basic operations require you to understand an important concept:  **iterator**.

---
# Basic Vector Operations
Let's review the operations of vectors using unit tests, which lets us experiment as well.
- construction
- `push_back` and `pop_back`
- size / max_size / capacity
- `assign` to fill the vector
- `clear` to erase the vector
- set / get using []

.callout[
Let's open the example test code for vectors.
]

---
# Insert / Remove?
We've seen how we can add and remove from end of vector.
- It's shouldn't be shocking that this is easy - arrays (the underlying data structure) are great for this.
- We implemented `insertAt` and `fromFrom` a few weeks ago on the `ArrayList` - it was a bit harder...

Although the reason isn't because "its hard", inserting and removing from arbitrary locations of a `vector` are fundamentally different than insert/remove from end.  To accomplish this, we need to understand **iterator**.

---
# Iterator?
- How do we represent a location in a sequence?
--

- For arrays, we always use an **integer** index.
- This works because arrays are simple structures - elements are all lined up next to eachother.
- **integer** indexes in fact can be used to **directly** calculate memory location.
--

.callout[
In other data structures, this is **not** the case - and the idea of "where" in a sequence we want to access is not well described simply with an integer.
]

---
# Iterator - abstraction
An **iterator** is an abstraction of a location within a sequence.
- We typically think of an **iterator** as an *object* that represents a location.
- As we've seen - objects can have internal state, and behavior
- Iterators have internal state and behavior that allows them to represent locations on *vastly more complex data structures*.
--

.callout[
Common behavior on iterators would be:
- to move to the next location, or 
- the previous location, 
- and to extract the value **at** the location.
]

---
# Iterators - the ugly..
An iterator in C++ can be ugly, because it needs to be templated to cover all the values that it might point to within a templated data structure.  It is also going to need to work on lots of data structures!

We can't just create an iterator - we need to let the sequence give us one.  Otherwise, it's a location with out a sequence to relate to!
```c++
vector<int> v;
v.assign(100, 42);

// Get an iterator that refers to the first
// location in the sequence.
vector<int>::iterator i = v.begin();
```

---
# `auto` cure
While you occasionally may need to write out the full data type of an iterator, usually you can use `auto` to let the C++ compiler *infer* it's type.  This is only available in C++ 11 and above - however that is very widely deployed.
```c++
vector<int> v;
v.assign(100, 42);

// Get an iterator that refers to the first
// location in the sequence.
auto i = v.begin();
```
Now, we could access the value at that location using the **dereferencing** operator.
```c++
cout << *i << endl;
```
*We'll be reviewing pointers next week, so if you don't remember the dereferencing operator, it will make more sense then.*

---
# Moving the iterator
Iterators typically have `back` and `next` methods to move along a sequence.  They also often implement `++` and `--`.
```cpp
vector<int> v;
for (int i = 0; i < 20; i++)  v.push_back(i * 10);

auto i = v.begin();

i++;
REQUIRE(*i == 10);

i += 5;
REQUIRE(*i == 60);

// #include <iterator>
i = std::prev(i);
REQUIRE(*i == 50);

i = std::next(i, 5);
REQUIRE(*i == 100);
```
---
# Iterating with iterators
Iterators can be used right in a `for` loop.
```c++
vector<int> v;
for (int i = 0; i < 20; i++)
{
    v.push_back(i * 10);
}

int a = 0;
// the end() method returns an iterator "one past" the end.
// just like count is an integer index "one past" the end
// of the array!
for (auto i = v.begin(); i < v.end(); i++)
{
    REQUIRE(*i == a);
    a++;
}
```
---
# Better iteration

```c++
a = 0;
// C++ 11 range loop
for (auto const &value : v)
{
    REQUIRE(a == value);
    a += 10;
}
```
.callback[
C++ is a lot bigger of a language than you might realize.  We are going to start increasingly seeing new ways of doing things...
]

---
# Back to `insert` and `remove`
Insert and Remove operations require you to specify the location using an **iterator**.

```c++
vector<int> v;
for (int i = 0; i < 20; i++)
{
    v.push_back(i * 10);
}

auto i = v.end() - 5; // points to index 15, with 150 in it.
v.insert(i, 1);       // put 1 at index 15

REQUIRE(v.size() == 21);
REQUIRE(v.at(14) == 140);
REQUIRE(v.at(15) == 1);
REQUIRE(v.at(16) == 150);
```

---
# Removal (erase)
We can remove a single item, or a range.
```c++
vector<int> v;
for (int i = 0; i < 20; i++)
{
    v.push_back(i * 10);
}

auto i = v.end() - 5; // points to index 15, with 150 in it.
v.erase(i);           // Removes index 15

REQUIRE(v.size() == 19);

// we cannot re-use the iterator, it's no longer valid.
i = v.end() - 5; // this is now index 14, 140
REQUIRE(*i == 140);

v.erase(v.begin(), v.begin() + 4); // remove index 0 through 3
REQUIRE(v.size() == 15);
REQUIRE(v.front() == 40);
```
---
# Why iterators?
You could make an argument that `vector` doesn't need to be this complicated... since it is indeed contigously allocated.  
- However - iterators are required for most containers.
- For consistency, `vectors` follow the iterator pattern, so they adhere to the same interface as any other STL container.
- When we study more elaborate containers, we will be able to navigate them and de-reference then **the same way** - so it's worth learning now!
- C++ also contains **algorithms** for common operations on sequences of data... but they work with **iterators** too...

---
# Algorithm example
We'll see more of this later... but here's a peek.

```c++
vector<int> v;
// add a whole bunch of values
int sum = 0;
// accumulate the values in v with low-tech syntax...
for ( int i = 0; i < v.size(); i++) sum += v[i];

// accumulate the values in v using the language itself..
// #include <algorithm>
sum = std::accumulate( v.begin(), v.end(), 0 );
```


---
# Stacks and Queues?
- A vector can be used for a stack
- A vector doesn't (efficiently) support insert / remove at front.
- A `deque` allows **efficient** insert/remove **at front**, and the back
 - Both `vector` and `deque` are contiguous allocation arrays, so the need to move data around to allow for arbitrary insertion and removal.
 - A `deque` simply creates a buffer pre-allocated to allow for efficient addition to the beginning of the array, and keeps track of the start position (doesn't assume it is 0) to provide efficient removal.

.callout[
A `deque` works **exactly** like a vector - but contains a `pop_front` and `push_front` method!
]

```c++
#include <deque>
...
deque<float> d;
```

---
# Adapters
While a `deque` is great, often we want a `stack` or a `queue`.
 - You don't iterate stacks and queues, you just pop/push to the front or back.
 - The point of a simple data structure is to reduce complexity, and increase efficiency.
 - While you could just use a `vector` or `deque`, it's helpful to **reduce** complexity by creating the right data structure!

The STL also defines **adapters** that alter the way you work with any of the core sequence containers:
- stack
- queue
- priority queue  (we'll see this soon)

These data structures are not really distinct implementations - for example a stack is actually a vector behind the scenes - but it's cleaner to use them rather than the underlying data structure.

---
# Stack, Queues

.split-left[

```cpp
stack<int> s;

for (int i = 0; i < 20; i++) {
    s.push(i);        
}

for (int i = 0; i < 20; i++) {
    int v = s.top();
    REQUIRE(v == 19 - i);
    s.pop();
}
```
]

.split-right[

```c++
queue<int> q;

for (int i = 0; i < 20; i++) {
    q.push(i);        
}

for (int i = 0; i < 20; i++) {
    int v = q.front();
    REQUIRE(v == i);
    q.pop();
}
```
]

.callout[
Note `pop` returns nothing, you use `top` or `front` to get the value out of the structure.
]