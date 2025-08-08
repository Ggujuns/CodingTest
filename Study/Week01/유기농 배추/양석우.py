from collections import deque

T = int(input())

def bfs(r, c):
    queue= deque()
    queue.append((r, c))
    graph[r][c] = 0

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nr = x+dr[i]
            nc = y+dc[i]
            if (0 > nr or nr >= N or 0> nc or nc >= M or graph[nr][nc] == 0):
                continue
            graph[nr][nc] = 0
            queue.append((nr,nc))
    return

# M: 가로 길이, N: 새로 길이, K: 위치 개수

dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]


for t in range(T):
    M, N, K = map(int, input().split(" "))
    graph = [[0]*M for _ in range(N)]

    cnt = 0
    for i in range(K):
        X, Y = map(int ,input().split())
        graph[Y][X] = 1
    
    for i in range(N):
        for j in range(M):
            # print(graph[i][j], end=" ")
            if graph[i][j] == 1:
                bfs(i, j)
                cnt +=1
        # print()
    print(cnt)
    

