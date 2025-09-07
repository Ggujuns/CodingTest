import sys
input = sys.stdin.readline

n = int(input())

node = [0]*(n+1)
visited = [False]*(n+1)
parent = [0]*(n+1)
for i in range(1, n+1):
    start, left, right = map(int, input().split())
    node[start] = [left, right]
    # 부모 설정
    if left != -1:
        parent[left] = start
    if right != -1:
        parent[right] = start

def findEndNode():
    end = 1
    while node[end][1] != -1:
        end = node[end][1]
    return end

tempNode = 1
visited[tempNode] = True
cnt = 0
endNode = findEndNode()

while True:
    # 왼쪽 자식 노드 존재 + 방문 X라면
    if node[tempNode][0] != -1 and not visited[node[tempNode][0]]:
        # 왼쪽 자식노드 순회
        tempNode = node[tempNode][0]
        cnt += 1
        visited[tempNode] = True
    # 오른쪽 자식 노드 존재 + 아직 방문 X
    elif node[tempNode][1] != -1 and not visited[node[tempNode][1]]:
        # 오른쪽 자식노드 순회
        tempNode = node[tempNode][1]
        cnt += 1
        visited[tempNode] = True
    # 순회의 끝
    elif tempNode == endNode:
        break
    # 부모노드 탐색
    else:
        tempNode = parent[tempNode]
        cnt += 1
        visited[tempNode] = True
print(cnt)