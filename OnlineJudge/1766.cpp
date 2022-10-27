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
    vector<int> vec[32000];
    priority_queue<int, vector<int>, greater<int>> pq;
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        degree[b]++;
        vec[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {

        if (degree[i] == 0) {
            pq.push(i);
        }

    }
    while (!pq.empty()) 
    {
        int qNum = pq.top();
        pq.pop();
        cout << qNum << ' ';

        for (int i = 0; i < vec[qNum].size(); i++) {

            int next = vec[qNum][i];

            if (--degree[next] == 0) {
                pq.push(next);
            }
        }
    }
}