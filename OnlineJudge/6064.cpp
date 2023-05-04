#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int rx, ry; // Ÿ�� x,y�� ������ ��� �� ���� 1�� �ǵ���
        if (x > y) { // y�� 1�� ���
            rx = x - y + 1;
            ry = 1;
        }
        else { // x�� 1�� ���
            ry = y - x + 1;
            rx = 1;
        }

        int cnt = 1; // �� ��° ��
        int nx = 1; // ���� ��° x
        int ny = 1; // ���� ��° y
        bool stop = false; // ����� �̰ų� ������ ã�Ұų�
        while (!stop) {
            //�����ذ� Ÿ�� x�� ���� ��� -> ����
            if (nx == rx && ny == ry) {
                cnt = cnt + x - rx; // �����ط� �� �� �ֵ��� ������
                nx = x;
                ny = y;
                stop = true;
            }
            else if (m - nx < n - ny) {// x�� ���� 1�̵Ǵ� ���
                ny = ny + m - nx + 1;
                cnt = cnt + m - nx + 1;
                nx = 1;
            }
            else if (m - nx > n - ny) { // y�� ���� 1�� �Ǵ� ���
                nx = nx + n - ny + 1;
                cnt = cnt + n - ny + 1;
                ny = 1;
            }
            else { // ������� ���
                cnt = cnt + n - ny;
                nx = m;
                ny = n;
                stop = true;
            }
        }
        if (nx == x && ny == y) { // ���� ��
            cout << cnt << endl;
        }
        else { // ����ر��� ���� ���
            cout << -1 << endl;
        }
    }
    return 0;
}
