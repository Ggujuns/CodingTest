n,  m = map(int, input().split())
snow = list(map(int, input().split()))

# dp[t][i]: t초에 위치 i에 도달할 때 가능한 최대 눈덩이 크기
dp = [[-1]*(n+1) for _ in range(m+1)]
dp[0][0] = 1

ans = 1

for t in range(m):
    for i in range(n+1):
        cur = dp[t][i]
        if cur < 0:
            continue
        # 중간에 있는 값이 더 크다면
        if cur > ans:
            ans = cur
        if i == n:
            continue
        # 1칸
        if i+1 <= n:
            next = cur + snow[i]
            if dp[t+1][i+1] < next:
                dp[t+1][i+1] = next
        # 2칸
        if i+2 <= n:
            nxt = (cur//2) + snow[i+1]
            if dp[t+1][i+2] < nxt:
                dp[t+1][i+2] = nxt

for i in range(n+1):
    if dp[m][i]>ans:
        ans = dp[m][i]

print(ans)

