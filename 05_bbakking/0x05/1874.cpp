#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    stack<int> st;

    int cnt = 1;
    vector<char> v;

    while (n--)
    {
        int x;
        cin >> x;

        while (cnt <= x)
        {
            st.push(cnt);
            cnt++;
            v.push_back('+');
        }

        if (st.empty() || st.top() != x)
        {
            cout << "NO\n";
            return;
        }

        st.pop();
        v.push_back('-');
    }

    for (char c : v)
    {
        cout << c << '\n';
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
