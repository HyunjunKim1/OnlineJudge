import sys

input = sys.stdin.readline

dp = [0] * 10001

N = int(input())


dp[1] = 1
dp[2] = 2
dp[3] = 4

for j in range(N):
    test = int(input())
    for i in range(4, test+1):
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1]
    
    print(dp[test])
