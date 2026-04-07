#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve()
{
    ull a, b, v;
    cin >> a >> b >> v;
    ull rm = v - a;
    ull onetime = a - b;
    if (rm % onetime == 0)
    {
        cout << rm / onetime + 1;
    }
    else
    {
        cout << rm / onetime + 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}