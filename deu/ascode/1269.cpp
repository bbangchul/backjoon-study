#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int arr[MAX];

void solve()
{
    string s;
    cin >> s;
    int ls = s.size();

    arr[0] = 0;
    for (int i = 1; i < ls; i++)
    {
        if (s[i] == s[i - 1])
        {
            arr[i] = arr[i - 1];
        }
        else
        {
            arr[i] = arr[i - 1] + 1;
        }
    }

    int n;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a >> b;

        if (arr[a] == arr[b])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}