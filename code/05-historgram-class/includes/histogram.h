

class Histogram
{
public:
    // Note, static const members only work for integral types (int, short, long, char)
    // no doubles, or other objects (i.e. strings).

    static const int MAX = 100;
    Histogram();
    int count(int value) const;
    void sample(int value);

private:
    int data[MAX];
};
