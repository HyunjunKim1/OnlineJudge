#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int line[1001][1001];
int visited[1001];
int n, m, v;
queue<int> q;
stack<int> stk;
void dfs(int idx) {

    stk.push(idx);


    while (!stk.empty()) {
        idx = stk.top();

        stk.pop();
        if (!visited[idx])
            cout << idx << ' ';
        visited[idx] = 1;
        for (int i = n; i > 0; i--) {
            if (line[idx][i] && !visited[i]) {
                stk.push(i);
            }
        }

    }

}

void bfs(int idx) {

    q.push(idx);

    while (!q.empty()) {

        idx = q.front();

        q.pop();

        cout << idx << ' ';

        for (int i = 1; i <= n; i++) {
            if (line[idx][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }


    }


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> v;


    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        line[from][to] = 1;
        line[to][from] = 1;
    }

    dfs(v);

    cout << '\n';
    fill_n(visited, 1001, 0);

    visited[v] = 1;
    bfs(v);
    return 0;
}