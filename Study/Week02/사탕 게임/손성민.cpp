#include <iostream>
#include <algorithm>
using namespace std;

// 사탕 게임 (실버 2)
// https://www.acmicpc.net/problem/3085
// 구현 Alg.
// 시간복잡도: O(n^4), 공간복잡도: O(n^)
int n, ret;
char arr[51][51];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void check() {
    for(int i=0; i<n; i++) {
        int cnt = 1;
        for(int j=0; j<n; j++) {
            if(arr[i][j] == arr[i][j+1]) cnt++;
            else {
                ret = max(ret, cnt);
                cnt = 1;        
            }
        }
    }
    for(int j=0; j<n; j++) {
        int cnt = 1;
        for(int i=0; i<n; i++) {
            if(arr[i][j] == arr[i+1][j]) cnt++;
            else {
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
    }
}
void solution() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // 행
            if(j < n-1) {
                if(arr[i][j] != arr[i][j+1]) {
                    swap(arr[i][j], arr[i][j+1]);
                    check();
                    swap(arr[i][j], arr[i][j+1]);
                }
            }
            // 열
            if(i < n-1) {
                if(arr[i][j] != arr[i+1][j]) {
                    swap(arr[i][j], arr[i+1][j]);
                    check();
                    swap(arr[i][j], arr[i+1][j]);
                }
            }
        }
    }
    cout << ret << "\n";
    return;
}
void input() {
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> arr[i][j];
    return;
}
int main() {
    fastIO();
    input();
    solution();
    return 0;
}