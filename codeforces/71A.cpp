#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    int ls = s.length();
    if (ls <= 10)
    {
        cout << s << '\n';
        return;
    }
    else
    {
        cout << s[0] << ls - 2 << s[ls - 1] << '\n';
    }
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
}