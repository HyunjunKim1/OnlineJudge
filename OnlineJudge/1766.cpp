#include <iostream>
#include<queue>
#include<vector>
using namespace std;

const int MAX = 32001;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int inDegree[MAX] = { 0 };
    vector<int> vt[MAX];
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        inDegree[b]++;
        vt[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {

        if (inDegree[i] == 0) {
            pq.push(i);
        }

    }
    while (!pq.empty()) {

        int here = pq.top();
        pq.pop();
        cout << here << ' ';

        for (int i = 0; i < vt[here].size(); i++) {

            int next = vt[here][i];

            if (--inDegree[next] == 0) {
                pq.push(next);
            }
        }

    }




    return 0;
}