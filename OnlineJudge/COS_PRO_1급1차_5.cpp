// 하단과 깉이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    int x = 0; int y = -1;

    vector<vector<int>> v(n, vector<int>(n));

    int dir = 0;
    int num = 0;
    int size = n;
    // 1 1 -1 -1 1
    // 3 2 2 1 1
    // 4 3 3 2 2 1 1
    // 5 4 4 3 3 2 2 1 1 
    //while (c_dir < ((n - 1) * 2) + 1)
    while(num < n*n)
    {
        for (int i = 0; i < size; i++)
        {
            x += dx[dir];
            y += dy[dir];
            num++;

            v[x][y] = num;
        }
        dir = (dir + 1) % 4;
        if (dir % 2)
            size -= 1;
    }

    int answer = 0;

    for (int i = 0; i < n; i++)
        answer += v[i][i];
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