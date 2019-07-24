#include <vector>

class Heap
{
public:
    Heap()
    {
        
    }
    void push(int value)
    {
        data.push_back(value);
        moveUp(data.size()-1);
    }
    int top()
    {
        if (data.size() == 0) {
            throw std::underflow_error("Cannot call top on empty heap");
        }
        return data[0];
    }
    bool is_empty() {
        return data.size() == 0;
    }
    void pop()
    {
        if (data.size() == 0) {
            throw std::underflow_error("Cannot call pop on empty heap");
        }
        data[0] = data[data.size()-1];
        data.pop_back();
        moveDown(0);
        
    }

private:
    std::vector<int> data;

     void moveUp(int cp) {
        int p = parent(cp);
        if ( data[p] >= data[cp] ) {
            return; // we're okay
        }
        else {
            swap(p, cp);
            moveUp(p);
        }
    }
 
    void moveDown(int cp) {
        // if left or right is greater, than swap with largest
 
        // initialize as one less than the current value,
        // this way if the left or right is not present, it will be ignored
        int lvalue = data[cp]-1;
        int rvalue = data[cp]-1;
 
        // get the left and right values (if they exist)
        if ( left(cp) < data.size() ) lvalue = data[left(cp)];
        if ( right(cp) < data.size() ) rvalue = data[right(cp)];
 
        // if the left value is greater than the current,
        // and it is the biggest of the children
        if ( lvalue > data[cp] && lvalue >= rvalue ) {
            swap ( cp, left(cp) );
            moveDown(left(cp));
        }
        // if the right value is greater than the current,
        // and it is the biggest of the children
        else if ( rvalue > data[cp] && rvalue >= lvalue ) {
            swap ( cp, right(cp) );
            moveDown(right(cp));
        }
        else {
            return;
        }
    }

    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    int parent(int i) {
        return (i-1)/2;
    }
    void swap (int i, int j) {
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
};