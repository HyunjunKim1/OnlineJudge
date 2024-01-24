N = int(input())

for i in range(N):
    cnt, s = input().split(' ')
    cnt = int(cnt)
    s = str(s)
    for j in range(len(s)):
        print(s[j]*cnt, end='')
    print('')
