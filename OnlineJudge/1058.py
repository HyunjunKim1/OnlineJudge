import sys
input = sys.stdin.readline

N = int(input())
friends = [list(input()) for _ in range(N)]

connected = [[0] * N for _ in range(N)]

for k in range(N):
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            if friends[i][j] == 'Y' or (friends[i][k] == 'Y' and friends[k][j] == 'Y'):
                connected[i][j] = 1

answer = 0
for row in connected:
    answer = max(answer, sum(row))
    
print(answer)