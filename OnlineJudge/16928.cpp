#include <iostream>
#include <queue>
using namespace std;
int map[102] = { 0 };
bool visit[102] = { 0 };

void game(int x, int c) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, c));
    while (!q.empty()) {
        int loc = q.front().first; // ���� ��ǥ
        int cnt = q.front().second; // ī��Ʈ
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int nx = loc + i; // ���� ��ǥ
            if (nx == 100) {
                cout << cnt + 1; // ���������� ���
                return;
            }
            else if (nx < 100) { // 100���� ���� ��ǥ��� 
                while (map[nx] != 0) { // ��ٸ� Ȥ�� ������ Ȯ��
                    nx = map[nx]; // ������ �ڸ��� �̵�
                }
                if (!visit[nx]) { // ó�� �湮�� ��ǥ�϶�
                    q.push(make_pair(nx, cnt + 1)); // ť�� �־���
                    visit[nx] = true; // �湮ó��
                }

            }
        }
    }
}

int main() {
    int n, m, t1, t2;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        map[t1] = t2; // ��ٸ� ����
    }
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        map[t1] = t2; // �� ����
    }
    game(1, 0);
    return 0;
}
