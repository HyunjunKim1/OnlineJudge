import sys

input = sys.stdin.readline

N,K = map(int, input().split())

def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n-1)

print(factorial(N) // (factorial(K) * factorial(N-K)))