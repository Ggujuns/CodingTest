import sys

def max_run_in_row(board, r):
    n = len(board)
    cnt = 1
    best = 1
    for c in range(1, n):
        if board[r][c] == board[r][c-1]:
            cnt += 1
        else:
            cnt = 1
        if cnt > best:
            best = cnt
    return best

def max_run_in_col(board, c):
    n = len(board)
    cnt = 1
    best = 1
    for r in range(1, n):
        if board[r][c] == board[r-1][c]:
            cnt += 1
        else:
            cnt = 1
        if cnt > best:
            best = cnt
    return best

def check_lines(board, rows, cols):
    best = 0
    for r in rows:
        best = max(best, max_run_in_row(board, r))
    for c in cols:
        best = max(best, max_run_in_col(board, c))
    return best

input = sys.stdin.readline
n = int(input().strip())
board = [list(input().strip()) for _ in range(n)]

ans = 1
for r in range(n):
    ans = max(ans, max_run_in_row(board, r))
for c in range(n):
    ans = max(ans, max_run_in_col(board, c))
if ans == n:
    print(n)
    sys.exit(0)

directions = [(0, 1), (1, 0)]
for r in range(n):
    for c in range(n):
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if nr >= n or nc >= n:
                continue
            if board[r][c] == board[nr][nc]:
                continue

            board[r][c], board[nr][nc] = board[nr][nc], board[r][c]

            rows = {r, nr}
            cols = {c, nc}
            ans = max(ans, check_lines(board, rows, cols))

            # 원상복구
            board[r][c], board[nr][nc] = board[nr][nc], board[r][c]

            if ans == n:
                print(n)
                sys.exit(0)
print(ans)