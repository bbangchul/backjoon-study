#include <bits/stdc++.h>
using namespace std;

int h, w;
char maze[101][101];
bool visited[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int weightSum;
int distSum;

int getWeight(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    return c - 'A' + 100;
}

void dfs(int y, int x, int dist) {
    visited[y][x] = true;

    if (isalpha(maze[y][x])) {
        weightSum += getWeight(maze[y][x]);
        distSum += dist;
    }

    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
            if (!visited[ny][nx] && maze[ny][nx] != '1') {
                dfs(ny, nx, dist + 1);
            }
        }
    }
}

void solve() {
    cin >> h >> w;
    cin.ignore();

    int sy = 0, sx = 0;

    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);

        for (int j = 0; j < w; j++) {
            maze[i][j] = line[j];

            if (maze[i][j] == '0') {
                sy = i;
                sx = j;
            }

            visited[i][j] = false;
        }
    }

    weightSum = 0;
    distSum = 0;

    dfs(sy, sx, 0);

    if (weightSum == 0) {
        cout << "No treasure.\n";
    } else {
        cout << "weight: " << weightSum << '\n';
        cout << "distance: " << distSum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
        if (t > 0) {
            cout << '\n';
        }
    }

    return 0;
}
