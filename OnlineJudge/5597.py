students = [i for i in range(1,31)]

for i in range(28):
    rst = int(input())
    students.remove(rst)
    
print(min(students))
print(max(students))