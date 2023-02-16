#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001
using namespace std;

int V;
queue<int> q;
vector<pair<int, int>> vertax[MAX];
int dis_sum[MAX];
int result, Loc;

void BFS(int idx, int isVisit[MAX])
{
	q.push(idx);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		isVisit[now] = 1;

		for (int i = 0; i < vertax[now].size(); i++)
		{
			pair<int, int> temp = vertax[now][i];

			int tx = temp.first;
			int ty = temp.second;

			if (isVisit[tx] != 0)
				continue;

			if (tx <= 0 || tx > V)
				continue;

			q.push(tx);

			dis_sum[tx] += dis_sum[now] + ty;

			if (dis_sum[tx] > result)
			{
				result = dis_sum[tx];
				Loc = tx;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V;

	for (int i = 0; i < V; i++) 
	{
		int node;

		cin >> node;

		while (1)
		{
			int ver_node;

			cin >> ver_node;
			if (ver_node == -1)
				break;

			int distance;
			cin >> distance;

			vertax[node].push_back({ ver_node, distance });

		}
	}
	int isVisit[MAX];
	fill(isVisit, isVisit + MAX, 0);

	BFS(1, isVisit);
	result = 0;

	fill(dis_sum, dis_sum + MAX, 0);
	fill(isVisit, isVisit + MAX, 0);

	BFS(Loc, isVisit);

	cout << result << "\n";
}