#include <bits/stdc++.h>

using namespace std;

queue<int> q;

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        q.push(i);

    while (q.size() != 1)
    {
        q.pop();
        int t = q.front();
        q.push(t);
        q.pop();
    }

    cout << q.front();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}