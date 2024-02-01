N, K = map(int,input().split())
K_list = []

for i in range(N):
    div = i+1
    if N % div == 0:
        K_list.append(div)

if K > int(len(K_list)):
    print('0')
else:
    print(K_list[K-1])
        