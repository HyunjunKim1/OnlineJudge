N, M = map(int, input().split())
N_list = list(map(int,input().split()))

N_list.sort()

Seq = []

def Backtracking(depth):
    if depth == M:
        print(' '.join(map(str, Seq)))
    else:
        for i in range(N):
            if not Seq or Seq[-1] <= N_list[i]:
                Seq.append(N_list[i])
                Backtracking(depth + 1)
                Seq.pop()
            
Backtracking(0)
