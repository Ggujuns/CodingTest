#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

// 미생물 연구
// 2025 삼성 상반기 오후 1번 기출
// https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/microbial-research/description
// 다 풀고, 입출력 에외 처리 하기!
const int maxN = 15;
const int maxQ = 50;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
// 좌표 구조체
struct COORDINATE {
    int r1, c1, r2, c2;
};
COORDINATE coordi[maxQ + 1];
// 미생물 구조체
struct MICRO {
    int id; // 미생물 번호
    int r1, c1, r2, c2;
    int size; // 미생물 크기
};
MICRO microbe[maxQ + 1];
int mcnt; // 살아있는 미생물 수
int n, q;
int arr[maxN + 1][maxN + 1], visited[maxN + 1][maxN + 1];
int dead[maxQ + 1]; // 죽은 미생물 관리
// 빠른 입출력
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 1. 미생물 투입
/*
- 좌측 하단 좌표가(r1, c1)에서 우측 상단 좌표가(r2, c2)인 직사각형 영역에 한 무리의 미생물 투입
- 영역 내에 다른 미생물이 존재한다면, 새로 투입된 미생물이 잡아먹음
- 기존 미생물 A가 새로운 미생물 B에 의해 나눠지는 경우, A는 전체 다 사라짐
*/

// Q1. 순서를 어떻게 관리할까?
// Q2. 잡아먹을 때 하나의 무리의 영역이 둘 이상으로 나눠지는지 안나눠지는지 어떻게 판별하는지?
// Q3. 배양 용기 이동할 때는 영역의 크기가 큰 것부터 이동하는데, 크기를 어떻게 관리할 건가?, 크기로 우선순위큐를 선언할까?, 크기를 관리한다면 잡아먹힐 때 해당 영역의 크기도 갱신해야 하지 않나?
void putMicrobe(int r1, int c1, int r2, int c2, int id) {
    for (int i = r1; i < r2; i++) {
        for (int j = c1; j < c2; j++) {
            arr[i][j] = id;
        }
    }
    return;
}
// 2. 배양 용기 이동
/*
- 모든 미생물을 새로운 배양 용기로 이동
- 기존 배양 용기 중 가장 영역이 넓은 무리 선택, 둘 이상이라면 선입선출
- 모양은 그대로 옮기고, x좌표가 작은 위치로 옮겨야 함, x좌표 같다면 y좌표가 작은 위치로
- 옮길 수 없다면 사라짐
*/
MICRO bfs(int y, int x) {
    int r1, c1, r2, c2, count = 1;
    r1 = r2 = y; c1 = c2 = x;
    queue<pair<int,int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while(!q.empty()) {
        int cy = q.front().first, cx = q.front().second;
        q.pop();
        for(int dir=0; dir<4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || arr[ny][nx] != arr[cy][cx]) continue;
            q.push({ny,nx});
            visited[ny][nx] = 1;
            count++;
            r1 = min(r1, ny); c1 = min(c1, nx);
            r2 = max(r2, ny); c2 = max(c2, nx);
        }
    }
    MICRO tmp;
    tmp.id = arr[y][x];
    tmp.r1 = r1; tmp.c1 = c1;
    tmp.r2 = r2; tmp.c2 = c2;
    tmp.size = count;
    return tmp;
}
void findActiveArea() {
    mcnt = 0;
    memset(visited, 0, sizeof(visited));

    // 살아있는 미생물 파악 (분리되어 있는지 아닌지)
    int check[maxQ + 1];
    memset(check, 0, sizeof(check));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int id = arr[i][j];
            if(!id || visited[i][j] || dead[id]) continue;
            MICRO tmp = bfs(i, j);
            if(check[id]) {
                dead[id] = 1;
                continue;
            }
            check[id] = 1;
            microbe[mcnt++] = tmp;
        }
    }
    // 마지막에 살아있는 미생물만 다시 정리 (중복 값이 있을 수 있어서)
    int cnt = mcnt;
    for(int i=0; i<cnt; i++) {
        if(dead[microbe[i].id]) continue;
        microbe[mcnt++] = microbe[i];
    }
}
// 우선순위 정렬 (크기 내림차순, 번호 오름차순)
bool cmp(MICRO a, MICRO b) {
    if(a.size != b.size) return a.size > b.size;
    return a.id < b.id;
}
void sort() {
    for(int i=0; i<mcnt-1; i++) {
        for(int j=i+1; j<mcnt; j++) {
            if(!cmp(microbe[i], microbe[j])) {
                MICRO tmp = microbe[i];
                microbe[i] = microbe[j];
                microbe[j] = tmp;
            }
        }
    }
    return;
}
bool check(int newArr[maxN + 1][maxN + 1], MICRO tmp, int y, int x) {
    int r1 = tmp.r1, c1 = tmp.c1, r2 = tmp.r2, c2 = tmp.c2;
    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            if(!arr[i][j] || arr[i][j] != tmp.id) continue;
            int ny = y - r1 + i;
            int nx = x - c1 + j;
            if(ny >= n || ny < 0 || nx >= n || nx < 0 || newArr[ny][nx]) return false;
        }
    }
    return true;
}
void shift(int newArr[maxN + 1][maxN + 1], MICRO tmp, int y, int x) {
    int r1 = tmp.r1, c1 = tmp.c1, r2 = tmp.r2, c2 = tmp.c2;
    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            if(arr[i][j] == 0 || arr[i][j] != tmp.id) continue;
            newArr[y - r1 + i][x - c1 + j] = tmp.id;
        }
    }
}
void moveMove(int newArr[maxN + 1][maxN + 1], MICRO tmp) {
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(check(newArr, tmp, i, j)) {
                shift(newArr, tmp, i, j);
                return;
            }
        }
    }
}
void move() {
    int newArr[maxN + 1][maxN + 1];
    memset(newArr, 0, sizeof(newArr));
    for(int i=0; i<mcnt; i++) {
        moveMove(newArr, microbe[i]);
    }
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            arr[i][j] = newArr[i][j];
        }
    }
    return;
}
void moveContainer() {
    findActiveArea();
    sort();
    move();
    return;
}
//3. 실험 결과 기록
/*
- 미생물 무리 중 상하좌우 맞닿은 면이 있는 무리끼리는 "인접한 무리"
- 모든 "인접한 무리"쌍 확인
- 무리 A, 무리 B가 인접하다면 A*B 만큼의 성과를 기록
- 모든 인접한 쌍에 대한 성과의 합
*/
int getSize(int id) {
    for(int i=0; i<mcnt; i++) {
        if(microbe[i].id == id) return microbe[i].size;
    }
    return 0;
}
int recordResult(int id) {
    int tmp[maxQ + 1][maxQ + 1];
    memset(tmp, 0, sizeof(tmp));
    // 인접한 무리 파악
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(!arr[i][j]) continue;
            for(int dir=0; dir<4; dir++) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                
                int idx1 = arr[i][j];
                int idx2 = arr[ny][nx];
                if(idx1 == idx2 || !idx2) continue;

                tmp[idx1][idx2] = 1;
                tmp[idx2][idx1] = 1;
            }
        }
    }
    int sum = 0;
    for(int i=1; i<=id-1; i++) {
        for(int j=i+1; j<=id; j++) {
            if(!tmp[i][j]) continue;
            int size1 = getSize(i);
            int size2 = getSize(j);
            // cout << "i: " << i << ", j: " << j << ", size1: " << size1 << ", size2: " << size2 << "\n";
            sum += (size1 * size2);
        }
    }
    return sum;
}
void solution() {
    // 입력
    cin >> n >> q;
    for(int i=1; i<=q; i++) {
        cin >> coordi[i].r1 >> coordi[i].c1 >> coordi[i].r2 >> coordi[i].c2;
    }
    // 처리
    for(int i=1; i<=q; i++) {
        putMicrobe(coordi[i].r1, coordi[i].c1, coordi[i].r2, coordi[i].c2, i);
        moveContainer();
        cout << recordResult(i) << "\n";
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return;
}
int main() {
    fastIO();
    solution();
    return 0;
}