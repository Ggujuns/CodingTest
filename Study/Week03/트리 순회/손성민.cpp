#include <iostream>
#include <vector>
using namespace std;

// 트리 순회 (골드 4)
// https://www.acmicpc.net/problem/22856
// 트리 Alg.
// 시간복잡도: O(n), 공간복잡도: O(n)
struct node {
    int data;
    node *left = NULL;
    node *right = NULL;
    node *parent = NULL;
};
int n, a, b, c, lastNode, ret, visited[100004];
vector<node> tree(100004);
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b >> c;
        tree[a].data = a;
        if(b != -1) {
            tree[a].left = &tree[b];
            tree[b].parent = &tree[a];
        }
        if(c != -1) {
            tree[a].right = &tree[c];
            tree[c].parent = &tree[a];
        }
    }
    return;
}
void findLastNode(node *cur) {
    if(cur == NULL) return;
    findLastNode(cur->left);
    lastNode = cur->data;
    findLastNode(cur->right);
    return;
}
void solution(node *cur) {
    // 현재 위치한 노드 왼쪽에 방문하지 않은 노드가 있다면
    if(cur->left != NULL && visited[cur->left->data] == 0) {
        visited[cur->left->data] = 1;
        ret++;
        solution(cur->left);
    // 현재 위치한 노드 오른쪽에 방문하지 않은 노드가 있다면
    } else if(cur->right != NULL && visited[cur->right->data] == 0) {
        visited[cur->right->data] = 1;
        ret++;
        solution(cur->right);
    // 마지막 노드라면
    } else if(cur->data == lastNode) {
        return;
    // 마지막 노드가 아니고, 부모 노드가 존재한다면
    } else {
        ret++;
        solution(cur->parent);
    }
    return;
}
int main() {
    fastIO();
    input();
    findLastNode(&tree[1]);
    solution(&tree[1]);
    cout << ret << "\n";
    return 0;
}