#include <iostream>
// #include <unordered_set>
#include <set>
#include <algorithm> //sort
#include <cstring>   //memset, use 0 or -1
#define endl '\n'
using namespace std;
// unordered_set<int> visited;
set<int> visited;
const int Max = 50 + 1;
int n, m, t, k, pn, on, cnt;
// int ppl[Max];

struct meet
{
    unsigned int p1;
    unsigned int p2;
};
typedef struct meet meet;
meet meetings[Max - 1];

//ppl who know the truth
struct ppl
{
    unsigned int p1;
    unsigned int p2;
};
typedef struct ppl ppl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ppl ppl;
    ppl.p1 = 0;
    ppl.p2 = 0;
    // meet meet;

    cin >> n >> m >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> pn;
        if (pn < 32)
            ppl.p1 |= 1 << pn;
        else
            ppl.p2 |= 1 << (pn - 32);
    }
    for (int j = 0; j < m; j++)
    {
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> pn;
            if (pn < 32)
                meetings[j].p1 |= 1 << pn;
            else
                meetings[j].p2 |= 1 << (pn - 32);
        }
    }
    if (!t)
        cout << m << endl;
    else
    {
        while (visited.size() != m)
        {
            for (int i = 0; i < m; ++i)
            {
                // unsigned int& pplP1=ppl.p1;
                // unsigned int& pplP2=ppl.p2;
                auto met = visited.find(i);
                if (met == visited.end())
                {
                    if (meetings[i].p1 & ppl.p1 || meetings[i].p2 & ppl.p2)
                    {
                        ppl.p1 |= meetings[i].p1;
                        ppl.p2 |= meetings[i].p2;
                        visited.insert(i);
                        i = -1; //important!!!
                    }
                    else if (on)
                    {
                        cnt++;
                        visited.insert(i);
                    }
                }
            }
            on = 1;
        }
        cout << cnt << endl;
    }
    return 0;
}