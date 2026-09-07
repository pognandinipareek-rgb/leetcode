#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int ind = m + n - 1; // Index for the merged array
        int i = m - 1; // Last index of the first array
        int j = n - 1; // Last index of the second array

        // Merge in reverse order
        while (i >= 0 && j >= 0) {
            if (a[i] >= b[j]) {
                a[ind--] = a[i--]; // Place element from a
            } else {
                a[ind--] = b[j--]; // Place element from b
            }
        }

        // If there are remaining elements in b, add them
        while (j >= 0) {
            a[ind--] = b[j--];
        }
        
        // No need to copy remaining elements from a, they are already in place
    }
};

