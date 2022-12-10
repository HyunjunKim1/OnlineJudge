#include <iostream>
#include <algorithm>

using namespace std;

string base[105][105] = {"0", };

string StringCalculate(string a, string b)
{
	int add = 0;
	string result;
	while (!a.empty() || !b.empty() || add)
	{
		if (!a.empty())
		{
			add += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty())
		{
			add += b.back() - '0';
			b.pop_back();
		}
		result.push_back((add % 10) + '0');
		add /= 10;
	}
	reverse(result.begin(), result.end());

	return result;
}

string nCm(int n, int m)
{
	if (n == m || m == 0)
		return "1";

	if (base[n][m] != "")
		return base[n][m];

	return base[n][m] = StringCalculate(nCm(n - 1, m - 1), nCm(n - 1, m));
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	cout << nCm(n, m);
}

