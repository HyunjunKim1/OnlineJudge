#include <iostream>
#include <algorithm>

using namespace std;

unsigned int ans;
unsigned int N, K;
unsigned int list[10000];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> K >> N;

	unsigned int maxi = 0;

	for (int i = 0; i < K; i++)
	{
		cin >> list[i];
		maxi = max(maxi, list[i]);
	}

	unsigned int left = 1, right = maxi, mid;

	while (left <= right)
	{
		// mid ����
		mid = (left + right) / 2;

		// ���� ���� �����ϴ� ����
		unsigned int now = 0;

		for (int i = 0; i < K; i++)
		{
			//mid�� ���� ���� ����
			now += list[i] / mid;
		}

		if (now >= N)
		{
			// ���� mid�� ���� ���� N���� ũ�ų� ���ٸ�,
			// left�� ������ ���̰� �� �� ���� �������� �˻�
			left = mid + 1;

			// N���� ���� �� ���� ��, ���� �� ū ������ ��� ����
			ans = max(ans, mid);
		}
		else
		{
			// ���� mid�� ���� ���� N���� �۴ٸ�,
			// right ������ ���̰� �� ª�� ���� �������� �˻�
			right = mid - 1;
		}
	}

	cout << ans << '\n';
}