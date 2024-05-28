from collections import deque

def dfs(start):
    isVisit[start] = True
    for i in vertax[start]:
        if not isVisit[i]:
            isVisit[i] = True
            dfs(i)

com_count = int(input())
vertax_count = int(input())
VisitCount = 0
vertax = [[] for _ in range(com_count + 1)]

for _ in range(vertax_count):
    a, b = map(int, input().split())
    vertax[a].append(b)
    vertax[b].append(a)
    
for i in vertax:
    i.sort()

isVisit = [False] * (com_count + 1)
dfs(1)

for i in isVisit:
    if i == True:
        VisitCount = VisitCount + 1

print(VisitCount - 1)
