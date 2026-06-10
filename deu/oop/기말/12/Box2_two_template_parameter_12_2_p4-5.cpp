#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Box2
{

private:
    T1 f_data;
    T2 s_data;

public:
    Box2() {}

    void set_f(T1 v)
    {
        f_data = v;
    }

    void set_s(T2 v)
    {
        s_data = v;
    }

    T1 get_f()
    {
        return f_data;
    }

    T2 get_s()
    {
        return s_data;
    }
};

int main()
{

    Box2<int, double> b;

    b.set_f(10);
    b.set_s(3.14);

    cout << b.get_f() << " "
         << b.get_s() << endl;

    return 0;
}