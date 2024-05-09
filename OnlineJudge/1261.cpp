#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int M, N;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool check[102][102][400];
string board[102];
int answer = 1e9;

struct xyz {
    int x, y, z;
};
queue<xyz> q;

void bfs() {

    check[0][0][0] = 1;
    q.push({ 0,0 });
    while (!q.empty()) {

        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;

        if (x == N - 1 && y == M - 1) {
            answer = min(answer, z);
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z;
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (check[nx][ny][nz]) continue;
            if (board[nx][ny] == '0') {
                check[nx][ny][nz] = true;
                q.push({ nx,ny,nz });
            }
            else {
                if (check[nx][ny][nz + 1]) continue;
                check[nx][ny][nz + 1] = true;
                q.push({ nx,ny,nz + 1 });
            }


        }
    }
}
int main() {
    //무방향성
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    bfs();
    cout << answer;
    return 0;
}