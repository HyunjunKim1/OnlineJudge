S = str(input())

sub = 'abcdefghijklmnopqrstuvwxyz'

for i in sub:
    if i in S:
        print(S.index(i), end = ' ')
    else:
        print('-1', end = ' ')
        