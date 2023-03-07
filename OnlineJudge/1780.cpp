#include <iostream>
#include <string.h>

using namespace std;

int N;
int _paper[2188][2188];
int result[3];

bool checkNum(int y, int x, int size)
{
    // 모두 같은 수 인지 아닌지 확인해야함.
    // 모두 같은 수일 경우
    int check = _paper[y][x];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(_paper[y + i][x + j] != check)
                return false;
        }
    }

    return true;
}
void checkPaper(int y, int x, int size)
{
    // 모든 수가 같다면 해당 종이 숫자 1 증가 
    if (checkNum(y, x, size))
    {
        int paperNum = _paper[y][x];
        result[paperNum + 1]++;
        return;
    }

    // 모든 수가 같지 않다면 3으로 나눠서 다시 확인
    int div = size / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            checkPaper(y + div * i, x + div * j, div);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    N = 0;
    cin >> N;

    // 종이배열 초기화
    memset(_paper, 0, sizeof(_paper));
    // 결과값 저장 배열 초기화
    memset(result, 0, sizeof(result));

    for (int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> _paper[y][x];
        }
    }

    checkPaper(0,0,N);

    for(int i = 0; i < 3; i++)
        cout << result[i] << endl;

}