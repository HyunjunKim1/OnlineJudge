import sys

N = int(sys.stdin.readline())
name_list = []
count = 0
for i in range(N):
    flag_cnt = 0
    name = sys.stdin.readline()
    name_list.append(name)
    if name == "ENTER":
        name_list.clear()
    else:
        count += 1
        for check in name_list:
            if name == check:
                flag_cnt += 1
                if flag_cnt == 2:
                    count -= 1
                    flag_cnt = 0
                    break
    
print(count)