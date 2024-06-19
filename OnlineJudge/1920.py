N = int(input())
A = list(map(int, input().split()))
M = int(input())
X = list(map(int, input().split()))

A.sort()

for num in X:
    left, right = 0, N - 1
    flag = False
    
    while left <= right:
        mid = (left + right) // 2
        if num == A[mid]:
            flag = True
            print(1)
            break
        elif num > A[mid]:
            left = mid + 1
        else:
            right = mid - 1
            
    if not flag:
        print(0)