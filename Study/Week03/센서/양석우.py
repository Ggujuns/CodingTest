import sys
input = sys.stdin.readline

n = int(input())
k = int(input())
sensor = sorted(set(map(int, input().split())))
m = len(sensor)

gap = []
for i in range(m-1):
    gap.append(sensor[i+1]-sensor[i])

gap.sort()
if m <= k:
    print(0)
    exit()
for i in range(k-1):
    gap.pop()
print(sum(gap))