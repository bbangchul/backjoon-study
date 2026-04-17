#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int ls = s.length();
    for (int i = 0; i < ls; i++)
    {
        if (s[i] == 'Z')
            s[i] = 'A';
        else
            s[i] = s[i] + 1;
    }
    cout << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}