croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

S = str(input())

for i in croatia:
    S = S.replace(i, '*')
    
print(len(S))