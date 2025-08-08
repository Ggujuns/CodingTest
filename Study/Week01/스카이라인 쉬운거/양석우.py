n = int(input())

stack = []
cnt = 0
for i in range(n):
    x, y = map(int, input().split())
    # 높 -> 낮
    while stack and stack[-1] > y:
        stack.pop()
    if not stack or stack[-1] < y:
        stack.append(y)
        if y != 0:
            cnt +=1
print(cnt)