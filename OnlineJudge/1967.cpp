#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

bool isVisit[MAX];
int N;
int MaxN, MaxWeight;
struct NODE
{
    int node;
    int weight;
};

vector<NODE> vec[MAX];

void DFS(int idx, int weight)
{
    if(isVisit[idx] == true)
        return;

    isVisit[idx] = true;

    if (weight > MaxWeight)
    {
        MaxWeight = weight;
        MaxN = idx;
    }

    for (int i = 0; i < vec[idx].size(); i++)
    {
        int next_node = vec[idx][i].node;
        int next_weight = vec[idx][i].weight + weight;
        DFS(next_node, next_weight);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 부모노드, 자식노드, 가중치
    int parent, child, weight;

    cin >> N;

    for(int i = 0; i < N - 1; i++)
    {
        cin >> parent >> child >> weight;
        vec[parent].push_back({child,weight});
        vec[child].push_back({parent, weight});
    }

    // 시작 노드는 항시 1이고, 1이 헤드이기에 가중치 0
    DFS(1, 0);

    // 이후 초기화
    memset(isVisit, 0, sizeof(isVisit));

    // 시작지점에서부터 가장 먼 정점을 찾았으니,
    // 그 해당 정점에서 가장 먼 정점 찾기. 가중치 초기화
    MaxWeight = 0; DFS(MaxN, 0);

    cout << MaxWeight;
}
