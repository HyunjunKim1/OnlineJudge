#N = int(input())
#card_list = list(map(int,input().split()))
#M = int(input())
#check_list = list(map(int,input().split()))

#result = []
#cnt = 0

#for i in range(len(check_list)):
#    for j in range(len(card_list)):
#        cnt = 0
#        if check_list[i] == card_list[j]:
#            result.append(1)
#            cnt = 1
#            break
#    if cnt == 0:
#        result.append(0)
        
#for i in range(len(result)):
#    print(result[i], end =' ')

import sys

N = int(sys.stdin.readline())
cards = sorted(list(map(int, sys.stdin.readline().split())))
M = int(sys.stdin.readline())
checks = list(map(int, sys.stdin.readline().split()))

for check in checks:
    low, high = 0, N-1  # cards의 이진 탐색 index
    exist = False
    while low <= high:
        mid = (low + high) // 2
        if cards[mid] > check:  # 중간 값보다 작다면
            high = mid - 1  # 중간보다 왼쪽 한 칸 옆까지 탐색
        elif cards[mid] < check:  # 중간 값보다 크다면
            low = mid + 1  # 중간보다 오른쪽 한 칸 옆부터 탐색
        else:
            exist = True
            break
    print(1 if exist else 0, end=' ')