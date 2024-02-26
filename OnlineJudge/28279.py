import sys
from collections import deque

N = int(sys.stdin.readline())
q= deque()
for _ in range(N):
    cmd = list(map(int, sys.stdin.readline().split()))
    n = cmd[0]
    if n == 1:
        q.appendleft(cmd[1])
    elif n == 2:
        q.append(cmd[1])
    elif n==3:
        if len(q) == 0:
            print(-1)
        else:
            print(q.popleft())
    elif n ==4:
        if len(q) == 0:
            print(-1)
        else:
            print(q.pop())
    elif n == 5:
        print(len(q))
    elif n ==6:
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif n == 7:
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])
    elif n == 8:
        if len(q) == 0:
            print(-1)
        else:
            print(q[-1])