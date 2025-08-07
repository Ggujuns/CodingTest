#include <iostream>
#include <map>
#include <cmath>
using namespace std;

// 반복수열 (실버4)
// https://www.acmicpc.net/problem/2331
// 구현 Alg.

int A, P, ret = 1;
map <int, int> mp;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> A >> P;
    mp[A] = 1;
    return;
}
void removeDuplicates(int num) {
    int tmp = num;
    while(true) {
        int next = 0;
        while (num > 0) {
            next += pow(num % 10, P);
            num /= 10;
        }
        if(next == tmp) {
            cout << ret - 1 << "\n";
            return;
        }
        ret--;
        num = next;
    }
    return;
}
void solution() {
    while(true) {
        int next = 0;
        while(A > 0) {
            next += pow(A % 10, P);
            A /= 10;
        }
        if(mp[next] > 0) {
            removeDuplicates(next);
            return;
        }
        A = next; mp[next]++;
        ret++;
    }
    return;
}
int main() {
    fastIO();
    input();
    solution();
    return 0;
}