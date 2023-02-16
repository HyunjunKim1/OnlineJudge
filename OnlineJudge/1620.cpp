#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
//�ؽøʻ��
int main() {
    map<string, int> pokemon;
    vector<string> name;
    int n, m;
    string temp; //���ϸ� �̸��� ��ȣ�� ���������Ƿ� string
    cin >> n >> m;
    vector<string> result;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        name.push_back(temp); // ������ȣ �־����� ���ϸ� �̸� ã��
        pokemon.insert(make_pair(temp, i)); // ���ϸ� �̸��� �־����� ������ȣ ������ ã��
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (temp[0] >= 65 && temp[0] <= 90) {
            // ���ϸ� �̸��� �־��� ��� (�� �� ���ڰ� ���� �빮���ΰ��� �̿�)
            result.push_back(to_string(pokemon[temp]));
            //result ���ʹ� string�̱� ������ ��ȣ�� string���� ��ȯ����
        }
        else // ���� ��ȣ�� �־��� ���
        {
            result.push_back(name[stoi(temp) - 1]);
            //�Է°��� string �׷��� ���������� ��ȯ �� �־���
            // -1�� ���� ������ name�迭�� 0���� �����߱� ���� 
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n'; // ���
    }
    return 0;
}
