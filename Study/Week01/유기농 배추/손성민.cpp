#include <bits/stdc++.h>
using namespace std;

// 유기농 배추 (실버2)
// https://www.acmicpc.net/problem/1012
// DFS/BFS Alg.

const int max_n = 50;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int T, M, N, K, cnt;
int visited[max_n][max_n], arr[max_n][max_n];
void input(){
    int x, y;
    cin >> M >> N >> K;
    for(int i=0; i<K; i++){
        cin >> x >> y;
        arr[x][y] = 1;
    }
}
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if(arr[ny][nx] == 1 && !visited[ny][nx]) dfs(ny, nx);
    }
    return;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for(int i=0; i<T; i++){
        input();
        for(int a=0; a<M; a++){
            for(int b=0; b<N; b++){
                if(arr[a][b] == 1 && !visited[a][b]){
                    cnt++; dfs(a, b);
                }
            }
        }
        cout << cnt << "\n";
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }
    return 0;
}