def burst_balloons(balloons):
    n = len(balloons)
    positions = list(range(1, n + 1))
    burst_order = []
    current_position = 0
    
    while balloons:
        burst_order.append(positions.pop(current_position))
        if not balloons:
            break

def main():
    N = int(input())

    s_list = []
    s_list.append(list(map(int,input().split())))
    
    if len(s_list) != 5:
        print("5개 숫자를 입력")
        return
    
    burst_order = burst_balloons(s_list)
    
    print(burst_order)
    
if __name__ == "__main__":
    main()