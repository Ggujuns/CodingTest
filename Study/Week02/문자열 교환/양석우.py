'''
1. 원형임
2. 특정 문자열 길이 안에 b의 개수가 최소가 되면 되는거임
3. 원형 + 슬라이드 윈도우

원형처리? 
aabbaabb

abababab
'''
s = input()
len_s = len(s)
a = s.count('a')
if a == 0 or a == len_s:
    print(0)
else:
    t = s+s
    b = t[:a].count('b')
    anw = b

    for i in range(1, len_s):
        if t[i-1] == 'b':
            b -=1
        if t[i+a-1] == 'b':
            b +=1
        anw = min(anw, b)

    print(anw)