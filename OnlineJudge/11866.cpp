#include <iostream>
#include <queue>

using namespace std;

queue<int> _queue;
int _cnt = 1;

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) 
        _queue.push(i);
    
    cout << "<";

    while (1) 
    {
        if (_cnt % K == 0)
        {
            int result = _queue.front();
            _queue.pop();
            if (_queue.empty())
            {
                cout << result << ">";
                break;
            }
            else 
                cout << result << ", ";
            
        }
        else 
        {
            int num = _queue.front();
            _queue.pop();
            _queue.push(num);
        }
        _cnt++;
    }
}