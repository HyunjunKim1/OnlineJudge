#N, L = map(int, input().split())
#arr = list(map(int,input().split()))
#arr.sort()
#count = 0
#
#i = 0
#
#while i < N:
#    if L != 1:
#        idx = L + i - 1
#        if L > arr[idx] - arr[i]:
#            count += 1
#            i += L
#        else:
#            i += 1
#    else:
#        count = N
#        break
#    
#print(count)

n,m = map(int,input().split())
pipe = list(map(int,input().split()))
pipe.sort()

start = pipe[0]
count = 1

for i in pipe[1:]:
    if (i+0.5)-(start-0.5)<=m:
        continue
    else:
        start = i
        count+=1
print(count)