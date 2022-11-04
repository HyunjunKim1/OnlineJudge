#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define endl "\n"
#define MAX 1010
#define INF 987654321
using namespace std;

int N, M, X, Answer;
int Dist[MAX], Res[MAX];
vector<pair<int, int>> V[MAX];

void Input()
{
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
    }
}

void Dijkstra(int Start)
{
    priority_queue<pair<int, int>> PQ;
    Dist[Start] = 0;
    PQ.push(make_pair(0, Start));

    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < V[Cur].size(); i++)
        {
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;

            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }

}

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) Dist[j] = INF;
        Dijkstra(i);
        Res[i] = Dist[X];
    }
    for (int j = 1; j <= N; j++) Dist[j] = INF;
    Dijkstra(X);
    for (int i = 1; i <= N; i++) Res[i] = Res[i] + Dist[i];
    sort(Res + 1, Res + N + 1);
    Answer = Res[N];
}

void Solve()
{
    Input();
    Solution();
    cout << Answer << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}