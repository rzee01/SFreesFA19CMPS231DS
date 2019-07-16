#include <list>
#include<iterator>

template <typename C, typename T>
typename C::const_iterator find_unsorted(const C & haystack, const T & needle) {
    auto it = haystack.cbegin();
    while ( it != haystack.cend() ) {
        if ( *it == needle) return it;
        else ++it; // prefer prefix increment, avoids copy.
    }
    return haystack.cend();
}

template <typename C, typename T>
typename C::const_iterator find_sorted(const C & haystack, const T & needle) {
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
}

template <typename C, typename T>
void insert_sorted(C & sorted, const T & value) {
    auto it = sorted.begin();
    while (it != sorted.end()) {
        if (*it > value ) {
            // The value needs to go before this...
            sorted.insert(it, value);
            return;
        } else ++it; // move on till we find an element larger 
    }
    // If we get here, NONE of the elements were larger than
    // the value we are inserting... so just add at end (it is end).
    // This works on an empty list too - since begin() would have 
    // been == to end()
    sorted.insert(it, value);
}

