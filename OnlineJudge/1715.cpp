#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;

    int cardNum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> cardNum;

        pq.push(cardNum);
    }

    //do {
    //
    //} while (!pq.empty());

    if (N == 1)
    {
        cout << "0" << "\n";
        return 0;
    }

    int result = 0;
    while (!pq.empty()) 
    {
        int sum = 0;
        sum += pq.top();
        pq.pop();
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
            if (!pq.empty())
                pq.push(sum);
        }

        result += sum;
    }

    cout << result << "\n";
}