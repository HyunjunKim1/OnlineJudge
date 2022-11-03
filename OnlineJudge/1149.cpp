#include <iostream>
#include <vector>

using namespace std;

int N;
int rgb[3];
int arr[999][3];
int result;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> rgb[0] >> rgb[1] >> rgb[2];

		if (i == 0)
		{
			arr[i][0] = rgb[0];
			arr[i][1] = rgb[1];
			arr[i][2] = rgb[2];
		}
		else
		{
			arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + rgb[0];
			arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + rgb[1];
			arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + rgb[2];
		}
		result = min(min(arr[N - 1][0], arr[N - 1][1]), min(arr[N - 1][1], arr[N - 1][2]));
	}

	cout << result << "\n";
}