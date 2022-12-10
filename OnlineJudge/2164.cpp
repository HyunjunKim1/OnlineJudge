#include <iostream>
#include <queue>

// test
using namespace std;

int main() 
{
	queue<int> _queue;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		_queue.push(i);
	}

	while (1) 
	{
		if (_queue.size() == 1)
		{
			cout << _queue.front() << "\n";
			break;
		}

		_queue.pop();
		_queue.push(_queue.front());
		_queue.pop();
	}
}