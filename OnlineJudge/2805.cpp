#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> tree;

int main() {
    cin >> n >> m;

    for (auto i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.push_back(x);
    }

    int start = 0;
    int end = *max_element(tree.begin(), tree.end());
    int result = 0;

    while (start <= end) {
        long long int total = 0;
        int mid = (start + end) / 2;
        for (auto i = 0; i < n; i++) {
            if (tree[i] > mid) total += tree[i] - mid;
        }
        if (total < m) {
            end = mid - 1;
        }
        else {
            result = mid;
            start = mid + 1;
        }
    }
    cout << result;
}