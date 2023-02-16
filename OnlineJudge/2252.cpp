#include <iostream>
#include<queue>
#include<vector>

using namespace std;
const int MAX = 32001;

int inDegree[MAX];


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(MAX);
    queue<int> q;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        inDegree[b]++;
        vec[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {

        int here = q.front();
        q.pop();
        cout << here << ' ';

        for (int i = 0; i < vec[here].size(); i++) {

            int next = vec[here][i];
            if (--inDegree[next] == 0) {
                q.push(next);
            }

        }

    }




    return 0;
}