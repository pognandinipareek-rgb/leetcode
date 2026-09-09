#include <string>
#include <algorithm>

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end()); // Reverse the entire string

        for (int i = 0; i < n; i++) {
            string word = "";
            // Extract each word
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            // Reverse the extracted word
            reverse(word.begin(), word.end());
            // Append to the answer if the word is not empty
            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        // Return the result without the leading space
        return ans.substr(1);
    }
};
