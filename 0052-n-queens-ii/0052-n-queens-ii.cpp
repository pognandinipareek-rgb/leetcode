class Solution {
    int cnt;

public:
    void solve(int i, int n, int row, int diag1, int diag2) {
        if (i == n) {
            cnt++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!(row & (1 << j)) && !(diag1 & (1 << (i - j + n - 1))) &&
                !(diag2 & (1 << (i + j)))) {
                solve(i + 1, n, row | (1 << j), diag1 | (1 << (i - j + n - 1)),
                      diag2 | (1 << (i + j)));
            }
        }
    }

    int totalNQueens(int n) {
        cnt = 0;
        solve(0, n, 0, 0, 0);
        return cnt;
    }
};