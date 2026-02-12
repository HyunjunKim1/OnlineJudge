def convertTime(n):
    h = n // 60
    m = n % 100
    
    return h * 60 + m

def solution(schedules, timelogs, startday):
    answer = 0
    
    for i in range(len(schedules)):
        s = startday
        schedule = convertTime(schedules[i])
        
        for time in timelogs[i]:
            if s == 6 or s == 7:
                s += 1
                if s==8:
                    s = 1
                continue
            t = convertTime(time)
            if schedule + 10 < t:
                break
            else:
                s += 1
        else:
            answer += 1  
             
    return answer

if __name__ == "__main__":
    timelogs = [[710, 2359, 1050, 700, 650, 631, 659], [800, 801, 805, 800, 759, 810, 809], [1105, 1001, 1002, 600, 1059, 1001, 1100]]
    print(solution([700, 800, 1100], timelogs, 5))