#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int testn;
	int n, m;
	int importance;
	int count;

	scanf("%d", &testn);

	for (int i = 0; i < testn; i++) {
		count = 0;
		scanf("%d %d", &n, &m);

		priority_queue<int> pq; // �������� �����ؾ� pop�� �� ������ ��������.
		queue<pair<int, int>> q;

		for (int j = 0; j < n; j++) {
			scanf("%d", &importance);
			q.push({ j, importance });
			pq.push(importance);
		}

		while (!q.empty()) {
			// ��ġ����, �켱���� ���� ������ �� pop����
			int location = q.front().first;
			int value = q.front().second;
			q.pop();

			// �� ��
			if (pq.top() == value) {
				pq.pop();
				++count;
				if (m == location) {
					printf("%d\n", count);
					break;
				}
			}

			else q.push({ location, value });
		}
	}

	return 0;
}