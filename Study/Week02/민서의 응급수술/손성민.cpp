#include <iostream>
#include <vector>
using namespace std;

// 민서의 응급 수술 (골드 4)
// https://www.acmicpc.net/problem/20955
// 그래프, 분리집합 Alg.
// 시간복잡도: O(n + m), 공간복잡도: O(1)
int n, m, u, v, cnt, visited[100004];
vector<int> adj[100004];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void dfs(int node) {
    visited[node] = 1;
    for(int next : adj[node]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
}
void input() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << (cnt - 1) + (m + cnt - n) << "\n";
}
int main() {
    fastIO();
    input();
    return 0;
}

// 먼저 dfs로 분리집합의 갯수를 구하고
// 연결 그래프로 만들 때 연산 횟수는 cnt - 1
// 트리로 만들기 위해서는 n - 1개의 간선이 필요
// 따라서 (m + cnt - 1) - x = n - 1
// x = m + cnt - n 추가로 제거해야 하는 간선의 갯수