#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> votes) {

    int vote_counter[11] = { 0 };
    for (int i = 0; i < votes.size(); i++) {
        vote_counter[votes[i]] += 1;
    }
    int max_val = 0;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (max_val < vote_counter[i]) {
            max_val = vote_counter[i];
            cnt = 1;
        }
        else if (max_val == vote_counter[i]) {
            cnt += 1;
        }
    }
    vector<int> answer(cnt, 0);
    for (int i = 1, idx = 0; i <= N; i++) {
        if (vote_counter[i] == max_val) {
            answer[idx] = i;
            idx += 1;
        }
    }
    return answer;
}

int main() {
    int N1 = 5;
    vector<int> votes1 = { 1,5,4,3,2,5,2,5,5,4 };
    vector<int> ret1 = solution(N1, votes1);

    cout << "solution 함수의 반환 값은 [";
    for (int i = 0; i < ret1.size(); i++) {
        if (i != 0) cout << ", ";
        cout << ret1[i];
    }
    cout << "] 입니다." << endl;

    int N2 = 4;
    vector<int> votes2 = { 1,3,2,3,2 };
    vector<int> ret2 = solution(N2, votes2);

    cout << "solution 함수의 반환 값은 [";
    for (int i = 0; i < ret2.size(); i++) {
        if (i != 0) cout << ", ";
        cout << ret2[i];
    }
    cout << "] 입니다." << endl;
}