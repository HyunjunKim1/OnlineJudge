#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int T, K;

    cin >> T;
    
    while (T > 0)
    {
        multiset<int> m;
        T--;
        cin >> K;

        for (int i = 0; i < K; i++)
        {
            char c;
            int n;

            cin >> c >> n;

            if (m.empty()) 
            {
                if (c == 'I') 
                    m.insert(n);
            }
            else
            {
                if (c == 'I') 
                    m.insert(n);
                else 
                {
                    if (n == 1) 
                        m.erase(--m.end());
                    else {
                        m.erase(m.begin());
                    }
                }
            }
        }

        if (m.empty())
            cout << "EMPTY" << '\n';
        else 
        {
            auto max = --m.end();
            auto min = m.begin();
            cout << *max << ' ' << *min << '\n';
        }
    }
}