#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct AbsGreater
{
	bool operator()(int a, int b) {
		if (abs(a) > abs(b))
			return true;
		else if (abs(a) == abs(b)) {
			if (a > b)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	priority_queue<int, vector<int>, AbsGreater> q;

	while (N--)
	{
		int x;

		cin >> x;

		if (x != 0)
		{
			q.push(x);
		}

		else if (x == 0)
		{
			if (q.empty() == true)
				cout << "0" << '\n';

			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}
}