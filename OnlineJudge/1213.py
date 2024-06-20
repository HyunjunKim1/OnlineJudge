from collections import Counter

def can_form_palindrome(s):
    char_count = Counter(s)
    odd_count = 0
    for char in char_count.values():
        check = char % 2
        if check == 1:
            odd_count += 1
    
    if odd_count > 1:
        return False
    
    return True

def form_palindrome(s):
    if not can_form_palindrome(s):
        return "I'm Sorry Hansoo"
    
    char_count = Counter(s)
    left_half = []
    middle = []
    
    for char, count in sorted(char_count.items()):
        if count % 2 != 0:
            middle = [char] * (count % 2)
        left_half.extend([char] * (count // 2))
    
    right_half = left_half[::-1]
    palindrome = "".join(left_half + middle + right_half)
    
    return palindrome

S = str(input())

result = form_palindrome(S)
print(result)