'''
트리의 필수 조건
- 연결 그래프 여야 한다.
- 간선수 = N-1이어야 한다.

연결 요소 개수 C

왜 Union Find이어야 하는가?
- 얼마나 연결이 되어 있는지 알기 위해


'''
import sys
input = sys.stdin.readline
# 작은게 부모
def find(x):
    if parent_neurons[x] != x:
        return find(parent_neurons[x])
    return x

def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent_neurons[b] = a
    else:
        parent_neurons[a] = b
n, m = map(int, input().split())

parent_neurons = [i for i in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    union(a, b)

for i in range(1, n+1):
    parent_neurons[i] = find(i)

# 현재 덩어리 개수
components = len(set(parent_neurons[1:]))

# 추가해야 할 간선 수
need_add_line = components - 1

# 삭제해야 할 간선 수
need_delete_line = m + need_add_line - (n - 1)  # == m + components - n

# 총 연산 수
print(need_add_line + need_delete_line)  # == m - n + 2*components - 1
