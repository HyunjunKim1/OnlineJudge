#include <iostream>

using namespace std;

int T, N;
int _zero[41] = { 1,0, };
int _one[41] = { 0,1, };

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 2; i <= N; i++)
		{
			_zero[i] = _zero[i - 1] + _zero[i - 2];
			_one[i]  = _one[i - 1] + _one[i - 2];
		}
		cout << _zero[N] << " " << _one[N] << "\n";
	}
}