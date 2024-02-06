while(True):
    s_list = []
    X,Y,Z = map(int, input().split())
    s_list.append(X)
    s_list.append(Y)
    s_list.append(Z)
    s_list.sort()
    if X==0 and Y==0 and Z==0:
        break;
    if s_list[2] < s_list[0]+s_list[1]:
        if X==Y==Z:
            print("Equilateral")
        elif X==Y or X==Z or Y==Z:
            print("Isosceles")
        else:
            print("Scalene")
    else:
        print("Invalid")
        
        
    