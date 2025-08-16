import sys
input = sys.stdin.readline
n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

max_num = -1e9

dp = [[0]*(m+1) for _ in range(n+1)]
# 시간 초과 코드
# for r in range(n):
#     for c in range(m):
#         h, w = n-r, m-c
#         dp = [[0]*(w+1) for _ in range(h+1)]
#         for i in range(1,h+1):
#             for j in range(1,w+1):
#                 dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + graph[r+i-1][c+j-1]
#                 if dp[i][j] > max_num:
#                     max_num = dp[i][j]
'''
왜 누적합을 구하는가?
- 그 값을 가지고 추가적으로 활용하기 위해서

r, c의 시작점을 정해주는 이유가 뭘까?
- 시작점을 바꿔서 누적합을 구해주면 되니까
'''
for i in range(1, n+1):
    for j in range(1, m+1):
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + graph[i-1][j-1]

for r in range(1, n):
    for c in range(1, m):
        for i in range(r, n+1):
            for j in range(c, m+1):
                temp = max(dp[i][j] - dp[i-r][j] - dp[i][j-c] + dp[i-r][j-c], dp[i][j])
                if max_num < temp:
                    max_num = temp
                    

print(max_num)
