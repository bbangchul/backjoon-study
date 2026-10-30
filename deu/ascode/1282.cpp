#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    int m, n;
    cin >> m >> n;

    vector<string> board(m);
    int mine_count = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> board[i];
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '@')
            {
                mine_count++;
            }
        }
    }

    cout << m * n << ' ' << mine_count << '\n';

    if (mine_count == 0)
    {
        cout << "No Mine\n";
        return;
    }

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '@')
            {
                cout << '@';
                continue;
            }

            int count = 0;

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                {
                    continue;
                }

                if (board[nx][ny] == '@')
                {
                    count++;
                }
            }

            cout << count;
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
