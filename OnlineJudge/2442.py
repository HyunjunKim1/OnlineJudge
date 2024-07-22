N = int(input())

for i in range(1, N + 1):
    print(" " * int(N-i), end='')
    print("*" * int(i * 2 - 1))
    