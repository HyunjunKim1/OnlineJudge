#N = int(input())

#str_list = []
#for _ in range(N):
#    str_list.append(str(input()))

#str_list = list(set(str_list))
#str_list.sort()

#for i in range(len(str_list)):
#    for j in range(i,len(str_list)):
#        if len(str_list[i]) > len(str_list[j]): 
#            str_list[i], str_list[j] = str_list[j],str_list[i]

#for i in range(len(str_list)):
#    print(str_list[i])
n = int(input())

words = [str(input()) for i in range(n)]

words = list(set(words))
words.sort()
words.sort(key=len)

for i in words:
    print(i)