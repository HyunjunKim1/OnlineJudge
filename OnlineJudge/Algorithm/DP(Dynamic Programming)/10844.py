N = int(input())

a = [[0] * 10 for _ in range(N)]

a[0] = [0,1,1,1,1,1,1,1,1,1]

for n in range(1,N):
    a[n][0] = a[n-1][1] 
    a[n][9] = a[n-1][8] 
    
    for k in range(1,9): 
        a[n][k] = a[n-1][k-1] + a[n-1][k+1]
        
print(sum(a[N-1])%1000000000) 