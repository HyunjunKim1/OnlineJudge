from collections import Counter
N = int(input())

num_list = []
for _ in range(N):
    num_list.append(int(input()))
    
def ave():
    total = 0
    for i in range(N):
        total += num_list[i]
    ave = int(round(total / len(num_list), 0))
    print(ave)   
        
def med():
    median = 0
    num_list.sort()
    median = num_list[len(num_list) // 2]
    print(median)
    
def val():
    counter = Counter(num_list)
    max_count = max(list(counter.values()))
    mode_val = [num for num, freq in counter.items() if freq == max_count]
    if len(mode_val) != 1:
        print(mode_val[1])
    else:
        print(mode_val[0])

def ran():
    num_list.sort()
    print(num_list[-1] - num_list[0])
    
ave()
med()
val()
ran()