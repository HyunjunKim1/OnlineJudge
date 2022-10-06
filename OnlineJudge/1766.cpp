#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int degree[32000] = { 0 };
    vector<int> vt[32000];
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        degree[b]++;
        vt[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {

        if (degree[i] == 0) {
            pq.push(i);
        }

    }
    while (!pq.empty()) 
    {
        int qNum = pq.top();
        pq.pop();
        cout << qNum << ' ';

        for (int i = 0; i < vt[qNum].size(); i++) {

            int next = vt[qNum][i];

            if (--degree[next] == 0) {
                pq.push(next);
            }
        }
    }
}