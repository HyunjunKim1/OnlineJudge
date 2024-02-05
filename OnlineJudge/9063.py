N = int(input())
x_list = []
y_list = []
for i in range(N):
    x,y = map(int, input().split())
    x_list.append(x)
    y_list.append(y)
    
x_max, x_min = max(x_list), min(x_list)
y_max, y_min = max(y_list), min(y_list)

print((x_max-x_min)*(y_max-y_min))