#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int line[1001][1001];
int visited[1001];
int N, M, V;

queue<int> q;
stack<int> stk;
void DFS(int idx) 
{

    stk.push(idx);


    while (!stk.empty()) 
    {
        idx = stk.top();

        stk.pop();
        if (!visited[idx])
            cout << idx << ' ';
        visited[idx] = 1;
        for (int i = N; i > 0; i--) 
        {
            if (line[idx][i] && !visited[i]) 
            {
                stk.push(i);
            }
        }

    }

}

void BFS(int idx) 
{

    q.push(idx);

    while (!q.empty()) 
    {

        idx = q.front();

        q.pop();

        cout << idx << ' ';

        for (int i = 1; i <= N; i++) 
        {
            if (line[idx][i] && !visited[i]) 
            {
                q.push(i);
                visited[i] = 1;
            }
        }


    }


}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;


    for (int i = 0; i < M; i++) 
    {
        int from, to;
        cin >> from >> to;
        line[from][to] = 1;
        line[to][from] = 1;
    }

    DFS(V);

    cout << '\n';

    fill_n(visited, 1001, 0);

    visited[V] = 1;
    BFS(V);
    return 0;
}