#include <iostream>
using namespace std;

// N-Queen (골드 4, 9663)
// https://www.acmicpc.net/problem/9663
int n, ret, arr[16];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n;
    return;
}
bool check(int idx) {
    for(int i=0; i<idx; i++) {
        if(arr[i] == arr[idx]) return false;
        // 대각선에 있는지 확인
        if(abs(arr[idx] - arr[i]) == idx - i) return false;
    }
    return true;
}
void solution(int idx) {
    if(idx == n) {
        ret++;
        return;
    }
    for(int i=0; i<n; i++) {
        arr[idx] = i;
        if(check(idx)) solution(idx + 1);    
    }
    return;
}
int main() {
    fastIO();
    input();
    solution(0);
    cout << ret << "\n";
    return 0;
}