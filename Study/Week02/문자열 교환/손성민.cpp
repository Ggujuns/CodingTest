#include <iostream>
#include <algorithm>
using namespace std;

// 문자열 교환 (실버 1)
// https://www.acmicpc.net/problem/1522
// 슬라이딩 윈도우 Alg.
// 시간복잡도: O(n), 공간복잡도: O(1)

string str;
int n, aWindowSize, bWindowSize, aCnt, bCnt, ret;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solution() {
    cin >> str;
    n = str.length();
    for (char ch : str) {
        if(ch == 'a') aWindowSize++;
        else bWindowSize++;
    }

    // a를 가운데로 몰기
    for(int i=0; i<aWindowSize; i++) if(str[i] == 'b') bCnt++;
    ret = bCnt;
    for(int i=0; i<n-aWindowSize; i++) {
        if(str[i] == 'b') bCnt--;
        if(str[i + aWindowSize] == 'b') bCnt++;
        ret = min(ret, bCnt);
    }

    int tmp = ret;

    // b를 가운데로 몰기
    for(int i=0; i<bWindowSize; i++) if(str[i] == 'a') aCnt++;
    ret = aCnt;
    for(int i=0; i<n-bWindowSize; i++) {
        if(str[i] == 'a') aCnt--;
        if(str[i + bWindowSize] == 'a') aCnt++;
        ret = min(ret, aCnt);
    }
    
    ret = min(ret, tmp);
    cout << ret << "\n";
    return;
}
int main() {
    fastIO();
    solution();
    return 0;
}

// abababababababa
// aWindowSize: 8, bWindowSize: 7

// a를 가운데로 모는 경우
// aWindowSize안에 있는 b의 갯수를 최소화 하기
// b를 가운데로 모는 경우
// bWindowSize안에 있는 a의 갯수를 최소화 하기
// 두 경우 중 최소값을 출력