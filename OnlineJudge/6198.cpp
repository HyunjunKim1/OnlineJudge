#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> s;
	int N, hi;
	int fIdx = 0;
	int total = 0;

	cin >> N;

	while (N--)
	{
		cin >> hi;

		if (s.empty())
		{
			s.push(hi);
			continue;
		}

		while (!s.empty() && s.top() <= hi)
			s.pop();

		total = total + s.size();

		s.push(hi);
	}

	cout << total << "\n";
}