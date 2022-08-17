#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() 
{
	int T;
	string s;
	int _size = 0;
	bool result = true;


	cin >> T;


	for (int i = 0; i < T; i++) {
		stack<char> _stack;
		cin >> s;

		_size = s.length();

		for (int j = 0; j < _size; j++) {

			if (s[j] == '(')
				_stack.push(s[j]);
			else if (s[j] == ')')
			{
				if (_stack.empty())
				{
					result = false;
					break;
				}
				else
					_stack.pop();
			}
		}
		if (!_stack.empty() || result == false)
			cout << "NO" << endl;
		else if(result)
			cout << "YES" << endl;

		result = true;
	}
}