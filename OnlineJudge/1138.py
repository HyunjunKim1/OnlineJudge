def lineup(n, memory):
    result = [0] * n
    for i in range(n):
        count = memory[i]
        for j in range(n):
            if count == 0 and result[j] == 0:
                result[j] = i + 1
                break
            elif result[j] == 0:
                count -= 1
    return result

# 입력
n = int(input())
memory = list(map(int, input().split()))

# 결과 계산
result = lineup(n, memory)

# 결과 출력
print(' '.join(map(str, result)))
