#include <iostream>
#define MAX 1000001
using namespace std;

int N;
int dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
		{
			if (dp[i] >= dp[i / 2] + 1)
				dp[i] = dp[i / 2] + 1;
		}
		if (i % 3 == 0)
		{
			if (dp[i] >= dp[i / 3] + 1)
				dp[i] = dp[i / 3] + 1;
		}
	}

	cout << dp[N];
}