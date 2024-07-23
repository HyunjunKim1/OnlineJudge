import sys
input = sys.stdin.readline
MAX = 1000001
dp = [0] * MAX

N = int(input())
for i in range(2, N + 1):
    dp[i] = dp[i-1] + 1
    
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i//2] + 1)
    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i//3] + 1)
        
print(dp[N])
    
