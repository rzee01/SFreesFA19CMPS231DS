title: STL Lists
---
class: center, middle, inverse
# STL List Containers

---
# A review
In many ways, there isn't much more to learn - as `list` works much like `vector` and others.
- The key differences are understanding what they are good for...
- (Linked) lists are great for insert/remove at any location within the list
- (Linked) lists can be iterated easily (as can vectors).
- (Linked) lists are very bad for **random** access however...

.callout[
Why is random access poor in linked list implementations?
]

---
# STL List interface
- Since linked lists are bad at random access, the STL `list` class make it hard for you to do it!
- There is no `at` method, and subscripting is not supported.

.info[
This is a key principle in software design:  We limit the interface of an object / module to the actions that 
the data structure are best suited for.  If they caller wants `at(5)` to work, they should use a `vector`!
]

*What other things would we consider when choosing between `vector` and `list`?*

---
# List usage example:  search
Let's build a quick utility function that allows you to search for a (number) in an STL list.
- The function accepts a list (haystack) to search.
- The function accepts a value (needle) to search for.
- The function returns an iterator:
  - If the value is found, the iterator points to the value.
  - If the value is **not** found, the iterator is equal to `list.end()` - as is convention.

```c++
template <typename C, typename T>
typename C::const_iterator find_unsorted(C & haystack, const T & needle) {
    return haystack.cend();
}
```
<div style='text-align:center'>
<img height ="75" src='../images/head-explode.png'/>
</div>

---
# Let's dissect that...
```cpp
template <typename C, typename T>
typename C::const_iterator find_unsorted(C & haystack, const T & needle) {
    return haystack.cend();
}
```
- First - we've created a function that has two templated types - C is the container (ie. `list<int>`, and `T` is the value type of the elements `T`).
- At first glance this might seems a bit awkward - shouldn't it be something like `C<T>`?  The container type is clearly related to `T`.  *You can write more elaborate signatures, but in practice, this is the cleanest way*.
- Next, we see `const_iterator` for the first time - which is used since we have passed `haystack` in as constant.
- Finally, we use `cend` rather than `end`, to get a constant iterator.
.callout[
Now we have to implement this thing...
]

---
# Analysis - time complexity
```c++
auto it = haystack.cbegin();
while ( it != haystack.cend() ) {
    if ( *it == needle) return it;
    else ++it; // prefer prefix increment, avoids copy.
}
return haystack.cend();
```

The number of times around the loop is dependent on two things:
- Do we find the number quickly?
- How many numbers are in the list...?

.callout[
Clearly, we could get lucky and find the number in the first element!
**or** we could never find the number - which means we cycle through the *entire* list.
]

---
# Reasoning about time complexity
Generally we don't consider "best case" scenario, it tends to be too optimistic.
- We like to classify algorithms by describing how CPU time grows as a **function of problem size**.
- In this case, the worst (and average) case grows **linearly** with the size of the list.

**What if we pre-sorted the list?** - this would let us stop a bit earlier... **why?**

---
# Searching sorted list
Well, searching sorted list is easy:
```c++
auto it = haystack.cbegin();
while ( it != haystack.cend() ) {
    if ( *it == needle) return it;
    // If the current value is bigger than what
    // we are looking for, it won't be later in 
    // the list... it's not hear
    else if (*it > needle) return haystack.cend();
    else ++it; // prefer prefix increment, avoids copy.
}
return haystack.cend();
```
*The problem of course, is that we need a sorted list!*.

---
# Building a sorted list
Remember that we can insert a value into a list fairly easily, we just need to find where it should go...
```c++
template <typename C, typename T>
void insert_sorted(C & sorted, const T & value) {
    auto it = sorted.begin();
    while (it != sorted.end()) {
        if (*it > value ) {
            sorted.insert(it, value);
            return;
        } else ++it; // move on till we find an element larger 
    }
    sorted.insert(it, value);
}
```
The `insert` method inserts the value **before** the position represented by the iterator.

---
# Worth it?
This wasn't that much work - so what is the time complexity now?
--
.callout[
"Slightly less" than it was before... by **still linear!
]
*The worst case is that you are adding a value which is larger than all existing... and that still grows linearly!*

**While better**, both of these algorithms are consider part of the same **class** - *O(N)*.

---
# Final notes
It's bad practice to pass containers to functions, we prefer to pass iterators.
- This generalizes - by using iterators the function can traverse the container.
- You can pass in any starting and end point, and the "algorithm" will still just work.

.callout[
**Exercise**:  Change the call signature to our find methods to use start/end iterators instead of `haystack`.
]
