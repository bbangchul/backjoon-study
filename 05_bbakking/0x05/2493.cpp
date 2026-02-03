#include <bits/stdc++.h>

using namespace std;

int arr[500001];

void solve()
{
    int n;
    cin >> n;
    stack<pair<int, int>> st;

    int nn = n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;

        while (!st.empty() && st.top().first < m)
            st.pop();

        // arr[i - 1] = st.empty() ? 0 : st.top().second;
        if (arr[i - 1] = st.empty())
        {
            arr[i - 1] = 0;
        }
        else
        {
            arr[i - 1] = st.top().second;
        }
        st.push({m, i});
    }

    for (int i = 0; i < nn; i++)
    {
        cout << arr[i] << ' ';
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
