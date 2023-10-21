#include <iostream>
#include <vector>

using namespace std;

bool IsSafe(int grid[9][9], int col, int row, int number) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == number)
            return false;
    }

    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == number)
            return false;
    }

    int grow = (row / 3) * 3;
    int gcol = (col / 3) * 3;

    for (int i = grow; i < (grow + 3); i++) {
        for (int j = gcol; j < (gcol + 3); j++) {
            if (grid[i][j] == number)
                return false;
        }
    }

    return true;
}

bool helper(int grid[9][9], int row, int col) {
    int nrow = 0, ncol = 0;

    // Base case: If both row and col have reached the end of the grid, return true.
    if (row ==9)
        return true;

    if (col != 8) {
        ncol = col + 1;
        nrow = row;
    } else {
        ncol = 0;
        nrow = row + 1;
    }

    if (grid[row][col] != 0) {
        if (helper(grid, nrow, ncol))
            return true;
    }
        else {
            for (int i = 1; i <= 9; i++) {
                if (IsSafe(grid, col, row, i)) {
                    grid[row][col] = i;
                    if (helper(grid, nrow, ncol))
                        return true;
                    else
                        grid[row][col] = 0;
                }
            }
        }
    return false;
    }




void sudoku_solve(int grid[9][9]) {
    if (helper(grid, 0, 0)) {
        cout << "Solution is:" << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << grid[i][j];
                if (j < 8) {
                    cout << " ";  
                }
            }
            cout << endl;  
        }
    }

    }

int main(void) {
    int n, board[9][9];
  cout<<"ENter your Sudoku Board here"<<endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                board[j][k] = 0;
                cin >> board[j][k];
            }
        }
        sudoku_solve(board);

    }

    return 0;
}
