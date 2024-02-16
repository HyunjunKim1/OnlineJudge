import sys

T=int(input())

for i in range(T):
    a,b=map(int,sys.stdin.readline().strip().split())
    aa,bb=a,b

    while bb!=0:
        aa=aa%bb
        aa,bb=bb,aa

    print(a*b//aa)