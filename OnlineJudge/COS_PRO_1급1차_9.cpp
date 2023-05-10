#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func(int record) {
    if (record == 0) return 1;
    else if (record == 1) return 2;
    return 0;
}

int solution(vector<int> recordA, vector<int> recordB) {
    int cnt = 0;
    for (int i = 0; i < (int)recordA.size(); i++) {
        if (recordA[i] == recordB[i])
            continue;
        else if (recordA[i] == func(recordB[i]))
            cnt = cnt + 3;
        else
            cnt = cnt - 1;
    }
    return cnt;
}
int main() {
    vector<int> recordA = { 2,0,0,0,0,0,1,1,0,0 };
    vector<int> recordB = { 0,0,0,0,2,2,0,2,2,2 };
    int ret = solution(recordA, recordB);

    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}