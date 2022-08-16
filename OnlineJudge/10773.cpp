#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int k, num;
    int sum = 0;

    cin >> k;

    stack<int> _stack;

    for (int i = 0; i < k; i++) {
        cin >> num;

        if (num != 0)
            _stack.push(num);
        else
            _stack.pop();
    }

    int size = _stack.size();
    for (int i = 0; i < size; i++) {
        sum += _stack.top();
        _stack.pop();
    }

    cout << sum << endl;

    return 0;
}