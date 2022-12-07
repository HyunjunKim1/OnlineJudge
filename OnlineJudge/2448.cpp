#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<string> star;
int n;

void make_star(int shift, vector<string>& star) 
{
    int c = star.size();
    for (int i = 0; i < c; i++) {
        star.push_back(star[i] + star[i]);
        string tmp;
        for (int j = 0; j < shift; j++)
            tmp += "   ";
        tmp += star[i];
        for (int j = 0; j < shift; j++)
            tmp += "   ";
        star[i] = tmp;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    // 반복되는 별 넣기
    star.push_back("  *   ");
    star.push_back(" * *  ");
    star.push_back("***** ");

    cin >> n;

    // N == 3 * 2^k , k값 구해서 반복시키기
    int k = log(n / 3) / log(2);

    // 값 vector에 넣기
    for (int i = 0; i < k; i++) 
    {
        make_star(int(pow(2, i)), star);
    }

    for (int i = 0; i < n; i++) 
    {
        cout << star[i] << endl;
    }
}