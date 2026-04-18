#include <iostream>
#include <string>
using namespace std;

struct S
{
    string rs;
    int score;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    S a[1000];
    string in;
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i].rs >> a[i].score;

    while (m--)
    {
        int sum = 0;
        bool first = true;

        while (1)
        {
            cin >> in;
            if (in == ".")
                break;

            int la = in.length();
            bool found = false;

            for (int i = 0; i < n; i++)
            {
                if (in == a[i].rs)
                {
                    sum -= a[i].score;
                    found = true;
                    break;
                }
            }

            bool special = (!found && first && (in[0] < 'A' || in[0] > 'Z'));

            if (special)
                sum -= 5;
            else if (!found)
                sum += la;

            first = false;
        }

        if (sum < 0)
            cout << "Fail\n";
        else
            cout << sum << '\n';
    }

    return 0;
}