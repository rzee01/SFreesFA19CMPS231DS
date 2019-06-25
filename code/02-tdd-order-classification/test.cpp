#include "classify.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Starting tests..." << endl;
    if (classify(0, 0, 0) != EQUAL)
    {
        cout << "Error 0 0 0" << endl;
    }
    if (classify(1, 1, 1) != EQUAL)
    {
        cout << "Error 1, 1, 1" << endl;
    }
    if (classify(-1, -1, -1) != EQUAL)
    {
        cout << "Error -1, -1, -1" << endl;
    }

    // Ascending tests
    if (classify(2, 3, 4) != ASCENDING)
    {
        cout << "Error 2, 3, 4" << endl;
    }
    if (classify(2, 3, 3) != ASCENDING)
    {
        cout << "Error 2, 3, 3" << endl;
    }
    if (classify(3, 3, 4) != ASCENDING)
    {
        cout << "Error 3, 3, 4" << endl;
    }

    // Descending tests
    if (classify(4, 3, 2) != DESCENDING)
    {
        cout << "Error 4, 3, 2" << endl;
    }
    if (classify(3, 3, 2) != DESCENDING)
    {
        cout << "Error 3, 3, 2" << endl;
    }
    if (classify(4, 3, 3) != DESCENDING)
    {
        cout << "Error 4, 3, 3" << endl;
    }

    // Descending tests
    if (classify(4, 5, 4) != NO_ORDER)
    {
        cout << "Error 4, 5, 4" << endl;
    }
    if (classify(1, 0, 9) != NO_ORDER)
    {
        cout << "Error 1, 0, 9" << endl;
    }
    if (classify(-9, 9, -9) != NO_ORDER)
    {
        cout << "Error -9, 9, -9" << endl;
    }

    cout << "Tests completed..." << endl;
}