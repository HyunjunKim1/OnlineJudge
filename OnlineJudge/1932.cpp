#include <iostream>
#include <algorithm>

using namespace std;

int node[501][501];
int N;
int result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            int node_value;
            cin >> node_value;
            node[i][j] = node_value;
        }
    }

    result = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            if(j == 0)
                node[i][j] = node[i - 1][j] + node[i][j];
            else if(i == j)
                node[i][j] = node[i - 1][j - 1] + node[i][j];
            else
                node[i][j] = max(node[i - 1][j - 1] + node[i][j], node[i - 1][j] + node[i][j]);    

            result = max(result, node[i][j]);
        }
    }
    cout << result << "\n";
}