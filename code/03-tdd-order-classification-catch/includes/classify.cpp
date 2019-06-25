#include "classify.h"

int classify(int a, int b, int c)
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