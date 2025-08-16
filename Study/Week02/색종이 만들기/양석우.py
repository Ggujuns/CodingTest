'''
왜 분할 정복인가?
- 목적: 특정 범위구간 내에서는 모두 동일한 값을 가진다.
- => 탐색하려는 한 영역이 모두 같은 값이거나 or 분할 후 1개만 남거나
'''

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

color_dict = {1:0, 0:0}

# 일정한 색인지 확인
def color_test(r, c, size):
    temp = graph[r][c]
    for i in range(r, r+size):
        for j in range(c, c+size):
            if temp != graph[i][j]:
                return False
    return True


def divide_conquer(r, c, size):
    if size == 1 or color_test(r, c, size):
        color_dict[graph[r][c]] += 1
        return
    
    divide = size//2
    divide_conquer(r, c, divide)
    divide_conquer(r, c+divide, divide)
    divide_conquer(r+divide, c, divide)
    divide_conquer(r+divide, c+divide, divide)

divide_conquer(0,0,n)
print(color_dict[0])
print(color_dict[1])

