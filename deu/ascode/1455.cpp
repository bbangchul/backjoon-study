#include <bits/stdc++.h>
using namespace std;

#define MAX 10

struct mcell {
    int x, y;
};

void search_maze(
    stack<mcell> &st,
    int visited[MAX][MAX],
    char maze[MAX][MAX + 1],
    int nx, int ny,
    int m, int n) {
    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
        return;

    if (visited[nx][ny] != 0)
        return;

    if (maze[nx][ny] == '#')
        return;

    visited[nx][ny] = 1;
    st.push({nx, ny});
}

void solve() {
    int m, n;
    cin >> m >> n;

    char maze[MAX][MAX + 1];
    int visited[MAX][MAX] = {0};

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

    stack<mcell> st;
    st.push({sx, sy});
    visited[sx][sy] = 1;

    while (!st.empty()) {
        mcell cur = st.top();
        st.pop();
        visited[cur.x][cur.y] = -1;

        if (maze[cur.x][cur.y] == 'E') {
            cout << "YES\n";
            return;
        }

        search_maze(st, visited, maze,
                    cur.x - 1, cur.y,
                    m, n);

        search_maze(st, visited, maze,
                    cur.x + 1, cur.y,
                    m, n);

        search_maze(st, visited, maze,
                    cur.x, cur.y - 1,
                    m, n);

        search_maze(st, visited, maze,
                    cur.x, cur.y + 1,
                    m, n);
    }

    cout << "NO\n";
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
