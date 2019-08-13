title: STL Maps
---
class: center, middle, inverse
# Maps:  STL Hash Tables

---
# Maps
The term **hash table** conveys a certain strategy (hash function).  The term **map** is more general - it just means that the container allows you to lookup values.
- The word of course implies that there is a **mapping** between the value and the location where it would be found!

.callout[
The STL contains two "map" containers - a `map` and an `unordered_map`.
]

- The two containers work similarly - however `unordered_map` is most like a *hash table*.
- `map` is actualy a binary search tree - and can be iterated in the order of insertion.

---
# STL Unordered Map
An `unordered_map` (and it's `map` counterpart) add a bit of indirection:
- You can store things by a particular **key**.
- The **key** is NOT the hash of a value - the container itself will hash the key to deal with the underlying hash table!  
- You can store arbitrary data at the **key** location - but each **key** is unique.

.callout[
**Important**:  Make sure you understand that there is no such thing as "key" collisions - you can't store multiple values associated with the same key!.
]

*Behind the scenes, multiple **keys** might **hash** to the same value, but the `unordered_map` takes care of this using collision strategies outlined earlier.

---
# Map types
```c++
#include <unordered_map>

...
std::unordered_map<key_type, value_type> map;
```

- `key_type` is the data type of the keys - which must support `==`.
- `value_type` is the data type of the values, associated with the key.  

So - we could create a map representing student objects, and their IDs
```c++
class Student {
    public:
        string name;
        int id;
};

unordered_map<int, Student> student_map;
```

---
# Example:  Strings
Let's say we are going to receive a series of words as input, and we simply want to keep track of which words we've seen.

```c++
unordered_map<sting, bool> word_map;
while (not done) {
    string word = <get word>;
    word_map.insert(word);
}

```
Our map now contains a true value for each word.

---
# `at` vs `[]`
- The `at` function throws an exection when given a key that does not yet exist.
- The `[]` operator does not throw - rather, it actually inserts a value - using the default constructor.

**Notice** how we can take advantage of this behavior:
- If we want to know if a *word* was inserted, we can use `[]`, since the default constructor for a boolean is `false`.

```c++
if (word_map['word_not_in_map']) {
    // this word was not in map
}
```

**However** -  we are increasing space used - adding a `false` entry on lookup.

---
# Checking if key exists
- `at` throws an exception if the key does not exist - which isn't ideal.
- `[]` constructs a default object and returns it - which might not be great either.
- `find` returns an iterator to the value, and an empty iterator if not found.
- `count` returns the count for a particular key - which is a great way to check exists.

.callout[
Let's look at a similar example - but with word counts.
]

---
# Word Counting
Let's implement a class that derives `unordered_map` and provides easy word counting facilities:

```c++
class WordCount {
    public:
        string word;
        unsigned int count;
};

class WordCounter :: protected std:unordered_map<string, unsigned int> {
    public:
        WordCounter();
        void add(string word);
        int count(string word) const;  // case insenstive
        vector<WordCount> words() const; // count for every word in map
}
```


---
# More about maps
You should check out the documentation on `map` and `unordered_map`!
- You can control and query hashing properties
- override / implement hashing functions for complex types
- obtain information on bucket counts / collisions.