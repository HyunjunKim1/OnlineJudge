#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N * N; i++)
	{
		int num;
		cin >> num;

		pq.push(num);
		if (pq.size() > N)
			pq.pop();
	}

	cout << pq.top() << "\n";
}