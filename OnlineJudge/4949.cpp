#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() 
{
	while (true)
	{
		stack<char> _stack;
		bool result = true;

		string s;

		getline(cin, s);

		if (s[0] == '.')
			break;

		// 마지막 글자는 . 이니까 - 1
		for (int i = 0; i < s.length() - 1; i++) 
		{
			if (s[i] == '(') _stack.push(s[i]);
			if (s[i] == '[') _stack.push(s[i]);
			
			/*
			* 닫는 괄호가 나오지만, stack에 여는 괄호가 없을경우 false
			* 스택에 쌓인 가장 위 데이터가 짝이 안맞으면 false
			*/ 
			if (s[i] == ')') 
			{
				if (_stack.empty() || _stack.top() == '[') result = false;
				else _stack.pop();
			}
			if (s[i] == ']')
			{
				if (_stack.empty() || _stack.top() == '(') result = false;
				else _stack.pop();
			}
		}

		if (_stack.empty() && result) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}