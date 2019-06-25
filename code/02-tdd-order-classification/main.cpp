#include <iostream>
#include "classify.h"

using namespace std;
int main()
{
    int x, y, z;
    cout << "Enter three numbers:  " << std::endl;
    cin >> x >> y >> z;
    switch (classify(x, y, z))
    {
    case EQUAL:
        cout << "The numbers are equal" << endl;
        break;
    case ASCENDING:
        cout << "The numbers are in ascending order" << endl;
        break;
    case DESCENDING:
        cout << "The numbers are in descending order" << endl;
        break;
    default:
        cout << "The numbers are not in any order" << endl;
    }
}