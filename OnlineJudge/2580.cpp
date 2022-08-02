#include <iostream>
using namespace std;

int sudoku[9][9];

bool check(int y, int x, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[y][i] == num) return false;
        if (sudoku[i][x] == num) return false;
    }

    for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++)
        for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++)
            if (sudoku[i][j] == num) return false;

    return true;
}

void func(int y, int x) {
    if (x == 9) { y++; x = 0; }

    if (y == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << sudoku[i][j] << " ";
            cout << endl;
        }
        exit(0);
    }

    if (sudoku[y][x] != 0) {
        func(y, x + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (check(y, x, i)) {
            sudoku[y][x] = i;
            func(y, x + 1);
            sudoku[y][x] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> sudoku[i][j];

    func(0, 0);

    return 0;
}