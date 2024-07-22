string = str(input())
string_arr = []
while True:
    if len(string) < 10:
        string_arr.append(string)
        break
    else:
        string_arr.append(string[:10])
        string = string[10:]

for i in range(len(string_arr)):
    print(string_arr[i])