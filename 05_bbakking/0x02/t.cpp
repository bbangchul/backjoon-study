#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a < b && a < c)
    {
        cout << a << " ";
        if (b < c)
            cout << b << " " << c;
        else if (c < b)
            cout << c << " " << b;
    }
    else if (b < a && b < c)
    {
        cout << b << " ";
        if (a < c)
            cout << a << " " << c;
        else if (c < a)
            cout << c << " " << a;
    }
    else
    {
        cout << c << " ";
        if (a < b)
            cout << a << " " << b;
        else if (b < a)
            cout << b << " " << a;
    }
}