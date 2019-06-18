title: Unit Testing
---
class: middle, center, inverse
# Unit Testing

---
# Does it work?
How do we *really* know the following code works?
```ruby
def add(a,b)
  a + b
end
```
---
# Looks good to me!
- When you write code, and test later... 
--

- You don't *really* want to find bugs
--

- You tend to do some superficial testing
--

- And you tend not too look carefully at the results
---
# Regressions
- You probably aren't finished with your program...
--

- You will return to the program and *enhance it*.
--

- Will you thoroughly test the old functionality to make sure you haven't introduced any errors?
---
# Regressions... by others
Many years from now, a poor intern may need to enhance *your code*, since you've moved on to another, better paid position.

How does the intern know what sorts of tests you did to make sure your code worked?  How can the intern run those tests now that you are gone?

---
# Test-Driven Development

- This is a well understood problem - with well understood solutions.
- We **do not** test our code manually, we test our code by running other code!
- We **do not** figure out what to test *after*  writing our code - we'll be too tired then.  We write our tests before we right the real code!
- Since the tests **are code**, now we can re-run them often - gaurding against **regressions**.

---
# TDD Advocates **are very enthusiastic**
:)