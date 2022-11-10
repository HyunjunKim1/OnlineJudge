#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 학생 수
int N;
// 도로 수
int M;
// 파티하는 마을
int X;
// 이동 최소거리 저장 
int _distance[1001];
// 오름차순 정렬 큐
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> _vec[1001];


void Dijkstra(int idx)
{
	// init
	fill(_distance, _distance + 1001, -1);
	_distance[idx] = 0;

	pq.push({ 0,idx });

	while (!pq.empty())
	{
		int d = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		for (int i = 0; i < _vec[x].size(); i++)
		{
			int mx = _vec[x][i].first;
			int md = _vec[x][i].second;

			// 처음 방문하거나, 큐에 있는 짧은 거리가 다음 방문할곳을 더한 거리보다 짧을 경우
			if (_distance[mx] == -1 || _distance[mx] > d + md)
			{
				// 다음 방문 거리까지 더한 후 갱신
				_distance[mx] = d + md;
				pq.push({ _distance[mx], mx });
			}
		}
	}
}

int main()
{
	int result[1001] = { 0, };
	int ans = 0;

	cin >> N >> M >> X;

	while (M--)
	{
		int s, e, t;
		cin >> s >> e >> t;
		// 시작위치에 끝점과 소요시간 저장
		_vec[s].push_back({ e,t });
	}

	// 시작 idx에서 X까지의 거리
	for (int i = 1; i <= N; i++)
	{
		// 같은 위치인 경우 제외
		if (i == X)
			continue;
		Dijkstra(i);
		result[i] = _distance[X];
	}

	Dijkstra(X);

	// 다시 돌아가는 거리 추가
	for (int i = 1; i <= N; i++)
	{
		result[i] += _distance[i];
	}


	for (int i = 1; i <= N; i++)
		ans = max(ans, result[i]);

	cout << ans;
}