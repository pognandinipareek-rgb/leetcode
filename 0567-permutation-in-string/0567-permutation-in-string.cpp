#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int feq[26] = {0};
        int s1Length = s1.length();
        int s2Length = s2.length();

        // If s1 is longer than s2, it's impossible for s1 to be a permutation of s2
        if (s1Length > s2Length) return false;

        // Count frequency of characters in s1
        for (char c : s1) {
            feq[c - 'a']++;
        }

        // Sliding window over s2
        std::vector<int> window(26, 0);
        for (int i = 0; i < s2Length; i++) {
            // Add current character to the window
            window[s2[i] - 'a']++;

            // Remove the character that is out of the window size
            if (i >= s1Length) {
                window[s2[i - s1Length] - 'a']--;
            }

            // Compare the frequency arrays
            if (window == std::vector<int>(feq, feq + 26)) {
                return true;
            }
        }

        return false;
    }
};
