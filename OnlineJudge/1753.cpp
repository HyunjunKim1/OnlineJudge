// 최단경로
// 그래프 이론, 다익스트라
#include<iostream>
#include<vector>
#include<queue>
#define INF 2147000000
#define MAX 20001
using namespace std;
struct Edge {
    int ver;
    int dist;
    Edge(int a, int b) :ver(a), dist(b) {};
    bool operator<(const Edge& e)const { return dist > e.dist; }
};
priority_queue<Edge>q;
vector<pair<int, int>>g[MAX];
vector<int>dist(MAX, INF);
void dijkstra(int x) {
    dist[x] = 0;
    q.push(Edge(x, 0));
    while (!q.empty()) {
        int v = q.top().ver;
        int d = q.top().dist;
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int nextV = g[v][i].first;
            int nextD = d + g[v][i].second;
            if (dist[nextV] > nextD) {
                dist[nextV] = nextD;
                q.push(Edge(nextV, nextD));
            }
        }
    }
}
int main() {
    int V, E, K, a, b, c;
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        g[a].push_back({ b,c });
    }
    dijkstra(K);
    for (int i = 1; i <= V; i++)
        cout << (dist[i] == INF ? "INF" : to_string(dist[i])) << '\n';
}
