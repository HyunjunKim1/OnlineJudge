N = int(input())
Serial = []
for _ in range(N):
    Serial.append(str(input()))
    
def sum_num(input_Serial):
    result = 0
    for i in input_Serial:
        if i.isdigit():
            result += int(i)
    return result

Serial.sort(key= lambda x:(len(x), sum_num(x), x))

for out in Serial:
    print(out)
    