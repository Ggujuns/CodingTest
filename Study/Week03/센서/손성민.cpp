#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 센서 (골드 5, 2212)
// https://www.acmicpc.net/problem/2212
int n, k, censor, ret;
vector<int> v;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> censor;
        v.push_back(censor);
    }
    return;
}
void solution() {
    if(k >= n) {
        cout << 0 << "\n";
        return;
    }
    sort(v.begin(), v.end());
    vector<int> diff;
    for(int i=1; i<n; i++) {
        if(v[i] == v[i-1]) continue; // 중복된 센서 값은 제외
        diff.push_back(v[i] - v[i-1]);
    }
    sort(diff.begin(), diff.end());
    for(int i=0; i<diff.size() - (k - 1); i++) {
        ret += diff[i];
    }
    cout << ret << "\n";
}
int main() {
    fastIO();
    input();
    solution();
    return 0;
}
// 1 3 6 6 7 9
// 1 2 2 3
// 1<->3 6<->9