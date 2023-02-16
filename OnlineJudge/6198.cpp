#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<long long> s;
	int N, hi;
	long long total = 0;

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

		total += s.size();

		s.push(hi);
	}

	cout << total << "\n";
}