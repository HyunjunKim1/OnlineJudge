#N, M = map(int, input().split())

#S = []
#check_str = []

#for _ in range(N):
#    S.append(str(input()))

#for _ in range(M):
#    check_str.append(str(input()))
    
#result = []

#for i in range(len(S)):
#    for j in range(len(check_str)):
#        if S[i] == check_str[j]:
#            result.append(S[i])
#            break

#print(len(result))
    
from itertools import count
import sys
input = sys.stdin.readline

# set 사용
s = set()
count = 0
n, m = map(int, input().split())

for _ in range(n):
    data = input().rstrip()
    s.add(data) # set은 add로 데이터 추가

# s = set([input().rstrip() for _ in range(n)])

for _ in range(m):
    data = input().rstrip()
    if data in s:
        count+=1

print(count)