#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int map[1001][1001];
int dist[1001][1001][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            if (map[nx][ny] == 0 && dist[nx][ny][z] == 0)
            {
                dist[nx][ny][z] = dist[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z));
            }
            if (z == 0 && map[nx][ny] == 1 && dist[nx][ny][z + 1] == 0)
            {
                dist[nx][ny][z + 1] = dist[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z + 1));
            }
        }
    }

    if (dist[n - 1][m - 1][0] != 0 && dist[n - 1][m - 1][1] != 0)
    {
        printf("%d\n", min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]));
    }
    else if (dist[n - 1][m - 1][0] != 0)
    {
        printf("%d\n", dist[n - 1][m - 1][0]);
    }
    else if (dist[n - 1][m - 1][1] != 0)
    {
        printf("%d\n", dist[n - 1][m - 1][1]);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}