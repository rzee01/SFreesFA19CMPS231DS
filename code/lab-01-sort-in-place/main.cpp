#include <iostream>
#include "sort.h"

using namespace std;
int main()
{
    int x, y, z;
    cout << "Enter three numbers:  " << std::endl;
    cin >> x >> y >> z;
    sort_in_place(x, y, z);
    cout << x << " " << y << " " << z << endl;
}