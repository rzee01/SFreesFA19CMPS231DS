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


// Not really what people should call...
int _bsearch(int haystack[], int left, int right, int needle) {
    // Continue as long ast there is at least one remaing
    // element between left and right.
    while (left <= right)  { 
        // Note middle will == left if there is 
        // only one element.
        int middle = left + (right-left)/2; 
        // Return index of middle if found.
        if (haystack[middle] == needle)  
            return middle;   
  
        // Search the right half - move left
        // to one position to the right of middle.
        if (haystack[middle] < needle)  
            left = middle + 1;  
  
        // Search the left half, move right to one
        // position to the left of middle.
        else  right = middle- 1;  
    }
    // There are no elements between left an right...
    // not found.
    return -1;  
}


// "Public" interface
int binary_search(int haystack[], int length, int needle) {
    return _bsearch(haystack, 0, length-1, needle);
}
