#include <iostream>
using namespace std;

// 참외밭 (실버 2)
// https://www.acmicpc.net/problem/2477
int arr[6][2], dir[4], ret, k;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
void input() {
    cin >> k;
    for(int i=0; i<6; i++) {
        cin >> arr[i][0] >> arr[i][1];
        dir[arr[i][0]-1]++; // 해당 방향이 몇 번 나왔는지 카운팅
    }
}
// 방향 카운팅, 가로 세로 쌍으로 나오므로 작은 사각형 계산
void solution() {
    int big = 1, small = 1;
    for(int i=0; i<6; i++) {
        if(dir[arr[i][0] - 1] == 1) {
            big *= arr[i][1];
            continue;
        }
        int next = (i + 1) % 6;
        int nnext = (i + 2) % 6;
        if(arr[i][0] == arr[nnext][0]) small *= arr[next][1];
    }
    cout << (big - small) * k << "\n";
    return;
}
int main() {
    fastIO();
    input();
    solution();
    return 0;
 }