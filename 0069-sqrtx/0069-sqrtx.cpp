class Solution {
public:
    int mySqrt(int x) {
        // Special cases when x is 0 or 1
        if (x == 0 || x == 1)
            return x;
        
        // Initialize the search range
        int start = 1;
        int end = x;
        
        // Perform binary search
        while (start <= end) {
            // Calculate the middle point
            int mid = start + (end - start) / 2;
            
            // Calculate square of mid
            long long square = static_cast<long long>(mid) * mid;
            
            // Adjust search range based on the square
            if (square > x) {
                end = mid - 1;
            } else if (square == x) {
                return mid; // Exact square root found
            } else {
                start = mid + 1;
            }
        }
        
        // Return the integer value of the square root
        return end; // end is the largest integer whose square is less than or equal to x
    }
};
