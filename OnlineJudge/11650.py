n=int(input())
li=[]
for i in range(n):
    [a, b] = map(int, input().split())
    li.append([a, b])
li.sort()
for i in li:
    print(i[0], i[1])