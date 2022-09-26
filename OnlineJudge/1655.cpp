// 시간초과 코드

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector <int> vec;
	priority_queue<int> q;

	while (N--)
	{
		int x;
		cin >> x;

		q.push(x);

		for (int i = 0; i < q.size(); i++)
		{
			vec.push_back(q.top());
			q.pop();
		}

		sort(vec.begin(), vec.end());

		if (vec.size() != 0)
		{
			if (vec.size() == 1)
				cout << vec[0] << '\n';
			else if (vec.size() == 2)
			{
				if (vec[0] > vec[1])
				{
					cout << vec[1] << '\n';
				}
				else
					cout << vec[0] << '\n';
			}
			else {
				int CalSize = vec.size() / 2;
				if (vec.size() % 2 == 0)
				{
					if (vec[CalSize - 1] > vec[CalSize])
					{
						cout << vec[CalSize] << '\n';
					}
					else
						cout << vec[CalSize - 1] << '\n';
				}
				else
				{
					if (vec[CalSize] > vec[CalSize + 1])
					{
						cout << vec[CalSize + 1] << '\n';
					}
					else
						cout << vec[CalSize] << '\n';
				}
			}
		}
	}
}
*/

#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int>> min;

	while (N--) {
		int a, size;
		cin >> a;
		if (max.size() == min.size()) {
			max.push(a);
		}
		else {
			min.push(a);
		}
		if (!max.empty() && !min.empty() && max.top() > min.top()) {
			int max_val, min_val;
			max_val = max.top();
			min_val = min.top();
			max.pop();
			min.pop();
			max.push(min_val);
			min.push(max_val);


		}
		cout << max.top() << '\n';
	}
}