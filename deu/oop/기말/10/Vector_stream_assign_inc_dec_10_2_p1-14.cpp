#include <iostream>
using namespace std;

class Vector
{
private:
    double x;
    double y;

public:
    Vector(double xvalue = 0.0, double yvalue = 0.0)
    {
        x = xvalue;
        y = yvalue;
    }

    // <<
    friend ostream &operator<<(ostream &os,
                               const Vector &v);

    // >>
    friend istream &operator>>(istream &is,
                               Vector &v);

    // =
    Vector &operator=(const Vector &v)
    {
        x = v.x;
        y = v.y;

        return *this;
    }

    // 전위 ++
    Vector &operator++()
    {
        x++;
        y++;

        return *this;
    }

    // 후위 ++
    Vector operator++(int)
    {
        Vector temp = *this;

        x++;
        y++;

        return temp;
    }

    // 전위 --
    Vector &operator--()
    {
        x--;
        y--;

        return *this;
    }

    // 후위 --
    Vector operator--(int)
    {
        Vector temp = *this;

        x--;
        y--;

        return temp;
    }
};

// <<
ostream &operator<<(ostream &os,
                    const Vector &v)
{

    os << "(" << v.x << ", "
       << v.y << ")";

    return os;
}

// >>
istream &operator>>(istream &is,
                    Vector &v)
{

    is >> v.x >> v.y;

    return is;
}

int main()
{
    Vector v1(1, 2);
    Vector v2;

    cout << "x y 입력 : ";
    cin >> v2;

    cout << v1 << endl;
    cout << v2 << endl;

    v2 = v1;

    cout << v2 << endl;

    ++v1;
    cout << v1 << endl;

    v1++;
    cout << v1 << endl;

    --v1;
    cout << v1 << endl;

    v1--;
    cout << v1 << endl;

    return 0;
}