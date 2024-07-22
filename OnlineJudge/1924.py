daylist = [31,28,31,30,31,30,31,31,30,31,30,31]
weeklist = ["SUN","MON","TUE","WED","THU","FRI","SAT"]
x, y = map(int,input().split())
count = 0
for i in range(x-1):
    count += daylist[i]
count += y
count %= 7
print(weeklist[count])