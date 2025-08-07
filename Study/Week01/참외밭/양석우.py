k = int(input())
field = []

max_row = 0
row_idx = 0

max_col = 0
col_idx = 0

for i in range(6):
    a, b = map(int, input().split())
    # 가로
    if a==1 or a==2:
        # 최대 가로값, 인덱스 계산
        if b > max_row:
            max_row = b
            row_idx = i
    # 세로
    if a==3 or a==4:
        # 최대 세로값, 인덱스 계산
        if b > max_col:
            max_col = b
            col_idx = i
    field.append(b)

y = min(field[(row_idx - 1) % 6], field[(row_idx + 1) % 6])
x = min(field[(col_idx - 1) % 6], field[(col_idx + 1) % 6])

print(((max_col*max_row) - ((max_col-y)*(max_row-x)))*k)