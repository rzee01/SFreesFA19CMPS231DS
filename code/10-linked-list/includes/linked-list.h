#include <stdexcept>
#include <iostream>

template <typename T>
class node
{
public:
    // Custom constructor to set all the fields,
    // we will always know these fields at time
    // of construction, so this is convenient.
    // Note, we do not provide a default constructor -
    // we there is no reason to ever use it!
    // This prevents  node<T> * t = new node<T>();
    node(node<T> *next, node<T> *prev, T data = 0) //  : next(next), prev(prev), data(data)
    {
        // Notice the use of initilizer lists, which are
        // slightly more efficient than setting things in
        // the constructor body - it avoids copying
        this->next = next;
        this->prev = prev;
        this->data = data;
    }
    node<T> *next;
    node<T> *prev;
    T data;
};

template <typename T>
class iterator;

template <typename T>
class List
{
public:
    List() : head(nullptr), tail(nullptr), length(0)
    {
        // We start without any elements,
        // so our head pointer can't point
        // to anything!
    }
    ~List()
    {
        // Free up all our nodes.
        // We already have a method for it, so there
        // is no need to be fancy here...

        clear();
    }

    iterator<T> begin() const
    {
        return iterator<T>(head);
    }

    iterator<T> end() const
    {
        return iterator<T>(tail);
    }

    bool is_empty() const
    { // Don't forget to mark things as const if they are!
        // head will always point to the first element,
        // so if it points to nullptr, then there is no
        // first element - meaning the list is empty.
        // Another alternative would be to check if tail
        // is nullptr (that's a little unintuitive),
        // or check if length is 0.
        return head == nullptr;
    }

    void clear()
    {
        while (!is_empty())
            pop_front();
    }

    // Insert in front of the given iterator.
    void insert(iterator<T> pos, T value) {
        if (!pos.valid()) {
            throw std::out_of_range("Cannot insert given an invalid iterator");
        }
        // Let's re-use existing functions if we are being asked to add
        // to the beginning or end of the list.
        // since we have private access, we can check target directly.
        // pointers are just addresses - so it's fair to test for equality.
        if ( pos.target == head) {
            push_front(value);
        } else if ( pos.target == tail) {
            push_back(value);
        } else {
            // Inserting before an element which has an element before it, and after it...
            auto before = pos.target->prev;
            auto after = pos.target;
            auto new_node = new node<T>(after, before, value);
            after->prev = new_node;
            before->next = new_node;
        }
    }
    void push_back(T value)
    {
        if (is_empty())
        {
            // We are adding to an empty list, just call
            // push_front - we already dealt with this beast.
            push_front(value);
            return;
        }
        // List has at least one element, so this is going to
        // become the next tail.
        auto new_tail = new node<T>(nullptr, tail, value);
        tail->next = new_tail;
        tail = new_tail;
        length++;
    }

    void pop_back()
    {

        if (is_empty())
        {
            throw std::underflow_error("Cannot pop_back from empty list");
        }
        // We are going to change the tail, it needs to
        // be whatever the current tail's previous is.
        // We will be deleting the old tail,so we need
        // to save a pointer to it.
        auto old_tail = tail;
        tail = tail->prev; // tail is now the second to last element
        delete old_tail;

        // It is possible this was the only element in the list,
        // if so, tail will point to nothing (there was no second to last
        // element) - as the old tail was also the head.
        if (tail == nullptr)
        {
            // We just deleted the only element, head
            // needs to point to null now too.
            head = nullptr;
        }
        else
        {
            // Otherise, tail points to real element, and that
            // element used to point to the old tail - and it
            // no longer should - it's the end of the list!
            tail->next = NULL;
        }
        // Note, in all other cases (there were 2 or more elements),
        // head would not change.
        length--;
    }

    void push_front(T value)
    {
        // We have two cases, (1) list is empty,
        // and (2) list has elements already.
        // Try to re-use your public functions when you can,
        // it makes for more readable and testable code.
        if (is_empty())
        {
            // Construct a new node - next and prev
            // point to nullptr because it's all by itself... first node.
            head = new node<T>(nullptr, nullptr, value);
            // New node is both the first, and the last.
            tail = head;
        }
        else
        {
            // this is the current, head, it will need to point back
            // to the new node.
            auto old_head = head;
            // New node is going in the front, but so next points
            // to the old head.  It's at the front, so prev is still nullptr.
            head = new node<T>(head, nullptr, value);
            old_head->prev = head;

            // As an exercise, prove that "old_head" IS tail on a list with one element,
            // so tail is going to automatically be kept in sync.
        }

        // Put the length bump outside the conditional blocks -
        // we increment length no matter what the state of the
        // list was before this was called.
        length++;
    }

    void pop_front()
    {
        if (is_empty())
        {
            throw std::underflow_error("Cannot get front of an empty list.");
        }
        // Head's next either points to the second element (new head),
        // or it points to nullptr, meaning there is only one
        // element in the list.
        auto old_head = head; // save for deletion.
        head = head->next;
        if (head == nullptr)
        {
            // We deleted the only element, so there is
            // no longer a tail.
            tail = nullptr;
        }
        else
        {
            // The current head is what used to be the second
            // element in the list.
            // We deleted the element in front of it, so we
            // better make sure it's previous pointer is now null!
            head->prev = nullptr;
        }
        // Delete the old head, and reduce length.
        delete old_head;
        length--;
    }

    T front() const
    {
        if (is_empty())
        {
            throw std::underflow_error("Cannot get front of an empty list.");
        }
        return head->data;
    }

    T back() const
    {
        if (is_empty())
        {
            throw std::underflow_error("Cannot get front of an empty list.");
        }
        return tail->data;
    }

    int size() const
    {
        return length;
    }

private:
    node<T> *head; // We don't have accessors for these,
    node<T> *tail; // the user of our list has no business getting these!

    int length; // Save the length each time we remove/insert,
                // so we don't need to traverse the list to
                // tell the user how many elements they have.

    void debug_printout()
    {
        std::cerr << "---------------------------" << std::endl;
        std::cerr << "Debug print of list:  size = " << size() << std::endl;

        auto current = head;
        while (current != nullptr)
        {
            std::cerr << current << ":  " << current->prev << " <= " << current->data << " => " << current->next << std::endl;
            current = current->next;
        }
    }
};

template <typename T>
class iterator
{
public:
    void forward()
    {
        if (!valid())
        {
            throw std::out_of_range("Cannot call next on invalid iterator");
        }
        target = target->next;
    }
    void back()
    {
        if (!valid())
        {
            throw std::underflow_error("Cannot call back on invalid iterator");
        }
        target = target->prev;
    }
    T &data()
    {
        if (!valid())
        {
            throw std::out_of_range("Cannot call data on invalid iterator");
        }
        return target->data;
    }
    bool valid()
    {
        return target != nullptr;
    }
    ~iterator<T>()
    {
    }

private:
    // This is important... notice that the
    // constructor is private.  This means
    // normal user code just can't create an
    // iterator.  But List is a friend, so it can.
    // This is a classic Factory pattern - the List
    // class is the only onen that can build an iterator
    // for you.
    // If we were building a library of containers, we
    // might need to use a base class as friend, so iterator
    // could be re-used across subclasses.
    iterator<T>(node<T> *target) : target(target)
    {
    }

    node<T> *target;
    friend class List<T>;
};