N = int(input())
score = list(map(int,input().split(' ')))

maxScore = max(score)
sum = 0

for i in range(N):
    score[i] = (score[i]/maxScore)*100
    sum = sum + score[i]

print(sum/N)