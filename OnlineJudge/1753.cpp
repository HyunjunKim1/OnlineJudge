#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
#define NODE_MAX 20001
#define VERTEX_MAX 300001

using namespace std;

int V, E, K;
int minVal[NODE_MAX];

// pair <가중치, 도착노드>
vector<pair<int, int>> vec[VERTEX_MAX];
priority_queue<pair<int, int>> pq;

void Dijkstra(int idx)
{
	int NowIdx = 0;
	int weight = 0;
	// 자기 자신으로 가는 가중치는 없음.
	minVal[idx] = 0;

	pq.push(make_pair(0, idx));

	while (!pq.empty())
	{
		NowIdx = pq.top().second;
		weight = -pq.top().first;

		pq.pop();

		if (minVal[NowIdx] < weight)
			continue;

		for (int i = 0; i < vec[NowIdx].size(); i++)
		{
			int next_node = vec[NowIdx][i].second;
			int total_weight = weight + vec[NowIdx][i].first;

			if (minVal[next_node] > total_weight)
			{
				minVal[next_node] = total_weight;

				pq.push(make_pair(-total_weight, next_node));
			}
		}
	}
}

int main()
{
	// 시작노드, 도착노드, 가중치
	int u, v, w;

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	cin >> K;

	fill(minVal, minVal + V + 1, INF);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;

		//시작노트 vec에 도착노드로 가는 가중치를 같이 저장
		vec[u].push_back(make_pair(w, v));
	}

	Dijkstra(K);

	for (int i = 1; i < V + 1; i++)
	{
		if (minVal[i] == INF)
			cout << "INF" << "\n";
		else
			cout << minVal[i] << "\n";
	}
}