#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct
{
    string word;
    int score;
} s;

void solve()
{
    int p, n;
    cin >> p >> n;
    s arr[100];
    for (int i = 0; i < p; i++)
    {
        cin >> arr[i].word >> arr[i].score;
    }

    while (n--)
    {
        int sum = 0;
        while (1)
        {
            string in;
            cin >> in;

            if (in == ".")
            {
                break;
            }

            int ck = 0;

            for (int i = 0; i < p; i++)
            {
                if (arr[i].word == in)
                {
                    ck = 1;
                    sum += arr[i].score;
                }
            }
            int ls = in.length();
            if (!ck)
            {
                if (ls % 4 == 0)
                {
                    sum += 2;
                }
            }
        }
        if (sum >= 100)
        {
            cout << "Perfect!\n";
        }
        else
        {
            cout << sum << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}