#include <bits/stdc++.h>

using namespace std;

vector<int> v(9);

void solve()
{
    string s;
    cin >> s;
    int ls = s.size();
    for (int i = 0; i < ls; i++)
    {
        int idx = s[i] - '0';
        if ((idx == 6) || (idx == 9))
            v[6]++;
        else
            v[idx]++;
    }
    int big = 0;
    v[6] = (v[6] + 1) / 2;
    for (int i = 0; i < 9; i++)
    {
        if (v[i] > big)
        {
            big = v[i];
        }
    }
    cout << big;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}