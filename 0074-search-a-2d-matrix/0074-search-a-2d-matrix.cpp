class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int row, int targ) {
        int n = matrix[row].size(); // Get the number of columns in the specified row
        int str = 0, endd = n - 1;

        while (str <= endd) {
            int mid = str + (endd - str) / 2;
            if (targ == matrix[row][mid]) {
                return true; // Target found
            } else if (targ > matrix[row][mid]) {
                str = mid + 1; // Search in the right half
            } else {
                endd = mid - 1; // Search in the left half
            }
        }
        return false; // Target not found in the row
    }

    bool searchMatrix(vector<vector<int>>& matrix, int targ) {
        int m = matrix.size(); // Get the number of rows
        if (m == 0) return false; // Handle empty matrix case
        int n = matrix[0].size(); // Get the number of columns

        int st = 0, end = m - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2; // Corrected assignment

            // Check if the target is within the range of the current row
            if (targ >= matrix[mid][0] && targ <= matrix[mid][n - 1]) {
                return searchInRow(matrix, mid, targ); // Search in the specified row
            } else if (targ > matrix[mid][n - 1]) {
                st = mid + 1; // Target is in the lower half
            } else {
                end = mid - 1; // Target is in the upper half
            }
        }
        return false; // Target not found in the matrix
    }
};
