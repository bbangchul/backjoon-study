#include <bits/stdc++.h>

using namespace std;

void solve()
{
    stack<int> st;
    int k;
    int sum = 0;

    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            sum -= st.top();
            st.pop();
        }
        else
        {
            st.push(n);
            sum += n;
        }
    }
    cout << sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}