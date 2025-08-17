#include <iostream>
#include <algorithm>
using namespace std;

// 퇴사 2 (골드 5)
// https://www.acmicpc.net/problem/15486
// DP Alg.
// 시간복잡도: O(n), 공간복잡도: O(1)
int n, t, p, dp[1500051];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
void solution() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> t >> p;
        if(dp[i] < dp[i-1]) dp[i] = dp[i-1];
        if(i + t > n + 1) continue; // 퇴사일을 넘는 경우
        dp[i + t] = max(dp[i + t], dp[i] + p);
    }
    cout << max(dp[n], dp[n + 1]) << "\n";
    return;
}
int main() {
    fastIO();
    solution();
    return 0;
}