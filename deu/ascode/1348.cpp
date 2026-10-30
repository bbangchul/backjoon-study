#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000012;

bool prime[MAX];

void makePrime()
{
    for (int i = 0; i < MAX; i++)
    {
        prime[i] = true;
    }

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i < MAX; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

void solve()
{
    int m, n;
    cin >> m >> n;

    if (m > n)
    {
        swap(m, n);
    }

    int cnt = 1;
    bool found = false;

    for (int i = m; i <= n - 12; i++)
    {
        if (prime[i] && prime[i + 6] && prime[i + 12])
        {
            cout << cnt << ": " << i << "-" << i + 6 << "-" << i + 12 << '\n';
            cnt++;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No Sexy Prime Triplets!\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    makePrime();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}