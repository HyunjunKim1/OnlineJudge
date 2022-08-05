#include <iostream>
using namespace std;

int cnt = 0;
int f[41] = { 0, };

int fib(int n) {
    if (n == 1 || n == 2) return 1;
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        cnt++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << " " << fibonacci(n);
    return 0;
}