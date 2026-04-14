#include <bits/stdc++.h>
using namespace std;

struct S
{
    string word;
    int score;
};

void solve()
{
    S a[100];
    int p, n;
    cin >> p >> n;
    for (int i = 0; i < p; i++)
    {
        cin >> a[i].word >> a[i].score;
    }
    while (n--)
    {
        int total = 0;
        while (true)
        {
            string str;
            cin >> str;

            if (str == ".")
            {
                break;
            }

            bool used = false;
            for (int i = 0; i < p; i++)
            {
                if (str == a[i].word)
                {
                    total += a[i].score;
                    used = true;
                    break;
                }
            }

            int la = str.size();
            if (!used)
            {
                bool ck = true;
                for (int i = 0; i < la; i++)
                {
                    if (str[i] < 'a' || str[i] > 'z')
                    {
                        ck = false;
                        break;
                    }
                }
                if (ck)
                {
                    total += la / 2;
                }
                else
                {
                    total -= 2;
                }
            }
        }

        if (total > 99)
        {
            cout << "Perfect!\n";
        }
        else if (total < 60)
        {
            cout << "Fail!\n";
        }
        else
        {
            cout << total << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
