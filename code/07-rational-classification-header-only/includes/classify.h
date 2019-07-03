const int ASCENDING = 1;
const int DESCENDING = -1;
const int EQUAL = 0;
const int NO_ORDER = 42;

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