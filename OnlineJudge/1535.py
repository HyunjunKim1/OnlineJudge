#def knapsack(values, weights, max_weight):
#    n = len(values)
#    dp = [[0] * (max_weight + 1) for _ in range(n + 1)]
#    
#    for i in range(1, n + 1):
#        for w in range(1, max_weight + 1):
#            if weights[i-1] <= w:
#                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1])
#            else:
#                dp[i][w] = dp[i-1][w]
#    
#    return dp[n][max_weight]
#
## 예제 사용법
#values = [60, 100, 120]
#weights = [10, 20, 30]
#max_weight = 50
#print(knapsack(values, weights, max_weight))  # 출력: 220

import sys

input = sys.stdin.readline

N = int(input())
stamina_cosum = [0] + list(map(int, input().split()))
get_p = [0] + list(map(int, input().split()))

dp = [[0] * 101 for _ in range(N+1)]

for i in range(1, N+1):
    for w in range(1, 101):
        if stamina_cosum[i] <= w:
            dp[i][w] = max(dp[i-1][w], dp[i-1])
            
