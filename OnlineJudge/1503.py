import sys
input = sys.stdin.readline
INF = sys.maxsize

n, m = list(map(int, input().rstrip().split()))
s = list(map(int, input().rstrip().split()))
res = INF

for i in range(1, 1002):
    if i in s: continue
    for j in range(1, 1002):
        if j in s: continue
        for k in range(1, 1002):
            if k in s: continue
            q = (i * j * k)
            if abs(n - q) < res: res = abs(n - q)
            if n + 1 < q: break
