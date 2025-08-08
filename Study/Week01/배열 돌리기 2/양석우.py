import sys
input = sys.stdin.readline
N, M, R = map(int ,input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

lines = min(N, M)//2
def printarr():
    for i in range(N):
        for j in range(M):
            print(arr[i][j], end=" ")
        print()

# line: 돌리는 layer층
for line in range(lines):
    height = N-2*line
    width = M-2*line

    rotate = R % (2*(height +width -2))


    for i in range(rotate):
        r = line
        c = line
        temp = arr[r][c]
        for j in range(4):
            while True:
                nr = r+dr[j]
                nc = c+dc[j]

                if (nr < line or nr >= N - line or nc < line or nc >= M - line):
                    break

                arr[r][c] = arr[nr][nc]
                r, c = nr, nc
        arr[line+1][line] = temp
printarr()


