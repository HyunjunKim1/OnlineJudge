from collections import deque

N,M = map(int, input().split())
pos = list(map(int, input().split()))
dq = deque([i for i in range(1, N + 1)])

count = 0

for i in pos:
    while True:
        if dq.index(i) < len(dq) / 2:
            while i != dq[0]:
                dq.append(dq.popleft())
                count += 1
            dq.popleft()
            break
        else:
            while i != dq[0]:
                dq.appendleft(dq.pop())
                count += 1
            dq.popleft()
            break

print(count)