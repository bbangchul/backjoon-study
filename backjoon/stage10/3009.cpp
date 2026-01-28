#include <iostream>

using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int findx, findy;
    if (x1 == x2)
        findx = x3;
    else
    {
        if (x2 == x3)
            findx = x1;
        else
            findx = x2;
    }
    if (y1 == y2)
        findy = y3;
    else
    {
        if (y2 == y3)
            findy = y1;
        else
            findy = y2;
    }
    cout << findx << ' ' << findy;
}