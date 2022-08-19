#include<iostream>
#include<queue>
using namespace std;

int main()
{
	// 아래의 두 구문을 사용할 경우 주의점
	// https://hyun-jun5.tistory.com/17
	/*
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	*/
	int cnt, num;
	string s;
	queue<int> _queue;

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> num;
			_queue.push(num);
		}
		else if (s == "pop")
		{
			if (!_queue.empty())
			{
				cout << _queue.front() << '\n';
				_queue.pop();
			}
			else cout << -1 << '\n';
		}
		else if (s == "size")  cout << _queue.size() << '\n';
		else if (s == "empty") cout << _queue.empty() << '\n';
		else if (s == "front")
		{
			if (!_queue.empty()) cout << _queue.front() << '\n';
			else cout << -1 << '\n';
		}
		else 
		{
			if (!_queue.empty()) cout << _queue.back() << '\n';
			else cout << -1 << '\n';
		}
	}

}