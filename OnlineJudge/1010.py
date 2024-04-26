import sys

input = sys.stdin.readline

def Factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * Factorial(n-1)

T = int(input())

for _ in range(T):
    N,M = map(int, input().split())
    result = Factorial(M) // (Factorial(N) * Factorial(M-N))
    print(result)