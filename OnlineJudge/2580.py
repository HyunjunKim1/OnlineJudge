from itertools import permutations

num = list(range(1, 10)) # 1, 2, ... 8, 9
num_pool = [] # 123, 124, 125 ... 789 (9*8*7 = 504개) 가 튜플 형태로 저장
for i in permutations(num, 3):
    num_pool.append(i)

n = int(input()) # 질문/대답의 수

for _ in range(n):
    checking, ans_st, ans_b = map(int, input().split())
    poss = [] # 하나의 질문/대답에서 유추된 가능성이 있는 수

    for num_check in num_pool: # 현재 가능성이 있는 수를 하나씩 조사
        strike, ball = 0, 0
        for i, check in enumerate(str(checking)):
            if int(check) == num_check[i]:
                strike += 1
            if int(check) != num_check[i] and int(check) in num_check:
                ball += 1

        if strike == ans_st and ball == ans_b: # 질문한 숫자와 동일한 대답이 얻어지는 경우
            poss.append(num_check)
    num_pool = poss # 다음 질문/대답은 현재의 질문/대답에서 유추된 가능성이 있는 수 중에서 유추
    
print(len(poss))