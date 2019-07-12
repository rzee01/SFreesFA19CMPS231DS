#include <iostream>
#include "linked-list.h"
using namespace std;
int main()
{
    List<int> list;
    for (int i = 0; i < 500; i++)
    {
        list.push_back(i);
    }

    List<int> list2;
    for (int i = 0; i < 500; i++)
    {
        list2.push_front(i);
    }
    // left as excercise...
}