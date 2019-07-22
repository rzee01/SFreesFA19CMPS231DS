title: Recursion
---
class: center, middle, inverse
# Recurson
Recursion

---
# What is recursion?
A recursive function is a function that calls *itself*.
- A recursive function **must** have at least one base case, where the recursive call returns an answert directly.
- A recrusive function must call *itself* with different input - and **hopefully** with input that is *easier* to compute the answer to!

```c++
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}
```
---
# A (bad) example:
```c++
// 0:1, 1:1, 2:2, 3:3, 4:5, 5:8, 6:13, 7:21, 8:34
int fib(int n) {
    if ( n <= 1 ) return 1;
    else return fib(n-2) + fib(n-1);
}

```
---
# Why is this bad?
On each call to `fib`, we call `fib` twice (unless base case).
--

- Each "sub-call" to `fib` acts on a problem space only slightly smaller than the original...
- The "sub-call"s to `fib` are actually performing much of the same work:
  - `fib(5)` calls `fib(4)` and `fib(3)`.
  - `fib(4)` calls `fib(3)` too!

---
# Costs of recursion
- CPU time... *possibly*.
- Memory?  *Likely* - there is a cost to calling all these functions!  What is it?

.alert[
Recursion is best employed when each "sub-call" operates on a problem space **significantly smaller** than the original... 
]

---
# When is recursion good?
We can think of **recursion complexity** a lot like we though of *time complexity* and *memory complexity* - and reason about how it grows as the problem space increases.
- recursive factorial - **function call depth grows linearly**
- recursive fibonacci - **function call depth grows quadratically!**.
- recursive binary search - **?**

.callout[
- Define "list" as a start and end index within array.
- Assumption:  List is sorted
- **Base case (1)**:  If list is empty, return false.
- **Base case (2)**:  If value at mid point is what you are looking for, return true!
- If value at midpoint is less than what you are looking for, *search right half*.
- Otherwise, *search left half!*
]

---
# Binary search, recursively
Note how powerful the recursive step is:
- Each call to `search` *may* call `search` itself, but always on a problem space **half as large** as the original.  
- When a problem is cut in half on each "iteration" - it's a log<sub>2</sub>n algorithm.
- No two successfive recursive calls repeats the same effort as others.

.callout[
Unlike `fib`, this is a great use of recursion.  The code is easier to keep track of, and cost of recursion is limited.
]

---
# Recursion:  Conclusion
- Never write a recursive function if the *imperative* solution is simple and easy to understand.
- Never write a recursive function that doesn't break the problem down significantly on each recursive call!
- Avoid writing recursive algorithms that duplicate work across different function calls.
- Always consider the cost of **stack maintenance**, design recursive functions with limited parameters and local variables.

.callout[
**Note**:  there is no reason we couldn't write this with a template implementation.
]
