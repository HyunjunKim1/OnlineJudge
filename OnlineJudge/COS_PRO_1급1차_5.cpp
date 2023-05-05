// 하단과 깉이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<vector<int>> arr(n, vector<int>(n));

    int cnt = 1;
    int row = 0, col = 0;
    int d_row = 1, d_col = 0;

    for (int i = 0; i < n * n; i++) {
        arr[row][col] = cnt++;
        int next_row = row + d_row;
        int next_col = col + d_col;

        if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n || arr[next_row][next_col] != 0) {
            int tmp = d_row;
            d_row = d_col;
            d_col = -tmp;
        }

        row += d_row;
        col += d_col;
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                answer += arr[i][j];
        }
    }

	return answer;
}

int main() {
    int n1 = 3;
    int ret1 = solution(n1);

    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    int n2 = 2;
    int ret2 = solution(n2);

    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}