#include <iostream>
using namespace std;

// 색종이 만들기 (실버 2)
// https://www.acmicpc.net/problem/2630
// Alg.
// 시간복잡도: O(n^2logn), 공간복잡도: O(1)
int n, arr[128][128], white, blue;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solution(int y, int x, int size) {
    int color = arr[y][x];
    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            if(arr[i][j] != color) {
                solution(y, x, size / 2);   // 왼쪽 위
                solution(y, x + size / 2, size / 2); // 오른쪽 위
                solution(y + size / 2, x, size / 2); // 왼쪽 아래
                solution(y + size / 2, x + size / 2, size / 2); // 오른쪽 아래
                return;
            }
        }
    }
    if(color == 0) white++;
    else blue++;
    return;
}
void input() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    return;
}
int main() {
    fastIO();
    input();
    solution(0, 0, n);
    cout << white << "\n" << blue << "\n";
    return 0;
}