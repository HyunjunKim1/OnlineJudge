#include <iostream>
#include <vector>
#define MAX 501
#define INF 1000000

using namespace std;

int N, M, W;
int S, E, T;
bool minusCycle;
int dist[MAX];
vector<pair<int, int>> vec[MAX];

bool BellmanAlgorithm()
{
	fill(dist, dist + MAX, INF);

	dist[1] = 0;
	minusCycle = false;

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (auto k : vec[j])
			{
				int n = k.first;
				int w = k.second;
				if (dist[n] > dist[j] + w)
				{
					dist[n] = dist[j] + w;
					if (i == N - 1) 
						minusCycle = true;
				}
			}
		}
	}
	return minusCycle;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;

	for (int i = 0; i < TC; i++) 
	{
		cin >> N >> M >> W;

		for (int i = 0; i < M; i++)
		{
			cin >> S >> E >> T;
			vec[S].push_back({ E,T });
			vec[S].push_back({ S,T });
		}

		for (int i = 0; i < W; i++)
		{
			cin >> S >> E >> T;
			vec[S].push_back({ E,-T });
		}

		if (BellmanAlgorithm())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

		for(int a = 0; a <= N; a++)
		{
			vec[a].clear();
		}
	}
	
}