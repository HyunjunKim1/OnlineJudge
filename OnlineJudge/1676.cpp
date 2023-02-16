#include <iostream>
using namespace std;

int num2 = 0;
int num5 = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	int temp;

	//2와 5의 개수
	for (int i = 2; i <= n; i++)
	{
		temp = i;
		// 2
		while (temp % 2 == 0)
		{
			num2++;
			temp /= 2;
		}
		// 5
		while (temp % 5 == 0)
		{
			num5++;
			temp /= 5;
		}
	}
	cout << min(num2, num5);
}