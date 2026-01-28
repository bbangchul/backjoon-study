#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x, y, w, h;
    int m;
    cin >> x >> y >> w >> h;

    w = min(w - x, h - y);
    h = min(x, y);
    // min = x;
    // if (y < min)
    //     min = y;
    // if (w < min)
    //     min = w;
    // if (h < min)
    //     min = h;

    cout << min(w, h);
}