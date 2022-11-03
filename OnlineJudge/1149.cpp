#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> house;
vector<int> cost;
int r = 0;
int g = 0;
int b = 0;
int result, N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> r >> g >> b;
		cost.push_back(r);
		cost.push_back(g);
		cost.push_back(b);

		house.push_back(cost);

		cost.clear();

		house[i][0] += min(house[i - 1][1], house[i - 1][2]) + house[i][0];
		house[i][1] += min(house[i - 1][0], house[i - 1][2]) + house[i][1];
		house[i][2] += min(house[i - 1][1], house[i - 1][0]) + house[i][2];
	}


	result = min(house[N][0], min(house[N][1], house[N][2]));

	cout << result;
}