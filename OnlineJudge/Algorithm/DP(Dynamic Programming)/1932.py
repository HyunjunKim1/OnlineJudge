import sys
input = sys.stdin.readline

N = int(input())
triangle = []

dp = []
for i in range(N):
    triangle.append(list(map(int,input().split())))


    