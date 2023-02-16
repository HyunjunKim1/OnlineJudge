#include <algorithm>
#include <stdio.h>

using namespace std;
//플로이드 와셜 알고리즘

const int MAX = 101;
const int INF = 10001000;
int D[MAX][MAX];
int ANS[MAX];

int main(void)
{
    int n, m; 
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            D[i][j] = INF;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        D[a][b] = 1;
        D[b][a] = 1;
    } 

    for (int K = 1; K <= n; K++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                D[i][j] = min(D[i][j], D[i][K] + D[K][j]);

    for (int K = 1; K <= n; K++) {
        for (int i = 1; i <= n; i++)
            ANS[K] += D[K][i];
        ANS[K] -= D[K][K];
    }

    int min = ANS[1];
    int index = 1;
    for (int i = 2; i <= n; i++) {
        if (ANS[i] < min) {
            min = ANS[i];
            index = i;
        }
    } 

    printf("%d\n", index);
}