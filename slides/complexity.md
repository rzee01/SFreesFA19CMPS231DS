title: Complexity
---
class: center, middle, inverse
# Time and Memory Complexity
Big-O Notation

---
# Complexity
In computer science, we use the work *complexity* to talk about how a specific algorithm behaves, as the domain grows.
- For example, searching... it takes longer for bigger lists.

We are often concerned about *time complexity*, but *space (memory) complexity* is often just as important.
.callout[
Complexity is one of the few areas of computer science where we aim to be **imprecise**.
]

---
# Imprecise?
We saw in the last module that searching a sorted list is clearly faster than an unsorted list.  However, it's hard to quantify just how much faster...
- The time it takes to search grows **linearly** in both.
- The grow **rate** is pretty much the same, but sorted lists are faster by some factor (i.e. the probability of trying to find a number both not in the list, and smaller than some elements).

.callout[
Ultimately, when we talk about two **linear** algorithms, one that runs at **1 &dot; N** (where N is number of elements), and one that runs at **0.75 &dot; N**, *we consider them the same... LINEAR*.
]

<div style="text-align:center">
We refer to this as <b>O(n)</b>
</div>


---
# What's not linear?
We've seen some "algorithms" that aren't linear already...
- Remove from a queue or stack
- Add to a queue or stack

Do these operations get *slower* if the queue or stack has more elements?

.callout[
Operations / Algorithms that do not change in complexity as the problem set grows are called **constant** time (or space) algorithms.
]

<div style="text-align:center">
We refer to this as <b>O(1)</b>
</div>

---
# No coefficients
**It is critical** to remember that we do not get bogged down in coefficients or factors in most cases.
- Given an algorithm that does 3 operations **per list element** versus one that does 10, we think of them both as **linear**.  They are both written as O(n).
- Given an algorithm that does 50 things, regardless of input size, and another that does 5000 things, we still think of them both as **constant**.  They are both written as O(1).

.callout[
Aside from **very** unusual circumstances - **any** constant time/space algorithm is preferred over on that is linear.
]

---
# More classes
If every algorithm was linear or constant, we'd live in a **very** different world.
- Unfortunately, some algorithms are **quadratic**, or even **exponential**.
- A quadratic algorithm grows at a rate of N<sup>2</sup> or N<sup>y</sup>, where y is a **constant**.
- An exponential algorithm grows at a rate of y<sup>N</sup> - where y is some constant.

```c++
// Example of a quadratic time complexity algorithm
// Figure out if there are duplicates in the list.
bool has_duplicates(int values [], int length) {
    for ( int i = 0; i < length; i++ ) {
        for (int j = 0; j < length; j++ ) {
            if ( values[i] == values[j] && i != j) return true;
        }
    }
    return false;
}
```

---
# Lots of classes...
<img src='../images/complexity.png' height='400'/>
<p style='color:gray; font-size:8pt'>https://adrianmejia.com/most-popular-algorithms-time-complexity-every-programmer-should-know-free-online-tutorial-course/</p>

---
# Logoritmic complexity
Given a problem, we often can quickly find a quadratic algorithm, or a linear algorithm (for simple stuff).  
- **Step 1**:  Write a correct program
- **Step 2**:  Try to make it more effient.

Often, with a bit of cleverness, we can turn a quadratic into **n &dot; log <sub>n</sub>**, or a linear into a **log<sub>n</sub>** or even constant!

- **n &dot; log <sub>n</sub>** is **significantly** better than quadratic.
- **log<sub>n</sub>** is **significantly** better than linear.

---
# Search:  Better than linear?
Both of our attempts at searching a list, unsorted or sorted, were **linear**.

However, given a *sorted* list, we can actually do a **a lot** better than linear.

Idea:  Given a sorted list, and a value (*needle*)to search for:
- **Search** Go to the middle of the list.
 - If list is empty, return false (**done**).
 - If the value at the middle is equal to *needle* - **done**.
 - If the value at the middle is **less** than *needle*, **search the second half**.
 - If the value at the middle is **greater** than *needle*, **search the first half**.

---
# Binary Search
This algorithm is a fundamental search algorithm, and can be implemented with or without recursion.
We are going to look at **recursion** next time, let's look at the non-recursive method.

--
.callout[
- This algorithm follows a clear pattern:  At every iteration, it cuts the problem space **in half**.
- Compare that with our original search... where every iteration elimated **one element**.
]

---
# log<sub>n</sub> search time
Whenever you cut a problem in half, on each iteration, you have a log<sub>n</sub> algorithm.  

- We will see examples of quadratic, log <sub>n</sub>, linear, log<sub>n</sub> algorithms in this class.
- Rarely do we get lucky enough to get a **constant** time algorithm - but we will always be on the lookout :)

---
# STL?
We kept our binary search simple - just an array of numbers.
- The STL library comes with *algorithms* along with *containers*.

```c++
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(10);
    ... fill the vector with any number of sorted values
    
    int input;
    cout << "Enter #:  ";
    cin  >> input;
    if ( binary_search(v.begin(), v.end(), input)) {
        cout << "Yes!" << endl;
    }
}
```

---
# Binary search on linked list?
As a lead in to our next data structure - **notice that the STL example used vector**.
- The classic binary search algorithm exhibits **random** access.
- The time complexity would be back to linear (actually, worse) if we used a linked list... **why**?

.callout[
Our next data structure will be a **Binary Search Tree**, which is the non-contigous storage cousin of linked lists, which supports fast binary search.
]