#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    string name;
    int stunum;
    double score[5];
    int maxscore = 0;
} s;

void solve()
{
    s arr[100];
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        double sum = 0;
        cin >> arr[i].name >> arr[i].stunum;
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i].score[j];
            sum += arr[i].score[j];
            if (arr[i].score[j] > arr[i].maxscore)
            {
                arr[i].maxscore = arr[i].score[j];
            }
        }
        cout << arr[i].name << ' ' << arr[i].maxscore << ' ';
        cout << fixed << setprecision(2) << sum / 5 << "\n";
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
        cout << '\n';
    }
}