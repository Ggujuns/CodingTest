"""
S => T
T => S

거꾸로
1. 문자열 뒤의 A를 삭제한다.
2. 문자열을 뒤집고 뒤에 B를 삭제한다.


"""
s = input()
t = input()
flag = False
def findstr(word):
    global flag
    if len(word) == len(s):
        if word == s:
            flag = True
            return
        return
    if word[-1] == 'A':
        findstr(word[:-1])
    if word[0]== 'B':
        findstr(word[::-1][:-1])

findstr(t)
if flag:
    print(1)
else:
    print(0)
        