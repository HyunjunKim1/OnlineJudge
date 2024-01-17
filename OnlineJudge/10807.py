N = int(input())
N_list = list(map(int, input().split()))

find = int(input())

cnt = 0
for i in range(N):
    if N_list[i]==find:
       cnt += 1

print(cnt)
