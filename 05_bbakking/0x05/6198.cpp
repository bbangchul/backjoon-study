#include <bits/stdc++.h>

using namespace std;

stack<int> st;

void solve()
{
    int n;
    cin >> n;
    long long ans = 0;
    long long cmp;
    while (n--)
    {
        cin >> cmp;
        while (!st.empty() && st.top() <= cmp)
            st.pop();
        ans += st.size();
        st.push(cmp);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}