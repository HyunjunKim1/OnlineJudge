#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <cstring> // memset

#define MAX_SIZE 1000+1

using namespace std;

void dfs(int start);
void bfs(int start);

vector<int> connected[MAX_SIZE];
bool visited[MAX_SIZE];

void dfs(int start) {
    visited[start] = true;
    for (int i = 0; i < connected[start].size(); i++) {
        int next = connected[start][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;

    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int csize = connected[current].size();
        for (int i = 0; i < csize; i++) {
            int next = connected[current][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m; // 정점의 개수, 간선의 개수
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) { // 간선의 연결
        int u, v;
        scanf("%d %d", &u, &v);
        connected[u].push_back(v);
        connected[v].push_back(u);
    }

    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            bfs(i);
            //dfs(i);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
