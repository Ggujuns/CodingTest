n, d, k, c = map(int, input().split())
# n: 접시 수, d: 초밥 가짓수, k: 연속접시 수, c: 쿠폰번호
sushi = [int(input()) for _ in range(n)]
refill_sushi = sushi + sushi[:k-1]

cnt = [0] * (d + 1)
kind = 0              

for i in range(k):
    if cnt[refill_sushi[i]] == 0:
        kind += 1
    cnt[refill_sushi[i]] += 1

ans = kind + (1 if cnt[c] == 0 else 0)

for s in range(1, n):
    left = refill_sushi[s-1]
    cnt[left] -= 1
    if cnt[left] == 0:
        kind -=1
    
    right = refill_sushi[s+k-1]
    if cnt[right] == 0:
        kind +=1
    cnt[right] += 1
    
    temp = kind + (1 if cnt[c] == 0 else 0)
    
    ans = max(ans, temp)
print(ans)

    
    