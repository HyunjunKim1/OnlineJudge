import sys

sys.setrecursionlimit(5000)

N,M = map(int, sys.stdin.readline().split())

def dfs(start):
    isVisit[start] = True
    for i in graph[start]:
        if not isVisit[i]:
            dfs(i)
    
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

for i in graph:
    i.sort()

isVisit = [False] * (N + 1)
count = 0
for i in range(1, N + 1):
    if not isVisit[i]:
        dfs(i)
        count += 1

print(count)