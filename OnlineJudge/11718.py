import sys

while True:
    try:
        print(sys.stdin.readline().rstrip())
    except EOFError:
        break