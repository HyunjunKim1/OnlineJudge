N, K = map(int, input().split())
Temp_list = list(map(int, input().split()))

# 초기 윈도우의 합 계산
current_sum = sum(Temp_list[:K])
max_sum = current_sum

# 슬라이딩 윈도우 적용
for i in range(1, N - K + 1):
    current_sum = current_sum - Temp_list[i - 1] + Temp_list[i + K - 1]
    if current_sum > max_sum:
        max_sum = current_sum

print(max_sum)