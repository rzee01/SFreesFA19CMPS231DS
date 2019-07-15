title: STL Lists
---
class: center, middle, inverse
# STL List Containers

--
# A review
In many ways, there isn't much more to learn - as `list` works much like `vector` and others.
- The key differences are understanding what they are good for...
- (Linked) lists are great for insert/remove at any location within the list
- (Linked) lists can be iterated easily (as can vectors).
- (Linked) lists are very bad for **random** access however...

.callout[
Why is random access poor in linked list implementations?
]

# STL List interfact
- Since linked lists are bad at random access, the STL `list` class make it hard for you to do it!
- There is no `at` method, and subscripting is not supported.

.info[
This is a key principle in software design:  We limit the interface of an object / module to the actions that 
the data structure are best suited for.  If they caller wants `at(5)` to work, they should use a `vector`!
]

*What other things would we consider when choosing between `vector` and `list`?

