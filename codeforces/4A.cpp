#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int w;
    cin >> w;
    if (w == 2)
        cout << "NO";
    else if (w % 2 == 0)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}