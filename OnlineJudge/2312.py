import sys
#input = sys.stdin.readline
#
#num = []
#N = int(input())
#result = []
#
#def resolve(num):
#    beforeNum = 2
#    idx = 0
#    mul = 2
#    cnt = 0
#    while num != 1:
#        if num % mul == 0:
#            if beforeNum != mul:
#                idx += 1
#            cnt += 1
#            num = num / mul
#            
#            if len(result) != 0:
#                (a,b) = result[idx]
#                if a == mul:
#                    result.pop()
#                    
#            result.append(list(map(int, (mul, cnt))))
#        else:
#            cnt = 0
#            mul += 1
#    
#    for i in range(len(result)):
#        (a, b) = result[i]
#        print(a, " ", b)
#    result.clear()
#
#for i in range(N):
#    num.append(int(input()))
#
#for i in range(len(num)):
#    resolve(num[i])    
#

input = sys.stdin.readline

def factorization(n):
     prime_cnt = []
     for p in range(2, n + 1):
          cnt = 0
          while n % p == 0:
               cnt += 1
               n = n // p
          if cnt:
               prime_cnt.append([p, cnt])
     for p in prime_cnt:
          print(*p)
               
                         

if __name__ == '__main__':
     t = int(input())
     for _ in range(t):
          factorization(int(input()))