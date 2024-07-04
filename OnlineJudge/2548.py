#import sys
#
#input = sys.stdin.readline
#
#N = int(input())
#
#templist = []
#templist.append(list(map(int,input().split())))
#
#num_list = templist[0].copy()
#
#result = []
#
#for i in range(N):
#    minus = 0
#    for j in range(N):
#        if i == j:
#            pass
#        else:
#            minus += abs(num_list[i] - num_list[j])
#    result.append(minus)
#
#minimal = min(result)
#
#ans = []
#
#idx = 0
#for num in result:
#    if num == minimal:
#        ans.append(num_list[idx])
#    idx += 1
#    
#print(min(ans))

N = int(input())
list1 = list(map(int, input().split()))

list1.sort()

if N %2 ==0:
    print(list1[N//2 -1 ])

else:
    print(list1[N//2])