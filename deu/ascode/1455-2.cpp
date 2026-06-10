#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;

    char maze[11][11] = {0};
    int visited[11][11] = {0};

    int sx = 0, sy = 0;

    for (int i = 0; i < m; i++) {
        cin >> maze[i];
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    bool found = false;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cout << '(' << x << ", " << y << ") -> ";

        if (maze[x][y] == 'E') {
            found = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                visited[nx][ny] == 0 && maze[nx][ny] != '#') {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    if (found)
        cout << "YES\n";
    else
        cout << "NO\n";

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
