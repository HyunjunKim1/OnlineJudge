#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vec(100);

	for (int i = 0; i < 101; i++)
	{
		vec.push_back(i);
	}

	for (int i : vec)
	{
		cout << i << " ";
	}
}