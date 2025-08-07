#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// A와 B 2 (12919)
// https://www.acmicpc.net/problem/12919
// 시간복잡도: O(2^N) (N: T의 길이)
// 공간복잡도: O(N) (N: T의 길이)

string S, T;
int lenS, lentT, ret;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> S >> T;
    lenS = S.length(); lentT = T.length();
    return;
}
void solution(string str) {
    if (str.length() == lenS && str == S) {
        ret = 1;
        return;
    }
    if(str.back() == 'B') {
        reverse(str.begin(), str.end());
        if(str.back() == 'B') {
            str.pop_back();
            solution(str);
        } else return;
    }
    else if(str.back() == 'A') {
        solution(str.substr(0, str.length() - 1));
        reverse(str.begin(), str.end());
        if(str.back() == 'B') {
            str.pop_back();
            solution(str);
        }
    }
    return;
}
int main() {
    fastIO();
    input();
    solution(T);
    cout << ret << "\n";
    return 0;
}