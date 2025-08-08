A, P = map(int, input().split())
num_dict = dict()

def findDn(num):
    first_num = 0
    for i in str(num):
        first_num += int(i)**P
    return first_num

idx = 1
num_list = list()
num_list.append(A)
num_dict[A] = 1
find_num = 0
while True:
    append_num = findDn(num_list[idx-1])
    # 값이 이미 있다면
    if (append_num in num_dict):
        find_num = append_num
        break
    num_list.append(append_num)
    num_dict[append_num] = 1
    idx +=1
for i in range(len(num_list)):
    
    if num_list.pop() == find_num:
        break
print(len(num_list))