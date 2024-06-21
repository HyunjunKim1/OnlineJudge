import sys
input = sys.stdin.readline

N = int(input())

if N == 1:
    print(1)
elif N == 2:
    print(2)
else:
    print(N + (N-2))