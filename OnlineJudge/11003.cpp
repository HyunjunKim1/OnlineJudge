#include<iostream>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n, l;
    cin >> n >> l;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        pq.push({ a, i });
        int start = i - l + 1;
        while (start > 0 && start > pq.top().second) {
            pq.pop();
        }
        cout << pq.top().first << ' ';

    }



    return 0;
}