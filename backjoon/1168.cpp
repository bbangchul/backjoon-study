#include <bits/stdc++.h>

using namespace std;

int pre[5001];
int nxt[5001];
vector<int> v;

void solve()
{
    int len = 0;
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        pre[i] = (i == 1) ? n : i - 1;
        nxt[i] = (i == n) ? 1 : i + 1;
        len++;
    }

    int i = 1;
    int cur = 1;

    while (len != 0)
    {
        if (i == k)
        {
            pre[nxt[cur]] = pre[cur];
            nxt[pre[cur]] = nxt[cur];
            v.push_back(cur);

            cur = nxt[cur];
            i = 1;
            len--;
        }
        else
        {
            cur = nxt[cur];
            i++;
        }
    }
    cout << '<';
    for (int i = 0; i < n - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[n - 1] << '>';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}