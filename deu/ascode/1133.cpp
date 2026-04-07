#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A() {};
    string rs;
    int score;
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    A a[1000];
    char in[26];
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i].rs >> a[i].score;

    while (m--)
    {
        int sum = 0;
        int first = 1;

        while (1)
        {
            cin >> in;
            if (!strcmp(in, "."))
                break;

            int la = (int)strlen(in);
            int found = 1;

            for (int i = 0; i < n; i++)
            {
                if (!strcmp(in, a[i].rs.c_str()))
                {
                    sum -= a[i].score;
                    found = 0;
                    break;
                }
            }

            int special = (found && first && (in[0] < 'A' || in[0] > 'Z'));

            if (special)
                sum -= 5;
            else if (found)
                sum += la;

            first = 0;
        }

        if (sum < 0)
            cout << "Fail" << '\n';
        else
            cout << sum << '\n';
    }

    return 0;
}
