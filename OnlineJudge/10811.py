N,M = map(int, input().split())
basket = [0] * N

for i in range(N):
    basket[i] = i + 1

for i in range(M):
    i,j = map(int, input().split())
    temp = basket[i-1:j]
    temp.reverse()
    basket[i-1:j] = temp
    
for i in range(N):
    print(basket[i], end = ' ')