import sys

input = sys.stdin.readline

N = int(input())
mul = 1

if N == 0 or N == 1:
    print(1)
else:
    for i in range(1,N+1):
        mul = mul * i
    print(mul)