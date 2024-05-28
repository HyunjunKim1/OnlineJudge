from collections import deque

def dfs(start):
    isVisit[start] = True
    print(start, end = " ")
    for i in vertax[start]:
        if not isVisit[i]:
            dfs(i)

def bfs(start):
    queue = deque([start])
    isVisit[start] = True
    
    while queue:
        v = queue.popleft()
        print(v, end = " ")
        for i in vertax:
            if not isVisit[i]:
                isVisit[i] = True
                queue.append(i)
    

N, M, V = map(int, input().split())

vertax = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int,input().split())
    vertax[a].append(b)
    vertax[b].append(a)

for i in vertax:
    i.sort()
    
isVisit = [False] * (N + 1)
dfs(V)

isVisit = [False] * (N + 1)
bfs(V)
