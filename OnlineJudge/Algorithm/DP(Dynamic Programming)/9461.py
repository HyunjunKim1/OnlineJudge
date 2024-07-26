import sys
input = sys.stdin.readline

N = int(input())

dp = [0] * 101

dp[0] = 1
dp[1] = 1
dp[2] = 1
for j in range(N):
    num = int(input())
    for i in range(3, num+1):
        dp[i] = dp[i-2] + dp[i-3]
    print(dp[num-1])