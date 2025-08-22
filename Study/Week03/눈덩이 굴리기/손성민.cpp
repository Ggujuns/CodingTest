#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 눈덩이 굴리기 (실버3, 21735)
// https://www.acmicpc.net/problem/21735
// 시간복잡도: O(2^m), 공간복잡도: O(n)
long long n, m, ret, snow;
vector<int> v;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n >> m;
    v.push_back(0);
    for(int i=0; i<n; i++) {
        cin >> snow;
        v.push_back(snow);
    }
    return;
}
void solution(long long sum, long long cnt, long long idx) {
    // m초 동안 눈덩이를 굴렸다면
    if(cnt == m || idx > n) {
        ret = max(ret, sum);
        return;
    }
    
    // 현재 위치 + 1칸
    solution(sum + v[idx + 1], cnt + 1, idx + 1);
    // 현재 위치 + 2칸
    solution(sum / 2 + v[idx + 2], cnt + 1, idx + 2);
    return;
}
int main() {
    fastIO();
    input();
    solution(1, 0, 0);
    cout << ret << "\n";
    return 0;
}