#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> sequence;
vector<char> ans;
int n;
int cur_num;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	sequence.push(cur_num);
	cur_num++;

	int num;
	bool valid = true;

	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> num;
		// stack 의 top이 num과 같아질때까지 반복
		while (sequence.top() < num) {
			sequence.push(cur_num);
			cur_num++;
			ans.push_back('+');
		}
		if (sequence.top() == num) {
			sequence.pop();
			ans.push_back('-');
		}
		else {
			valid = false;
		}
	}

	if (!valid) {
		cout << "NO" << '\n';
	}
	else {
		for (auto ch : ans) {
			cout << ch << '\n';
		}
	}

}