while(True):
    N = int(input())
    div_list = []
    sum = 0

    if N == -1:
        break
    
    for i in range(N):
        div = i+1
        if N % div == 0:
            div_list.append(div)
    
    div_list.pop()
    for i in range(len(div_list)):
        sum += int(div_list[i])
    if N == sum:
        print(N," = "," + ".join(str(i) for i in div_list), sep="")
    else:
        print(N," is NOT perfect.")
        
    