#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        stack<int> st;
        for (auto c : a)
        {
            if (!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(c);
        }
        if (st.empty())
            ans++;
    }
    cout << ans << "\n";
}