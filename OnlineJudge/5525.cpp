#include <iostream>
#include <string>
using namespace std;

int N, M, res;
string S;

int main()
{
	cin >> N >> M >> S;

	for (int i = 0; i < M; i++) {
		if (S[i] == 'O') continue;
		int oCnt = 0;
		while (S[i + 1] == 'O' && S[i + 2] == 'I') {
			oCnt++;
			i += 2;
			if (oCnt == N) {
				oCnt--;
				res++;
			}
		}
	}

	cout << res;
}