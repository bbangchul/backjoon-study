#include <bits/stdc++.h>

using namespace std;

bool isOperator(string s)
{
    return s == "+" || s == "-" || s == "*" || s == "/";
}

void solve()
{
    int n;
    cin >> n;

    stack<int> st;
    bool ok = true;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (isOperator(s))
        {
            if (st.size() < 2)
            {
                ok = false;
                continue;
            }

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (s == "+")
                st.push(a + b);
            else if (s == "-")
                st.push(a - b);
            else if (s == "*")
                st.push(a * b);
            else if (s == "/")
                st.push(a / b);
        }
        else
        {
            st.push(atoi(s.c_str()));
        }
    }

    if (ok && st.size() == 1)
        cout << st.top() << '\n';
    else
        cout << "Incorrect Expression!" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}