M = int(input())
N = int(input())

s_list = []
for num in range(M, N+1):
    error = False
    if num > 1 :
        for i in range(2, num): 
            if num % i == 0:
                error = True
                break  
        if error == False:
            s_list.append(num) 
            
if len(s_list) > 0 :
    print(sum(s_list))
    print(min(s_list))
else:
    print(-1)