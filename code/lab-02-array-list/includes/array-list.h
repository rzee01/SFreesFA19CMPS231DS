class ArrayList
{
public:
    // Initialize the contents of your list to 0, and initialize any other member variables you need.
    ArrayList();

    // Add the value to the beginning of the list. Throw length_error if beyond capacity
    void prepend(int value);

    // Add the value to the end of the list. Throw length_error if beyond capacity
    void append(int value);

    // Return the value at the given index.  Throw out_of_range if outside the bounds of the data in array.
    int get(int index) const;

    // Return index where given value is found.  Return -1 if the value is not found.
    int find(int value) const;

    // Return the current length of the array (the part that has data!)
    int length() const;

    // Make sure you reference this const whenever dealing with capacity, so you can
    // change the capacity of the array list by altering just this line of code.
    static const int CAPACITY = 100;

private:
    // add any private members you think are necessary.
};