#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    char map[101][101] = {0};

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cin >> map[i][j];
        }
    }

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (map[i][j] == '*') {
                cout << '*';
            } else {
                int cnt = 0;

                for (int k = 0; k < 8; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (ny >= 0 && ny < y && nx >= 0 && nx < x) {
                        if (map[ny][nx] == '*') {
                            cnt++;
                        }
                    }
                }

                if (cnt == 0)
                    cout << '.';
                else
                    cout << cnt;
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
