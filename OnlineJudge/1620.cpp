#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
//해시맵사용
int main() {
    map<string, int> pokemon;
    vector<string> name;
    int n, m;
    string temp; //포켓몬 이름과 번호가 섞여있으므로 string
    cin >> n >> m;
    vector<string> result;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        name.push_back(temp); // 도감번호 주어질때 포켓몬 이름 찾기
        pokemon.insert(make_pair(temp, i)); // 포켓몬 이름이 주어질때 도감번호 빠르게 찾기
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (temp[0] >= 65 && temp[0] <= 90) {
            // 포켓몬 이름이 주어진 경우 (맨 앞 문자가 영어 대문자인것을 이용)
            result.push_back(to_string(pokemon[temp]));
            //result 벡터는 string이기 때문에 번호를 string으로 변환해줌
        }
        else // 도감 번호가 주어진 경우
        {
            result.push_back(name[stoi(temp) - 1]);
            //입력값은 string 그래서 정수형으로 변환 후 넣어줌
            // -1을 해준 이유는 name배열은 0부터 시작했기 때문 
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n'; // 출력
    }
    return 0;
}
