#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;

        if ((a >= b + c) || (b >= a + c) || (c >= a + b))
        {
            cout << "Invalid\n";
        }
        else if (a == b && a == c)
        {
            cout << "Equilateral\n";
        }
        else if (a == b || b == c || a == c)
        {
            cout << "Isosceles\n";
        }
        else
        {
            cout << "Scalene\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}