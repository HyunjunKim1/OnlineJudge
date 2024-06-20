n = int(input())
T = []

for _ in range(n):
    T.append(list(map(int, input().split())))
    
def fine_candidate(T):
    candidate = None
    count = 0
    
    for num in T:
        if count == 0:
            candidate = num
            count = 1
        elif num == candidate:
            count += 1
        else:
            count -= 1
    return candidate

def check_isMajority(T, candidate):
    count = 0
    for num in T:
        if num == candidate:
            count += 1
    return count > len(T) // 2

for rmv in T:
    del rmv[0]
    
for i in range(n):
    candidate = fine_candidate(T[i])
    if check_isMajority(T[i], candidate):
        print(candidate)
    else:
        print("SYJKGW")

