 #include <iostream>

using namespace std;

bool _isExist[10000000];
int _gi[14];
int k;
int sum;
int result;

void recursive(int idx, int input)
{
	if (input >= 1)
	{
		if (!_isExist[input])
			result++;
		_isExist[input] = true;
	}

	if (idx == k)
		return;

	recursive(idx + 1, input + _gi[idx]);
	recursive(idx + 1, input - _gi[idx]);
	recursive(idx + 1, input);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> _gi[i];

		sum += _gi[i];
	}

	recursive(0, 0);

	cout << sum - result << "\n";
}