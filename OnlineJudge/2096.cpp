#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[3];
int max_dp[2][3] = {0,};
int min_dp[2][3] = {0,}; 

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        
        if(i == 0)
        {
            max_dp[0][0] = min_dp[0][0] = arr[0];
            max_dp[0][1] = min_dp[0][1] = arr[1];
            max_dp[0][2] = min_dp[0][2] = arr[2];
            continue;
        }

        max_dp[1][0] = arr[0] + max(max_dp[0][0], max_dp[0][1]);
        max_dp[1][1] = arr[1] + max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]);
        max_dp[1][2] = arr[2] + max(max_dp[0][1], max_dp[0][2]);

        max_dp[0][0] = max_dp[1][0];
        max_dp[0][1] = max_dp[1][1];
        max_dp[0][2] = max_dp[1][2];

        min_dp[1][0] = arr[0] + min(min_dp[0][0], min_dp[0][1]);
        min_dp[1][1] = arr[1] + min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]);
        min_dp[1][2] = arr[2] + min(min_dp[0][1], min_dp[0][2]);

        min_dp[0][0] = min_dp[1][0];
        min_dp[0][1] = min_dp[1][1];
        min_dp[0][2] = min_dp[1][2];
    }

    cout << max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]) << ' ' << min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]) << endl;
}