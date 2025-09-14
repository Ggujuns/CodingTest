import sys
input = sys.stdin.readline
from collections import deque

dr = [1,-1,0,0]
dc = [0,0,1,-1]

n, q = map(int, input().split())
board = [[0]*n for _ in range(n)]

def overwrite(r1, c1, r2, c2, idx):
    global board
    for r in range(r1, r2):
        for c in range(c1, c2):
            board[r][c] = idx
    return

def divideCheck():
    visited = [[False]*n for _ in range(n)]
    # 연결 요소 개수
    comp_count = {}
    
    for r in range(n):
        for c in range(n):
            idx = board[r][c]
            # 미생물이 없거나, 방문한 경우
            if idx == 0 or visited[r][c]:
                continue

            comp_count[idx] = comp_count.get(idx,0) + 1
            q = deque()
            q.append((r, c))
            visited[r][c] = True

            while q:
                cr, cc = q.popleft()
                for i in range(4):
                    nr, nc = cr + dr[i], cc + dc[i]
                    if 0<= nr < n and 0<= nc < n and not visited[nr][nc] and board[nr][nc] == idx:
                        visited[nr][nc] = True
                        q.append((nr, nc))
    # 2개 이상인 것 삭제
    kill_set = {gid for gid, cnt in comp_count.items() if cnt >= 2}

    if not kill_set:
        return
    for r in range(n):
        for c in range(n):
            if board[r][c] in kill_set:
                board[r][c] = 0

def extractGroups():
    visited = [[False]*n for _ in range(n)]
    groups = []

    for r in range(n):
        for c in range(n):
            gid = board[r][c]

            if gid == 0 or visited[r][c]:
                continue

            q = deque([(r,c)])
            visited[r][c] = True
            cells = [(r, c)]

            while q:
                cr, cc = q.popleft()
                for i in range(4):
                    nr, nc = cr+dr[i], cc+dc[i]
                    if 0<= nr < n and 0 <= nc < n and not visited[nr][nc] and board[nr][nc] == gid:
                        visited[nr][nc] = True
                        cells.append((nr, nc))
                        q.append((nr, nc))
            
            # r기준, c기준 정렬 기준값 찾기
            ar, ac = min(cells, key= lambda x: (x[0], x[1]))
            shape = [(r - ar, c - ac) for r, c in cells]

            groups.append({
                "id":gid,
                "size":len(cells),
                "shape":shape
            })
    groups.sort(key = lambda g: (-g["size"], g["id"]))
    return groups

def movePalette():
    groups = extractGroups()
    new_board = [[0]*n for _ in range(n)]

    for g in groups:
        gid = g["id"]
        shape = g["shape"]

        placed = False
        
        # 열 부터 탐색
        for c in range(n):
            if placed: break
            for r in range(n):

                ok = True
                for dr, dc in shape:
                    rr, cc = r + dr, c+dc
                    # 범위 체크
                    if not (0 <= rr < n and 0 <= cc < n):
                        ok = False
                        break
                    # 충돌 체크
                    if new_board[rr][cc] != 0:
                        ok = False
                        break
                if not ok:
                    continue

                # 배치하기
                for dr, dc in shape:
                    rr, cc = r + dr, c + dc
                    new_board[rr][cc] = gid
                placed = True
                break
    return new_board

def boardDebug(board):
    for r in range(n):
        for c in range(n):
            print(board[r][c], end=" ")
        print()
    print('--------------')
    return

# 점수계산
def calc_score(board):
    id_to_size = {}
    for r in range(n):
        for c in range(n):
            gid = board[r][c]
            if gid == 0:
                continue
            id_to_size[gid] = id_to_size.get(gid, 0) + 1

    pairs = set()
    for r in range(n):
        for c in range(n):
            gid = board[r][c]
            if gid == 0:
                continue
            for i in range(4):
                nr, nc = r + dr[i], c + dc[i]
                if 0 <= nr < n and 0 <= nc < n:
                    ngid = board[nr][nc]
                    if ngid != 0 and ngid != gid:
                        a, b = sorted((gid, ngid))
                        pairs.add((a, b))

    score = 0
    for a, b in pairs:
        score += id_to_size[a] * id_to_size[b]
    return score

for idx in range(1, q+1):
    r1, c1, r2, c2 = map(int, input().split())

    # 덮어쓰기
    overwrite(r1, c1, r2, c2, idx)
    # 분할체크
    divideCheck()
    board = movePalette()
    boardDebug(board)
    print(calc_score(board))