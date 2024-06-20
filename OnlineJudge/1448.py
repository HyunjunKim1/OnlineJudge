import sys
input = sys.stdin.readline
N = int(input())

Triangle = []
for _ in range(N):
    Triangle.append(int(input()))
Triangle.sort()
Triangle.reverse()
result = []
for i in range(N - 2):
    if Triangle[i] < Triangle[i + 1] + Triangle[i + 2]:
        result.append(Triangle[i] + Triangle[i + 1] + Triangle[i + 2])

if len(result) == 0:
    print(-1)
else:
    print(result[0])