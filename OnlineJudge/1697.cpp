#include <iostream>
#include <queue>

using namespace std;

int N, K;
int _isVisit[100001];

int BFS(int X)
{
	queue<int> q;
	q.push(X);

	while (!q.empty())
	{
		X = q.front();

		// ����� �� ����.
		int move[3] = { 1,-1,X };

		// ��ġ(��)�� �����ϸ� �ٷ� ����
		if (X == K)
			break;

		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int SearchX = X + move[i];
			if (SearchX >= 0 && SearchX < 100001 && !_isVisit[SearchX])
			{
				q.push(SearchX);
				_isVisit[SearchX] = _isVisit[X] + 1;

			}
		}
	}

	return _isVisit[K];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	cout << BFS(N);
}