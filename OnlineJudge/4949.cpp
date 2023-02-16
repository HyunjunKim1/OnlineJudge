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

		// ������ ���ڴ� . �̴ϱ� - 1
		for (int i = 0; i < s.length() - 1; i++) 
		{
			if (s[i] == '(') _stack.push(s[i]);
			if (s[i] == '[') _stack.push(s[i]);
			
			/*
			* �ݴ� ��ȣ�� ��������, stack�� ���� ��ȣ�� ������� false
			* ���ÿ� ���� ���� �� �����Ͱ� ¦�� �ȸ����� false
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