#include "rational.h"
#include <stdexcept>

Rational::Rational(int n, int d) : numerator(n), denominator(d)
{
    if (this->denominator == 0)
    {
        throw std::domain_error("Denominator cannot be 0 in a rational number");
    }
    this->reduce();
}

int Rational::get_numerator() const
{
    return this->numerator;
}

int Rational::get_denominator() const
{
    return this->denominator;
}

void Rational::set_numerator(int value)
{
    this->numerator = value;
    this->reduce();
}

void Rational::set_denominator(int value)
{
    if (value == 0)
    {
        throw std::domain_error("Denominator cannot be 0 in a rational number");
    }
    this->denominator = value;
    this->reduce();
}

Rational Rational ::add(const Rational &other) const
{
    int n = numerator * other.get_denominator() +
            denominator * other.get_numerator();
    int d = denominator * other.get_denominator();
    return Rational(n, d); // reduces
}

Rational Rational ::subtract(const Rational &other) const
{
    int n = numerator * other.get_denominator() -
            denominator * other.get_numerator();
    int d = denominator * other.get_denominator();
    return Rational(n, d); // reduces
}

void Rational::reduce()
{
    int factor = gcd(numerator, denominator);
    if (denominator > 0)
    {
        this->numerator = numerator / factor;
    }
    else
    {
        this->numerator = -numerator / factor;
    }
    this->denominator = abs(denominator) / factor;
}

int Rational ::gcd(int n, int d)
{
    int n1 = abs(n);
    int n2 = abs(d);
    int retval = 1;
    for (int k = 1; k <= n1 && k <= n2; k++)
    {
        if (n1 % k == 0 && n2 % k == 0)
            retval = k;
    }
    return retval;
}

Rational operator+(const Rational &r1, const Rational &r2)
{
    return r1.add(r2);
}
Rational operator-(const Rational &r1, const Rational &r2)
{
    return r1.subtract(r2);
}