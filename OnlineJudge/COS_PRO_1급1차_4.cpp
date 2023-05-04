// 하단과 같이 include를 사용할 수 있습니다.
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

	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}