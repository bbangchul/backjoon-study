#include <iostream>
using namespace std;

class A
{
    int v;

public:
    A(int x);
    A(const A &a);
    void add(int x);
    void show();
};

A::A(int x)
{
    v = x;
}

A::A(const A &a)
{
    v = a.v + 2;
}

void A::add(int x)
{
    v += x;
}

void A::show()
{
    cout << v << endl;
}

int main()
{
    A a1(5);
    A a2 = a1;
    A a3 = a2;

    a2.add(3);
    a3.add(1);

    a1.show();
    a2.show();
    a3.show();
}