#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

// 아기 상어 2(실버2, 17086)
// https://www.acmicpc.net/problem/17086
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1}; 
int n, m, cnt, flag, ret, arr[54][54], visited[54][54];
vector<pair<int,int>> v;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            if(!arr[i][j]) v.push_back({i, j});
        }
    }
    return;
}
void solution() {
    queue<pair<pair<int,int>, int>> q;
    for(pair<int,int> it : v) {
        int y = it.first, x = it.second;
        visited[y][x] = 1;
        q.push({{y, x}, 0});
        while(!q.empty()) {
            y = q.front().first.first, x = q.front().first.second, cnt = q.front().second; q.pop();
            for(int i=0; i<8; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                if(arr[ny][nx]) {
                    ret = max(ret, cnt + 1);
                    flag = 1;
                    break;
                }
                q.push({{ny, nx}, cnt + 1});
                visited[ny][nx] = 1;
            }
            if(flag) break;
        }
        q = queue<pair<pair<int,int>, int>>();
        memset(visited, 0, sizeof(visited));
        flag = 0;
    }
    return;
}
int main() {
    fastIO();
    input();
    solution();
    cout << ret << "\n";
    return 0;
}