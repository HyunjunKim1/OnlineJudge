N = int(input())
result = []

for i in range(N):
    h_info = list(map(str,input().split()))
    result.append([h_info[0], h_info[1]])    
    
result.sort(key = lambda x : x[0])

for i in result:
    print(i[0], i[1])