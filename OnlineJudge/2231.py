N = int(input())
result = 0

for i in range(1, N+1):
    temp = list(map(int, str(i)))
    result = i + sum(temp)
    if result == N:
        print(i)
        break

    if i == N:
        print(0)