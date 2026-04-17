#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    int la = a.length();

    int ck = 0;
    for (int i = 0; i < la; i++)
    {
        if (a[i] > b[i])
        {
            cout << '1';
            ck = 1;
            break;
        }
        if (a[i] < b[i])
        {
            cout << "-1";
            ck = 1;
            break;
        }
    }
    if (!ck)
    {
        cout << '0';
    }
    else
    {
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}