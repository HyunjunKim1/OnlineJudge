import sys
input = sys.stdin.readline

N, L = map(int, input().split())

for i in range(L, 101):
    x = N - i * (i + 1) / 2
    if x % i == 0:
        x = int(x / i)
        if x >= -1:
            print(*list(range(x + 1, x + i + 1)))
    else:
        print(-1)        
        break