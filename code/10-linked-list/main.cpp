#include <iostream>
#include "linked-list.h"
using namespace std;
void go()
{
    List<int> list;
    for (int i = 0; i < 10; i++)
    {
        list.push_back(i);
    }

    for (int i = 0; i < 10; i++)
    {
        list.push_front(i);
    }

    auto it = list.begin();
    while (it.valid())
    {
        cout << it.data() << endl;
        it.forward();
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        go();
        go();
    }
}