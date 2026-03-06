#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;

    Point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }

    int dist2(Point p)
    {
        int dx = x - p.x;
        int dy = y - p.y;
        return dx * dx + dy * dy;
    }
};

void solve()
{
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    Point a(x1, y1);
    Point b(x2, y2);

    int d = a.dist2(b);
    int sum = r1 + r2;
    int sub = r1 - r2;
    if (sub < 0)
        sub = -sub;

    if (!d && r1 == r2)
        cout << -1 << '\n';
    else if (d > sum * sum || d < sub * sub)
        cout << 0 << '\n';
    else if (d == sum * sum || d == sub * sub)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}