#include <iostream>
using namespace std;

int _binary_search(int haystack[], int start, int end, int needle) {
    if ( start > end) return -1;
    int mid = (start+end)/2;
    if ( haystack[mid] == needle) return mid;
    else if (haystack[mid] < needle ){
        return _binary_search(haystack, mid+1, end, needle);
    } else {
        return _binary_search(haystack, start, mid-1, needle);
    }
    
}
// "Public" interface
int binary_search(int haystack[], int length, int needle) {
    return _binary_search(haystack, 0, length-1, needle);
}
