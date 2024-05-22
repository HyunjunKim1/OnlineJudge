from collections import deque

def DFS(M,V,Visited):
    Visited[V] = True
    print(V, end = ' ')
    for i in Vertax[V]:
        if not Visited[i]:
            DFS(M,i,Visited)

def BFS(M, V, Visited):
    queue = deque([V])
    Visited[V] = True
    
    while queue:
        V = queue.popleft()
        print(V, end=' ')
        for i in Vertax[V]:
            if not Visited[i]:
                queue.append(i)
                Visited[i] = True
        
N, M, V = map(int, input().split())
Vertax = [[]]
isVisited = [False] * N

for _ in range(M):
    Vertax.append([map(int,input().split())])

DFS(M,V,isVisited)
BFS(M,V,isVisited)