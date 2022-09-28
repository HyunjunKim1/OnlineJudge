#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N 32000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Indegree[N] = { 0, };
	vector<int> vec[N];

	priority_queue<int, vector<int>, greater<int>> pq;
	int n, m;

	cin >> n >> m;

	for (int i = 0; i <= m; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		Indegree[num2]++;
		vec[num1].push_back(num2);
	}
}