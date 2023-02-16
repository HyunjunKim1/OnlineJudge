#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// �л� ��
int N;
// ���� ��
int M;
// ��Ƽ�ϴ� ����
int X;
// �̵� �ּҰŸ� ���� 
int _distance[1001];
// �������� ���� ť
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

			// ó�� �湮�ϰų�, ť�� �ִ� ª�� �Ÿ��� ���� �湮�Ұ��� ���� �Ÿ����� ª�� ���
			if (_distance[mx] == -1 || _distance[mx] > d + md)
			{
				// ���� �湮 �Ÿ����� ���� �� ����
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
		// ������ġ�� ������ �ҿ�ð� ����
		_vec[s].push_back({ e,t });
	}

	// ���� idx���� X������ �Ÿ�
	for (int i = 1; i <= N; i++)
	{
		// ���� ��ġ�� ��� ����
		if (i == X)
			continue;
		Dijkstra(i);
		result[i] = _distance[X];
	}

	Dijkstra(X);

	// �ٽ� ���ư��� �Ÿ� �߰�
	for (int i = 1; i <= N; i++)
	{
		result[i] += _distance[i];
	}


	for (int i = 1; i <= N; i++)
		ans = max(ans, result[i]);

	cout << ans;
}