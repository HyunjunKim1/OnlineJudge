#include <iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int degree[32000];
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(32000);
    queue<int> q;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        degree[b]++;
        vec[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {

        int qNum = q.front();
        q.pop();
        cout << qNum << ' ';

        for (int i = 0; i < vec[qNum].size(); i++) {

            int next = vec[qNum][i];
            if (--degree[next] == 0) {
                q.push(next);
            }

        }

    }
}