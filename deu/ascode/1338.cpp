#include <bits/stdc++.h>
using namespace std;

int m, n;
char arr[51][51];
int visited[51][51];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve() {
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    int answer = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '1' && visited[i][j] == 0) {
                queue<pair<int, int>> q;

                q.push({i, j});
                visited[i][j] = 1;

                int cnt = 1;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;

                        if (visited[nx][ny] == 0 && arr[nx][ny] == '1') {
                            visited[nx][ny] = 1;
                            q.push({nx, ny});
                            cnt++;
                        }
                    }
                }

                answer = max(answer, cnt);
            }
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
int board[1002][1002];
int dist[1002][1002];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  queue<pair<int,int> > Q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 1)
        Q.push({i,j});
      if(board[i][j] == 0)
        dist[i][j] = -1;
    }
  }
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist[nx][ny] >= 0) continue;
      dist[nx][ny] = dist[cur.X][cur.Y]+1;
      Q.push({nx,ny});
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(dist[i][j] == -1){
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans;
}

*/
