class Solution {
public:
    bool isAlphaNum(char ch) {
        return (ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z');
    }

    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;
        while (st < end) {
            // Increment `st` if it's not alphanumeric
            while (st < end && !isAlphaNum(s[st])) {
                st++;
            }
            // Increment `end` if it's not alphanumeric
            while (st < end && !isAlphaNum(s[end])) {
                end--;
            }
            // Check for palindrome
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }
            st++;
            end--;
        }
        return true; // Return true if it is a palindrome
    }
};
