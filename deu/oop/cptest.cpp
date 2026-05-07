#include <iostream>
using namespace std;

class A
{
private:
    int x;
    static int cnt;

public:
    A(int n) : x(n) { cnt++; }
    A(const A &o) : x(o.x) { cnt++; }
    ~A() { cnt--; }

    A &add(int v)
    {
        x += v;
        return *this;
    }

    static void showCnt()
    {
        cout << cnt << endl;
    }

    void show() const
    {
        cout << x << endl;
    }
};

int A::cnt = 0;

class B
{
public:
    void func(A a)
    {
        a.add(5).add(5);
        a.show();
        A::showCnt();
    }
};

int main()
{
    A a(10);
    B b;
    b.func(a);
    A::showCnt();
}