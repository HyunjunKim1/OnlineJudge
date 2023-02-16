#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> _stack;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    int len = str.length();

    for (char ch : str)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            cout << ch;
        }

        else
        {
            if (ch == '(')
            {
                _stack.push(ch);
            }

            else if (ch == '*' || ch == '/')
            {
                while (!_stack.empty() && (_stack.top() == '*' || _stack.top() == '/'))
                {
                    cout << _stack.top();
                    _stack.pop();
                }
                _stack.push(ch);
            }

            else if (ch == '+' || ch == '-')
            {
                while (!_stack.empty() && _stack.top() != '(')
                {
                    cout << _stack.top();
                    _stack.pop();
                }
                _stack.push(ch);
            }

            else if (ch == ')')
            {
                while (!_stack.empty() && _stack.top() != '(')
                {
                    cout << _stack.top();
                    _stack.pop();
                }
                _stack.pop();
            }
        }
    }

    while (!_stack.empty())
    {
        cout << _stack.top();
        _stack.pop();
    }
}