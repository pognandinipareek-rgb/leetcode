#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool inPair = false; // Flag to track if we are between a pair of '|'

        for (char c : s) {
            if (c == '|') {
                inPair = !inPair; // Toggle the inPair flag
            } else if (c == '*' && !inPair) {
                count++; // Count '*' only if we are not in a pair
            }
        }
        return count; // Return the total count of '*' outside pairs
    }
};



