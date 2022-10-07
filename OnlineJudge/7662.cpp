#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t, k;
    cin >> t;

    while (t--) {
        cin >> k;
        multiset<int> s;
        while (k--) {
            char order;
            int input;
            cin >> order >> input;
            if (s.empty()) {
                if (order == 'I') {//삽입
                    s.insert(input);
                }

            }
            else {
                if (order == 'I') {//삽입

                    s.insert(input);

                }
                else {//삭제
                    if (input == 1) {//최댓값삭제
                        s.erase(--s.end());
                    }
                    else {
                        s.erase(s.begin());
                    }
                }
            }


        }

        if (s.empty())
            cout << "EMPTY" << '\n';
        else {
            auto max = --s.end(), min = s.begin();
            cout << *max << ' ' << *min << '\n';
        }
        //출력부분
    }



    return 0;
}