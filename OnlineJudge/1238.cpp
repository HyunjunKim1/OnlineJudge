#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 987654321
using namespace std;

int n, m, x;
int u, v, w;
int ans;

typedef pair<int, int> pii;

vector<pii> adj[MAX];
vector<pii> r_adj[MAX];

void dijkstra(int s) {
    vector<int> dist1(n + 1, INF);
    vector<int> dist2(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // 목표 지점에서 돌아오는 길
    pq.push(pii(0, s));
    dist1[s] = 0;
    while (!pq.empty()) {
        int pre_d = pq.top().first;
        int pre_v = pq.top().second;
        pq.pop();

        if (pre_d > dist1[pre_v]) continue;

        for (int i = 0; i < adj[pre_v].size(); i++) {
            int nxt_v = adj[pre_v][i].first;
            int cost = adj[pre_v][i].second;

            if (dist1[nxt_v] > dist1[pre_v] + cost) {
                dist1[nxt_v] = dist1[pre_v] + cost;
                pq.push(pii(dist1[nxt_v], nxt_v));
            }
        }
    }

    // 목표 지점으로 가는길
    pq.push(pii(0, s));
    dist2[s] = 0;

    while (!pq.empty()) {
        int pre_d = pq.top().first;
        int pre_v = pq.top().second;
        pq.pop();

        if (pre_d > dist2[pre_v]) continue;

        for (int i = 0; i < r_adj[pre_v].size(); i++) {
            int nxt_v = r_adj[pre_v][i].first;
            int cost = r_adj[pre_v][i].second;

            if (dist2[nxt_v] > dist2[pre_v] + cost) {
                dist2[nxt_v] = dist2[pre_v] + cost;
                pq.push(pii(dist2[nxt_v], nxt_v));
            }
        }
    }

    ans = 0;
    for (int i = 1; i <= n; i++) {
        int d = dist1[i] + dist2[i];
        ans = max(ans, d);
    }
    cout << ans << endl;
}

int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(pii(v, w));
        r_adj[v].push_back(pii(u, w));
    }

    dijkstra(x);
}