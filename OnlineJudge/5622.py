dial = ['ABC', 'DEF', 'GHI','JKL','MNO','PQRS','TUV','WXYZ']
S = str(input())
rst = 0

for j in range(len(S)):
    for i in dial:
        if S[j] in i:
            rst += dial.index(i)+3

print(rst)

