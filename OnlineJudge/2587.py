num = []
total = 0
for i in range(5):
    num.append(int(input()))
    total += num[i]

num.sort()
print(int(total//5))
print(num[2])