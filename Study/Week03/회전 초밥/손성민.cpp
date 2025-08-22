#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 회전 초밥(실버1, 2531)
// https://www.acmicpc.net/problem/2531
int n, d, k, c;
int flag, coupon, ret;
int arr[300001];
int check[3001];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n >> d >> k >> c;
    for(int i=0; i<n; i++) cin >> arr[i];
    return;
}
void solution() {
    for(int i=0; i<n; i++) {
        flag = 0; coupon = 1;
        // k 만큼 슬라이딩 윈도우
        for(int j=i; j<i+k; j++) {
            if(check[arr[j % n]] == 1) flag++;  // 이미 먹은 초밥인 경우
            else check[arr[j % n]] = 1; // 처음 먹어보는 초밥인 경우
            if(arr[j % n] == c) coupon = 0; // 먹은 초밥이 쿠폰 초밥인 경우
        }
        ret = max(ret, k - flag + coupon);
        memset(check, 0, sizeof(check));
    }
    cout << ret << "\n";
    return;
}
int main() {
    fastIO();
    input();
    solution();
    return 0;
}