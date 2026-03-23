#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    deque<pair<int, int>> dq;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        while (!dq.empty() && dq.back().second >= num)
        {
            dq.pop_back();
        }

        dq.push_back({i, num});

        if (dq.front().first <= i - m)
        {
            dq.pop_front();
        }

        cout << dq.front().second << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}