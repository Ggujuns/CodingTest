#include <iostream>
#include <stack>
using namespace std;

// 스카이라인 쉬운거 (골드4)
// https://www.acmicpc.net/problem/1863
// 자료구조 Alg.
// 시간복잡도: O(n) 공간복잡도: O(n)
int n, x, y, ret;
stack <int> st;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
void solution() {
    cin >> n;
    for(int i=0; i<=n; i++) {
        // 마지막 입력은 없지만 0 추가
        if(i == n) y=0;
        else cin >> x >> y;
        // 스택이 비어있거나 현재 높이가 스택의 top보다 클 때
        while(!st.empty() && st.top() >= y) {
            if(st.top() != y) ret++;
            st.pop(); 
        }
        st.push(y);
    }
    cout << ret << "\n";
    return;
}
int main() {
    fastIO();
    solution();
    return 0;
}