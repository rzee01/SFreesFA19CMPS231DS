

class Rational
{
public:
    Rational(int n = 1, int d = 2) : numerator(n), denominator(d)
    {
        if (this->denominator == 0)
        {
            throw std::domain_error("Denominator cannot be 0 in a rational number");
        }
        this->reduce();
    }

    int get_numerator() const
    {
        return this->numerator;
    }

    int get_denominator() const
    {
        return this->denominator;
    }

    void set_numerator(int value)
    {
        this->numerator = value;
        this->reduce();
    }

    void set_denominator(int value)
    {
        if (value == 0)
        {
            throw std::domain_error("Denominator cannot be 0 in a rational number");
        }
        this->denominator = value;
        this->reduce();
    }

    Rational add(const Rational &other) const
    {
        int n = numerator * other.get_denominator() +
                denominator * other.get_numerator();
        int d = denominator * other.get_denominator();
        return Rational(n, d); // reduces
    }

    Rational subtract(const Rational &other) const
    {
        int n = numerator * other.get_denominator() -
                denominator * other.get_numerator();
        int d = denominator * other.get_denominator();
        return Rational(n, d); // reduces
    }

    int compareTo(const Rational &other) const
    {
        Rational tmp = subtract(other);
        if (tmp.get_numerator() < 0)
            return -1;
        else if (tmp.get_numerator() > 0)
            return 1;
        else
            return 0;
    }

    bool equals(const Rational &other) const
    {
        return compareTo(other) == 0;
    }

private:
    void reduce()
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

    int gcd(int n, int d)
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

    int numerator;
    int denominator;
};

Rational operator+(const Rational &r1, const Rational &r2)
{
    return r1.add(r2);
}
Rational operator-(const Rational &r1, const Rational &r2)
{
    return r1.subtract(r2);
}

bool operator<(const Rational &r1, const Rational &r2)
{
    return r1.compareTo(r2) < 0;
}
bool operator<=(const Rational &r1, const Rational &r2)
{
    return r1.compareTo(r2) <= 0;
}
bool operator>(const Rational &r1, const Rational &r2)
{
    return r1.compareTo(r2) > 0;
}
bool operator>=(const Rational &r1, const Rational &r2)
{
    return r1.compareTo(r2) >= 0;
}
bool operator==(const Rational &r1, const Rational &r2)
{
    return r1.compareTo(r2) == 0;
}
bool operator!=(const Rational &r1, const Rational &r2)
{
    return r1.compareTo(r2) != 0;
}