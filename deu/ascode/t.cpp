#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>

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

int isPal(int n)
{
    int mul = 10000000;
    int origin = n;
    int reverse = 0;
    while (origin > 0)
    {
        reverse += (origin % 10) * mul;
        origin /= 10;
        mul /= 10;
    }
    if (n == reverse)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPal(i) && prime[i])
        {
            cout << i << ' ';
            cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << "no";
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
