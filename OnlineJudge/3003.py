Chess = [1, 1, 2, 2, 2, 8]

cnt = list(input().split())

for i in range(len(Chess)):
    print(int(Chess[i])-int(cnt[i]), end=' ')
