#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	priority_queue<int,vector<int>, greater<int>> q;

	cin >> N;
	while (N--)
	{
		int x;
		cin >> x;

		if (x == 0 && q.empty())
		{
			cout << "0" << '\n';
		}
		else if (x == 0)
		{
			cout << q.top() << '\n';
			q.pop();
		}
		else
			q.push(x);
	}
}