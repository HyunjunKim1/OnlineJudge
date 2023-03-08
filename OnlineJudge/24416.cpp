<<<<<<< HEAD
=======
// Macbook Visual code test
>>>>>>> 8f45f529f38ca65198d77054f198b7983b9f08e6
#include <iostream>
using namespace std;

int cnt = 0;
int f[41] = { 0, };

<<<<<<< HEAD
int fib(int n) 
{
=======
int fib(int n) {
>>>>>>> 8f45f529f38ca65198d77054f198b7983b9f08e6
    if (n == 1 || n == 2) return 1;
    else return (fib(n - 1) + fib(n - 2));
}

<<<<<<< HEAD
int fibonacci(int n) 
{
=======
int fibonacci(int n) {
>>>>>>> 8f45f529f38ca65198d77054f198b7983b9f08e6
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        cnt++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return cnt;
}

<<<<<<< HEAD
int main() 
{
    int num;
    cin >> num;
    cout << fib(num) << " " << fibonacci(num) << endl;

=======
int main() {
    int n;
    cin >> n;
    cout << fib(n) << " " << fibonacci(n);
>>>>>>> 8f45f529f38ca65198d77054f198b7983b9f08e6
    return 0;
}