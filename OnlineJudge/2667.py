from collections import deque

N = int(input())
map = [list(map(int,input())) for _ in range(N)]

dx = [0,0,-1,1]
dy = [1,-1,0,0]

count = []

def bfs(x,y):
    q = deque()
    near = 1
    q.append((x,y))
    map[x][y] = 0
    while q:
        x,y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
            if map[nx][ny] == 1:
                q.append((nx,ny))
                map[nx][ny] = 0
                near += 1
    count.append(near)
    
for i in range(N):
    for j in range(N):
        if map[i][j] == 1:
            bfs(i, j)
            
print(len(count))
count.sort(reverse=True)
while count:
    print(count.pop())