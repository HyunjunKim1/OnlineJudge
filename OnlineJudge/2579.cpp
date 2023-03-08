#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num;
int stair[301];
int dp[301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> stair[i];

	dp[0] = stair[0];
	dp[1] = max(stair[1], stair[0] + stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < N; i++)
		dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);

	cout << dp[N - 1];
}