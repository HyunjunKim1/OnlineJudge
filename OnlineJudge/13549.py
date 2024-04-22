import sys
from collections import deque
input = sys.stdin.readline
 
a,b = map(int,input().split())
limit = 100001
time = [0]*limit
 
def bfs(x,y):
    q = deque()
    if x == 0 :
        q.append(1)
    else :
        q.append(x)
    
    while q:
        x = q.popleft()
        if y == x :
            return time[x]
        
        for nx in (x-1,x+1,x*2):
            if 0 <= nx < limit and time[nx]==0:
                if nx == 2*x :
                    time[nx] = time[x]
                    q.appendleft(nx)
                else : 
                    time[nx] = time[x] + 1
                    q.append(nx)
 
if a==0:
    if b==0:
        print(0)
    else:
        print(bfs(a,b)+1)
else :
    print(bfs(a,b))