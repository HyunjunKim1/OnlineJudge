import sys

input = sys.stdin.readline
data = list(map(int, input().rstrip()))
len = len(data)

dp = [0] * (len + 1)
dp[0] = 1
dp[1] = 1

if data[0] == 0:
    print(0)
else:
    for k in range(1, len):
        i = k + 1
        if data[k] > 0:
            dp[i] += dp[i-1]
        if 10 <= data[k] + data[k-1]* 10 <= 26:
            dp[i] += dp[i-2]
            
    print(dp[len] % 10000000)