#include <iostream>

using namespace std;

class Array
{
private:
    int *ptr;
    int size;

public:
    Array(int = 10);
    Array(const Array &);
    ~Array();
    int getSize();
    int &operator[](int);
    const int operator[](int) const;
};

Array::Array(int size)
{
}

Array::Array(const Array &)
{
}

int main()
{

    return 0;
}