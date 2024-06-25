#import sys
#import re
#input = sys.stdin.readline
#
#N = int(input())
#postfix = str(input()).rstrip()
#
#nums = []
#stack = []
#for _ in range(N):
#    nums.append(int(input()))
#
#def ev_Postfix(postfix):
#    count = 0
#    temp = []
#    for token in postfix:
#        if token == '+':
#            temp.append(token)
#        elif token == '-':
#            temp.append(token)
#        elif token == '*':
#            temp.append(token)
#        elif token == '/':
#            temp.append(token)
#        else:
#            temp.append(nums[count])
#            count += 1
#    
#    for token in temp:
#        if str(token).isdigit():
#            stack.append(int(token))
#        else:
#            b = stack.pop()
#            a = stack.pop()
#            if token == '+':
#                stack.append(a+b)
#            elif token == '-':
#                stack.append(a-b)
#            elif token == '*':
#                stack.append(a*b)
#            elif token == '/':
#                stack.append(a/b)
#    
#    print('%.2f' %stack[0])
#            
#ev_Postfix(postfix)

n = int(input())
word = input()                # 후위표기식을 word에 저장함
num_lst = [0]*n				  # 피연산자값을 저장하기 위한 num_lst 생성	

for i in range(n):
    num_lst[i] = int(input())  # 피연산자값 받기

stack = []                    # stack 리스트를 통해 후위표기식 계산

for i in word :					
    if 'A' <= i <= 'Z' :		# 후위표기식에서 알파벳을 만나면 stack에 저장한다.(물론 알파벳 형태가 아닌 피연산자값의 형태로)
        stack.append(num_lst[ord(i)-ord('A')])
    else :						# 연산자를 만나면
        str2 = stack.pop()		# stack 리스트의 마지막 2항목을 꺼내와서 계산한다.
        str1 = stack.pop()

        if i =='+' :
            stack.append(str1+str2)
        elif i == '-' :
            stack.append(str1-str2)
        elif i == '*' :
            stack.append(str1*str2)
        elif i == '/' :
            stack.append(str1/str2)

print('%.2f' %stack[0])	