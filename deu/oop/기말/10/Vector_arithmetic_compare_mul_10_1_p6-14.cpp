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

    void display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // +
    Vector operator+(const Vector &v)
    {
        return Vector(x + v.x, y + v.y);
    }

    // -
    Vector operator-(const Vector &v)
    {
        return Vector(x - v.x, y - v.y);
    }

    // ==
    bool operator==(const Vector &v)
    {
        return (x == v.x && y == v.y);
    }

    // !=
    bool operator!=(const Vector &v)
    {
        return !(*this == v);
    }

    // 스칼라 곱
    friend Vector operator*(const Vector &v, double a);
    friend Vector operator*(double a, const Vector &v);
};

// v * 2.0
Vector operator*(const Vector &v, double a)
{
    return Vector(v.x * a, v.y * a);
}

// 2.0 * v
Vector operator*(double a, const Vector &v)
{
    return Vector(v.x * a, v.y * a);
}

int main()
{
    Vector v1(1, 2);
    Vector v2(3, 4);

    Vector v3;

    v3 = v1 + v2;
    v3.display();

    v3 = v2 - v1;
    v3.display();

    cout << (v1 == v2) << endl;
    cout << (v1 != v2) << endl;

    v3 = v1 * 2.0;
    v3.display();

    v3 = 3.0 * v1;
    v3.display();

    return 0;
}