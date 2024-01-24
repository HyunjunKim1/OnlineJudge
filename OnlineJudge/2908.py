s = list(map(str, input().split()))

A = s[0]
B = s[1]

A = A[::-1]
B = B[::-1]

int_list = [int(A), int(B)]
print(max(int_list))