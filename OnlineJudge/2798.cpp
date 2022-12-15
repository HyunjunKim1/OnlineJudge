#include <iostream>
#include <algorithm>
using namespace std;


int N, M;
int ans = 0;

int card[100] = { 0, };

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> card[i];

	for (int i = 0; i < N; i++) 
	{
		for (int j = i + 1; j < N; j++) 
		{
			for (int k = j + 1; k < N; k++) 
			{
				if (card[i] + card[j] + card[k] <= M)
				{
					if (ans < card[i] + card[j] + card[k])
						ans = card[i] + card[j] + card[k];
				}
			}
		}
	}
	
	cout << ans << "\n";
}