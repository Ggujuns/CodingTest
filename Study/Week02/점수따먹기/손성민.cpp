#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

// 점수따먹기 (골드 4)
// https://www.acmicpc.net/problem/1749
// 누적합, Brute Force Alg.
// 시간복잡도: O(n^2 * m^2), 공간복잡도: O(n * m)
int n, m, arr[201][201];
int ret = INT_MIN;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solution(int y, int x) {
    int tmp = INT_MIN;
    for(int i=1; i<=n-y; i++) {
        for(int j=1; j<=m-x; j++) {
            tmp = max(tmp, arr[y + i - 1][x + j - 1] - arr[y - 1][x + j - 1] - arr[y + i - 1][x - 1] + arr[y - 1][x - 1]);
        }
    }
    ret = max(ret, tmp);
    return;
}
void input() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            solution(i, j);
        }
    }
    cout << ret << "\n";
    return;
}
int main() {
    fastIO();
    input();
    return 0;
}