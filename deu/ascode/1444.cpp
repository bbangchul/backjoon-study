#include <bits/stdc++.h>
using namespace std;

void solve()
{
    char a[101];
    char b[101];
    cin >> a >> b;

    int st, end;
    cin >> st >> end;
    for (int i = st; i < end; i++)
    {
        char t = a[i];
        a[i] = b[i];
        b[i] = t;
    }
    cout << a << ' ' << b << '\n';
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