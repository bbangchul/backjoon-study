#include <bits/stdc++.h>
using namespace std;

void solve()
{
    stack<string> st;

    string line;
    while (getline(cin, line))
    {
        if (line == ".")
            break;

        stack<char> st;
        bool isValid = true;

        int ls = line.size();
        for (int i = 0; i < ls; i++)
        {
            char c = line[i];

            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    isValid = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    isValid = false;
                    break;
                }
                st.pop();
            }
            else if (c == '}')
            {
                if (st.empty() || st.top() != '{')
                {
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }

        if (!st.empty())
            isValid = false;

        if (isValid)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}