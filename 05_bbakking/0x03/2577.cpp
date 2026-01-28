#include <bits/stdc++.h>

using namespace std;

vector<int> v(10);

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int r = a * b * c;
    string s = to_string(r);
    int ls = s.size();
    for (int i = 0; i < ls; i++)
    {
        int idx = s[i] - '0';
        v[idx]++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}