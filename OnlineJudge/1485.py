#import sys
#import math
#from itertools import combinations
#
#input = sys.stdin.readline
#
## d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
#def distance(p1, p2):
#    return math.sqrt((p2[0]-p1[0]) ** 2 + (p2[1] - p1[1]) ** 2)
#
#def is_Square(points):
#    if len(points) != 4:
#        return False
#    dists = []
#    
#    for (p1,p2) in combinations(points, 2):
#        dists.append(distance(p1,p2))
#        
#    dists.sort()
#    
#    return (dists[0] == dists[1] == dists[2] == dists[3] and  # 네 변의 길이가 동일
#            dists[4] == dists[5] and                          # 두 대각선의 길이가 동일
#            math.isclose(dists[0] * math.sqrt(2), dists[4]))  
#    
#N = int(input())
#
#points = []
#for i in range(N):
#    for j in range(4):
#        x,y = map(int, input().split())
#        points.append((x,y))
#        
#    if is_Square(points):
#        print(1)
#    else:
#        print(0)
#    
import sys

def check_square(c):
    side_one = (c[0][0] - c[1][0])**2 + (c[0][1] - c[1][1])**2
    side_two = (c[1][0] - c[3][0])**2 + (c[1][1] - c[3][1])**2
    if side_one != side_two:
        return 0
    side_three = (c[3][0] - c[2][0])**2 + (c[3][1] - c[2][1])**2
    if side_two != side_three:
        return 0
    side_four = (c[2][0] - c[0][0])**2 + (c[2][1] - c[0][1])**2
    if side_three != side_four:
        return 0
    diagonal_one = (c[0][0] - c[3][0])**2 + (c[0][1] - c[3][1])**2
    diagonal_two = (c[2][0] - c[1][0])**2 + (c[2][1] - c[1][1])**2
    if diagonal_one != diagonal_two or side_one + side_two != diagonal_one:
        return 0
    return 1

if __name__ == "__main__":
    t = int(sys.stdin.readline())
    for i in range(t):
        coordinates = []
        for j in range(4):
            x, y = list(map(int,sys.stdin.readline().split()))
            coordinates.append((x, y))
        coordinates.sort(key=lambda a: (a[0], a[1]))
        print(check_square(coordinates))