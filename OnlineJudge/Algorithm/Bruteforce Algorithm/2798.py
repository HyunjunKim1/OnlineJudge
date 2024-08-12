N, M = map(int, input().split())
num = list(map(int, input().split()))
ans = 0
result = 0

for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            if num[i] + num[j] + num[k] <= M:
                ans = num[i] + num[j] + num[k]
                if ans > result:
                    result = ans
                    if result == M:
                        break

print(result)