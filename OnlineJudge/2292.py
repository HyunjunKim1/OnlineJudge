n = int(input())

nums_pileup = 1  
cnt = 1
while n > nums_pileup :
    nums_pileup += 6 * cnt  
    cnt += 1  
print(cnt)