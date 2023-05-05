// �ϴܰ� ���� include ���� ����� �� �ֽ��ϴ�.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string pos) {
    int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

    int posX = pos[0] - 'A';
    int posY = pos[1] - '1';

    int i = 0;
    int loop = 8;
    int answer = 0;
    while (loop--)
    {
        int defX = posX + dx[i];
        int defY = posY + dy[i];
        i++;

        if (defX >= 0 && defX < 8 && defY >= 0 && defY < 8)
            answer++;
    }

    return answer;
}

int main() {
    string pos = "A7";
    int ret = solution(pos);

    cout << "solution �Լ��� ��ȯ ���� " << ret << " �Դϴ�." << endl;
}