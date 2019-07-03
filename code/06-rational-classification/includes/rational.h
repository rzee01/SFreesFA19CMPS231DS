

class Rational
{
public:
    Rational(int n = 1, int d = 1);
    int get_numerator() const;
    int get_denominator() const;
    void set_numerator(int value);
    void set_denominator(int value);

    int compareTo(const Rational &other) const;
    bool equals(const Rational &other) const;
    Rational add(const Rational &other) const;
    Rational subtract(const Rational &other) const;

private:
    int numerator;
    int denominator;

    void reduce();
    static int gcd(int n, int d);
};

Rational operator+(const Rational &r1, const Rational &r2);
Rational operator-(const Rational &r1, const Rational &r2);

bool operator<(const Rational &r1, const Rational &r2);
bool operator<=(const Rational &r1, const Rational &r2);
bool operator>(const Rational &r1, const Rational &r2);
bool operator>=(const Rational &r1, const Rational &r2);
bool operator==(const Rational &r1, const Rational &r2);
bool operator!=(const Rational &r1, const Rational &r2);