N = int(input())
for i in range(N, 0, -1):
    print(" " * (N-i) + "*" * (2*i-1))
for j in range(2,N+1):
    print(" " * (N-j) + "*" * (2*j-1))