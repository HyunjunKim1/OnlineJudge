#A, B, V = map(int, input().split())
#result = 0
#cnt = 0
#while(True):
#    cnt += 1
#    result += A
#    if result >= V:
#        break;
#    result -= B
#    
#print(cnt)

A, B, V = map(int, input().split())

if (V-B) % (A-B) == 0:
    print((V-B)//(A-B))
else:
    print((V-B)//(A-B)+1)