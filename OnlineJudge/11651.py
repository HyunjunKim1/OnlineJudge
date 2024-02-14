N = int(input())

loc = []

for _ in range(N):
    xy = list(map(int, input().split()))
    loc.append([xy[1], xy[0]])
    
loc.sort()

for i in loc:
    print(i[1], i[0])