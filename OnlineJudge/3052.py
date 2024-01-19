list = 0
result = [] 

for i in range(10):
    list = int(input())
    result.append(list % 42)

print(len(set(result)))
