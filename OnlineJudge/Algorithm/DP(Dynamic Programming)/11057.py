import sys
input = sys.stdin.readline

N = int(input())

dp = [[0] * 10 for _ in range(N+1)]
dp[0] = [1,1,1,1,1,1,1,1,1,1]
for i in range(1, N):
    for j in range(10):
        if j == 0:
            dp[i][j] = 1
        else:
            dp[i][j] = dp[i][j-1] + dp[i-1][j]

print(sum(dp[N-1]) % 10007)
