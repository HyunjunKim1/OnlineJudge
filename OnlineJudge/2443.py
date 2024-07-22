N = int(input())
count = 0

for i in range(N, 0, -1):
    print(" " * count + "*" * int(i * 2 - 1))
    count += 1