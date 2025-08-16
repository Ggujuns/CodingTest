import sys
input = sys.stdin.readline

n = int(input())
t = [0]*(n+1)
p = [0]*(n+1)

for i in range(1, n+1):
    a, b = map(int ,input().split())
    t[i] = a
    p[i] = b

dp = [0]*(n+2)

for i in range(1, n+1):
    dp[i] = max(dp[i-1], dp[i])
    if i + t[i] <= n+1:
        dp[i+t[i]] = max(dp[i+t[i]], dp[i]+p[i]) 
print(max(dp[n+1], dp[n]))