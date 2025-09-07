import sys
input = sys.stdin.readline

dr = [-1, -1, -1]
dc = [-1, 0, 1]

n = int(input())

col = [False]*n
diag1 = [False]*(2*n-1)
diag2 = [False]*(2*n-1)

cnt = 0
chess = [[False]*n for _ in range(n)]

def queenCheck(r, c):
    d1 = r+c
    d2 = r-c+(n-1)
    # 대각선 체크
    return not (col[c] or diag1[d1] or diag2[d2])
def backtracking(depth):
    global cnt
    if depth == n:
        cnt+=1
        return
    for i in range(n):
        if (queenCheck(depth, i)):
            chess[depth][i] = True
            d1 = depth +i
            d2 = depth -i +(n-1)
            col[i] = diag1[d1] = diag2[d2] = True

            backtracking(depth+1)

            col[i] = diag1[d1] = diag2[d2] = False
            chess[depth][i] = False

backtracking(0)
print(cnt)
