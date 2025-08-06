#include <iostream>
#include <algorithm>
using namespace std;

// 배열 돌리기 2 (골드5)
// https://www.acmicpc.net/problem/16927
// 구현 Alg.
const int dy[4] = {0, 1, 0, -1}; // 위, 왼쪽, 아래, 오른쪽
const int dx[4] = {1, 0, -1, 0};
int n, m, r;
int arr[301][301];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n >> m >> r;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    return;
}
void solution() {
    int depth = min(n, m) / 2;
    int N = n, M = m;
    for(int i=0; i<depth; i++) {
        int height = n - 2 * i;
        int width = m - 2 * i;
        int cnt = 2 * (height + width) - 4;
        int rotate = r % cnt;
        while(rotate--) {
            int tmp = arr[i][i];
            int y = i, x = i;
            int dir = 0;
            while(dir < 4) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(ny == i && nx == i) break;
                if(ny < i || ny >= n - i || nx < i || nx >= m - i) {
                    dir++;
                    continue;
                }
                arr[y][x] = arr[ny][nx];
                y = ny; x = nx;
            }
            arr[i + 1][i] = tmp; // 마지막 위치에 원래 값
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}
int main() {
    fastIO();
    input();
    solution();
    return 0;
}