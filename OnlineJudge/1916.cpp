
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1000000

using namespace std;

int N, M;
int minCost[MAX];
vector<pair<int, int>> vec[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra(int idx)
{
	minCost[idx] = 0;
	pq.push({ 0,idx });

	while (!pq.empty()) 
	{
		int NowIdx = pq.top().second;
		int cost = pq.top().first;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> M;

	int start, end, cost;

	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> cost;
		vec[start].push_back({ end,cost });
	}

	int startNode, endNode;

	cin >> startNode >> endNode;

	fill(minCost, minCost + MAX, INF);

	Dijkstra(startNode);

	cout << minCost[endNode];
}