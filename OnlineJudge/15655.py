import sys
input = sys.stdin.readline

n,m = map(int,input().split())
arr = sorted(list(map(int,input().split())))
ans = []

def bt(idx, cnt):
    if cnt==m:
        print(*ans)
        return
    
    for i in range(idx, n):
        idx+=1
        ans.append(arr[i])
        bt(idx, cnt+1)
        ans.pop()
        
bt(0,0)