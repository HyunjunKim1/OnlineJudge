#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vec;
vector<string> result;
int N,M;
string str;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    N = M = 0;

    cin >> N >> M;

    // 벡터에 저장
    for(int i = 0; i < N; i++)
    {
        cin >> str;
        vec.push_back(str);
    }
    // 정렬
    sort(vec.begin(), vec.end());

    for(int i = 0; i < M; i++)
    {
        cin >> str;

        // 문자열 이진탐색 후 동일한거만 벡터에 추가
        if(binary_search(vec.begin(), vec.end(), str) == true)
        {
            result.push_back(str);
        }
    }

    sort(result.begin(), result.end());
    int size = result.size();
    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << endl;
    }
}