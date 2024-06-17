N, M = map(int, input().split())

N_list = list(map(int,input().split()))

N_list.sort()

def backtracking(depth):
    if depth == M:
        print(' '.join(map(str,Seq)))
        return
    else:
        for i in range(N):
            if N_list[i] in Seq:
                continue
            Seq.append(N_list[i])
            backtracking(depth + 1)
            Seq.pop()
    
Seq = []
backtracking(0)
