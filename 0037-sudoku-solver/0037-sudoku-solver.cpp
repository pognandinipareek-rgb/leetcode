class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0, 0);
    }

    bool solver(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if (board[row][col] != '.') {
            return solver(board, nextRow, nextCol);
        }

        for (int i = 1; i <= 9; i++) {
            if (safe(board, row, col, i)) {
                board[row][col] = '0' + i;

                if (solver(board, nextRow, nextCol)) {
                    return true;
                }

                board[row][col] = '.';
            }
        }

        return false;
    }

    bool safe(vector<vector<char>>& board, int row, int col, int val) {
        char ch = '0' + val;

        // Check row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) {
                return false;
            }
        }

        // Check 3x3 box
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;

        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == ch) {
                    return false;
                }
            }
        }

        return true;
    }
};