#include<iostream>
using namespace std;

string s;
int N;
int video[64][64];

void solve(int y, int x, int size)
{
	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
		{
			if (video[i][j] != video[y][x])
			{
				cout << "(";
				solve(y, x, size / 2);
				solve(y, x + size / 2, size / 2);
				solve(y + size / 2, x, size / 2);
				solve(y + size / 2, x + size / 2, size / 2);
				cout << ")";
				return;
			}
		}
	cout << video[y][x];
}

int main()
{
	cin >> N;
	for (int y = 0; y < N; y++)
	{
		cin >> s;
		for (int x = 0; x < N; x++)
			video[y][x] = s[x] - '0';
	}
	solve(0, 0, N);

}