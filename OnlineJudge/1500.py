import sys
n,m = map(int , sys.stdin.readline().split(" "))

p = (n//m); 
q = (n%m); 
ans = 1
for _ in range(m):
    if q > 0:
        ans *= (p+1)
        q -= 1
    else:
        ans *= p
print(ans)