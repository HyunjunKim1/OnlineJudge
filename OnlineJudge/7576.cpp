#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int tomato[1001][1001];
int d[1001][1001];
int n, m;
int main() {
    scanf("%d %d", &m, &n);
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &tomato[i][j]);
            d[i][j] = -1;
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
                d[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (tomato[nx][ny] == 0 && d[nx][ny] == -1) {
                    // 익지 않은 토마토 이면서 방문하지 않은 곳 
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            result = max(result, d[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (tomato[i][j] == 0 && d[i][j] == -1)
                result = -1;

    printf("%d\n", result);

}