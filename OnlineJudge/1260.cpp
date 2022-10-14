#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int line[1001][1001];
int isVisit[1001];
int N, M, V;

queue<int> _q;
stack<int> _stack;
void DFS(int vertex_num)
{

    _stack.push(vertex_num);


    while (!_stack.empty())
    {
        vertex_num = _stack.top();

        _stack.pop();
        if (!isVisit[vertex_num])
            cout << vertex_num << ' ';
        isVisit[vertex_num] = true;
        for (int i = N; i > 0; i--) 
        {
            if (line[vertex_num][i] && !isVisit[i])
            {
                _stack.push(i);
            }
        }

    }

}

void BFS(int vertex_num) 
{

    _q.push(vertex_num);

    while (!_q.empty()) 
    {

        vertex_num = _q.front();

        _q.pop();

        cout << vertex_num << ' ';

        for (int i = 1; i <= N; i++) 
        {
            if (line[vertex_num][i] && !isVisit[i])
            {
                _q.push(i);
                isVisit[i] = true;
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

    fill_n(isVisit, 1001, 0);

    isVisit[V] = true;
    BFS(V);
    return 0;
}