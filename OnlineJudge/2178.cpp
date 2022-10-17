#include <iostream>
#include <queue>
#include <string>

using namespace std;
int N, M;

int _search[101][101];
int _isVisit[101][101];

int BFS(int X, int Y)
{
	queue<pair<int, int>> q;
	int move[4][2] = { {0,1},{0,-1}, {1,0}, {-1,0} };

	// 시작점 입력
	q.push({ 1, 1 });

	while (!q.empty())
	{
		X = q.front().first;
		Y = q.front().second;

		q.pop();

		// 4방향 탐색
		for (int i = 0; i < 4; i++)
		{
			int SearchX = X + move[i][0];
			int SearchY = Y + move[i][1];

			if (SearchX < 101 && SearchY < 101 && _search[SearchX][SearchY] && !_isVisit[SearchX][SearchY])
			{
				q.push({ SearchX,SearchY });
				_isVisit[SearchX][SearchY] = _isVisit[X][Y] + 1;
			}
		}
	}
	return _isVisit[N][M];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	string* maze = new string[N];

	for (int i = 0; i < N; i++)
	{
		cin >> maze[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == '1')
				// 1,1에서 시작하기에, 좌표에 + 1을 시켜준다.
				_search[i + 1][j + 1] = 1;
		}
	}

	//처음 방문 좌표 1,1은 탐색한거로 간주
	_isVisit[1][1] = 1;
	cout << BFS(1, 1) << "\n";

	delete[] maze;
}