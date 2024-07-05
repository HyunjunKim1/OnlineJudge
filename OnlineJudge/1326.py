from collections import deque

def min_jumps_to_reach_b(N, stones, a, b):
    a -= 1
    b -= 1
    
    # BFS setup
    queue = deque([a])
    visited = [-1] * N  
    visited[a] = 0  

    while queue:
        current = queue.popleft()
        
        step_size = stones[current]
        for next_pos in range(current + step_size, N, step_size):
            if visited[next_pos] == -1:
                visited[next_pos] = visited[current] + 1
                queue.append(next_pos)
            if next_pos == b:
                return visited[b]
        
        for next_pos in range(current - step_size, -1, -step_size):
            if visited[next_pos] == -1:
                visited[next_pos] = visited[current] + 1
                queue.append(next_pos)
            if next_pos == b:
                return visited[b]
    
    return -1

N = int(input())
stones = list(map(int, input().split()))
a, b = map(int, input().split())

result = min_jumps_to_reach_b(N, stones, a, b)
print(result)