#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 10000000 

int N, E;
int a, b, c;
int v1, v2;

vector<pair<int, int>> _vec[801];
int result[801];
int node1[801], node2[801];
queue<int> q;

void Dijkstra(int idx, int* result)
{
	for (int i = 1; i <= N; i++)
		result[i] = INF;

	result[idx] = 0;
	q.push(idx);

	while (!q.empty())
	{
		int node = q.front();
		int distance = result[node];
		q.pop();

		for (int i = 0; i < _vec[node].size(); i++)
		{
			int next_node = _vec[node][i].first;
			int next_dist = _vec[node][i].second;

			if (result[next_node] > distance + next_dist) 
			{
				result[next_node] = distance + next_dist;
				q.push(next_node);
			}
		}
	}
}

int main()
{
	int X, Y;
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		_vec[a].push_back(pair<int, int>(b, c));
		_vec[b].push_back(pair<int, int>(a, c));
	}

	cin >> v1 >> v2;

	Dijkstra(1, result);
	Dijkstra(v1, node1);
	Dijkstra(v2, node2);

	X = result[v1] + node1[v2] + node2[N];
	Y = result[v2] + node2[v1] + node1[N];

	if (min(X, Y) >= INF) 
		cout << -1;
	else 
		cout << min(X, Y);
}