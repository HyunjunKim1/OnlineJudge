import sys
import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    queue = []
    heapq.heappush(queue, [distances[start], start])

    while queue:
        current_distance, current_node = heapq.heappop(queue)

        if distances[current_node] < current_distance:
            continue

        for adjacent, weight in graph[current_node].items():
            distance = current_distance + weight

            if distance < distances[adjacent]:
                distances[adjacent] = distance
                heapq.heappush(queue, [distance, adjacent])

    return distances

V, E = map(int, input().split())
start = int(input())
graph = {i: {} for i in range(1, V+1)}


for _ in range(E):
    u, v, w = map(int, input().split())
    if v in graph[u]:
        graph[u][v] = min(graph[u][v], w)
    else:
        graph[u][v] = w

distances = dijkstra(graph, start)

for i in range(1, V+1):
    if distances[i] == float('inf'):
        print('INF')
    else:
        print(distances[i])
