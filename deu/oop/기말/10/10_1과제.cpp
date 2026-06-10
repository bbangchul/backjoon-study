#include <iostream>
using namespace std;

class Vector
{
private:
    int x, y;

public:
    Vector()
    {
        x = 0;
        y = 0;
    };

    Vector(int x, int y)
    {
        this->x = x;
        this->y = y;
    };

    Vector operator-(const Vector &v)
    {
        Vector t;

        t.x = this->x - v.x;
        t.y = this->y - v.y;

        return t;
    }

    Vector &operator=(const Vector &v)
    {
        this->x = v.x;
        this->y = v.y;

        return *this;
    }

    Vector &operator-=(const Vector &v)
    {
        this->x -= v.x;
        this->y -= v.y;

        return *this;
    }

    friend ostream &operator<<(ostream &out, const Vector &v)
    {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Vector a(1, 2), b(2, 3), c;

    c = a - b;

    cout << a << " , " << b << " , " << c << '\n';

    a = b;
    cout << a << " , " << b << " , " << c << '\n';

    a -= c;
    cout << a << " , " << b << " , " << c << '\n';

    return 0;
}