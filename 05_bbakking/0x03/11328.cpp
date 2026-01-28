#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string a, b;
    int arr[26] = {0};
    int brr[26] = {0};
    cin >> a >> b;
    int l = a.size();

    for (int i = 0; i < l; i++)
    {
        arr[a[i] - 'a']++;
        brr[b[i] - 'a']++;
    }

    int ck = 1;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != brr[i])
            ck = 0;
    }
    if (ck)
    {
        cout << "Possible\n";
    }
    else
    {
        cout << "Impossible\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}