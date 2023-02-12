#include<iostream>
using namespace std;

string s;
int N;
int video[64][64];

void solve(int x, int y, int size)
{
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
		{
			if (video[i][j] != video[x][y])
			{
				cout << "(";
				solve(x, y, size / 2);
				solve(x, y + size / 2, size / 2);
				solve(x + size / 2, y, size / 2);
				solve(x + size / 2, y + size / 2, size / 2);
				cout << ")";
				return;
			}
		}
	cout << video[x][y];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
			video[i][j] = s[j] - '0';
	}
	solve(0, 0, N);

}