#include <bits/stdc++.h>
using namespace std;

const int MAX = 32768;

bool prime[MAX];

void cal()
{
    for (int i = 0; i < MAX; i++)
    {
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

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
    cal();

    int n;

    while (cin >> n)
    {

        if (n == 0)

            break;

        int count = 0;

        // 중복 제거 위해 n/2 까지만 검사

        for (int i = 2; i <= n / 2; i++)
        {

            if (prime[i] && prime[n - i])
            {

                count++;
            }
        }

        cout << count << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}