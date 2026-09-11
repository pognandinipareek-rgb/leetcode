#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int srow = 0, scol = 0, erow = n - 1, ecol = m - 1;
        vector<int> ans;

        while (srow <= erow && scol <= ecol) {
            // Traverse from left to right
            for (int j = scol; j <= ecol; j++)
                ans.push_back(mat[srow][j]);
            srow++; // Move down to the next row

            // Traverse from top to bottom
            for (int j = srow; j <= erow; j++)
                ans.push_back(mat[j][ecol]);
            ecol--; // Move left to the previous column

            if (srow <= erow) {
                // Traverse from right to left
                for (int j = ecol; j >= scol; j--)
                    ans.push_back(mat[erow][j]);
                erow--; // Move up to the previous row
            }

            if (scol <= ecol) {
                // Traverse from bottom to top
                for (int j = erow; j >= srow; j--)
                    ans.push_back(mat[j][scol]);
                scol++; // Move right to the next column
            }
        }

        return ans;
    }
};
