from collections import deque

dr = [-1, -1, -1, 0, 0, 1, 1, 1]
dc = [-1, 0, 1, -1, 1, -1, 0, 1]

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]


def bfs(a, b):
    if graph[a][b] == 1:
        return 0
    distance = [[-1]*m for _ in range(n)]
    queue = deque()
    queue.append((a, b))
    distance[a][b] = 0

    while queue:
        r, c = queue.popleft()
        d = distance[r][c]
        for i in range(8):
            nr = r + dr[i]
            nc = c + dc[i]
            if 0<= nr < n and 0<= nc < m and distance[nr][nc] == -1:
                if graph[nr][nc] == 1:
                    return d+1
                distance[nr][nc] = d+1
                queue.append((nr, nc))
    return 0
anw = 0
for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            anw = max(anw, bfs(i,j))
print(anw)
