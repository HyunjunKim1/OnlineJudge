#include <iostream>
#include <map>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    map<string, string> m;
    string a, b;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;

        m[a] = b;
    }

    for (int i = 0; i < M; i++) {
        cin >> a;

        cout << m[a] << '\n';
    }

    return 0;
}