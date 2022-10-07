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
                if (order == 'I') {//����
                    s.insert(input);
                }

            }
            else {
                if (order == 'I') {//����

                    s.insert(input);

                }
                else {//����
                    if (input == 1) {//�ִ񰪻���
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
        //��ºκ�
    }



    return 0;
}