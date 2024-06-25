import sys
input = sys.stdin.readline

N = int(input())

count = 0
num = []
result = 0
for i in range(1, 9876543210):
    temp = str(i)
    if len(temp) >= 2:
        check = 0
        for idx in temp:
            num.append(idx)
        for j in range(1, len(num)):
            if num[j - 1] > num[j]:
                check += 1
            if check == len(num) - 1:
                count += 1
        num.clear()
    elif len(temp) == 1:
        count += 1
    if N == 0:
        print(N)
        break
    elif N == 1:
        print(N)
        break
    if count == N:
        print(i)
        break
    if i == 9876543210 and count < N:
        print(-1)
        break
        