#include <iostream>
#include <cmath>

using namespace std;

bool remote[10];
int N, M;

int Search(int n) 
{
    int count = 0;
    if (n == 0) 
    {
        if (!remote[0])
            return 1;
        else
            return 0;
    }

    while (n) 
    {
        if (remote[n % 10])
            return 0;
        n /= 10;
        count++;
    }
    return count;
}

int main() 
{

    cin >> N >> M;

    for (int i = 0; i < M; i++) 
    {
        int btn;
        cin >> btn;
        remote[btn] = true;
    }

    int result = abs(100 - N);
    for (int i = 0; i <= 1000000; i++) 
    {
        int count = Search(i);
        if (count > 0) 
        {
            int b = abs(N - i);
            if (result > b + count)
                result = b + count;
        }
    }

    cout << result;
}