#include "histogram.h"
#include <stdexcept>

Histogram::Histogram()
{
    for (int i = 0; i < MAX; i++)
        data[i] = 0;
}

int Histogram::count(int value) const
{
    if (value < 0 || value >= MAX)
    {
        throw std::out_of_range("Values between 0 and 99 accepted");
    }
    return data[value];
}

void Histogram::sample(int value)
{
    if (value < 0 || value >= MAX)
    {
        throw std::out_of_range("Values between 0 and 99 accepted");
    }
    data[value]++;
}
