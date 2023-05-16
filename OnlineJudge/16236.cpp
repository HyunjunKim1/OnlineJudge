#include <iostream>
#include <queue>

using namespace std;
int n;
int map[22][22];
int dx[] = { 0, -1, 1, 0 }; // ���¿���
int dy[] = { -1, 0, 0, 1 };
int bx, by;
int result = 0; // �� �ɸ� �ð�
int count = 0; // ����� ���� Ƚ��
int sz = 2; // ��� ������
bool stop = false; // ���� ����Ⱑ ���� ���
bool eat = false; // �� ������ ���� ���
void bfs(int a, int b, bool visit[][22], int shSize) {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(a, b), 0));
    visit[b][a] = true;
    int temp; // �� ������ �Դµ� �ɸ� �ð�
    while (!q.empty()) {
        int x = q.front().first.first; // �� ��ǥ
        int y = q.front().first.second; // �� ��ǥ
        int cnt = q.front().second; // ���� �ð�
        // ���� ������ ���� �� ���� ������ �켱������ �Դ� ���� ���
        if (map[y][x] > 0 && map[y][x] < shSize && temp == cnt) {
            if ((by > y) || (by == y && bx > x)) {
                by = y; // ����⸦ ���� ��� ��ġ ����
                bx = x;
                continue;
            }
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // ���� �̵�
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[ny][nx]) {
                if (map[ny][nx] <= shSize) {// �������ų� ���� �� �ִ� ���
                    if (map[ny][nx] > 0 && map[ny][nx] < shSize && !eat) { //����⸦ ���� �� �ִ� ���
                        eat = true; // �� ���� ����
                        bx = nx; //���� ��ġ�� ����⸦ �Ծ��� ��ġ��
                        by = ny;
                        temp = cnt + 1; // �� ���� �Դµ��ɸ� �ð�
                        result += temp; // �� �ð��� �߰�
                    }
                    else { // ����⸦ ���Դ� ���
                        q.push(make_pair(make_pair(nx, ny), cnt + 1));
                        visit[ny][nx] = true;
                    }
                }
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                by = i; // ��� ���� ��ġ
                bx = j;
                map[i][j] = 0;
            }
        }
    }

    while (!stop) {
        bool visit[22][22] = { 0 };
        bfs(bx, by, visit, sz); // �� ���� ���������� �̵�
        if (eat) { // �Ծ��� ���
            eat = false;
            count += 1; // ���� ũ�⿡�� ����� ���� Ƚ�� ����
            map[by][bx] = 0; // ���� ����� ����
            if (count == sz) { // ��� ũ�Ⱑ �����ϴ� ���
                sz += 1; // ��� ������ +1
                count = 0; //���� ũ�⿡�� ����� ���� Ƚ�� �ʱ�ȭ
            }
        }
        else { // �� ������ ���Դ� ���
            stop = true; // ���� ���� ���� ��û�ؾ���.
        }
    }
    cout << result << '\n';
    return 0;
}
