#include <iostream>

using namespace std;


long long pow(long long A, long long B, long long C)
{
	if (B == 0) 
		return 1;
	if (B == 1)
		return A % C;
	long long result = pow(A, B / 2, C);
	
	result = result * result % C;
	if (B % 2 == 0)
		return result;
	return result * A % C;
}

int main()
{
	long long A, B, C;

	cin >> A >> B >> C;

	cout << pow(A, B, C);
}