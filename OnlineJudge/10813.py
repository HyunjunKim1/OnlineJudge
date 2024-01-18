N,M = map(int, input().split())

box = [0] * N
for i in range(5):
    box[i] = i + 1

#print(box)

for i in range(M):
    i, j = map(int, input().split())
    temp = box[i - 1]
    box[i - 1] = box[j - 1]
    box[j - 1] = temp
    
for i in range(N):
    print(box[i] , end=' ')