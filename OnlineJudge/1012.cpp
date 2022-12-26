#include<iostream>
using namespace std;


int map[50][50];
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };
pair<int, int> cab[2500];

void dfs(int x, int y, int r, int c) {


	for (int i = 0; i < 4; i++) {

		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c) continue;
		if (map[next_x][next_y] == 1) {
			map[next_x][next_y] = 2; //방문하고 안으로 깊이 들어간다.
			dfs(next_x, next_y, r, c);
		}

	}

}


int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int r, c;
		int K;
		cin >> r >> c >> K;


		//map초기화
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				map[j][k] = 0;
			}
		}

		for (int j = 0; j < K; j++) {

			cin >> cab[j].first >> cab[j].second;
			map[cab[j].first][cab[j].second] = 1;
		}

		int cnt = 0;
		for (int j = 0; j < K; j++) {
			if (map[cab[j].first][cab[j].second] == 1) {
				cnt++;
				map[cab[j].first][cab[j].second] = 2;
				dfs(cab[j].first, cab[j].second, r, c);

			}

		}

		cout << cnt << endl;
	}
}