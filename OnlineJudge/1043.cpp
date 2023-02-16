#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int t; // ���� �ƴ� ����� ��
int tn; // ���Ǿƴ� ����� �ѹ�
int p; // ��Ƽ �����ϴ� ����� ������ �ƴ»��
bool _isTrueP[51];
bool _isFalseP[51];
vector<int> party[51];
queue<int> q;

int result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	fill(_isTrueP, _isTrueP + 51, false);
	fill(_isFalseP, _isFalseP + 51, false);

	cin >> t;

	// ������ �ƴ»�� üũ
	for (int i = 0; i < t; i++)
	{
		cin >> tn;
		_isTrueP[tn] = true;
		q.push(tn);
	}

	// ��Ƽ �����ϴ� ���üũ
	for (int i = 1; i <= M; i++)
	{
		cin >> tn;
		for (int j = 0; j < tn; j++)
		{
			cin >> p;
			party[i].push_back(p);
		}
	}

	while (!q.empty())
	{
		p = q.front();
		q.pop();

		for (int i = 1; i <= M; i++)
		{
			if (find(party[i].begin(), party[i].end(), p) != party[i].end())
			{
				_isFalseP[i] = true;

				/* 
				 * �ش���Ƽ�� ������ �ƴ»���� �Ѹ��̶� �ִ°��, �ش� ��Ƽ�ο��鵵 ������ �˱⿡
				 * q�� ����������
				 */
				if (party[i].size() > 1) 
				{
					for (int j = 0; j < party[i].size(); j++)
					{
						if (!_isTrueP[party[i][j]])
						{
							_isTrueP[party[i][j]] = true;
							q.push(party[i][j]);
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= M; i++)
		if (!_isFalseP[i]) result++;

	cout << result << endl;
}