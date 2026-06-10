#include <bits/stdc++.h>
using namespace std;

struct cell {
    int x, y;
};

char maze[101][101];
int dista[101][101];

void solve() {
    int n, m;
    cin >> n >> m;

    int sx, sy;
    int ex, ey;

    for (int i = 0; i < n; i++) {
        cin >> maze[i];

        for (int j = 0; j < m; j++) {
            dista[i][j] = -1;

            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            }

            if (maze[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<cell> q;

    q.push({sx, sy});
    dista[sx][sy] = 0;

    while (!q.empty()) {
        cell cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                dista[nx][ny] == -1 && maze[nx][ny] != '#') {
                dista[nx][ny] = dista[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dista[ex][ey] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
