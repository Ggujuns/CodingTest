import sys
from collections import deque

dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]

input = sys.stdin.readline

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

min_val = min(map(min, graph))
max_val = max(map(max, graph))

def checkField(height):
    global graph
    visited = [[False] * n for _ in range(n)]
    cnt = 0
    for i in range(n):
        for j in range(n):
            if graph[i][j] > height and not visited[i][j]:
                visited = bfs(i, j, height, visited)
                cnt +=1
    return cnt


def bfs(r, c, height, visited):
    queue = deque([(r, c)])
    visited[r][c] = True

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x + dr[i], y + dc[i]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and graph[nx][ny] > height:
                queue.append((nx, ny))
                visited[nx][ny] = True
    return visited
                
result = 0
for i in range(max_val):
    result = max(result, checkField(i))
print(result)
