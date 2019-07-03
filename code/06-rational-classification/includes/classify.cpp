#include "classify.h"

template <typename T>
int classify(T a, T b, T c)
{
    if (a == b && b == c)
    {
        return EQUAL;
    }
    else if (a <= b && b <= c)
    {
        return ASCENDING;
    }
    else if (a >= b && b >= c)
    {
        return DESCENDING;
    }
    else
    {
        return NO_ORDER;
    }
}