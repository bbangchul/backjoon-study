#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    int men[8] = {0};
    int wmn[8] = {0};
    int s, p;
    int count = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> p;
        if (s == 0)
            wmn[p]++;
        else
            men[p]++;
    }

    // for (int i = 0; i < 7; i++)
    //     cout << wmn[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < 7; i++)
    //     cout << men[i] << ' ';
    // cout << '\n';

    for (int i = 1; i < 7; i++)
    {
        if (wmn[i] == 0)
            continue;
        else if (wmn[i] <= k)
        {
            wmn[i] = 0;
            count++;
        }
        else
        {
            int div = (wmn[i] + k - 1) / k;
            count += div;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if (men[i] == 0)
            continue;
        else if (men[i] <= k)
        {
            men[i] = 0;
            count++;
        }
        else
        {
            int div = (men[i] + k - 1) / k;
            count += div;
        }
    }

    // cout << '\n';
    cout << count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}