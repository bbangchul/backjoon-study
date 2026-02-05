#include <bits/stdc++.h>

using namespace std;

void solve()
{
    deque<int> dq;
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push_back")
        {
            int tm;
            cin >> tm;
            dq.push_back(tm);
        }
        else if (s == "push_front")
        {
            int tm;
            cin >> tm;
            dq.push_front(tm);
        }
        else if (s == "pop_front")
        {
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (s == "pop_back")
        {
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (s == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (s == "empty")
        {
            if (dq.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (s == "front")
        {
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.front() << '\n';
        }
        else
        {
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.back() << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}
