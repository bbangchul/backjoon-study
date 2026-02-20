#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;

    deque<int> dq;

    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }

    int count = 0;
    for (int i = 0; i < M; i++)
    {
        int tg;
        cin >> tg;

        int idx = 0;
        int dql = dq.size();
        for (int j = 0; j < dql; j++)
        {
            if (dq[j] == tg)
            {
                idx = j;
                break;
            }
        }

        if (idx <= dql / 2)
        {
            for (int j = 0; j < idx; j++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
        }
        else
        {
            for (int k = 0; k < dql - idx; k++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
        }
        dq.pop_front();
    }
    cout << count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}