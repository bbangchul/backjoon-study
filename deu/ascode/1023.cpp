#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int start = (n + 1) / 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int layer = i;
            if (j < layer)
                layer = j;
            if (n - 1 - i < layer)
                layer = n - 1 - i;
            if (n - 1 - j < layer)
                layer = n - 1 - j;
            cout << start - layer;
        }
        cout << '\n';
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

    return 0;
}
