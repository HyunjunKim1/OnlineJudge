// �ϴܰ� ���� include�� ����� �� �ֽ��ϴ�.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long num) {
	num += 1;
	string temp = to_string(num);
	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] == '0')
			temp[i] = '1';
	}
	long long answer = stoll(temp);
	return answer;
}

int main() {
	long long num = 9949999;
	long long ret = solution(num);

	cout << "solution �Լ��� ��ȯ ���� " << ret << " �Դϴ�." << endl;
}