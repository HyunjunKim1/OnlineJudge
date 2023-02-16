#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(int argc, char** argv) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> DQ;
	int N;

	cin >> N;

	while (N--) {
		string str;
		cin >> str;

		if (str == "push_front") {
			int X;
			cin >> X;
			DQ.push_front(X);
		}

		else if (str == "push_back") {
			int X;
			cin >> X;
			DQ.push_back(X);
		}

		else if (str == "pop_front") {
			if (!DQ.empty()) {
				cout << DQ.front() << "\n";
				DQ.pop_front();
			}
			else
				cout << "-1\n";
		}

		else if (str == "pop_back") {
			if (!DQ.empty()) {
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
			else
				cout << "-1\n";
		}

		else if (str == "size") {
			cout << DQ.size() << "\n";
		}

		else if (str == "empty") {
			cout << DQ.empty() << "\n";
		}

		else if (str == "front") {
			if (!DQ.empty()) {
				cout << DQ.front() << "\n";
			}
			else
				cout << "-1\n";
		}

		else if (str == "back") {
			if (!DQ.empty()) {
				cout << DQ.back() << "\n";
			}
			else
				cout << "-1\n";
		}
	}
	return 0;
}