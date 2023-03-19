#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    string order;
    int val, BIT = 0; // BIT�� �ݵ�� 0���� �ʱ�ȭ ���ش�.
    while (m--)
    {
        cin >> order;
        if (order == "add")
        {
            cin >> val;
            // or �����ڸ� ���� val��° �ڸ����� 1�� ä���.
            BIT |= (1 << val);
        }
        else if (order == "remove")
        {
            cin >> val;
            // ex) 1000 & ~(1000) = 0000
            BIT &= ~(1 << val);
        }
        else if (order == "check")
        {
            cin >> val;
            if (BIT & (1 << val))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (order == "toggle")
        {
            cin >> val;
            // BIT�� val��° �ڸ��� 1�̶�� 1^1=0�� �Ǿ� 1->0�� �ǰ�
            // val��° �ڸ��� 0�̶�� 0^1=1 �� �Ǿ� 0 -> 1�� �ȴ�.
            BIT ^= (1 << val);
        }
        else if (order == "all")
        {
            // ex) 10000 - 1 = 1111
            BIT = (1 << 21) - 1;
        }
        else if (order == "empty")
        {
            BIT = 0;
        }
    }

    return 0;
}